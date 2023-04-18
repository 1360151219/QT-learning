const L = 0.00944 // 175艇的艇长/海里

/**
    * 添加无人艇
    * 【补充说明】：只有添加了无人艇，才可以通过id来对艇的位置进行显示或者显示预测轨迹
    */
function addBoat() {
  let boatMarker = new BMap.Marker;
  let boatIcon = new BMap.Symbol(BMap_Symbol_SHAPE_FORWARD_CLOSED_ARROW, { //BMap_Symbol_SHAPE_PLANE
    scale: 1.5,
    strokeWeight: 1,
    fillColor: getRandomColor(boatMarkerArray.length),
    fillOpacity: 0.8
  });
  let boatLabel = new BMap.Label("0mD，0mH", { offset: new BMap.Size(20, -20) });
  let boatPoints = new Array();  //保存艇的轨迹点
  let boatTrackPolyline = new BMap.Polyline([], { strokeColor: getRandomColor(boatMarkerArray.length), strokeWeight: 2, strokeOpacity: 0.5 });
  let predPoints = [];
  let predPolyline = new BMap.Polyline([], { strokeColor: getRandomColor(boatMarkerArray.length), strokeWeight: 1, strokeOpacity: 1, strokeStyle: 'dashed' });
  let quaternion = new BMap.Polygon(a, { strokeColor: "black", strokeStyle: 'dashed', strokeWeight: 1, fillOpacity: 0.1 });
  boatLabel.setStyle({ color: "black", fontSize: "15px" });
  boatIconArray.push(boatIcon)
  boatMarkerArray.push(boatMarker)
  boatLabelArray.push(boatLabel)
  boatPointsArray.push(boatPoints)
  boatTrackPolylineArray.push(boatTrackPolyline)
  // predictionPointsArray.push(predPoints);
  predictionPolylineArray.push(predPolyline);
  quaternionArray.push(quaternion)
}
/**
 * 更新船舶位置
 * 【补充说明】必须先加载对应id的无人艇后才可以使用相应的id
 * @param {number} id 艇id：从0开始
 * @param {number} lng 经度
 * @param {number} lat 纬度
 * @param {number} course 角度
 * @param {number} depth 深度
 * @param {boolean} hasQuaternion 是否显示四元安全领域
 * @param {number} v 艇速度
 * @param {0-1} quaternionOpacity 四元安全领域透明度
 */
function showBoatPosition(id, lng, lat, course, depth, hasQuaternion, v, quaternionOpacity = 0.1) {
  var currentPosition = wgs84tobd09(lng, lat);
  let quaterPolygona = quaternionArray[id]
  // todo 热力图

  // ===== 四元安全领域绘制
  if (hasQuaternion) {
    const { r_fore, r_aft, r_starb, r_port } = Quaternion(v, L)
    const obj = {
      fore: newCoordinate(lng, lat, r_fore, 0), // 从上开始顺时针
      starb: newCoordinate(lng, lat, r_starb, 90),
      aft: newCoordinate(lng, lat, r_aft, 270),
      port: newCoordinate(lng, lat, r_port, 180)
    }
    const x_axis = ((obj.starb[0] - obj.port[0]))
    const y_axis = ((obj.fore[1] - obj.aft[1]))
    map.removeOverlay(quaterPolygona)
    let a = ellipse({ lng: currentPosition[0], lat: currentPosition[1] }, x_axis, y_axis, 180 - course);
    quaterPolygona = new BMap.Polygon(a, { strokeColor: "black", strokeStyle: 'dashed', strokeWeight: 1, fillOpacity: quaternionOpacity });
    quaternionArray[id] = quaterPolygona
  }
  // ===== 无人艇实时轨迹绘制
  const currentPoint = new BMap.Point(currentPosition[0], currentPosition[1]);
  const boatIcon = boatIconArray[id]
  const boatLabel = boatLabelArray[id]
  const boatMarker = boatMarkerArray[id]
  const boatPoints = boatPointsArray[id]
  const boatTrackPolyline = boatTrackPolylineArray[id]
  if (!boatIcon || !boatLabel || !boatMarker || !boatPoints || !boatTrackPolyline) {
    alert(`id为${id}的艇不存在`)
    return false
  }
  boatIcon.setRotation(course);
  boatLabel.setContent(id);
  boatMarker.setIcon(boatIcon);
  boatMarker.setLabel(boatLabel);
  boatMarker.setPosition(currentPoint);
  boatPoints.push(currentPoint);
  boatTrackPolyline.setPath(boatPoints);
  // 只有全部视图或者是当前艇的视图才显示
  if (activeId === id || activeId === -1) {
    map.addOverlay(boatMarker);
    map.addOverlay(quaterPolygona);
    if (boatPoints.length == 1) {
      // 添加轨迹折线
      map.addOverlay(boatTrackPolyline);
    }
  }
  return true
}
/**
 * 显示无人艇的预测航行轨迹
 * @param {*} lng 经度
 * @param {*} lat 纬度
 * @param {*} initialPsi 艏向角
 * @param {*} initialU 横向速度
 * @param {*} initialV 纵向速度
 * @param {*} initialR 角速度
 * @param {*} angle 舵角
 * @param {*} PWM 推进器输入
 * @param {*} isDynamic 是否是动力学预测
 * @param {*} dt 时间预测间隔
 * @param {*} id 无人艇id
 * @param {*} time 预测步数
 * @returns 
 */
