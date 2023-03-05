#pragma once
// MESSAGE GCS_SET_SERVO_PARAM PACKING

#define MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM 158

MAVPACKED(
typedef struct __mavlink_gcs_set_servo_param_t {
 uint16_t propeller_mid_pwm; /*< [us] */
 uint16_t stern_up_mid_pwm; /*< [us] */
 uint16_t stern_down_mid_pwm; /*< [us] */
 uint16_t stern_right_mid_pwm; /*< [us] */
 uint16_t stern_left_mid_pwm; /*< [us] */
 int8_t offset_rudder; /*< [deg] */
 int8_t offset_stern; /*< [deg] */
}) mavlink_gcs_set_servo_param_t;

#define MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN 12
#define MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN 12
#define MAVLINK_MSG_ID_158_LEN 12
#define MAVLINK_MSG_ID_158_MIN_LEN 12

#define MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC 169
#define MAVLINK_MSG_ID_158_CRC 169



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_SERVO_PARAM { \
    158, \
    "GCS_SET_SERVO_PARAM", \
    7, \
    {  { "propeller_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_gcs_set_servo_param_t, propeller_mid_pwm) }, \
         { "stern_up_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_gcs_set_servo_param_t, stern_up_mid_pwm) }, \
         { "stern_down_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_gcs_set_servo_param_t, stern_down_mid_pwm) }, \
         { "stern_right_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_gcs_set_servo_param_t, stern_right_mid_pwm) }, \
         { "stern_left_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gcs_set_servo_param_t, stern_left_mid_pwm) }, \
         { "offset_rudder", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_gcs_set_servo_param_t, offset_rudder) }, \
         { "offset_stern", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_gcs_set_servo_param_t, offset_stern) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_SERVO_PARAM { \
    "GCS_SET_SERVO_PARAM", \
    7, \
    {  { "propeller_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_gcs_set_servo_param_t, propeller_mid_pwm) }, \
         { "stern_up_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_gcs_set_servo_param_t, stern_up_mid_pwm) }, \
         { "stern_down_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_gcs_set_servo_param_t, stern_down_mid_pwm) }, \
         { "stern_right_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_gcs_set_servo_param_t, stern_right_mid_pwm) }, \
         { "stern_left_mid_pwm", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gcs_set_servo_param_t, stern_left_mid_pwm) }, \
         { "offset_rudder", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_gcs_set_servo_param_t, offset_rudder) }, \
         { "offset_stern", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_gcs_set_servo_param_t, offset_stern) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_servo_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param propeller_mid_pwm [us] 
 * @param stern_up_mid_pwm [us] 
 * @param stern_down_mid_pwm [us] 
 * @param stern_right_mid_pwm [us] 
 * @param stern_left_mid_pwm [us] 
 * @param offset_rudder [deg] 
 * @param offset_stern [deg] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t propeller_mid_pwm, uint16_t stern_up_mid_pwm, uint16_t stern_down_mid_pwm, uint16_t stern_right_mid_pwm, uint16_t stern_left_mid_pwm, int8_t offset_rudder, int8_t offset_stern)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, propeller_mid_pwm);
    _mav_put_uint16_t(buf, 2, stern_up_mid_pwm);
    _mav_put_uint16_t(buf, 4, stern_down_mid_pwm);
    _mav_put_uint16_t(buf, 6, stern_right_mid_pwm);
    _mav_put_uint16_t(buf, 8, stern_left_mid_pwm);
    _mav_put_int8_t(buf, 10, offset_rudder);
    _mav_put_int8_t(buf, 11, offset_stern);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN);
#else
    mavlink_gcs_set_servo_param_t packet;
    packet.propeller_mid_pwm = propeller_mid_pwm;
    packet.stern_up_mid_pwm = stern_up_mid_pwm;
    packet.stern_down_mid_pwm = stern_down_mid_pwm;
    packet.stern_right_mid_pwm = stern_right_mid_pwm;
    packet.stern_left_mid_pwm = stern_left_mid_pwm;
    packet.offset_rudder = offset_rudder;
    packet.offset_stern = offset_stern;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
}

