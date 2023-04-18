#pragma once
// MESSAGE DOCK_MESSAGE_TRANSFORM PACKING

#define MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM 157

MAVPACKED(
typedef struct __mavlink_dock_message_transform_t {
 uint32_t lng; /*< */
 uint32_t lat; /*< */
 float velocity; /*< */
 float course; /*< */
 float roll; /*< */
 float pitch; /*< */
 float yaw; /*< */
 uint32_t status; /*< */
}) mavlink_dock_message_transform_t;

#define MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN 32
#define MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN 32
#define MAVLINK_MSG_ID_157_LEN 32
#define MAVLINK_MSG_ID_157_MIN_LEN 32

#define MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC 88
#define MAVLINK_MSG_ID_157_CRC 88



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DOCK_MESSAGE_TRANSFORM { \
	157, \
	"DOCK_MESSAGE_TRANSFORM", \
	8, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dock_message_transform_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dock_message_transform_t, lat) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dock_message_transform_t, velocity) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dock_message_transform_t, course) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dock_message_transform_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dock_message_transform_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dock_message_transform_t, yaw) }, \
         { "status", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_dock_message_transform_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DOCK_MESSAGE_TRANSFORM { \
	"DOCK_MESSAGE_TRANSFORM", \
	8, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dock_message_transform_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dock_message_transform_t, lat) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_dock_message_transform_t, velocity) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dock_message_transform_t, course) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dock_message_transform_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dock_message_transform_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dock_message_transform_t, yaw) }, \
         { "status", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_dock_message_transform_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a dock_message_transform message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lng 
 * @param lat 
 * @param velocity 
 * @param course 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param status 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dock_message_transform_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t lng, uint32_t lat, float velocity, float course, float roll, float pitch, float yaw, uint32_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, velocity);
	_mav_put_float(buf, 12, course);
	_mav_put_float(buf, 16, roll);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint32_t(buf, 28, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN);
#else
	mavlink_dock_message_transform_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.velocity = velocity;
	packet.course = course;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
}

/**
 * @brief Pack a dock_message_transform message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lng 
 * @param lat 
 * @param velocity 
 * @param course 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param status 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dock_message_transform_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t lng,uint32_t lat,float velocity,float course,float roll,float pitch,float yaw,uint32_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, velocity);
	_mav_put_float(buf, 12, course);
	_mav_put_float(buf, 16, roll);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint32_t(buf, 28, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN);
#else
	mavlink_dock_message_transform_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.velocity = velocity;
	packet.course = course;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
}

/**
 * @brief Encode a dock_message_transform struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dock_message_transform C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dock_message_transform_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dock_message_transform_t* dock_message_transform)
{
	return mavlink_msg_dock_message_transform_pack(system_id, component_id, msg, dock_message_transform->lng, dock_message_transform->lat, dock_message_transform->velocity, dock_message_transform->course, dock_message_transform->roll, dock_message_transform->pitch, dock_message_transform->yaw, dock_message_transform->status);
}

/**
 * @brief Encode a dock_message_transform struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dock_message_transform C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dock_message_transform_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dock_message_transform_t* dock_message_transform)
{
	return mavlink_msg_dock_message_transform_pack_chan(system_id, component_id, chan, msg, dock_message_transform->lng, dock_message_transform->lat, dock_message_transform->velocity, dock_message_transform->course, dock_message_transform->roll, dock_message_transform->pitch, dock_message_transform->yaw, dock_message_transform->status);
}

/**
 * @brief Send a dock_message_transform message
 * @param chan MAVLink channel to send the message
 *
 * @param lng 
 * @param lat 
 * @param velocity 
 * @param course 
 * @param roll 
 * @param pitch 
 * @param yaw 
 * @param status 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dock_message_transform_send(mavlink_channel_t chan, uint32_t lng, uint32_t lat, float velocity, float course, float roll, float pitch, float yaw, uint32_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, velocity);
	_mav_put_float(buf, 12, course);
	_mav_put_float(buf, 16, roll);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint32_t(buf, 28, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM, buf, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
#else
	mavlink_dock_message_transform_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.velocity = velocity;
	packet.course = course;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM, (const char *)&packet, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
#endif
}

/**
 * @brief Send a dock_message_transform message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dock_message_transform_send_struct(mavlink_channel_t chan, const mavlink_dock_message_transform_t* dock_message_transform)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dock_message_transform_send(chan, dock_message_transform->lng, dock_message_transform->lat, dock_message_transform->velocity, dock_message_transform->course, dock_message_transform->roll, dock_message_transform->pitch, dock_message_transform->yaw, dock_message_transform->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM, (const char *)dock_message_transform, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
#endif
}

#if MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dock_message_transform_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t lng, uint32_t lat, float velocity, float course, float roll, float pitch, float yaw, uint32_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, velocity);
	_mav_put_float(buf, 12, course);
	_mav_put_float(buf, 16, roll);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, yaw);
	_mav_put_uint32_t(buf, 28, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM, buf, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
#else
	mavlink_dock_message_transform_t *packet = (mavlink_dock_message_transform_t *)msgbuf;
	packet->lng = lng;
	packet->lat = lat;
	packet->velocity = velocity;
	packet->course = course;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM, (const char *)packet, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_CRC);
#endif
}
#endif

#endif

// MESSAGE DOCK_MESSAGE_TRANSFORM UNPACKING


/**
 * @brief Get field lng from dock_message_transform message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_dock_message_transform_get_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from dock_message_transform message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_dock_message_transform_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field velocity from dock_message_transform message
 *
 * @return 
 */
static inline float mavlink_msg_dock_message_transform_get_velocity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field course from dock_message_transform message
 *
 * @return 
 */
static inline float mavlink_msg_dock_message_transform_get_course(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll from dock_message_transform message
 *
 * @return 
 */
static inline float mavlink_msg_dock_message_transform_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch from dock_message_transform message
 *
 * @return 
 */
static inline float mavlink_msg_dock_message_transform_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yaw from dock_message_transform message
 *
 * @return 
 */
static inline float mavlink_msg_dock_message_transform_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field status from dock_message_transform message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_dock_message_transform_get_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Decode a dock_message_transform message into a struct
 *
 * @param msg The message to decode
 * @param dock_message_transform C-struct to decode the message contents into
 */
static inline void mavlink_msg_dock_message_transform_decode(const mavlink_message_t* msg, mavlink_dock_message_transform_t* dock_message_transform)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	dock_message_transform->lng = mavlink_msg_dock_message_transform_get_lng(msg);
	dock_message_transform->lat = mavlink_msg_dock_message_transform_get_lat(msg);
	dock_message_transform->velocity = mavlink_msg_dock_message_transform_get_velocity(msg);
	dock_message_transform->course = mavlink_msg_dock_message_transform_get_course(msg);
	dock_message_transform->roll = mavlink_msg_dock_message_transform_get_roll(msg);
	dock_message_transform->pitch = mavlink_msg_dock_message_transform_get_pitch(msg);
	dock_message_transform->yaw = mavlink_msg_dock_message_transform_get_yaw(msg);
	dock_message_transform->status = mavlink_msg_dock_message_transform_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN? msg->len : MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN;
        memset(dock_message_transform, 0, MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_LEN);
	memcpy(dock_message_transform, _MAV_PAYLOAD(msg), len);
#endif
}
