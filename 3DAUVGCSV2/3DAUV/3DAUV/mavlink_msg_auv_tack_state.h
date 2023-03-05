#pragma once
// MESSAGE AUV_TACK_STATE PACKING

#define MAVLINK_MSG_ID_AUV_TACK_STATE 152

MAVPACKED(
typedef struct __mavlink_auv_tack_state_t {
 float desiredDepth; /*< [m] */
 float desidredPitch; /*< [degree] */
 float desiredCourse; /*< [degree] */
 float depth; /*< [m] */
 float roll; /*< [degree] */
 float pitch; /*< [degree] */
 float yaw; /*< [degree] */
}) mavlink_auv_tack_state_t;

#define MAVLINK_MSG_ID_AUV_TACK_STATE_LEN 28
#define MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN 28
#define MAVLINK_MSG_ID_152_LEN 28
#define MAVLINK_MSG_ID_152_MIN_LEN 28

#define MAVLINK_MSG_ID_AUV_TACK_STATE_CRC 156
#define MAVLINK_MSG_ID_152_CRC 156



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_TACK_STATE { \
    152, \
    "AUV_TACK_STATE", \
    7, \
    {  { "desiredDepth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_tack_state_t, desiredDepth) }, \
         { "desidredPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_tack_state_t, desidredPitch) }, \
         { "desiredCourse", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_tack_state_t, desiredCourse) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_tack_state_t, depth) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_tack_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_tack_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_auv_tack_state_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_TACK_STATE { \
    "AUV_TACK_STATE", \
    7, \
    {  { "desiredDepth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_tack_state_t, desiredDepth) }, \
         { "desidredPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_tack_state_t, desidredPitch) }, \
         { "desiredCourse", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_tack_state_t, desiredCourse) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_tack_state_t, depth) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_tack_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_tack_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_auv_tack_state_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_tack_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param desiredDepth [m] 
 * @param desidredPitch [degree] 
 * @param desiredCourse [degree] 
 * @param depth [m] 
 * @param roll [degree] 
 * @param pitch [degree] 
 * @param yaw [degree] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_tack_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float desiredDepth, float desidredPitch, float desiredCourse, float depth, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_TACK_STATE_LEN];
    _mav_put_float(buf, 0, desiredDepth);
    _mav_put_float(buf, 4, desidredPitch);
    _mav_put_float(buf, 8, desiredCourse);
    _mav_put_float(buf, 12, depth);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN);
#else
    mavlink_auv_tack_state_t packet;
    packet.desiredDepth = desiredDepth;
    packet.desidredPitch = desidredPitch;
    packet.desiredCourse = desiredCourse;
    packet.depth = depth;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_TACK_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
}

