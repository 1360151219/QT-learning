#pragma once
// MESSAGE NEUPOINT_WITH_COURSE_FOLLOW PACKING

#define MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW 155

MAVPACKED(
typedef struct __mavlink_neupoint_with_course_follow_t {
 uint32_t longi_point; /*< */
 uint32_t lati_point; /*< */
 float point_course; /*< */
}) mavlink_neupoint_with_course_follow_t;

#define MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN 12
#define MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN 12
#define MAVLINK_MSG_ID_155_LEN 12
#define MAVLINK_MSG_ID_155_MIN_LEN 12

#define MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC 65
#define MAVLINK_MSG_ID_155_CRC 65



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NEUPOINT_WITH_COURSE_FOLLOW { \
	155, \
	"NEUPOINT_WITH_COURSE_FOLLOW", \
	3, \
	{  { "longi_point", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_neupoint_with_course_follow_t, longi_point) }, \
         { "lati_point", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_neupoint_with_course_follow_t, lati_point) }, \
         { "point_course", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_neupoint_with_course_follow_t, point_course) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NEUPOINT_WITH_COURSE_FOLLOW { \
	"NEUPOINT_WITH_COURSE_FOLLOW", \
	3, \
	{  { "longi_point", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_neupoint_with_course_follow_t, longi_point) }, \
         { "lati_point", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_neupoint_with_course_follow_t, lati_point) }, \
         { "point_course", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_neupoint_with_course_follow_t, point_course) }, \
         } \
}
#endif

/**
 * @brief Pack a neupoint_with_course_follow message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param longi_point 
 * @param lati_point 
 * @param point_course 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_neupoint_with_course_follow_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t longi_point, uint32_t lati_point, float point_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN];
	_mav_put_uint32_t(buf, 0, longi_point);
	_mav_put_uint32_t(buf, 4, lati_point);
	_mav_put_float(buf, 8, point_course);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN);
#else
	mavlink_neupoint_with_course_follow_t packet;
	packet.longi_point = longi_point;
	packet.lati_point = lati_point;
	packet.point_course = point_course;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
}

/**
 * @brief Pack a neupoint_with_course_follow message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param longi_point 
 * @param lati_point 
 * @param point_course 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_neupoint_with_course_follow_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t longi_point,uint32_t lati_point,float point_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN];
	_mav_put_uint32_t(buf, 0, longi_point);
	_mav_put_uint32_t(buf, 4, lati_point);
	_mav_put_float(buf, 8, point_course);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN);
#else
	mavlink_neupoint_with_course_follow_t packet;
	packet.longi_point = longi_point;
	packet.lati_point = lati_point;
	packet.point_course = point_course;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
}

/**
 * @brief Encode a neupoint_with_course_follow struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param neupoint_with_course_follow C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_neupoint_with_course_follow_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_neupoint_with_course_follow_t* neupoint_with_course_follow)
{
	return mavlink_msg_neupoint_with_course_follow_pack(system_id, component_id, msg, neupoint_with_course_follow->longi_point, neupoint_with_course_follow->lati_point, neupoint_with_course_follow->point_course);
}

/**
 * @brief Encode a neupoint_with_course_follow struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param neupoint_with_course_follow C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_neupoint_with_course_follow_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_neupoint_with_course_follow_t* neupoint_with_course_follow)
{
	return mavlink_msg_neupoint_with_course_follow_pack_chan(system_id, component_id, chan, msg, neupoint_with_course_follow->longi_point, neupoint_with_course_follow->lati_point, neupoint_with_course_follow->point_course);
}

/**
 * @brief Send a neupoint_with_course_follow message
 * @param chan MAVLink channel to send the message
 *
 * @param longi_point 
 * @param lati_point 
 * @param point_course 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_neupoint_with_course_follow_send(mavlink_channel_t chan, uint32_t longi_point, uint32_t lati_point, float point_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN];
	_mav_put_uint32_t(buf, 0, longi_point);
	_mav_put_uint32_t(buf, 4, lati_point);
	_mav_put_float(buf, 8, point_course);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW, buf, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
#else
	mavlink_neupoint_with_course_follow_t packet;
	packet.longi_point = longi_point;
	packet.lati_point = lati_point;
	packet.point_course = point_course;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW, (const char *)&packet, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
#endif
}

/**
 * @brief Send a neupoint_with_course_follow message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_neupoint_with_course_follow_send_struct(mavlink_channel_t chan, const mavlink_neupoint_with_course_follow_t* neupoint_with_course_follow)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_neupoint_with_course_follow_send(chan, neupoint_with_course_follow->longi_point, neupoint_with_course_follow->lati_point, neupoint_with_course_follow->point_course);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW, (const char *)neupoint_with_course_follow, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
#endif
}

#if MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_neupoint_with_course_follow_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t longi_point, uint32_t lati_point, float point_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, longi_point);
	_mav_put_uint32_t(buf, 4, lati_point);
	_mav_put_float(buf, 8, point_course);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW, buf, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
#else
	mavlink_neupoint_with_course_follow_t *packet = (mavlink_neupoint_with_course_follow_t *)msgbuf;
	packet->longi_point = longi_point;
	packet->lati_point = lati_point;
	packet->point_course = point_course;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW, (const char *)packet, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_CRC);
#endif
}
#endif

#endif

// MESSAGE NEUPOINT_WITH_COURSE_FOLLOW UNPACKING


/**
 * @brief Get field longi_point from neupoint_with_course_follow message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_neupoint_with_course_follow_get_longi_point(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lati_point from neupoint_with_course_follow message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_neupoint_with_course_follow_get_lati_point(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field point_course from neupoint_with_course_follow message
 *
 * @return 
 */
static inline float mavlink_msg_neupoint_with_course_follow_get_point_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a neupoint_with_course_follow message into a struct
 *
 * @param msg The message to decode
 * @param neupoint_with_course_follow C-struct to decode the message contents into
 */
static inline void mavlink_msg_neupoint_with_course_follow_decode(const mavlink_message_t* msg, mavlink_neupoint_with_course_follow_t* neupoint_with_course_follow)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	neupoint_with_course_follow->longi_point = mavlink_msg_neupoint_with_course_follow_get_longi_point(msg);
	neupoint_with_course_follow->lati_point = mavlink_msg_neupoint_with_course_follow_get_lati_point(msg);
	neupoint_with_course_follow->point_course = mavlink_msg_neupoint_with_course_follow_get_point_course(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN? msg->len : MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN;
        memset(neupoint_with_course_follow, 0, MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_LEN);
	memcpy(neupoint_with_course_follow, _MAV_PAYLOAD(msg), len);
#endif
}
