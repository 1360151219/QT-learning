#pragma once
// MESSAGE MOTION_INFO PACKING

#define MAVLINK_MSG_ID_MOTION_INFO 21

MAVPACKED(
typedef struct __mavlink_motion_info_t {
 double lng; /*< */
 double lat; /*< */
 float depth; /*< */
 float height; /*< */
 float roll; /*< */
 float pitch; /*< */
 float yaw; /*< */
 float course; /*< */
 float vel; /*< */
 float p; /*< */
 float q; /*< */
 float r; /*< */
}) mavlink_motion_info_t;

#define MAVLINK_MSG_ID_MOTION_INFO_LEN 56
#define MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN 56
#define MAVLINK_MSG_ID_21_LEN 56
#define MAVLINK_MSG_ID_21_MIN_LEN 56

#define MAVLINK_MSG_ID_MOTION_INFO_CRC 224
#define MAVLINK_MSG_ID_21_CRC 224



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTION_INFO { \
	21, \
	"MOTION_INFO", \
	12, \
	{  { "lng", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_motion_info_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_motion_info_t, lat) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motion_info_t, depth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motion_info_t, height) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motion_info_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motion_info_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_motion_info_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_motion_info_t, course) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_motion_info_t, vel) }, \
         { "p", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_motion_info_t, p) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_motion_info_t, q) }, \
         { "r", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_motion_info_t, r) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTION_INFO { \
	"MOTION_INFO", \
	12, \
	{  { "lng", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_motion_info_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_motion_info_t, lat) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motion_info_t, depth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motion_info_t, height) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motion_info_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motion_info_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_motion_info_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_motion_info_t, course) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_motion_info_t, vel) }, \
         { "p", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_motion_info_t, p) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_motion_info_t, q) }, \
         { "r", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_motion_info_t, r) }, \
         } \
}
#endif

