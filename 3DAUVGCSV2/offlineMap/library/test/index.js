let timer1, timer2;
function test1() {
  let i = 114.4375999
  let y = 0
  addBoat()
  console.log('test1');
  timer1 = setInterval(() => {
    if (!showBoatPosition(0, i, 30.5252794, y += 2, 0, 0.1)) {
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
    if (!showBoatPosition(1, i, 30.5252794, y -= 2, 0, 0.1)) {
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
  let t = 0.01;
  const dt = 0.01;
  const v = 0.0987648 * 0.5144;
  const course = 0.536457242582897;
  const r = 0.00261780104712042
  let psi = 1.19249563699825
  let x = 15.76954
  let y = 26.169334
  setInterval(() => {
    const res = getPrediction({
      x,
      y,
      psi,
      u: v * Math.cos(course - psi),
      v: v * Math.sin(course - psi),
      r,
      angle:0,
      PWM:1000,
      isDynamic:false,
      t,
      dt
    })
    console.log(res);
    x = res.x
    y = res.y
    psi = res.psi
    t = t+res.dt
  }, 1000)
}