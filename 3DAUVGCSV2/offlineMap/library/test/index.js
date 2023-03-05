function test1(){
  let i = 114.4375999
    let y = 0
    console.log('test');
    setInterval(() => {
        showBoatPosition(0, i, 30.5252794, y += 2, 0)
        i -= 0.00002
    }, 500)
}