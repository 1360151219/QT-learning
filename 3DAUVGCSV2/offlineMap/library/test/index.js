let timer1, timer2, timer5;
function test1() {
  let i = 114.4375999
  let y = 0
  addBoat()
  console.log('test1');
  timer1 = setInterval(() => {
    if (!showBoatPosition(0, 13, i, 30.5252794, y += 2, 0, true, 0.1,)) {
      clearInterval(timer1)
    }
    i -= 0.00002
  }, 500)
}
function test2() {
  let i = 114.4375999
  let y = 0
  addBoat()
  console.log('test2');
  timer2 = setInterval(() => {
    if (!showBoatPosition(1, 13, i, 30.5252794, y -= 2, 0, false, 0.1)) {
      clearInterval(timer2)
    }
    i += 0.00002
  }, 500)
}

let clicks = 0
function test3() {
  if (clicks >= boatPointsArray.length) {
    clearTrackAll()
    clearInterval(timer1)
    clearInterval(timer2)
  } else {
    clearTrack(clicks++)
  }
}

function test4(id) {
  switchTrack(id)
}

function test5() {
  const dt = 20;
  const vv = 0.9063728 * 0.5144;
  const course = 2.49905759162304;
  const course_degree = 180 * course / Math.PI
  const r = -0.0387085514834206;
  let psi = 2.40523560209424
  let x = -110.355637
  let y = 105.503448
  let { lon, lat } = XYZtoBLH(x, y)
  map.centerAndZoom(new BMap.Point(lon, lat), 18); // 设置地图中心点
  if (!showBoatPosition(2, vv, lon, lat, course_degree, 0, true, 0.1)) {
    clearInterval(timer5)
  }
  showBoatPrediction(
    lon,
    lat,
    psi,
    vv * Math.cos(course - psi),
    vv * Math.sin(course - psi),
    r,
    0,
    1000,
    false,
    dt,
    2,
    5
  )
}
function test6() {
  const dt = 0.1;
  const vv = 0.1291144 * 0.5144;
  const course = 5.62731239092496
  const course_degree = 180 * course / Math.PI
  const r = 0.0303664921465969
  let psi = 0.143630017452007
  let x = 8.56009
  let y = -2.005358
  let { lon, lat } = XYZtoBLH(x, y)
  map.centerAndZoom(new BMap.Point(lon, lat), 18); // 设置地图中心点
  if (!showBoatPosition(2, vv, lon, lat, course_degree, 0, true, 0.1)) {
    clearInterval(timer5)
  }
  showBoatPrediction(
    lon,
    lat,
    psi,
    vv * Math.cos(course - psi),
    vv * Math.sin(course - psi),
    r,
    -0.785340314136126,
    1300,
    true,
    dt,
    2,
    100
  )
}