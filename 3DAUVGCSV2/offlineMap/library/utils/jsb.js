const L = 0.00944 // 175艇的艇长/海里


/**
 * 更新船舶位置
 * 【补充说明】必须先加载对应id的无人艇后才可以使用相应的id
 * @param {number} id 艇id：从0开始
 * @param {number} v 艇速度
 * @param {number} lng 经度
 * @param {number} lat 纬度
 * @param {number} course 角度
 * @param {number} depth 深度
 * @param {boolean} hasQuaternion 是否显示四元安全领域
 * @param {0-1} quaternionOpacity 四元安全领域透明度
 */
function showBoatPosition(id, v, lng, lat, course, depth, hasQuaternion, quaternionOpacity) {
  var currentPosition = wgs84tobd09(lng, lat);

  // ===== 四元安全领域绘制
  if (hasQuaternion) {
    let polygona = quaternionArray[id]
    const { r_fore, r_aft, r_starb, r_port } = Quaternion(v, L)
    // console.log(r_fore,r_aft,r_port,r_starb);
    const obj = {
      fore: newCoordinate(lng, lat, r_fore, 0), // 从上开始顺时针
      starb: newCoordinate(lng, lat, r_starb, 90),
      aft: newCoordinate(lng, lat, r_aft, 270),
      port: newCoordinate(lng, lat, r_port, 180)
    }
    const x_axis = ((obj.starb[0] - obj.port[0]))
    const y_axis = ((obj.fore[1] - obj.aft[1]))
    map.removeOverlay(polygona)
    let a = ellipse({ lng: currentPosition[0], lat: currentPosition[1] }, x_axis, y_axis);
    polygona = new BMap.Polygon(a, { strokeColor: "black", strokeStyle: 'dashed', strokeWeight: 1, fillOpacity: quaternionOpacity });
    map.addOverlay(polygona);
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
  boatLabel.setContent(depth.toFixed(2) + "mD");
  boatMarker.setIcon(boatIcon);
  boatMarker.setLabel(boatLabel);
  boatMarker.setPosition(currentPoint);
  boatPoints.push(currentPoint);
  boatTrackPolyline.setPath(boatPoints);
  // 只有全部视图或者是当前艇的视图才显示
  if (activeId === id || activeId === -1) {
    map.addOverlay(boatMarker);
    if (boatPoints.length == 1) {
      // 添加轨迹折线
      map.addOverlay(boatTrackPolyline);
    }
  }
  return true
}
/**
 * 显示无人艇的预测航行轨迹
 * @param {*} initialX 横坐标
 * @param {*} initialY 纵坐标
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
  initialX,
  initialY,
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
  let x = initialX;
  let y = initialY;
  let psi = initialPsi;
  let u = initialU;
  let v = initialV;
  let r = initialR;
  const predPoints = predictionPointsArray[id];
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
      t,
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
  }
  predPolyline.setPath(predPoints);
  map.addOverlay(predPolyline);
}

// 切换无人艇
function switchTrack(id) {
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
