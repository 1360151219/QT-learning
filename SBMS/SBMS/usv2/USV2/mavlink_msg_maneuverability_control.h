#pragma once
// MESSAGE MANEUVERABILITY_CONTROL PACKING

#define MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL 156

MAVPACKED(
typedef struct __mavlink_maneuverability_control_t {
 float Z_FI; /*< */
 float Z_Z5; /*< */
 float huizhuan_Angle; /*< */
}) mavlink_maneuverability_control_t;

#define MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN 12
#define MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN 12
#define MAVLINK_MSG_ID_156_LEN 12
#define MAVLINK_MSG_ID_156_MIN_LEN 12

#define MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC 250
#define MAVLINK_MSG_ID_156_CRC 250



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MANEUVERABILITY_CONTROL { \
	156, \
	"MANEUVERABILITY_CONTROL", \
	3, \
	{  { "Z_FI", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_maneuverability_control_t, Z_FI) }, \
         { "Z_Z5", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_maneuverability_control_t, Z_Z5) }, \
         { "huizhuan_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_maneuverability_control_t, huizhuan_Angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MANEUVERABILITY_CONTROL { \
	"MANEUVERABILITY_CONTROL", \
	3, \
	{  { "Z_FI", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_maneuverability_control_t, Z_FI) }, \
         { "Z_Z5", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_maneuverability_control_t, Z_Z5) }, \
         { "huizhuan_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_maneuverability_control_t, huizhuan_Angle) }, \
         } \
}
#endif

/**
 * @brief Pack a maneuverability_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Z_FI 
 * @param Z_Z5 
 * @param huizhuan_Angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_maneuverability_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float Z_FI, float Z_Z5, float huizhuan_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN];
	_mav_put_float(buf, 0, Z_FI);
	_mav_put_float(buf, 4, Z_Z5);
	_mav_put_float(buf, 8, huizhuan_Angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN);
#else
	mavlink_maneuverability_control_t packet;
	packet.Z_FI = Z_FI;
	packet.Z_Z5 = Z_Z5;
	packet.huizhuan_Angle = huizhuan_Angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
}

/**
 * @brief Pack a maneuverability_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Z_FI 
 * @param Z_Z5 
 * @param huizhuan_Angle 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_maneuverability_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float Z_FI,float Z_Z5,float huizhuan_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN];
	_mav_put_float(buf, 0, Z_FI);
	_mav_put_float(buf, 4, Z_Z5);
	_mav_put_float(buf, 8, huizhuan_Angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN);
#else
	mavlink_maneuverability_control_t packet;
	packet.Z_FI = Z_FI;
	packet.Z_Z5 = Z_Z5;
	packet.huizhuan_Angle = huizhuan_Angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
}

/**
 * @brief Encode a maneuverability_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param maneuverability_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_maneuverability_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_maneuverability_control_t* maneuverability_control)
{
	return mavlink_msg_maneuverability_control_pack(system_id, component_id, msg, maneuverability_control->Z_FI, maneuverability_control->Z_Z5, maneuverability_control->huizhuan_Angle);
}

/**
 * @brief Encode a maneuverability_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param maneuverability_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_maneuverability_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_maneuverability_control_t* maneuverability_control)
{
	return mavlink_msg_maneuverability_control_pack_chan(system_id, component_id, chan, msg, maneuverability_control->Z_FI, maneuverability_control->Z_Z5, maneuverability_control->huizhuan_Angle);
}

/**
 * @brief Send a maneuverability_control message
 * @param chan MAVLink channel to send the message
 *
 * @param Z_FI 
 * @param Z_Z5 
 * @param huizhuan_Angle 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_maneuverability_control_send(mavlink_channel_t chan, float Z_FI, float Z_Z5, float huizhuan_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN];
	_mav_put_float(buf, 0, Z_FI);
	_mav_put_float(buf, 4, Z_Z5);
	_mav_put_float(buf, 8, huizhuan_Angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL, buf, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
#else
	mavlink_maneuverability_control_t packet;
	packet.Z_FI = Z_FI;
	packet.Z_Z5 = Z_Z5;
	packet.huizhuan_Angle = huizhuan_Angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
#endif
}

/**
 * @brief Send a maneuverability_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_maneuverability_control_send_struct(mavlink_channel_t chan, const mavlink_maneuverability_control_t* maneuverability_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_maneuverability_control_send(chan, maneuverability_control->Z_FI, maneuverability_control->Z_Z5, maneuverability_control->huizhuan_Angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL, (const char *)maneuverability_control, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_maneuverability_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float Z_FI, float Z_Z5, float huizhuan_Angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, Z_FI);
	_mav_put_float(buf, 4, Z_Z5);
	_mav_put_float(buf, 8, huizhuan_Angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL, buf, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
#else
	mavlink_maneuverability_control_t *packet = (mavlink_maneuverability_control_t *)msgbuf;
	packet->Z_FI = Z_FI;
	packet->Z_Z5 = Z_Z5;
	packet->huizhuan_Angle = huizhuan_Angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL, (const char *)packet, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE MANEUVERABILITY_CONTROL UNPACKING


/**
 * @brief Get field Z_FI from maneuverability_control message
 *
 * @return 
 */
static inline float mavlink_msg_maneuverability_control_get_Z_FI(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Z_Z5 from maneuverability_control message
 *
 * @return 
 */
static inline float mavlink_msg_maneuverability_control_get_Z_Z5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field huizhuan_Angle from maneuverability_control message
 *
 * @return 
 */
static inline float mavlink_msg_maneuverability_control_get_huizhuan_Angle(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a maneuverability_control message into a struct
 *
 * @param msg The message to decode
 * @param maneuverability_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_maneuverability_control_decode(const mavlink_message_t* msg, mavlink_maneuverability_control_t* maneuverability_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	maneuverability_control->Z_FI = mavlink_msg_maneuverability_control_get_Z_FI(msg);
	maneuverability_control->Z_Z5 = mavlink_msg_maneuverability_control_get_Z_Z5(msg);
	maneuverability_control->huizhuan_Angle = mavlink_msg_maneuverability_control_get_huizhuan_Angle(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN;
        memset(maneuverability_control, 0, MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_LEN);
	memcpy(maneuverability_control, _MAV_PAYLOAD(msg), len);
#endif
}
