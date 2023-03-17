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
// UTM投影坐标系（以49N为例）
const utm = '+proj=utm +zone=49 +datum=WGS84 +units=m +no_defs';
function wgs84ToUTM(lng, lat) {
  return proj4(wgs84, utm, [lng, lat]);
}
function UTMToWgs84(lng, lat) {
  return proj4(utm, wgs84, [lng, lat]);
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
function XYZtoBLH(RE, data) {
  let X = data.X;
  let Y = data.Y;
  let Z = data.Z;
  let x2y2 = square(X) + square(Y)
  let e2 = (square(RE.a) - square(RE.b)) / (square(RE.a));
  //使用迭代算法来计算B的值，先求出B的初值B0

  let B0 = Math.atan(Z / Math.sqrt(x2y2) + 1);
  let B1 = Math.atan(Z / Math.sqrt(x2y2));
  while (Math.abs(B1 - B0) >= 0.000000000001) {
    B0 = B1;
    var N = RE.a / Math.sqrt(1 - e2 * square(Math.sin(B0)));
    var H = (Z / Math.sin(B0)) - N * (1 - e2);
    B1 = Math.atan((Z + N * e2 * Math.sin(B0)) / Math.sqrt(x2y2));
  }
  let L = Math.atan2(Y, X);
  let B = B1;

  let result = { L: L * r2d, B: B * r2d, H: H };
  return result;
}

// 无人艇的固定参数
const a_11 = -0.8455; const a_12 = -1.6741; const a_13 = -4.5662; const a_14 = 0.0065; const a_15 = 0.1174;
const a_21 = -0.3197; const a_22 = -3.3009; const a_23 = -0.1651; const a_24 = 2.4964; const a_25 = -0.2109;
const a_31 = -1.9904; const a_32 = 2.0397; const a_33 = -0.673; const a_34 = 1.1948; const a_35 = 0.2657;

function getPrediction({ x, y, psi, u, v, r, angle, PWM, isDynamic, t,dt }) {
  const rad = (psi) => psi * Math.PI / 180;
  const dot_x = Math.cos(rad(psi)) * u - Math.sin(rad(psi)) * v
  const dot_y = Math.sin(rad(psi)) * u + Math.cos(rad(psi)) * v
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