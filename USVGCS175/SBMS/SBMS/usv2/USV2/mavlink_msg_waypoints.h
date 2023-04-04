#pragma once
// MESSAGE WAYPOINTS PACKING

#define MAVLINK_MSG_ID_WAYPOINTS 152

MAVPACKED(
typedef struct __mavlink_waypoints_t {
 uint32_t lng; /*< Lng of the waypoint*/
 uint32_t lat; /*< Lat of the waypoint*/
 uint8_t id; /*< Index of the waypoint*/
}) mavlink_waypoints_t;

#define MAVLINK_MSG_ID_WAYPOINTS_LEN 9
#define MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN 9
#define MAVLINK_MSG_ID_152_LEN 9
#define MAVLINK_MSG_ID_152_MIN_LEN 9

#define MAVLINK_MSG_ID_WAYPOINTS_CRC 80
#define MAVLINK_MSG_ID_152_CRC 80



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WAYPOINTS { \
	152, \
	"WAYPOINTS", \
	3, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_waypoints_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_waypoints_t, lat) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_waypoints_t, id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WAYPOINTS { \
	"WAYPOINTS", \
	3, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_waypoints_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_waypoints_t, lat) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_waypoints_t, id) }, \
         } \
}
#endif

/**
 * @brief Pack a waypoints message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Index of the waypoint
 * @param lng Lng of the waypoint
 * @param lat Lat of the waypoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoints_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t id, uint32_t lng, uint32_t lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINTS_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_uint8_t(buf, 8, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINTS_LEN);
#else
	mavlink_waypoints_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINTS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINTS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
}

/**
 * @brief Pack a waypoints message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id Index of the waypoint
 * @param lng Lng of the waypoint
 * @param lat Lat of the waypoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoints_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t id,uint32_t lng,uint32_t lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINTS_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_uint8_t(buf, 8, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WAYPOINTS_LEN);
#else
	mavlink_waypoints_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WAYPOINTS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WAYPOINTS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
}

/**
 * @brief Encode a waypoints struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param waypoints C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoints_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoints_t* waypoints)
{
	return mavlink_msg_waypoints_pack(system_id, component_id, msg, waypoints->id, waypoints->lng, waypoints->lat);
}

/**
 * @brief Encode a waypoints struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param waypoints C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_waypoints_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_waypoints_t* waypoints)
{
	return mavlink_msg_waypoints_pack_chan(system_id, component_id, chan, msg, waypoints->id, waypoints->lng, waypoints->lat);
}

/**
 * @brief Send a waypoints message
 * @param chan MAVLink channel to send the message
 *
 * @param id Index of the waypoint
 * @param lng Lng of the waypoint
 * @param lat Lat of the waypoint
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_waypoints_send(mavlink_channel_t chan, uint8_t id, uint32_t lng, uint32_t lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WAYPOINTS_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_uint8_t(buf, 8, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINTS, buf, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
#else
	mavlink_waypoints_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINTS, (const char *)&packet, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
#endif
}

/**
 * @brief Send a waypoints message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_waypoints_send_struct(mavlink_channel_t chan, const mavlink_waypoints_t* waypoints)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_waypoints_send(chan, waypoints->id, waypoints->lng, waypoints->lat);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINTS, (const char *)waypoints, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WAYPOINTS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_waypoints_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, uint32_t lng, uint32_t lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_uint8_t(buf, 8, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINTS, buf, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
#else
	mavlink_waypoints_t *packet = (mavlink_waypoints_t *)msgbuf;
	packet->lng = lng;
	packet->lat = lat;
	packet->id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WAYPOINTS, (const char *)packet, MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_WAYPOINTS_LEN, MAVLINK_MSG_ID_WAYPOINTS_CRC);
#endif
}
#endif

#endif

// MESSAGE WAYPOINTS UNPACKING


/**
 * @brief Get field id from waypoints message
 *
 * @return Index of the waypoint
 */
static inline uint8_t mavlink_msg_waypoints_get_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field lng from waypoints message
 *
 * @return Lng of the waypoint
 */
static inline uint32_t mavlink_msg_waypoints_get_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from waypoints message
 *
 * @return Lat of the waypoint
 */
static inline uint32_t mavlink_msg_waypoints_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a waypoints message into a struct
 *
 * @param msg The message to decode
 * @param waypoints C-struct to decode the message contents into
 */
static inline void mavlink_msg_waypoints_decode(const mavlink_message_t* msg, mavlink_waypoints_t* waypoints)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	waypoints->lng = mavlink_msg_waypoints_get_lng(msg);
	waypoints->lat = mavlink_msg_waypoints_get_lat(msg);
	waypoints->id = mavlink_msg_waypoints_get_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WAYPOINTS_LEN? msg->len : MAVLINK_MSG_ID_WAYPOINTS_LEN;
        memset(waypoints, 0, MAVLINK_MSG_ID_WAYPOINTS_LEN);
	memcpy(waypoints, _MAV_PAYLOAD(msg), len);
#endif
}
