let timer1, timer2, timer5;
function test1() {
  let i = 114.42649989999968 // 经度
  let j = 30.5207794 // 纬度
  let y = 0
  // const data = []
  addBoat()
  timer1 = setInterval(() => {
    // const [lng, lat] = wgs84tobd09(i, j);
    // data.push({ lng, lat, count: 10 })
    // heatOverlayMap.setDataSet({ max: 50, data })
    if (!showBoatPosition(0, i, j, y, 0, true, 13)) {
      clearInterval(timer1)
    }
    j += 0.00002
    y += 10
  }, 500)
}
function test2() {
  let i = 114.42629989999968 // 经度
  let j = 30.5207794 // 纬度
  let y = 0
  addBoat()
  timer1 = setInterval(() => {
    if (!showBoatPosition(1, i, j, y, 0, false)) {
      clearInterval(timer1)
    }
    j += 0.00002
  }, 500)
}
function test7() {
  let i = 114.42589989999968 // 经度
  let j = 30.5207794 // 纬度
  let y = 0
  addBoat()
  timer1 = setInterval(() => {
    if (!showBoatPosition(2, i, j, y, 0, false)) {
      clearInterval(timer1)
    }
    j += 0.00002
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
  const dt = 1;
  const vv = 0.9063728 * 0.5144;
  const course = 2.49905759162304;
  const course_degree = 180 * course / Math.PI
  const r = -0.0387085514834206;
  let psi = 2.40523560209424
  let x = -110.355637
  let y = 105.503448
  let { lon, lat } = XYZtoBLH(x, y)
  console.log(lon, lat);
  map.centerAndZoom(new BMap.Point(lon, lat), 18); // 设置地图中心点
  if (!showBoatPosition(2, lon, lat, course_degree, 0, true, vv, 0.1)) {
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
    40
  )
}
function test6() {
  const dt = 20;
  const vv = 0.1291144 * 0.5144;
  const course = 5.62731239092496
  const course_degree = 180 * course / Math.PI
  const r = 0.0303664921465969
  let psi = 0.143630017452007
  let x = 8.56009
  let y = -2.005358
  let { lon, lat } = XYZtoBLH(x, y)
  map.centerAndZoom(new BMap.Point(lon, lat), 18); // 设置地图中心点
  if (!showBoatPosition(2, lon, lat, course_degree, 0, true, vv, 0.1)) {
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