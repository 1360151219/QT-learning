const v = 13 // 13节
const L = 0.00944 // 海里
/**
 * 更新船舶位置
 * @param {*} lng 经度
 * @param {*} lat 纬度
 * @param {*} course 角度
 * @param {0} depth 深度
 */
let polygona;
// todo: 参数的封装
function showBoatPosition(id, lng, lat, course, depth, quaternionOpacity) {
  var currentPosition = wgs84tobd09(lng, lat);

  // ===== 四元安全领域绘制
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
  polygona = new BMap.Polygon(a, { strokeColor: "black", strokeStyle:'dashed', strokeWeight: 1, fillOpacity: quaternionOpacity });
  map.addOverlay(polygona);

  // =====
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

// 清除指定Id无人艇的轨迹
function clearTrack(id) {
  boatPointsArray[id] = []
  map.removeOverlay(boatTrackPolylineArray[id]);
  map.removeOverlay(boatMarkerArray[id])
}
// 清除所有无人艇的轨迹
function clearTrackAll() {
  boatPointsArray = []
  for (let boatTrackPolyline of boatTrackPolylineArray) {
    map.removeOverlay(boatTrackPolyline);
  }
  for (let boatMarker of boatMarkerArray) {
    map.removeOverlay(boatMarker);
  }
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