/**
 * @brief Pack a auv_tack_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param desiredDepth [m] 
 * @param desidredPitch [degree] 
 * @param desiredCourse [degree] 
 * @param depth [m] 
 * @param roll [degree] 
 * @param pitch [degree] 
 * @param yaw [degree] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_tack_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float desiredDepth,float desidredPitch,float desiredCourse,float depth,float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_TACK_STATE_LEN];
    _mav_put_float(buf, 0, desiredDepth);
    _mav_put_float(buf, 4, desidredPitch);
    _mav_put_float(buf, 8, desiredCourse);
    _mav_put_float(buf, 12, depth);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN);
#else
    mavlink_auv_tack_state_t packet;
    packet.desiredDepth = desiredDepth;
    packet.desidredPitch = desidredPitch;
    packet.desiredCourse = desiredCourse;
    packet.depth = depth;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_TACK_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
}

/**
 * @brief Encode a auv_tack_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_tack_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_tack_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_tack_state_t* auv_tack_state)
{
    return mavlink_msg_auv_tack_state_pack(system_id, component_id, msg, auv_tack_state->desiredDepth, auv_tack_state->desidredPitch, auv_tack_state->desiredCourse, auv_tack_state->depth, auv_tack_state->roll, auv_tack_state->pitch, auv_tack_state->yaw);
}

/**
 * @brief Encode a auv_tack_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_tack_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_tack_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_tack_state_t* auv_tack_state)
{
    return mavlink_msg_auv_tack_state_pack_chan(system_id, component_id, chan, msg, auv_tack_state->desiredDepth, auv_tack_state->desidredPitch, auv_tack_state->desiredCourse, auv_tack_state->depth, auv_tack_state->roll, auv_tack_state->pitch, auv_tack_state->yaw);
}

/**
 * @brief Send a auv_tack_state message
 * @param chan MAVLink channel to send the message
 *
 * @param desiredDepth [m] 
 * @param desidredPitch [degree] 
 * @param desiredCourse [degree] 
 * @param depth [m] 
 * @param roll [degree] 
 * @param pitch [degree] 
 * @param yaw [degree] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_tack_state_send(mavlink_channel_t chan, float desiredDepth, float desidredPitch, float desiredCourse, float depth, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_TACK_STATE_LEN];
    _mav_put_float(buf, 0, desiredDepth);
    _mav_put_float(buf, 4, desidredPitch);
    _mav_put_float(buf, 8, desiredCourse);
    _mav_put_float(buf, 12, depth);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_TACK_STATE, buf, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
#else
    mavlink_auv_tack_state_t packet;
    packet.desiredDepth = desiredDepth;
    packet.desidredPitch = desidredPitch;
    packet.desiredCourse = desiredCourse;
    packet.depth = depth;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_TACK_STATE, (const char *)&packet, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
#endif
}

/**
 * @brief Send a auv_tack_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_tack_state_send_struct(mavlink_channel_t chan, const mavlink_auv_tack_state_t* auv_tack_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_tack_state_send(chan, auv_tack_state->desiredDepth, auv_tack_state->desidredPitch, auv_tack_state->desiredCourse, auv_tack_state->depth, auv_tack_state->roll, auv_tack_state->pitch, auv_tack_state->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_TACK_STATE, (const char *)auv_tack_state, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_TACK_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_tack_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float desiredDepth, float desidredPitch, float desiredCourse, float depth, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, desiredDepth);
    _mav_put_float(buf, 4, desidredPitch);
    _mav_put_float(buf, 8, desiredCourse);
    _mav_put_float(buf, 12, depth);
    _mav_put_float(buf, 16, roll);
    _mav_put_float(buf, 20, pitch);
    _mav_put_float(buf, 24, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_TACK_STATE, buf, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
#else
    mavlink_auv_tack_state_t *packet = (mavlink_auv_tack_state_t *)msgbuf;
    packet->desiredDepth = desiredDepth;
    packet->desidredPitch = desidredPitch;
    packet->desiredCourse = desiredCourse;
    packet->depth = depth;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_TACK_STATE, (const char *)packet, MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN, MAVLINK_MSG_ID_AUV_TACK_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_TACK_STATE UNPACKING


/**
 * @brief Get field desiredDepth from auv_tack_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_auv_tack_state_get_desiredDepth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field desidredPitch from auv_tack_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_auv_tack_state_get_desidredPitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field desiredCourse from auv_tack_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_auv_tack_state_get_desiredCourse(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field depth from auv_tack_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_auv_tack_state_get_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll from auv_tack_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_auv_tack_state_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch from auv_tack_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_auv_tack_state_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yaw from auv_tack_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_auv_tack_state_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a auv_tack_state message into a struct
 *
 * @param msg The message to decode
 * @param auv_tack_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_tack_state_decode(const mavlink_message_t* msg, mavlink_auv_tack_state_t* auv_tack_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_tack_state->desiredDepth = mavlink_msg_auv_tack_state_get_desiredDepth(msg);
    auv_tack_state->desidredPitch = mavlink_msg_auv_tack_state_get_desidredPitch(msg);
    auv_tack_state->desiredCourse = mavlink_msg_auv_tack_state_get_desiredCourse(msg);
    auv_tack_state->depth = mavlink_msg_auv_tack_state_get_depth(msg);
    auv_tack_state->roll = mavlink_msg_auv_tack_state_get_roll(msg);
    auv_tack_state->pitch = mavlink_msg_auv_tack_state_get_pitch(msg);
    auv_tack_state->yaw = mavlink_msg_auv_tack_state_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_TACK_STATE_LEN? msg->len : MAVLINK_MSG_ID_AUV_TACK_STATE_LEN;
        memset(auv_tack_state, 0, MAVLINK_MSG_ID_AUV_TACK_STATE_LEN);
    memcpy(auv_tack_state, _MAV_PAYLOAD(msg), len);
#endif
}
