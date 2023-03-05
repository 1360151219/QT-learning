/**
 * 展示船舶位置
 * @param {*} lng 经度
 * @param {*} lat 纬度
 * @param {*} course 角度
 * @param {0} depth 深度
 */
function showBoatPosition(id, lng, lat, course, depth) {
  var currentPosition = wgs84tobd09(lng, lat);
  var currentPoint = new BMap.Point(currentPosition[0], currentPosition[1]);
  const boatIcon = boatIconArray[id]
  const boatLabel = boatLabelArray[id]
  const boatMarker = boatMarkerArray[id]
  if (!boatIcon || !boatLabel || !boatMarker) {
    alert(`id为${id}的艇不存在`)
    return
  }
  boatIcon.setRotation(course);
  boatLabel.setContent(depth.toFixed(2) + "mD");
  boatMarker.setIcon(boatIcon);
  boatMarker.setLabel(boatLabel);
  boatMarker.setPosition(currentPoint);
  map.addOverlay(boatMarker);
  boatPoints.push(currentPoint);
  boatTrackPolyline.setPath(boatPoints);
  if (boatPoints.length == 1) {
    // 添加轨迹折线
    map.addOverlay(boatTrackPolyline);
  }
}

// function clearTrack() {
    //     boatPoints = [];
    //     map.removeOverlay(boatTrackPolyline);
    // }
