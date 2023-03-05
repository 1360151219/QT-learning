#pragma once
// MESSAGE GCS_SET_CONTROL_PARAM PACKING

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM 155

MAVPACKED(
typedef struct __mavlink_gcs_set_control_param_t {
 float kp_psi; /*<  */
 float ki_psi; /*<  */
 float kd_psi; /*<  */
 float kp_theta; /*<  */
 float ki_theta; /*<  */
 float kd_theta; /*<  */
 float k_psi_guid; /*<  */
 float k_theta_guid; /*<  */
 int16_t xunhang_pwm; /*<  */
}) mavlink_gcs_set_control_param_t;

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN 34
#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN 34
#define MAVLINK_MSG_ID_155_LEN 34
#define MAVLINK_MSG_ID_155_MIN_LEN 34

#define MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC 158
#define MAVLINK_MSG_ID_155_CRC 158



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_CONTROL_PARAM { \
    155, \
    "GCS_SET_CONTROL_PARAM", \
    9, \
    {  { "xunhang_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_gcs_set_control_param_t, xunhang_pwm) }, \
         { "kp_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_control_param_t, kp_psi) }, \
         { "ki_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_control_param_t, ki_psi) }, \
         { "kd_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_set_control_param_t, kd_psi) }, \
         { "kp_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gcs_set_control_param_t, kp_theta) }, \
         { "ki_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gcs_set_control_param_t, ki_theta) }, \
         { "kd_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gcs_set_control_param_t, kd_theta) }, \
         { "k_psi_guid", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gcs_set_control_param_t, k_psi_guid) }, \
         { "k_theta_guid", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gcs_set_control_param_t, k_theta_guid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_CONTROL_PARAM { \
    "GCS_SET_CONTROL_PARAM", \
    9, \
    {  { "xunhang_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_gcs_set_control_param_t, xunhang_pwm) }, \
         { "kp_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_control_param_t, kp_psi) }, \
         { "ki_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_control_param_t, ki_psi) }, \
         { "kd_psi", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_set_control_param_t, kd_psi) }, \
         { "kp_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gcs_set_control_param_t, kp_theta) }, \
         { "ki_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gcs_set_control_param_t, ki_theta) }, \
         { "kd_theta", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gcs_set_control_param_t, kd_theta) }, \
         { "k_psi_guid", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gcs_set_control_param_t, k_psi_guid) }, \
         { "k_theta_guid", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gcs_set_control_param_t, k_theta_guid) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_control_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xunhang_pwm  
 * @param kp_psi  
 * @param ki_psi  
 * @param kd_psi  
 * @param kp_theta  
 * @param ki_theta  
 * @param kd_theta  
 * @param k_psi_guid  
 * @param k_theta_guid  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t xunhang_pwm, float kp_psi, float ki_psi, float kd_psi, float kp_theta, float ki_theta, float kd_theta, float k_psi_guid, float k_theta_guid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN];
    _mav_put_float(buf, 0, kp_psi);
    _mav_put_float(buf, 4, ki_psi);
    _mav_put_float(buf, 8, kd_psi);
    _mav_put_float(buf, 12, kp_theta);
    _mav_put_float(buf, 16, ki_theta);
    _mav_put_float(buf, 20, kd_theta);
    _mav_put_float(buf, 24, k_psi_guid);
    _mav_put_float(buf, 28, k_theta_guid);
    _mav_put_int16_t(buf, 32, xunhang_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN);
#else
    mavlink_gcs_set_control_param_t packet;
    packet.kp_psi = kp_psi;
    packet.ki_psi = ki_psi;
    packet.kd_psi = kd_psi;
    packet.kp_theta = kp_theta;
    packet.ki_theta = ki_theta;
    packet.kd_theta = kd_theta;
    packet.k_psi_guid = k_psi_guid;
    packet.k_theta_guid = k_theta_guid;
    packet.xunhang_pwm = xunhang_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
}

