let timer1, timer2;
function test1() {
  let i = 114.4375999
  let y = 0
  addBoat()
  console.log('test1');
  timer1 = setInterval(() => {
    if (!showBoatPosition(0, i, 30.5252794, y += 2, 0)) {
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
    if (!showBoatPosition(1, i, 30.5252794, y -= 2, 0)) {
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