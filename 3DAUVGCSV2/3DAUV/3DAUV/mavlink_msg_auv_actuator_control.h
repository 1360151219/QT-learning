#pragma once
// MESSAGE AUV_ACTUATOR_CONTROL PACKING

#define MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL 153

MAVPACKED(
typedef struct __mavlink_auv_actuator_control_t {
 int16_t propeller_pwm; /*< [us] The pulse width of control propeller*/
 int16_t stern_up; /*< [degE1] The angle of this rudder*/
 int16_t stern_down; /*< [degE1] The angle of this rudder*/
 int16_t stern_right; /*< [degE1] The angle of this rudder*/
 int16_t stern_left; /*< [degE1] The angle of this rudder*/
}) mavlink_auv_actuator_control_t;

#define MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN 10
#define MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN 10
#define MAVLINK_MSG_ID_153_LEN 10
#define MAVLINK_MSG_ID_153_MIN_LEN 10

#define MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC 34
#define MAVLINK_MSG_ID_153_CRC 34



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_ACTUATOR_CONTROL { \
    153, \
    "AUV_ACTUATOR_CONTROL", \
    5, \
    {  { "propeller_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_auv_actuator_control_t, propeller_pwm) }, \
         { "stern_up", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_auv_actuator_control_t, stern_up) }, \
         { "stern_down", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_auv_actuator_control_t, stern_down) }, \
         { "stern_right", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_auv_actuator_control_t, stern_right) }, \
         { "stern_left", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_auv_actuator_control_t, stern_left) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_ACTUATOR_CONTROL { \
    "AUV_ACTUATOR_CONTROL", \
    5, \
    {  { "propeller_pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_auv_actuator_control_t, propeller_pwm) }, \
         { "stern_up", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_auv_actuator_control_t, stern_up) }, \
         { "stern_down", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_auv_actuator_control_t, stern_down) }, \
         { "stern_right", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_auv_actuator_control_t, stern_right) }, \
         { "stern_left", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_auv_actuator_control_t, stern_left) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_actuator_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param stern_up [degE1] The angle of this rudder
 * @param stern_down [degE1] The angle of this rudder
 * @param stern_right [degE1] The angle of this rudder
 * @param stern_left [degE1] The angle of this rudder
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_actuator_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t propeller_pwm, int16_t stern_up, int16_t stern_down, int16_t stern_right, int16_t stern_left)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, propeller_pwm);
    _mav_put_int16_t(buf, 2, stern_up);
    _mav_put_int16_t(buf, 4, stern_down);
    _mav_put_int16_t(buf, 6, stern_right);
    _mav_put_int16_t(buf, 8, stern_left);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN);
#else
    mavlink_auv_actuator_control_t packet;
    packet.propeller_pwm = propeller_pwm;
    packet.stern_up = stern_up;
    packet.stern_down = stern_down;
    packet.stern_right = stern_right;
    packet.stern_left = stern_left;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
}