/**
 * @brief Pack a motion_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lng 
 * @param lat 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 * @param p 
 * @param q 
 * @param r 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motion_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       double lng, double lat, float depth, float height, float roll, float pitch, float yaw, float course, float vel, float p, float q, float r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTION_INFO_LEN];
	_mav_put_double(buf, 0, lng);
	_mav_put_double(buf, 8, lat);
	_mav_put_float(buf, 16, depth);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, vel);
	_mav_put_float(buf, 44, p);
	_mav_put_float(buf, 48, q);
	_mav_put_float(buf, 52, r);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTION_INFO_LEN);
#else
	mavlink_motion_info_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.course = course;
	packet.vel = vel;
	packet.p = p;
	packet.q = q;
	packet.r = r;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTION_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTION_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
}

/**
 * @brief Pack a motion_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lng 
 * @param lat 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 * @param p 
 * @param q 
 * @param r 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motion_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           double lng,double lat,float depth,float height,float roll,float pitch,float yaw,float course,float vel,float p,float q,float r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTION_INFO_LEN];
	_mav_put_double(buf, 0, lng);
	_mav_put_double(buf, 8, lat);
	_mav_put_float(buf, 16, depth);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, vel);
	_mav_put_float(buf, 44, p);
	_mav_put_float(buf, 48, q);
	_mav_put_float(buf, 52, r);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTION_INFO_LEN);
#else
	mavlink_motion_info_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.course = course;
	packet.vel = vel;
	packet.p = p;
	packet.q = q;
	packet.r = r;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTION_INFO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTION_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
}

/**
 * @brief Encode a motion_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motion_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motion_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motion_info_t* motion_info)
{
	return mavlink_msg_motion_info_pack(system_id, component_id, msg, motion_info->lng, motion_info->lat, motion_info->depth, motion_info->height, motion_info->roll, motion_info->pitch, motion_info->yaw, motion_info->course, motion_info->vel, motion_info->p, motion_info->q, motion_info->r);
}

/**
 * @brief Encode a motion_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motion_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motion_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motion_info_t* motion_info)
{
	return mavlink_msg_motion_info_pack_chan(system_id, component_id, chan, msg, motion_info->lng, motion_info->lat, motion_info->depth, motion_info->height, motion_info->roll, motion_info->pitch, motion_info->yaw, motion_info->course, motion_info->vel, motion_info->p, motion_info->q, motion_info->r);
}

/**
 * @brief Send a motion_info message
 * @param chan MAVLink channel to send the message
 *
 * @param lng 
 * @param lat 
 * @param depth 
 * @param height 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param course 
 * @param vel 
 * @param p 
 * @param q 
 * @param r 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motion_info_send(mavlink_channel_t chan, double lng, double lat, float depth, float height, float roll, float pitch, float yaw, float course, float vel, float p, float q, float r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MOTION_INFO_LEN];
	_mav_put_double(buf, 0, lng);
	_mav_put_double(buf, 8, lat);
	_mav_put_float(buf, 16, depth);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, vel);
	_mav_put_float(buf, 44, p);
	_mav_put_float(buf, 48, q);
	_mav_put_float(buf, 52, r);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_INFO, buf, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
#else
	mavlink_motion_info_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.depth = depth;
	packet.height = height;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.course = course;
	packet.vel = vel;
	packet.p = p;
	packet.q = q;
	packet.r = r;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_INFO, (const char *)&packet, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
#endif
}

/**
 * @brief Send a motion_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motion_info_send_struct(mavlink_channel_t chan, const mavlink_motion_info_t* motion_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motion_info_send(chan, motion_info->lng, motion_info->lat, motion_info->depth, motion_info->height, motion_info->roll, motion_info->pitch, motion_info->yaw, motion_info->course, motion_info->vel, motion_info->p, motion_info->q, motion_info->r);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_INFO, (const char *)motion_info, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTION_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motion_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  double lng, double lat, float depth, float height, float roll, float pitch, float yaw, float course, float vel, float p, float q, float r)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_double(buf, 0, lng);
	_mav_put_double(buf, 8, lat);
	_mav_put_float(buf, 16, depth);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, roll);
	_mav_put_float(buf, 28, pitch);
	_mav_put_float(buf, 32, yaw);
	_mav_put_float(buf, 36, course);
	_mav_put_float(buf, 40, vel);
	_mav_put_float(buf, 44, p);
	_mav_put_float(buf, 48, q);
	_mav_put_float(buf, 52, r);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_INFO, buf, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
#else
	mavlink_motion_info_t *packet = (mavlink_motion_info_t *)msgbuf;
	packet->lng = lng;
	packet->lat = lat;
	packet->depth = depth;
	packet->height = height;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->course = course;
	packet->vel = vel;
	packet->p = p;
	packet->q = q;
	packet->r = r;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_INFO, (const char *)packet, MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTION_INFO_LEN, MAVLINK_MSG_ID_MOTION_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTION_INFO UNPACKING


/**
 * @brief Get field lng from motion_info message
 *
 * @return 
 */
static inline double mavlink_msg_motion_info_get_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field lat from motion_info message
 *
 * @return 
 */
static inline double mavlink_msg_motion_info_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field depth from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_depth(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field height from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_height(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field roll from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pitch from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yaw from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field course from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field vel from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field p from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_p(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field q from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_q(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field r from motion_info message
 *
 * @return 
 */
static inline float mavlink_msg_motion_info_get_r(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Decode a motion_info message into a struct
 *
 * @param msg The message to decode
 * @param motion_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_motion_info_decode(const mavlink_message_t* msg, mavlink_motion_info_t* motion_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	motion_info->lng = mavlink_msg_motion_info_get_lng(msg);
	motion_info->lat = mavlink_msg_motion_info_get_lat(msg);
	motion_info->depth = mavlink_msg_motion_info_get_depth(msg);
	motion_info->height = mavlink_msg_motion_info_get_height(msg);
	motion_info->roll = mavlink_msg_motion_info_get_roll(msg);
	motion_info->pitch = mavlink_msg_motion_info_get_pitch(msg);
	motion_info->yaw = mavlink_msg_motion_info_get_yaw(msg);
	motion_info->course = mavlink_msg_motion_info_get_course(msg);
	motion_info->vel = mavlink_msg_motion_info_get_vel(msg);
	motion_info->p = mavlink_msg_motion_info_get_p(msg);
	motion_info->q = mavlink_msg_motion_info_get_q(msg);
	motion_info->r = mavlink_msg_motion_info_get_r(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTION_INFO_LEN? msg->len : MAVLINK_MSG_ID_MOTION_INFO_LEN;
        memset(motion_info, 0, MAVLINK_MSG_ID_MOTION_INFO_LEN);
	memcpy(motion_info, _MAV_PAYLOAD(msg), len);
#endif
}
