#pragma once
// MESSAGE AUV_FIELD_STATUS PACKING

#define MAVLINK_MSG_ID_AUV_FIELD_STATUS 1

MAVPACKED(
typedef struct __mavlink_auv_field_status_t {
 int32_t lat; /*< */
 int32_t lon; /*< */
 float x; /*< */
 float y; /*< */
 float yaw; /*< */
 float course; /*< */
 int16_t depth; /*< */
 int16_t height; /*< */
 int16_t roll; /*< */
 int16_t pitch; /*< */
 int16_t vel; /*< */
}) mavlink_auv_field_status_t;

#define MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN 34
#define MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN 34
#define MAVLINK_MSG_ID_1_LEN 34
#define MAVLINK_MSG_ID_1_MIN_LEN 34

#define MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC 133
#define MAVLINK_MSG_ID_1_CRC 133



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_FIELD_STATUS { \
	1, \
	"AUV_FIELD_STATUS", \
	11, \
	{  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_auv_field_status_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_auv_field_status_t, lon) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_field_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_field_status_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_field_status_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_field_status_t, course) }, \
         { "depth", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_auv_field_status_t, depth) }, \
         { "height", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_auv_field_status_t, height) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_auv_field_status_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_auv_field_status_t, pitch) }, \
         { "vel", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_auv_field_status_t, vel) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_FIELD_STATUS { \
	"AUV_FIELD_STATUS", \
	11, \
	{  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_auv_field_status_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_auv_field_status_t, lon) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_field_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_field_status_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_field_status_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_field_status_t, course) }, \
         { "depth", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_auv_field_status_t, depth) }, \
         { "height", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_auv_field_status_t, height) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_auv_field_status_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_auv_field_status_t, pitch) }, \
         { "vel", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_auv_field_status_t, vel) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_field_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat 
 * @param lon 
 * @param x 
 * @param y 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_field_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t lat, int32_t lon, float x, float y, int16_t depth, int16_t height, int16_t roll, int16_t pitch, float yaw, float course, int16_t vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, course);
	_mav_put_int16_t(buf, 24, depth);
	_mav_put_int16_t(buf, 26, height);
	_mav_put_int16_t(buf, 28, roll);
	_mav_put_int16_t(buf, 30, pitch);
	_mav_put_int16_t(buf, 32, vel);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN);
#else
	mavlink_auv_field_status_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.course = course;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.vel = vel;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUV_FIELD_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
}

/**
 * @brief Pack a auv_field_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat 
 * @param lon 
 * @param x 
 * @param y 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_field_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t lat,int32_t lon,float x,float y,int16_t depth,int16_t height,int16_t roll,int16_t pitch,float yaw,float course,int16_t vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, course);
	_mav_put_int16_t(buf, 24, depth);
	_mav_put_int16_t(buf, 26, height);
	_mav_put_int16_t(buf, 28, roll);
	_mav_put_int16_t(buf, 30, pitch);
	_mav_put_int16_t(buf, 32, vel);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN);
#else
	mavlink_auv_field_status_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.course = course;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.vel = vel;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUV_FIELD_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
}

/**
 * @brief Encode a auv_field_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_field_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_field_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_field_status_t* auv_field_status)
{
	return mavlink_msg_auv_field_status_pack(system_id, component_id, msg, auv_field_status->lat, auv_field_status->lon, auv_field_status->x, auv_field_status->y, auv_field_status->depth, auv_field_status->height, auv_field_status->roll, auv_field_status->pitch, auv_field_status->yaw, auv_field_status->course, auv_field_status->vel);
}

/**
 * @brief Encode a auv_field_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_field_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_field_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_field_status_t* auv_field_status)
{
	return mavlink_msg_auv_field_status_pack_chan(system_id, component_id, chan, msg, auv_field_status->lat, auv_field_status->lon, auv_field_status->x, auv_field_status->y, auv_field_status->depth, auv_field_status->height, auv_field_status->roll, auv_field_status->pitch, auv_field_status->yaw, auv_field_status->course, auv_field_status->vel);
}

/**
 * @brief Send a auv_field_status message
 * @param chan MAVLink channel to send the message
 *
 * @param lat 
 * @param lon 
 * @param x 
 * @param y 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_field_status_send(mavlink_channel_t chan, int32_t lat, int32_t lon, float x, float y, int16_t depth, int16_t height, int16_t roll, int16_t pitch, float yaw, float course, int16_t vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, course);
	_mav_put_int16_t(buf, 24, depth);
	_mav_put_int16_t(buf, 26, height);
	_mav_put_int16_t(buf, 28, roll);
	_mav_put_int16_t(buf, 30, pitch);
	_mav_put_int16_t(buf, 32, vel);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS, buf, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
#else
	mavlink_auv_field_status_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.course = course;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.vel = vel;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS, (const char *)&packet, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
#endif
}

/**
 * @brief Send a auv_field_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_field_status_send_struct(mavlink_channel_t chan, const mavlink_auv_field_status_t* auv_field_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_field_status_send(chan, auv_field_status->lat, auv_field_status->lon, auv_field_status->x, auv_field_status->y, auv_field_status->depth, auv_field_status->height, auv_field_status->roll, auv_field_status->pitch, auv_field_status->yaw, auv_field_status->course, auv_field_status->vel);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS, (const char *)auv_field_status, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_field_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lat, int32_t lon, float x, float y, int16_t depth, int16_t height, int16_t roll, int16_t pitch, float yaw, float course, int16_t vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, course);
	_mav_put_int16_t(buf, 24, depth);
	_mav_put_int16_t(buf, 26, height);
	_mav_put_int16_t(buf, 28, roll);
	_mav_put_int16_t(buf, 30, pitch);
	_mav_put_int16_t(buf, 32, vel);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS, buf, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
#else
	mavlink_auv_field_status_t *packet = (mavlink_auv_field_status_t *)msgbuf;
	packet->lat = lat;
	packet->lon = lon;
	packet->x = x;
	packet->y = y;
	packet->yaw = yaw;
	packet->course = course;
	packet->depth = depth;
	packet->height = height;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->vel = vel;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_FIELD_STATUS, (const char *)packet, MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN, MAVLINK_MSG_ID_AUV_FIELD_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_FIELD_STATUS UNPACKING


/**
 * @brief Get field lat from auv_field_status message
 *
 * @return 
 */
