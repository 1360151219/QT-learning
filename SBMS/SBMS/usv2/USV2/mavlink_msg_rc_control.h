#pragma once
// MESSAGE RC_CONTROL PACKING

#define MAVLINK_MSG_ID_RC_CONTROL 154

MAVPACKED(
typedef struct __mavlink_rc_control_t {
 float RC_rudder_Angle; /*< */
 uint16_t RC_v_PWM; /*< */
}) mavlink_rc_control_t;

#define MAVLINK_MSG_ID_RC_CONTROL_LEN 6
#define MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN 6
#define MAVLINK_MSG_ID_154_LEN 6
#define MAVLINK_MSG_ID_154_MIN_LEN 6

#define MAVLINK_MSG_ID_RC_CONTROL_CRC 53
#define MAVLINK_MSG_ID_154_CRC 53



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RC_CONTROL { \
	154, \
	"RC_CONTROL", \
	2, \
	{  { "RC_rudder_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc_control_t, RC_rudder_Angle) }, \
         { "RC_v_PWM", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_rc_control_t, RC_v_PWM) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RC_CONTROL { \
	"RC_CONTROL", \
	2, \
	{  { "RC_rudder_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rc_control_t, RC_rudder_Angle) }, \
         { "RC_v_PWM", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_rc_control_t, RC_v_PWM) }, \
         } \
}
#endif

/**
 * @brief Pack a rc_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param RC_v_PWM 
 * @param RC_rudder_Angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t RC_v_PWM, float RC_rudder_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RC_CONTROL_LEN];
	_mav_put_float(buf, 0, RC_rudder_Angle);
	_mav_put_uint16_t(buf, 4, RC_v_PWM);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC_CONTROL_LEN);
#else
	mavlink_rc_control_t packet;
	packet.RC_rudder_Angle = RC_rudder_Angle;
	packet.RC_v_PWM = RC_v_PWM;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RC_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
}

/**
 * @brief Pack a rc_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param RC_v_PWM 
 * @param RC_rudder_Angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t RC_v_PWM,float RC_rudder_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RC_CONTROL_LEN];
	_mav_put_float(buf, 0, RC_rudder_Angle);
	_mav_put_uint16_t(buf, 4, RC_v_PWM);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC_CONTROL_LEN);
#else
	mavlink_rc_control_t packet;
	packet.RC_rudder_Angle = RC_rudder_Angle;
	packet.RC_v_PWM = RC_v_PWM;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RC_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
}

/**
 * @brief Encode a rc_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc_control_t* rc_control)
{
	return mavlink_msg_rc_control_pack(system_id, component_id, msg, rc_control->RC_v_PWM, rc_control->RC_rudder_Angle);
}

/**
 * @brief Encode a rc_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rc_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rc_control_t* rc_control)
{
	return mavlink_msg_rc_control_pack_chan(system_id, component_id, chan, msg, rc_control->RC_v_PWM, rc_control->RC_rudder_Angle);
}

/**
 * @brief Send a rc_control message
 * @param chan MAVLink channel to send the message
 *
 * @param RC_v_PWM 
 * @param RC_rudder_Angle 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rc_control_send(mavlink_channel_t chan, uint16_t RC_v_PWM, float RC_rudder_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RC_CONTROL_LEN];
	_mav_put_float(buf, 0, RC_rudder_Angle);
	_mav_put_uint16_t(buf, 4, RC_v_PWM);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CONTROL, buf, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
#else
	mavlink_rc_control_t packet;
	packet.RC_rudder_Angle = RC_rudder_Angle;
	packet.RC_v_PWM = RC_v_PWM;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
#endif
}

/**
 * @brief Send a rc_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rc_control_send_struct(mavlink_channel_t chan, const mavlink_rc_control_t* rc_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rc_control_send(chan, rc_control->RC_v_PWM, rc_control->RC_rudder_Angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CONTROL, (const char *)rc_control, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_RC_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rc_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t RC_v_PWM, float RC_rudder_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, RC_rudder_Angle);
	_mav_put_uint16_t(buf, 4, RC_v_PWM);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CONTROL, buf, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
#else
	mavlink_rc_control_t *packet = (mavlink_rc_control_t *)msgbuf;
	packet->RC_rudder_Angle = RC_rudder_Angle;
	packet->RC_v_PWM = RC_v_PWM;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CONTROL, (const char *)packet, MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN, MAVLINK_MSG_ID_RC_CONTROL_LEN, MAVLINK_MSG_ID_RC_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE RC_CONTROL UNPACKING


/**
 * @brief Get field RC_v_PWM from rc_control message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_rc_control_get_RC_v_PWM(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field RC_rudder_Angle from rc_control message
 *
 * @return 
 */
static inline float mavlink_msg_rc_control_get_RC_rudder_Angle(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a rc_control message into a struct
 *
 * @param msg The message to decode
 * @param rc_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_rc_control_decode(const mavlink_message_t* msg, mavlink_rc_control_t* rc_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	rc_control->RC_rudder_Angle = mavlink_msg_rc_control_get_RC_rudder_Angle(msg);
	rc_control->RC_v_PWM = mavlink_msg_rc_control_get_RC_v_PWM(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RC_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_RC_CONTROL_LEN;
        memset(rc_control, 0, MAVLINK_MSG_ID_RC_CONTROL_LEN);
	memcpy(rc_control, _MAV_PAYLOAD(msg), len);
#endif
}
