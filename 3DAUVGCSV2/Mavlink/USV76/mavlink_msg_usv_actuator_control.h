#pragma once
// MESSAGE USV_ACTUATOR_CONTROL PACKING

#define MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL 152

MAVPACKED(
typedef struct __mavlink_usv_actuator_control_t {
 float rudder_angle; /*< [us] */
 int16_t propeller_pwm; /*< [us] The pulse width of control propeller*/
}) mavlink_usv_actuator_control_t;

#define MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN 6
#define MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN 6
#define MAVLINK_MSG_ID_152_LEN 6
#define MAVLINK_MSG_ID_152_MIN_LEN 6

#define MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC 122
#define MAVLINK_MSG_ID_152_CRC 122



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_ACTUATOR_CONTROL { \
    152, \
    "USV_ACTUATOR_CONTROL", \
    2, \
    {  { "propeller_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_usv_actuator_control_t, propeller_pwm) }, \
         { "rudder_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_actuator_control_t, rudder_angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_ACTUATOR_CONTROL { \
    "USV_ACTUATOR_CONTROL", \
    2, \
    {  { "propeller_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_usv_actuator_control_t, propeller_pwm) }, \
         { "rudder_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_actuator_control_t, rudder_angle) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_actuator_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param rudder_angle [us] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_actuator_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t propeller_pwm, float rudder_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN];
    _mav_put_float(buf, 0, rudder_angle);
    _mav_put_int16_t(buf, 4, propeller_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN);
#else
    mavlink_usv_actuator_control_t packet;
    packet.rudder_angle = rudder_angle;
    packet.propeller_pwm = propeller_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
}

/**
 * @brief Pack a usv_actuator_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param rudder_angle [us] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_actuator_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t propeller_pwm,float rudder_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN];
    _mav_put_float(buf, 0, rudder_angle);
    _mav_put_int16_t(buf, 4, propeller_pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN);
#else
    mavlink_usv_actuator_control_t packet;
    packet.rudder_angle = rudder_angle;
    packet.propeller_pwm = propeller_pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
}

/**
 * @brief Encode a usv_actuator_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_actuator_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_actuator_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_actuator_control_t* usv_actuator_control)
{
    return mavlink_msg_usv_actuator_control_pack(system_id, component_id, msg, usv_actuator_control->propeller_pwm, usv_actuator_control->rudder_angle);
}

/**
 * @brief Encode a usv_actuator_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_actuator_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_actuator_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_actuator_control_t* usv_actuator_control)
{
    return mavlink_msg_usv_actuator_control_pack_chan(system_id, component_id, chan, msg, usv_actuator_control->propeller_pwm, usv_actuator_control->rudder_angle);
}

/**
 * @brief Send a usv_actuator_control message
 * @param chan MAVLink channel to send the message
 *
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param rudder_angle [us] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_actuator_control_send(mavlink_channel_t chan, int16_t propeller_pwm, float rudder_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN];
    _mav_put_float(buf, 0, rudder_angle);
    _mav_put_int16_t(buf, 4, propeller_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL, buf, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
#else
    mavlink_usv_actuator_control_t packet;
    packet.rudder_angle = rudder_angle;
    packet.propeller_pwm = propeller_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
#endif
}

/**
 * @brief Send a usv_actuator_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_actuator_control_send_struct(mavlink_channel_t chan, const mavlink_usv_actuator_control_t* usv_actuator_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_actuator_control_send(chan, usv_actuator_control->propeller_pwm, usv_actuator_control->rudder_angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL, (const char *)usv_actuator_control, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_actuator_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t propeller_pwm, float rudder_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, rudder_angle);
    _mav_put_int16_t(buf, 4, propeller_pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL, buf, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
#else
    mavlink_usv_actuator_control_t *packet = (mavlink_usv_actuator_control_t *)msgbuf;
    packet->rudder_angle = rudder_angle;
    packet->propeller_pwm = propeller_pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL, (const char *)packet, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_ACTUATOR_CONTROL UNPACKING


/**
 * @brief Get field propeller_pwm from usv_actuator_control message
 *
 * @return [us] The pulse width of control propeller
 */
static inline int16_t mavlink_msg_usv_actuator_control_get_propeller_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field rudder_angle from usv_actuator_control message
 *
 * @return [us] 
 */
static inline float mavlink_msg_usv_actuator_control_get_rudder_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a usv_actuator_control message into a struct
 *
 * @param msg The message to decode
 * @param usv_actuator_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_actuator_control_decode(const mavlink_message_t* msg, mavlink_usv_actuator_control_t* usv_actuator_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_actuator_control->rudder_angle = mavlink_msg_usv_actuator_control_get_rudder_angle(msg);
    usv_actuator_control->propeller_pwm = mavlink_msg_usv_actuator_control_get_propeller_pwm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN;
        memset(usv_actuator_control, 0, MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_LEN);
    memcpy(usv_actuator_control, _MAV_PAYLOAD(msg), len);
#endif
}
