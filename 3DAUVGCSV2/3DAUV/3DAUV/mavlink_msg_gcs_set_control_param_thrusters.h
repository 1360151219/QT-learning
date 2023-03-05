#pragma once
// MESSAGE GCS_SET_CONTROL_PARAM_THRUSTERS PACKING

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS 166

MAVPACKED(
typedef struct __mavlink_gcs_set_control_param_thrusters_t {
 float kp_depth; /*<  */
 float ki_depth; /*<  */
 float kd_depth; /*<  */
 float kp_pitch; /*<  */
 float ki_pitch; /*<  */
 float kd_pitch; /*<  */
 float kp_course; /*<  */
 float ki_course; /*<  */
 float kd_course; /*<  */
 int16_t xunhang_pwm; /*<  */
}) mavlink_gcs_set_control_param_thrusters_t;

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN 38
#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN 38
#define MAVLINK_MSG_ID_166_LEN 38
#define MAVLINK_MSG_ID_166_MIN_LEN 38

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC 241
#define MAVLINK_MSG_ID_166_CRC 241



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_CONTROL_PARAM_THRUSTERS { \
    166, \
    "GCS_SET_CONTROL_PARAM_THRUSTERS", \
    10, \
    {  { "xunhang_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_gcs_set_control_param_thrusters_t, xunhang_pwm) }, \
         { "kp_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_depth) }, \
         { "ki_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_depth) }, \
         { "kd_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_depth) }, \
         { "kp_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_pitch) }, \
         { "ki_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_pitch) }, \
         { "kd_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_pitch) }, \
         { "kp_course", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_course) }, \
         { "ki_course", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_course) }, \
         { "kd_course", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_course) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_CONTROL_PARAM_THRUSTERS { \
    "GCS_SET_CONTROL_PARAM_THRUSTERS", \
    10, \
    {  { "xunhang_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_gcs_set_control_param_thrusters_t, xunhang_pwm) }, \
         { "kp_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_depth) }, \
         { "ki_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_depth) }, \
         { "kd_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_depth) }, \
         { "kp_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_pitch) }, \
         { "ki_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_pitch) }, \
         { "kd_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_pitch) }, \
         { "kp_course", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gcs_set_control_param_thrusters_t, kp_course) }, \
         { "ki_course", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gcs_set_control_param_thrusters_t, ki_course) }, \
         { "kd_course", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_gcs_set_control_param_thrusters_t, kd_course) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_control_param_thrusters message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xunhang_pwm  
 * @param kp_depth  
 * @param ki_depth  
 * @param kd_depth  
 * @param kp_pitch  
 * @param ki_pitch  
 * @param kd_pitch  
 * @param kp_course  
 * @param ki_course  
 * @param kd_course  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_thrusters_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t xunhang_pwm, float kp_depth, float ki_depth, float kd_depth, float kp_pitch, float ki_pitch, float kd_pitch, float kp_course, float ki_course, float kd_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN];
    _mav_put_float(buf, 0, kp_depth);
    _mav_put_float(buf, 4, ki_depth);
    _mav_put_float(buf, 8, kd_depth);
    _mav_put_float(buf, 12, kp_pitch);
    _mav_put_float(buf, 16, ki_pitch);
    _mav_put_float(buf, 20, kd_pitch);
    _mav_put_float(buf, 24, kp_course);
    _mav_put_float(buf, 28, ki_course);
    _mav_put_float(buf, 32, kd_course);
    _mav_put_int16_t(buf, 36, xunhang_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN);
#else
    mavlink_gcs_set_control_param_thrusters_t packet;
    packet.kp_depth = kp_depth;
    packet.ki_depth = ki_depth;
    packet.kd_depth = kd_depth;
    packet.kp_pitch = kp_pitch;
    packet.ki_pitch = ki_pitch;
    packet.kd_pitch = kd_pitch;
    packet.kp_course = kp_course;
    packet.ki_course = ki_course;
    packet.kd_course = kd_course;
    packet.xunhang_pwm = xunhang_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
}