/**
 * @brief Pack a gcs_set_servo_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param propeller_mid_pwm [us] 
 * @param stern_up_mid_pwm [us] 
 * @param stern_down_mid_pwm [us] 
 * @param stern_right_mid_pwm [us] 
 * @param stern_left_mid_pwm [us] 
 * @param offset_rudder [deg] 
 * @param offset_stern [deg] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t propeller_mid_pwm,uint16_t stern_up_mid_pwm,uint16_t stern_down_mid_pwm,uint16_t stern_right_mid_pwm,uint16_t stern_left_mid_pwm,int8_t offset_rudder,int8_t offset_stern)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, propeller_mid_pwm);
    _mav_put_uint16_t(buf, 2, stern_up_mid_pwm);
    _mav_put_uint16_t(buf, 4, stern_down_mid_pwm);
    _mav_put_uint16_t(buf, 6, stern_right_mid_pwm);
    _mav_put_uint16_t(buf, 8, stern_left_mid_pwm);
    _mav_put_int8_t(buf, 10, offset_rudder);
    _mav_put_int8_t(buf, 11, offset_stern);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN);
#else
    mavlink_gcs_set_servo_param_t packet;
    packet.propeller_mid_pwm = propeller_mid_pwm;
    packet.stern_up_mid_pwm = stern_up_mid_pwm;
    packet.stern_down_mid_pwm = stern_down_mid_pwm;
    packet.stern_right_mid_pwm = stern_right_mid_pwm;
    packet.stern_left_mid_pwm = stern_left_mid_pwm;
    packet.offset_rudder = offset_rudder;
    packet.offset_stern = offset_stern;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
}

/**
 * @brief Encode a gcs_set_servo_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_servo_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_servo_param_t* gcs_set_servo_param)
{
    return mavlink_msg_gcs_set_servo_param_pack(system_id, component_id, msg, gcs_set_servo_param->propeller_mid_pwm, gcs_set_servo_param->stern_up_mid_pwm, gcs_set_servo_param->stern_down_mid_pwm, gcs_set_servo_param->stern_right_mid_pwm, gcs_set_servo_param->stern_left_mid_pwm, gcs_set_servo_param->offset_rudder, gcs_set_servo_param->offset_stern);
}

/**
 * @brief Encode a gcs_set_servo_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_servo_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_servo_param_t* gcs_set_servo_param)
{
    return mavlink_msg_gcs_set_servo_param_pack_chan(system_id, component_id, chan, msg, gcs_set_servo_param->propeller_mid_pwm, gcs_set_servo_param->stern_up_mid_pwm, gcs_set_servo_param->stern_down_mid_pwm, gcs_set_servo_param->stern_right_mid_pwm, gcs_set_servo_param->stern_left_mid_pwm, gcs_set_servo_param->offset_rudder, gcs_set_servo_param->offset_stern);
}

/**
 * @brief Send a gcs_set_servo_param message
 * @param chan MAVLink channel to send the message
 *
 * @param propeller_mid_pwm [us] 
 * @param stern_up_mid_pwm [us] 
 * @param stern_down_mid_pwm [us] 
 * @param stern_right_mid_pwm [us] 
 * @param stern_left_mid_pwm [us] 
 * @param offset_rudder [deg] 
 * @param offset_stern [deg] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_servo_param_send(mavlink_channel_t chan, uint16_t propeller_mid_pwm, uint16_t stern_up_mid_pwm, uint16_t stern_down_mid_pwm, uint16_t stern_right_mid_pwm, uint16_t stern_left_mid_pwm, int8_t offset_rudder, int8_t offset_stern)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, propeller_mid_pwm);
    _mav_put_uint16_t(buf, 2, stern_up_mid_pwm);
    _mav_put_uint16_t(buf, 4, stern_down_mid_pwm);
    _mav_put_uint16_t(buf, 6, stern_right_mid_pwm);
    _mav_put_uint16_t(buf, 8, stern_left_mid_pwm);
    _mav_put_int8_t(buf, 10, offset_rudder);
    _mav_put_int8_t(buf, 11, offset_stern);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM, buf, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
#else
    mavlink_gcs_set_servo_param_t packet;
    packet.propeller_mid_pwm = propeller_mid_pwm;
    packet.stern_up_mid_pwm = stern_up_mid_pwm;
    packet.stern_down_mid_pwm = stern_down_mid_pwm;
    packet.stern_right_mid_pwm = stern_right_mid_pwm;
    packet.stern_left_mid_pwm = stern_left_mid_pwm;
    packet.offset_rudder = offset_rudder;
    packet.offset_stern = offset_stern;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
#endif
}

/**
 * @brief Send a gcs_set_servo_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_servo_param_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_servo_param_t* gcs_set_servo_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_servo_param_send(chan, gcs_set_servo_param->propeller_mid_pwm, gcs_set_servo_param->stern_up_mid_pwm, gcs_set_servo_param->stern_down_mid_pwm, gcs_set_servo_param->stern_right_mid_pwm, gcs_set_servo_param->stern_left_mid_pwm, gcs_set_servo_param->offset_rudder, gcs_set_servo_param->offset_stern);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM, (const char *)gcs_set_servo_param, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_servo_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t propeller_mid_pwm, uint16_t stern_up_mid_pwm, uint16_t stern_down_mid_pwm, uint16_t stern_right_mid_pwm, uint16_t stern_left_mid_pwm, int8_t offset_rudder, int8_t offset_stern)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, propeller_mid_pwm);
    _mav_put_uint16_t(buf, 2, stern_up_mid_pwm);
    _mav_put_uint16_t(buf, 4, stern_down_mid_pwm);
    _mav_put_uint16_t(buf, 6, stern_right_mid_pwm);
    _mav_put_uint16_t(buf, 8, stern_left_mid_pwm);
    _mav_put_int8_t(buf, 10, offset_rudder);
    _mav_put_int8_t(buf, 11, offset_stern);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM, buf, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
#else
    mavlink_gcs_set_servo_param_t *packet = (mavlink_gcs_set_servo_param_t *)msgbuf;
    packet->propeller_mid_pwm = propeller_mid_pwm;
    packet->stern_up_mid_pwm = stern_up_mid_pwm;
    packet->stern_down_mid_pwm = stern_down_mid_pwm;
    packet->stern_right_mid_pwm = stern_right_mid_pwm;
    packet->stern_left_mid_pwm = stern_left_mid_pwm;
    packet->offset_rudder = offset_rudder;
    packet->offset_stern = offset_stern;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_SERVO_PARAM UNPACKING


/**
 * @brief Get field propeller_mid_pwm from gcs_set_servo_param message
 *
 * @return [us] 
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_get_propeller_mid_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field stern_up_mid_pwm from gcs_set_servo_param message
 *
 * @return [us] 
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_get_stern_up_mid_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field stern_down_mid_pwm from gcs_set_servo_param message
 *
 * @return [us] 
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_get_stern_down_mid_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field stern_right_mid_pwm from gcs_set_servo_param message
 *
 * @return [us] 
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_get_stern_right_mid_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field stern_left_mid_pwm from gcs_set_servo_param message
 *
 * @return [us] 
 */
