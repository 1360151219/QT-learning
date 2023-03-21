function getRandomColor() {
  const letters = "0123456789ABCDEF";
  let color = "#";
  for (let i = 0; i < 6; i++) {
    color += letters[Math.floor(Math.random() * 16)];
  }
  return color;
}


//centre:椭圆中心点,X:横向经度,Y:纵向纬度
function ellipse(centre, x, y) {
  var assemble = new Array();
  var angle;
  var dot;
  var tangent = x / y;

  for (i = 0; i < 360; i += 5) {
    angle = (Math.PI / 180) * i;
    dot = new BMap.Point((centre.lng + Math.sin(angle) * x * tangent), (centre.lat + Math.cos(angle) * y));
    assemble.push(dot);
  }
  return assemble;
}

function nMileToMeter(num) {
  return 1852 * num
}
// 四元安全领域
/**
 * 求船舶旋回进距和初径的系数
 * @param {number} v 船速(海里) 
 * @returns 
 */
function getK(v) {
  let k_ad = 10 ** (0.3591 * Math.log10(v) + 0.0952)
  let k_dt = 10 ** (0.5441 * Math.log10(v) - 0.0795)
  return { k_ad, k_dt }
}
/**
 * 求四元数
 * @param {number} v 船速(海里) 
 * @param {number} L 船长(海里)
 * @returns 
 */
function Quaternion(v, L) {
  let k_ad = 10 ** (0.3591 * Math.log10(v) + 0.0952)
  let k_dt = 10 ** (0.5441 * Math.log10(v) - 0.0795)
  let r_fore = (1 + 1.34 * Math.sqrt(k_ad ** 2 + (k_ad / 2) ** 2)) * L
  let r_aft = (1 + 0.67 * Math.sqrt(k_ad ** 2 + (k_ad / 2) ** 2)) * L
  let r_starb = (0.2 + k_dt) * L
  let r_port = (0.2 + 0.75 * k_dt) * L
  // 90 270 0 180
  return { r_fore: nMileToMeter(r_fore), r_aft: nMileToMeter(r_aft), r_starb: nMileToMeter(r_starb), r_port: nMileToMeter(r_port) }
}

// ============距离和wgs84之间的互转
// WGS84坐标系
const wgs84 = '+proj=longlat +datum=WGS84 +no_defs';
const xyz = '+proj=geocent +datum=WGS84 +no_defs';
// UTM投影坐标系（以49N为例）
const utm = '+proj=utm +zone=49 +datum=WGS84 +units=m +no_defs';
function wgs84ToUTM(lng, lat) {
  return proj4(wgs84, utm, [lng, lat]);
}
function UTMToWgs84(lng, lat) {
  return proj4(utm, wgs84, [lng, lat]);
}
function xyzToWgs84(x, y, z) {
  return proj4(xyz, wgs84, [x, y, z])
}
function newCoordinate(lng, lat, distance, bearing) {
  let [u_lng, u_lat] = wgs84ToUTM(lng, lat)
  // 根据给定的距离和方向，计算出新的平面直角坐标系下的坐标
  let bearing_rad = bearing * Math.PI / 180;
  let dx = distance * Math.sin(bearing_rad);
  let dy = distance * Math.cos(bearing_rad);
  let x_new = u_lng + dx;
  let y_new = u_lat + dy;
  const [w_lng, w_lat] = UTMToWgs84(x_new, y_new)
  return wgs84tobd09(w_lng, w_lat)
}

// ============= 船舶预测算法

//----------------------------------------------------定义坐标系椭球参数对象
let wgs84Param = {
  a: 6378137,                     //长半径,单位m
  b: 6356752.3142451795,          //短半径
  f: 1 / 298.257223563,             //扁率
}
var square = num => num * num         //快速计算平方
let d2r = Math.PI / 180;
let r2d = 180 / Math.PI;            //角度 = 弧度 * 180 / Math.PI;