/**
 * @brief Pack a gcs_set_control_param_thrusters message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xunhang_pwm  
 * @param kp_depth  
 * @param ki_depth  
 * @param kd_depth  
 * @param kp_pitch  
 * @param ki_pitch  
 * @param kd_pitch  
 * @param kp_course  
 * @param ki_course  
 * @param kd_course  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_thrusters_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t xunhang_pwm,float kp_depth,float ki_depth,float kd_depth,float kp_pitch,float ki_pitch,float kd_pitch,float kp_course,float ki_course,float kd_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN];
    _mav_put_float(buf, 0, kp_depth);
    _mav_put_float(buf, 4, ki_depth);
    _mav_put_float(buf, 8, kd_depth);
    _mav_put_float(buf, 12, kp_pitch);
    _mav_put_float(buf, 16, ki_pitch);
    _mav_put_float(buf, 20, kd_pitch);
    _mav_put_float(buf, 24, kp_course);
    _mav_put_float(buf, 28, ki_course);
    _mav_put_float(buf, 32, kd_course);
    _mav_put_int16_t(buf, 36, xunhang_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN);
#else
    mavlink_gcs_set_control_param_thrusters_t packet;
    packet.kp_depth = kp_depth;
    packet.ki_depth = ki_depth;
    packet.kd_depth = kd_depth;
    packet.kp_pitch = kp_pitch;
    packet.ki_pitch = ki_pitch;
    packet.kd_pitch = kd_pitch;
    packet.kp_course = kp_course;
    packet.ki_course = ki_course;
    packet.kd_course = kd_course;
    packet.xunhang_pwm = xunhang_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
}

/**
 * @brief Encode a gcs_set_control_param_thrusters struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_control_param_thrusters C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_thrusters_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_control_param_thrusters_t* gcs_set_control_param_thrusters)
{
    return mavlink_msg_gcs_set_control_param_thrusters_pack(system_id, component_id, msg, gcs_set_control_param_thrusters->xunhang_pwm, gcs_set_control_param_thrusters->kp_depth, gcs_set_control_param_thrusters->ki_depth, gcs_set_control_param_thrusters->kd_depth, gcs_set_control_param_thrusters->kp_pitch, gcs_set_control_param_thrusters->ki_pitch, gcs_set_control_param_thrusters->kd_pitch, gcs_set_control_param_thrusters->kp_course, gcs_set_control_param_thrusters->ki_course, gcs_set_control_param_thrusters->kd_course);
}

/**
 * @brief Encode a gcs_set_control_param_thrusters struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_control_param_thrusters C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_thrusters_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_control_param_thrusters_t* gcs_set_control_param_thrusters)
{
    return mavlink_msg_gcs_set_control_param_thrusters_pack_chan(system_id, component_id, chan, msg, gcs_set_control_param_thrusters->xunhang_pwm, gcs_set_control_param_thrusters->kp_depth, gcs_set_control_param_thrusters->ki_depth, gcs_set_control_param_thrusters->kd_depth, gcs_set_control_param_thrusters->kp_pitch, gcs_set_control_param_thrusters->ki_pitch, gcs_set_control_param_thrusters->kd_pitch, gcs_set_control_param_thrusters->kp_course, gcs_set_control_param_thrusters->ki_course, gcs_set_control_param_thrusters->kd_course);
}

/**
 * @brief Send a gcs_set_control_param_thrusters message
 * @param chan MAVLink channel to send the message
 *
 * @param xunhang_pwm  
 * @param kp_depth  
 * @param ki_depth  
 * @param kd_depth  
 * @param kp_pitch  
 * @param ki_pitch  
 * @param kd_pitch  
 * @param kp_course  
 * @param ki_course  
 * @param kd_course  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_control_param_thrusters_send(mavlink_channel_t chan, int16_t xunhang_pwm, float kp_depth, float ki_depth, float kd_depth, float kp_pitch, float ki_pitch, float kd_pitch, float kp_course, float ki_course, float kd_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN];
    _mav_put_float(buf, 0, kp_depth);
    _mav_put_float(buf, 4, ki_depth);
    _mav_put_float(buf, 8, kd_depth);
    _mav_put_float(buf, 12, kp_pitch);
    _mav_put_float(buf, 16, ki_pitch);
    _mav_put_float(buf, 20, kd_pitch);
    _mav_put_float(buf, 24, kp_course);
    _mav_put_float(buf, 28, ki_course);
    _mav_put_float(buf, 32, kd_course);
    _mav_put_int16_t(buf, 36, xunhang_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS, buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
#else
    mavlink_gcs_set_control_param_thrusters_t packet;
    packet.kp_depth = kp_depth;
    packet.ki_depth = ki_depth;
    packet.kd_depth = kd_depth;
    packet.kp_pitch = kp_pitch;
    packet.ki_pitch = ki_pitch;
    packet.kd_pitch = kd_pitch;
    packet.kp_course = kp_course;
    packet.ki_course = ki_course;
    packet.kd_course = kd_course;
    packet.xunhang_pwm = xunhang_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
#endif
}

/**
 * @brief Send a gcs_set_control_param_thrusters message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_control_param_thrusters_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_control_param_thrusters_t* gcs_set_control_param_thrusters)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_control_param_thrusters_send(chan, gcs_set_control_param_thrusters->xunhang_pwm, gcs_set_control_param_thrusters->kp_depth, gcs_set_control_param_thrusters->ki_depth, gcs_set_control_param_thrusters->kd_depth, gcs_set_control_param_thrusters->kp_pitch, gcs_set_control_param_thrusters->ki_pitch, gcs_set_control_param_thrusters->kd_pitch, gcs_set_control_param_thrusters->kp_course, gcs_set_control_param_thrusters->ki_course, gcs_set_control_param_thrusters->kd_course);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS, (const char *)gcs_set_control_param_thrusters, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_control_param_thrusters_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t xunhang_pwm, float kp_depth, float ki_depth, float kd_depth, float kp_pitch, float ki_pitch, float kd_pitch, float kp_course, float ki_course, float kd_course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, kp_depth);
    _mav_put_float(buf, 4, ki_depth);
    _mav_put_float(buf, 8, kd_depth);
    _mav_put_float(buf, 12, kp_pitch);
    _mav_put_float(buf, 16, ki_pitch);
    _mav_put_float(buf, 20, kd_pitch);
    _mav_put_float(buf, 24, kp_course);
    _mav_put_float(buf, 28, ki_course);
    _mav_put_float(buf, 32, kd_course);
    _mav_put_int16_t(buf, 36, xunhang_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS, buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
#else
    mavlink_gcs_set_control_param_thrusters_t *packet = (mavlink_gcs_set_control_param_thrusters_t *)msgbuf;
    packet->kp_depth = kp_depth;
    packet->ki_depth = ki_depth;
    packet->kd_depth = kd_depth;
    packet->kp_pitch = kp_pitch;
    packet->ki_pitch = ki_pitch;
    packet->kd_pitch = kd_pitch;
    packet->kp_course = kp_course;
    packet->ki_course = ki_course;
    packet->kd_course = kd_course;
    packet->xunhang_pwm = xunhang_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_CONTROL_PARAM_THRUSTERS UNPACKING


/**
 * @brief Get field xunhang_pwm from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline int16_t mavlink_msg_gcs_set_control_param_thrusters_get_xunhang_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field kp_depth from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kp_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ki_depth from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_ki_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field kd_depth from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kd_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field kp_pitch from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kp_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field ki_pitch from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_ki_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field kd_pitch from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kd_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field kp_course from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kp_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field ki_course from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_ki_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field kd_course from gcs_set_control_param_thrusters message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_thrusters_get_kd_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a gcs_set_control_param_thrusters message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_control_param_thrusters C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_control_param_thrusters_decode(const mavlink_message_t* msg, mavlink_gcs_set_control_param_thrusters_t* gcs_set_control_param_thrusters)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_control_param_thrusters->kp_depth = mavlink_msg_gcs_set_control_param_thrusters_get_kp_depth(msg);
    gcs_set_control_param_thrusters->ki_depth = mavlink_msg_gcs_set_control_param_thrusters_get_ki_depth(msg);
    gcs_set_control_param_thrusters->kd_depth = mavlink_msg_gcs_set_control_param_thrusters_get_kd_depth(msg);
    gcs_set_control_param_thrusters->kp_pitch = mavlink_msg_gcs_set_control_param_thrusters_get_kp_pitch(msg);
    gcs_set_control_param_thrusters->ki_pitch = mavlink_msg_gcs_set_control_param_thrusters_get_ki_pitch(msg);
    gcs_set_control_param_thrusters->kd_pitch = mavlink_msg_gcs_set_control_param_thrusters_get_kd_pitch(msg);
    gcs_set_control_param_thrusters->kp_course = mavlink_msg_gcs_set_control_param_thrusters_get_kp_course(msg);
    gcs_set_control_param_thrusters->ki_course = mavlink_msg_gcs_set_control_param_thrusters_get_ki_course(msg);
    gcs_set_control_param_thrusters->kd_course = mavlink_msg_gcs_set_control_param_thrusters_get_kd_course(msg);
    gcs_set_control_param_thrusters->xunhang_pwm = mavlink_msg_gcs_set_control_param_thrusters_get_xunhang_pwm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN;
        memset(gcs_set_control_param_thrusters, 0, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_LEN);
    memcpy(gcs_set_control_param_thrusters, _MAV_PAYLOAD(msg), len);
#endif
}