static inline uint16_t mavlink_msg_gcs_set_servo_param_get_stern_left_mid_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field offset_rudder from gcs_set_servo_param message
 *
 * @return [deg] 
 */
static inline int8_t mavlink_msg_gcs_set_servo_param_get_offset_rudder(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  10);
}

/**
 * @brief Get field offset_stern from gcs_set_servo_param message
 *
 * @return [deg] 
 */
static inline int8_t mavlink_msg_gcs_set_servo_param_get_offset_stern(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  11);
}

/**
 * @brief Decode a gcs_set_servo_param message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_servo_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_servo_param_decode(const mavlink_message_t* msg, mavlink_gcs_set_servo_param_t* gcs_set_servo_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_servo_param->propeller_mid_pwm = mavlink_msg_gcs_set_servo_param_get_propeller_mid_pwm(msg);
    gcs_set_servo_param->stern_up_mid_pwm = mavlink_msg_gcs_set_servo_param_get_stern_up_mid_pwm(msg);
    gcs_set_servo_param->stern_down_mid_pwm = mavlink_msg_gcs_set_servo_param_get_stern_down_mid_pwm(msg);
    gcs_set_servo_param->stern_right_mid_pwm = mavlink_msg_gcs_set_servo_param_get_stern_right_mid_pwm(msg);
    gcs_set_servo_param->stern_left_mid_pwm = mavlink_msg_gcs_set_servo_param_get_stern_left_mid_pwm(msg);
    gcs_set_servo_param->offset_rudder = mavlink_msg_gcs_set_servo_param_get_offset_rudder(msg);
    gcs_set_servo_param->offset_stern = mavlink_msg_gcs_set_servo_param_get_offset_stern(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN;
        memset(gcs_set_servo_param, 0, MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_LEN);
    memcpy(gcs_set_servo_param, _MAV_PAYLOAD(msg), len);
#endif
}
