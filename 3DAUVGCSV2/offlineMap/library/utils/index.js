function getRandomColor() {
  const letters = "0123456789ABCDEF";
  let color = "#";
  for (let i = 0; i < 6; i++) {
    color += letters[Math.floor(Math.random() * 16)];
  }
  return color;
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