/**
 * @brief Pack a gcs_set_control_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xunhang_pwm  
 * @param kp_psi  
 * @param ki_psi  
 * @param kd_psi  
 * @param kp_theta  
 * @param ki_theta  
 * @param kd_theta  
 * @param k_psi_guid  
 * @param k_theta_guid  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t xunhang_pwm,float kp_psi,float ki_psi,float kd_psi,float kp_theta,float ki_theta,float kd_theta,float k_psi_guid,float k_theta_guid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN];
    _mav_put_float(buf, 0, kp_psi);
    _mav_put_float(buf, 4, ki_psi);
    _mav_put_float(buf, 8, kd_psi);
    _mav_put_float(buf, 12, kp_theta);
    _mav_put_float(buf, 16, ki_theta);
    _mav_put_float(buf, 20, kd_theta);
    _mav_put_float(buf, 24, k_psi_guid);
    _mav_put_float(buf, 28, k_theta_guid);
    _mav_put_int16_t(buf, 32, xunhang_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN);
#else
    mavlink_gcs_set_control_param_t packet;
    packet.kp_psi = kp_psi;
    packet.ki_psi = ki_psi;
    packet.kd_psi = kd_psi;
    packet.kp_theta = kp_theta;
    packet.ki_theta = ki_theta;
    packet.kd_theta = kd_theta;
    packet.k_psi_guid = k_psi_guid;
    packet.k_theta_guid = k_theta_guid;
    packet.xunhang_pwm = xunhang_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
}

/**
 * @brief Encode a gcs_set_control_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_control_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_control_param_t* gcs_set_control_param)
{
    return mavlink_msg_gcs_set_control_param_pack(system_id, component_id, msg, gcs_set_control_param->xunhang_pwm, gcs_set_control_param->kp_psi, gcs_set_control_param->ki_psi, gcs_set_control_param->kd_psi, gcs_set_control_param->kp_theta, gcs_set_control_param->ki_theta, gcs_set_control_param->kd_theta, gcs_set_control_param->k_psi_guid, gcs_set_control_param->k_theta_guid);
}

/**
 * @brief Encode a gcs_set_control_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_control_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_control_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_control_param_t* gcs_set_control_param)
{
    return mavlink_msg_gcs_set_control_param_pack_chan(system_id, component_id, chan, msg, gcs_set_control_param->xunhang_pwm, gcs_set_control_param->kp_psi, gcs_set_control_param->ki_psi, gcs_set_control_param->kd_psi, gcs_set_control_param->kp_theta, gcs_set_control_param->ki_theta, gcs_set_control_param->kd_theta, gcs_set_control_param->k_psi_guid, gcs_set_control_param->k_theta_guid);
}

/**
 * @brief Send a gcs_set_control_param message
 * @param chan MAVLink channel to send the message
 *
 * @param xunhang_pwm  
 * @param kp_psi  
 * @param ki_psi  
 * @param kd_psi  
 * @param kp_theta  
 * @param ki_theta  
 * @param kd_theta  
 * @param k_psi_guid  
 * @param k_theta_guid  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_control_param_send(mavlink_channel_t chan, int16_t xunhang_pwm, float kp_psi, float ki_psi, float kd_psi, float kp_theta, float ki_theta, float kd_theta, float k_psi_guid, float k_theta_guid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN];
    _mav_put_float(buf, 0, kp_psi);
    _mav_put_float(buf, 4, ki_psi);
    _mav_put_float(buf, 8, kd_psi);
    _mav_put_float(buf, 12, kp_theta);
    _mav_put_float(buf, 16, ki_theta);
    _mav_put_float(buf, 20, kd_theta);
    _mav_put_float(buf, 24, k_psi_guid);
    _mav_put_float(buf, 28, k_theta_guid);
    _mav_put_int16_t(buf, 32, xunhang_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM, buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
#else
    mavlink_gcs_set_control_param_t packet;
    packet.kp_psi = kp_psi;
    packet.ki_psi = ki_psi;
    packet.kd_psi = kd_psi;
    packet.kp_theta = kp_theta;
    packet.ki_theta = ki_theta;
    packet.kd_theta = kd_theta;
    packet.k_psi_guid = k_psi_guid;
    packet.k_theta_guid = k_theta_guid;
    packet.xunhang_pwm = xunhang_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
#endif
}

/**
 * @brief Send a gcs_set_control_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_control_param_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_control_param_t* gcs_set_control_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_control_param_send(chan, gcs_set_control_param->xunhang_pwm, gcs_set_control_param->kp_psi, gcs_set_control_param->ki_psi, gcs_set_control_param->kd_psi, gcs_set_control_param->kp_theta, gcs_set_control_param->ki_theta, gcs_set_control_param->kd_theta, gcs_set_control_param->k_psi_guid, gcs_set_control_param->k_theta_guid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM, (const char *)gcs_set_control_param, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_control_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t xunhang_pwm, float kp_psi, float ki_psi, float kd_psi, float kp_theta, float ki_theta, float kd_theta, float k_psi_guid, float k_theta_guid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, kp_psi);
    _mav_put_float(buf, 4, ki_psi);
    _mav_put_float(buf, 8, kd_psi);
    _mav_put_float(buf, 12, kp_theta);
    _mav_put_float(buf, 16, ki_theta);
    _mav_put_float(buf, 20, kd_theta);
    _mav_put_float(buf, 24, k_psi_guid);
    _mav_put_float(buf, 28, k_theta_guid);
    _mav_put_int16_t(buf, 32, xunhang_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM, buf, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
#else
    mavlink_gcs_set_control_param_t *packet = (mavlink_gcs_set_control_param_t *)msgbuf;
    packet->kp_psi = kp_psi;
    packet->ki_psi = ki_psi;
    packet->kd_psi = kd_psi;
    packet->kp_theta = kp_theta;
    packet->ki_theta = ki_theta;
    packet->kd_theta = kd_theta;
    packet->k_psi_guid = k_psi_guid;
    packet->k_theta_guid = k_theta_guid;
    packet->xunhang_pwm = xunhang_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_CONTROL_PARAM UNPACKING


/**
 * @brief Get field xunhang_pwm from gcs_set_control_param message
 *
 * @return  
 */