static inline int32_t mavlink_msg_auv_field_status_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lon from auv_field_status message
 *
 * @return 
 */
static inline int32_t mavlink_msg_auv_field_status_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field x from auv_field_status message
 *
 * @return 
 */
static inline float mavlink_msg_auv_field_status_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from auv_field_status message
 *
 * @return 
 */
static inline float mavlink_msg_auv_field_status_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field depth from auv_field_status message
 *
 * @return 
 */
static inline int16_t mavlink_msg_auv_field_status_get_depth(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field height from auv_field_status message
 *
 * @return 
 */
static inline int16_t mavlink_msg_auv_field_status_get_height(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field roll from auv_field_status message
 *
 * @return 
 */
static inline int16_t mavlink_msg_auv_field_status_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field pitch from auv_field_status message
 *
 * @return 
 */
static inline int16_t mavlink_msg_auv_field_status_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field yaw from auv_field_status message
 *
 * @return 
 */
static inline float mavlink_msg_auv_field_status_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field course from auv_field_status message
 *
 * @return 
 */
static inline float mavlink_msg_auv_field_status_get_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field vel from auv_field_status message
 *
 * @return 
 */
static inline int16_t mavlink_msg_auv_field_status_get_vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Decode a auv_field_status message into a struct
 *
 * @param msg The message to decode
 * @param auv_field_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_field_status_decode(const mavlink_message_t* msg, mavlink_auv_field_status_t* auv_field_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	auv_field_status->lat = mavlink_msg_auv_field_status_get_lat(msg);
	auv_field_status->lon = mavlink_msg_auv_field_status_get_lon(msg);
	auv_field_status->x = mavlink_msg_auv_field_status_get_x(msg);
	auv_field_status->y = mavlink_msg_auv_field_status_get_y(msg);
	auv_field_status->yaw = mavlink_msg_auv_field_status_get_yaw(msg);
	auv_field_status->course = mavlink_msg_auv_field_status_get_course(msg);
	auv_field_status->depth = mavlink_msg_auv_field_status_get_depth(msg);
	auv_field_status->height = mavlink_msg_auv_field_status_get_height(msg);
	auv_field_status->roll = mavlink_msg_auv_field_status_get_roll(msg);
	auv_field_status->pitch = mavlink_msg_auv_field_status_get_pitch(msg);
	auv_field_status->vel = mavlink_msg_auv_field_status_get_vel(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN? msg->len : MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN;
        memset(auv_field_status, 0, MAVLINK_MSG_ID_AUV_FIELD_STATUS_LEN);
	memcpy(auv_field_status, _MAV_PAYLOAD(msg), len);
#endif
}