/**
 * @brief Pack a auv_actuator_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param stern_up [degE1] The angle of this rudder
 * @param stern_down [degE1] The angle of this rudder
 * @param stern_right [degE1] The angle of this rudder
 * @param stern_left [degE1] The angle of this rudder
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_actuator_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t propeller_pwm,int16_t stern_up,int16_t stern_down,int16_t stern_right,int16_t stern_left)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, propeller_pwm);
    _mav_put_int16_t(buf, 2, stern_up);
    _mav_put_int16_t(buf, 4, stern_down);
    _mav_put_int16_t(buf, 6, stern_right);
    _mav_put_int16_t(buf, 8, stern_left);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN);
#else
    mavlink_auv_actuator_control_t packet;
    packet.propeller_pwm = propeller_pwm;
    packet.stern_up = stern_up;
    packet.stern_down = stern_down;
    packet.stern_right = stern_right;
    packet.stern_left = stern_left;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
}

/**
 * @brief Encode a auv_actuator_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_actuator_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_actuator_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_actuator_control_t* auv_actuator_control)
{
    return mavlink_msg_auv_actuator_control_pack(system_id, component_id, msg, auv_actuator_control->propeller_pwm, auv_actuator_control->stern_up, auv_actuator_control->stern_down, auv_actuator_control->stern_right, auv_actuator_control->stern_left);
}

/**
 * @brief Encode a auv_actuator_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_actuator_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_actuator_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_actuator_control_t* auv_actuator_control)
{
    return mavlink_msg_auv_actuator_control_pack_chan(system_id, component_id, chan, msg, auv_actuator_control->propeller_pwm, auv_actuator_control->stern_up, auv_actuator_control->stern_down, auv_actuator_control->stern_right, auv_actuator_control->stern_left);
}

/**
 * @brief Send a auv_actuator_control message
 * @param chan MAVLink channel to send the message
 *
 * @param propeller_pwm [us] The pulse width of control propeller
 * @param stern_up [degE1] The angle of this rudder
 * @param stern_down [degE1] The angle of this rudder
 * @param stern_right [degE1] The angle of this rudder
 * @param stern_left [degE1] The angle of this rudder
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_actuator_control_send(mavlink_channel_t chan, int16_t propeller_pwm, int16_t stern_up, int16_t stern_down, int16_t stern_right, int16_t stern_left)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN];
    _mav_put_int16_t(buf, 0, propeller_pwm);
    _mav_put_int16_t(buf, 2, stern_up);
    _mav_put_int16_t(buf, 4, stern_down);
    _mav_put_int16_t(buf, 6, stern_right);
    _mav_put_int16_t(buf, 8, stern_left);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL, buf, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
#else
    mavlink_auv_actuator_control_t packet;
    packet.propeller_pwm = propeller_pwm;
    packet.stern_up = stern_up;
    packet.stern_down = stern_down;
    packet.stern_right = stern_right;
    packet.stern_left = stern_left;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
#endif
}

/**
 * @brief Send a auv_actuator_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_actuator_control_send_struct(mavlink_channel_t chan, const mavlink_auv_actuator_control_t* auv_actuator_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_actuator_control_send(chan, auv_actuator_control->propeller_pwm, auv_actuator_control->stern_up, auv_actuator_control->stern_down, auv_actuator_control->stern_right, auv_actuator_control->stern_left);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL, (const char *)auv_actuator_control, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_actuator_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t propeller_pwm, int16_t stern_up, int16_t stern_down, int16_t stern_right, int16_t stern_left)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, propeller_pwm);
    _mav_put_int16_t(buf, 2, stern_up);
    _mav_put_int16_t(buf, 4, stern_down);
    _mav_put_int16_t(buf, 6, stern_right);
    _mav_put_int16_t(buf, 8, stern_left);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL, buf, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
#else
    mavlink_auv_actuator_control_t *packet = (mavlink_auv_actuator_control_t *)msgbuf;
    packet->propeller_pwm = propeller_pwm;
    packet->stern_up = stern_up;
    packet->stern_down = stern_down;
    packet->stern_right = stern_right;
    packet->stern_left = stern_left;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL, (const char *)packet, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_ACTUATOR_CONTROL UNPACKING


/**
 * @brief Get field propeller_pwm from auv_actuator_control message
 *
 * @return [us] The pulse width of control propeller
 */
static inline int16_t mavlink_msg_auv_actuator_control_get_propeller_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field stern_up from auv_actuator_control message
 *
 * @return [degE1] The angle of this rudder
 */
static inline int16_t mavlink_msg_auv_actuator_control_get_stern_up(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field stern_down from auv_actuator_control message
 *
 * @return [degE1] The angle of this rudder
 */
static inline int16_t mavlink_msg_auv_actuator_control_get_stern_down(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field stern_right from auv_actuator_control message
 *
 * @return [degE1] The angle of this rudder
 */
static inline int16_t mavlink_msg_auv_actuator_control_get_stern_right(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field stern_left from auv_actuator_control message
 *
 * @return [degE1] The angle of this rudder
 */
static inline int16_t mavlink_msg_auv_actuator_control_get_stern_left(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a auv_actuator_control message into a struct
 *
 * @param msg The message to decode
 * @param auv_actuator_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_actuator_control_decode(const mavlink_message_t* msg, mavlink_auv_actuator_control_t* auv_actuator_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_actuator_control->propeller_pwm = mavlink_msg_auv_actuator_control_get_propeller_pwm(msg);
    auv_actuator_control->stern_up = mavlink_msg_auv_actuator_control_get_stern_up(msg);
    auv_actuator_control->stern_down = mavlink_msg_auv_actuator_control_get_stern_down(msg);
    auv_actuator_control->stern_right = mavlink_msg_auv_actuator_control_get_stern_right(msg);
    auv_actuator_control->stern_left = mavlink_msg_auv_actuator_control_get_stern_left(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN;
        memset(auv_actuator_control, 0, MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_LEN);
    memcpy(auv_actuator_control, _MAV_PAYLOAD(msg), len);
#endif
}
