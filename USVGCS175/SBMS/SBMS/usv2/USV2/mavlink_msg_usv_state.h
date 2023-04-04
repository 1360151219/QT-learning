#pragma once
// MESSAGE USV_STATE PACKING

#define MAVLINK_MSG_ID_USV_STATE 150

MAVPACKED(
typedef struct __mavlink_usv_state_t {
 uint32_t lng; /*< */
 uint32_t lat; /*< */
 float x; /*< */
 float y; /*< */
 float yaw; /*< */
 float pitch; /*< */
 float heel; /*< */
 float velocity; /*< */
 float electric_current; /*< */
 float voltage; /*< */
 uint8_t mode; /*< */
 uint8_t thrust; /*< */
 int8_t rudder; /*< */
 uint8_t progress; /*< */
}) mavlink_usv_state_t;

#define MAVLINK_MSG_ID_USV_STATE_LEN 44
#define MAVLINK_MSG_ID_USV_STATE_MIN_LEN 44
#define MAVLINK_MSG_ID_150_LEN 44
#define MAVLINK_MSG_ID_150_MIN_LEN 44

#define MAVLINK_MSG_ID_USV_STATE_CRC 137
#define MAVLINK_MSG_ID_150_CRC 137



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_STATE { \
	150, \
	"USV_STATE", \
	14, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_usv_state_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_usv_state_t, lat) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_usv_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_usv_state_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_state_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_state_t, pitch) }, \
         { "heel", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_usv_state_t, heel) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_usv_state_t, velocity) }, \
         { "electric_current", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_usv_state_t, electric_current) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_usv_state_t, voltage) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_usv_state_t, mode) }, \
         { "thrust", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_usv_state_t, thrust) }, \
         { "rudder", NULL, MAVLINK_TYPE_INT8_T, 0, 42, offsetof(mavlink_usv_state_t, rudder) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_usv_state_t, progress) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_STATE { \
	"USV_STATE", \
	14, \
	{  { "lng", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_usv_state_t, lng) }, \
         { "lat", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_usv_state_t, lat) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_usv_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_usv_state_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_state_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_state_t, pitch) }, \
         { "heel", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_usv_state_t, heel) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_usv_state_t, velocity) }, \
         { "electric_current", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_usv_state_t, electric_current) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_usv_state_t, voltage) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_usv_state_t, mode) }, \
         { "thrust", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_usv_state_t, thrust) }, \
         { "rudder", NULL, MAVLINK_TYPE_INT8_T, 0, 42, offsetof(mavlink_usv_state_t, rudder) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_usv_state_t, progress) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode 
 * @param lng 
 * @param lat 
 * @param x 
 * @param y 
 * @param yaw 
 * @param pitch 
 * @param heel 
 * @param velocity 
 * @param thrust 
 * @param rudder 
 * @param progress 
 * @param electric_current 
 * @param voltage 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode, uint32_t lng, uint32_t lat, float x, float y, float yaw, float pitch, float heel, float velocity, uint8_t thrust, int8_t rudder, uint8_t progress, float electric_current, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, heel);
	_mav_put_float(buf, 28, velocity);
	_mav_put_float(buf, 32, electric_current);
	_mav_put_float(buf, 36, voltage);
	_mav_put_uint8_t(buf, 40, mode);
	_mav_put_uint8_t(buf, 41, thrust);
	_mav_put_int8_t(buf, 42, rudder);
	_mav_put_uint8_t(buf, 43, progress);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATE_LEN);
#else
	mavlink_usv_state_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.heel = heel;
	packet.velocity = velocity;
	packet.electric_current = electric_current;
	packet.voltage = voltage;
	packet.mode = mode;
	packet.thrust = thrust;
	packet.rudder = rudder;
	packet.progress = progress;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_USV_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
}