//----------------------------------------------------XYZ转换为BLH
function XYZtoBLH(x, y) {
  const lon1 = 114.466975
  const lat1 = 31.115171
  const x1 = -110.355637
  const y1 = 105.503448
  const lon2 = 114.466979
  const lat2 = 31.115167
  const x2 = -110.78701
  const y2 = 105.870926
  let lon_cos = Math.cos(lat2 * Math.PI / 180);
  let m = (lon2 - lon1) * lon_cos;
  let n = lat2 - lat1;
  let M = x2 - x1;
  let N = y2 - y1;
  let P = x - x1;
  let Q = y - y1;
  let a = (P * P + Q * Q) * (m * m + n * n) / (M * M + N * N);
  let b = (M * P + Q * N) * Math.sqrt(n * n + m * m) * Math.sqrt(a) / (Math.sqrt(N * N + M * M) * Math.sqrt(P * P + Q * Q));
  let c = Math.sqrt(b * b * n * n - (m * m + n * n) * (b * b - a * m * m));
  let q1 = (b * n + c) / (m * m + n * n);
  let q2 = (b * n - c) / (m * m + n * n);
  let p1 = (b - q1 * n) / m;
  let p2 = (b - q2 * n) / m;
  let lon_1 = p1 / lon_cos + lon1;
  let lat_1 = q1 + lat1;
  let lon_2 = p2 / lon_cos + lon1;
  let lat_2 = q2 + lat1;
  let judge1 = (lon_1 - lon1) * (lat2 - lat1) - (lat_1 - lat1) * (lon2 - lon1);
  let judge2 = (lon_2 - lon1) * (lat2 - lat1) - (lat_2 - lat1) * (lon2 - lon1);
  let judge = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);

  let lon = 0;
  let lat = 0;
  if (judge * judge1 < 0) {
    lon = lon_1;
    lat = lat_1;
  } else {
    lon = lon_2;
    lat = lat_2;
  }
  return { lon, lat }
}

// 无人艇的固定参数
const a_11 = -0.8455; const a_12 = -1.6741; const a_13 = -4.5662; const a_14 = 0.0065; const a_15 = 0.1174;
const a_21 = -0.3197; const a_22 = -3.3009; const a_23 = -0.1651; const a_24 = 2.4964; const a_25 = -0.2109;
const a_31 = -1.9904; const a_32 = 2.0397; const a_33 = -0.673; const a_34 = 1.1948; const a_35 = 0.2657;

// 这里的psi已经是rad的
function getPrediction({ x, y, psi, u, v, r, angle, PWM, isDynamic, dt }) {
  // const rad = (psi) => psi * Math.PI / 180;
  const dot_x = Math.cos(psi) * u - Math.sin(psi) * v
  const dot_y = Math.sin(psi) * u + Math.cos(psi) * v
  const dot_psi = r;

  //  动力学：速度变化
  const dot_u = a_11 * u * Math.abs(u) + a_12 * v * v + a_13 * r * r + a_14 * u * (PWM - 1020) + a_15 * u * u * Math.sin(angle) * Math.sin(angle);
  const dot_v = a_21 * v + a_22 * v * Math.abs(v) + a_23 * r + a_24 * r * Math.abs(r) + a_25 * u * u * Math.sin(angle) * Math.cos(angle);
  const dot_r = a_31 * r + a_32 * r * Math.abs(r) + a_33 * v + a_34 * v * Math.abs(v) + a_35 * u * u * Math.sin(angle) * Math.cos(angle);

  const new_x = x + dot_x * dt;
  const new_y = y + dot_y * dt;
  const new_psi = psi + dot_psi * dt;

  const new_u = u + (isDynamic ? dot_u * dt : 0);
  const new_v = v + (isDynamic ? dot_v * dt : 0);
  const new_r = r + (isDynamic ? dot_r * dt : 0);
  
  return {
    x: new_x,
    y: new_y,
    psi: new_psi,
    u: new_u,
    v: new_v,
    r: new_r,
  }
}