static inline int16_t mavlink_msg_gcs_set_control_param_get_xunhang_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field kp_psi from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_kp_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ki_psi from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_ki_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field kd_psi from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_kd_psi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field kp_theta from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_kp_theta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field ki_theta from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_ki_theta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field kd_theta from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_kd_theta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field k_psi_guid from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_k_psi_guid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field k_theta_guid from gcs_set_control_param message
 *
 * @return  
 */
static inline float mavlink_msg_gcs_set_control_param_get_k_theta_guid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a gcs_set_control_param message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_control_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_control_param_decode(const mavlink_message_t* msg, mavlink_gcs_set_control_param_t* gcs_set_control_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_control_param->kp_psi = mavlink_msg_gcs_set_control_param_get_kp_psi(msg);
    gcs_set_control_param->ki_psi = mavlink_msg_gcs_set_control_param_get_ki_psi(msg);
    gcs_set_control_param->kd_psi = mavlink_msg_gcs_set_control_param_get_kd_psi(msg);
    gcs_set_control_param->kp_theta = mavlink_msg_gcs_set_control_param_get_kp_theta(msg);
    gcs_set_control_param->ki_theta = mavlink_msg_gcs_set_control_param_get_ki_theta(msg);
    gcs_set_control_param->kd_theta = mavlink_msg_gcs_set_control_param_get_kd_theta(msg);
    gcs_set_control_param->k_psi_guid = mavlink_msg_gcs_set_control_param_get_k_psi_guid(msg);
    gcs_set_control_param->k_theta_guid = mavlink_msg_gcs_set_control_param_get_k_theta_guid(msg);
    gcs_set_control_param->xunhang_pwm = mavlink_msg_gcs_set_control_param_get_xunhang_pwm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN;
        memset(gcs_set_control_param, 0, MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_LEN);
    memcpy(gcs_set_control_param, _MAV_PAYLOAD(msg), len);
#endif
}