/**
 * @brief Pack a usv_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode 
 * @param lng 
 * @param lat 
 * @param x 
 * @param y 
 * @param yaw 
 * @param pitch 
 * @param heel 
 * @param velocity 
 * @param thrust 
 * @param rudder 
 * @param progress 
 * @param electric_current 
 * @param voltage 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode,uint32_t lng,uint32_t lat,float x,float y,float yaw,float pitch,float heel,float velocity,uint8_t thrust,int8_t rudder,uint8_t progress,float electric_current,float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, heel);
	_mav_put_float(buf, 28, velocity);
	_mav_put_float(buf, 32, electric_current);
	_mav_put_float(buf, 36, voltage);
	_mav_put_uint8_t(buf, 40, mode);
	_mav_put_uint8_t(buf, 41, thrust);
	_mav_put_int8_t(buf, 42, rudder);
	_mav_put_uint8_t(buf, 43, progress);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATE_LEN);
#else
	mavlink_usv_state_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.heel = heel;
	packet.velocity = velocity;
	packet.electric_current = electric_current;
	packet.voltage = voltage;
	packet.mode = mode;
	packet.thrust = thrust;
	packet.rudder = rudder;
	packet.progress = progress;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_USV_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
}

/**
 * @brief Encode a usv_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_state_t* usv_state)
{
	return mavlink_msg_usv_state_pack(system_id, component_id, msg, usv_state->mode, usv_state->lng, usv_state->lat, usv_state->x, usv_state->y, usv_state->yaw, usv_state->pitch, usv_state->heel, usv_state->velocity, usv_state->thrust, usv_state->rudder, usv_state->progress, usv_state->electric_current, usv_state->voltage);
}

/**
 * @brief Encode a usv_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_state_t* usv_state)
{
	return mavlink_msg_usv_state_pack_chan(system_id, component_id, chan, msg, usv_state->mode, usv_state->lng, usv_state->lat, usv_state->x, usv_state->y, usv_state->yaw, usv_state->pitch, usv_state->heel, usv_state->velocity, usv_state->thrust, usv_state->rudder, usv_state->progress, usv_state->electric_current, usv_state->voltage);
}

/**
 * @brief Send a usv_state message
 * @param chan MAVLink channel to send the message
 *
 * @param mode 
 * @param lng 
 * @param lat 
 * @param x 
 * @param y 
 * @param yaw 
 * @param pitch 
 * @param heel 
 * @param velocity 
 * @param thrust 
 * @param rudder 
 * @param progress 
 * @param electric_current 
 * @param voltage 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_state_send(mavlink_channel_t chan, uint8_t mode, uint32_t lng, uint32_t lat, float x, float y, float yaw, float pitch, float heel, float velocity, uint8_t thrust, int8_t rudder, uint8_t progress, float electric_current, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, heel);
	_mav_put_float(buf, 28, velocity);
	_mav_put_float(buf, 32, electric_current);
	_mav_put_float(buf, 36, voltage);
	_mav_put_uint8_t(buf, 40, mode);
	_mav_put_uint8_t(buf, 41, thrust);
	_mav_put_int8_t(buf, 42, rudder);
	_mav_put_uint8_t(buf, 43, progress);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, buf, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#else
	mavlink_usv_state_t packet;
	packet.lng = lng;
	packet.lat = lat;
	packet.x = x;
	packet.y = y;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.heel = heel;
	packet.velocity = velocity;
	packet.electric_current = electric_current;
	packet.voltage = voltage;
	packet.mode = mode;
	packet.thrust = thrust;
	packet.rudder = rudder;
	packet.progress = progress;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)&packet, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}

/**
 * @brief Send a usv_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_state_send_struct(mavlink_channel_t chan, const mavlink_usv_state_t* usv_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_state_send(chan, usv_state->mode, usv_state->lng, usv_state->lat, usv_state->x, usv_state->y, usv_state->yaw, usv_state->pitch, usv_state->heel, usv_state->velocity, usv_state->thrust, usv_state->rudder, usv_state->progress, usv_state->electric_current, usv_state->voltage);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)usv_state, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, uint32_t lng, uint32_t lat, float x, float y, float yaw, float pitch, float heel, float velocity, uint8_t thrust, int8_t rudder, uint8_t progress, float electric_current, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, lng);
	_mav_put_uint32_t(buf, 4, lat);
	_mav_put_float(buf, 8, x);
	_mav_put_float(buf, 12, y);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, pitch);
	_mav_put_float(buf, 24, heel);
	_mav_put_float(buf, 28, velocity);
	_mav_put_float(buf, 32, electric_current);
	_mav_put_float(buf, 36, voltage);
	_mav_put_uint8_t(buf, 40, mode);
	_mav_put_uint8_t(buf, 41, thrust);
	_mav_put_int8_t(buf, 42, rudder);
	_mav_put_uint8_t(buf, 43, progress);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, buf, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#else
	mavlink_usv_state_t *packet = (mavlink_usv_state_t *)msgbuf;
	packet->lng = lng;
	packet->lat = lat;
	packet->x = x;
	packet->y = y;
	packet->yaw = yaw;
	packet->pitch = pitch;
	packet->heel = heel;
	packet->velocity = velocity;
	packet->electric_current = electric_current;
	packet->voltage = voltage;
	packet->mode = mode;
	packet->thrust = thrust;
	packet->rudder = rudder;
	packet->progress = progress;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)packet, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_STATE UNPACKING


/**
 * @brief Get field mode from usv_state message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_usv_state_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field lng from usv_state message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_usv_state_get_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from usv_state message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_usv_state_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field x from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field heel from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_heel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field velocity from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_velocity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field thrust from usv_state message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_usv_state_get_thrust(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field rudder from usv_state message
 *
 * @return 
 */
static inline int8_t mavlink_msg_usv_state_get_rudder(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  42);
}

/**
 * @brief Get field progress from usv_state message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_usv_state_get_progress(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field electric_current from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_electric_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field voltage from usv_state message
 *
 * @return 
 */
static inline float mavlink_msg_usv_state_get_voltage(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a usv_state message into a struct
 *
 * @param msg The message to decode
 * @param usv_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_state_decode(const mavlink_message_t* msg, mavlink_usv_state_t* usv_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	usv_state->lng = mavlink_msg_usv_state_get_lng(msg);
	usv_state->lat = mavlink_msg_usv_state_get_lat(msg);
	usv_state->x = mavlink_msg_usv_state_get_x(msg);
	usv_state->y = mavlink_msg_usv_state_get_y(msg);
	usv_state->yaw = mavlink_msg_usv_state_get_yaw(msg);
	usv_state->pitch = mavlink_msg_usv_state_get_pitch(msg);
	usv_state->heel = mavlink_msg_usv_state_get_heel(msg);
	usv_state->velocity = mavlink_msg_usv_state_get_velocity(msg);
	usv_state->electric_current = mavlink_msg_usv_state_get_electric_current(msg);
	usv_state->voltage = mavlink_msg_usv_state_get_voltage(msg);
	usv_state->mode = mavlink_msg_usv_state_get_mode(msg);
	usv_state->thrust = mavlink_msg_usv_state_get_thrust(msg);
	usv_state->rudder = mavlink_msg_usv_state_get_rudder(msg);
	usv_state->progress = mavlink_msg_usv_state_get_progress(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_STATE_LEN? msg->len : MAVLINK_MSG_ID_USV_STATE_LEN;
        memset(usv_state, 0, MAVLINK_MSG_ID_USV_STATE_LEN);
	memcpy(usv_state, _MAV_PAYLOAD(msg), len);
#endif
}