function showBoatPrediction(
  lng,
  lat,
  initialPsi,
  initialU,
  initialV,
  initialR,
  angle,
  PWM,
  isDynamic,
  dt,
  id,
  time = 5
) {
  let { x, y } = BLHtoXYZ(lng, lat);
  let psi = initialPsi;
  let u = initialU;
  let v = initialV;
  let r = initialR;
  const predPoints = [];
  const predictionData = [{ x, y, psi: initialPsi, u: initialU, v: initialV, r: initialR }];
  // 初始化：加上原始点
  const initBd09Pos = wgs84tobd09(lng, lat)
  predPoints.push(new BMap.Point(initBd09Pos[0], initBd09Pos[1]))
  const predPolyline = predictionPolylineArray[id];
  if (!predPoints || !predPolyline) {
    alert(`id为${id}的艇不存在`)
    return false
  }
  // 循环5次
  for (let i = 0; i < time; i++) {
    const res = getPrediction({
      x,
      y,
      psi,
      u,
      v,
      r,
      angle,
      PWM,
      isDynamic,
      dt
    })
    // 绘制轨迹
    const wgs84Pos = XYZtoBLH(res.x, res.y)
    const bd09Pos = wgs84tobd09(wgs84Pos.lon, wgs84Pos.lat)
    const currentPoint = new BMap.Point(bd09Pos[0], bd09Pos[1]);
    predPoints.push(currentPoint);
    x = res.x
    y = res.y
    u = res.u
    v = res.v
    psi = res.psi
    r = res.r
    predictionData.push({ x, y, psi, u, v, r })
  }
  predPolyline.setPath(predPoints);
  map.addOverlay(predPolyline);
  window.bridge.sendPredictionData(predictionData)
}

// 切换无人艇
function switchTrack(id) {
  if (id === undefined || id === -1) {
    activeId = -1
    boatTrackPolylineArray.forEach((boatTrackPolyline, index) => {
      map.addOverlay(boatTrackPolyline);
    })
    boatMarkerArray.forEach((boatMarker, index) => {
      map.addOverlay(boatMarker);
    })
    return
  }
  activeId = id
  boatTrackPolylineArray.forEach((boatTrackPolyline, index) => {
    if (id !== index) {
      map.removeOverlay(boatTrackPolyline);
    }
  })
  map.clearOverlays();
  map.addOverlay(boatTrackPolylineArray[id])
  map.addOverlay(boatMarkerArray[id])
}

// 启动热力图
function showHeatOverlayMap() {
  // ===== 热力图显示深度
  map.addOverlay(heatOverlayMap)
  heatOverlayMap.setOptions({
    gradient: {
      1: 'rgb(210, 40, 40)',
      .5: 'rgb(223, 110, 70)',
      .2: 'rgb(228, 149, 70)',
      0: 'rgb(192, 215, 63)',
    }
  })
  heatOverlayMap.setDataSet({ max: 50, data: heatData })
}

function addHeatPoint(lng, lat, count) {
  heatData.push({ lng, lat, count })
}
