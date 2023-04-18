#pragma once
// MESSAGE VISUAL_SETTING PACKING

#define MAVLINK_MSG_ID_VISUAL_SETTING 158

MAVPACKED(
typedef struct __mavlink_visual_setting_t {
 uint8_t visual_test; /*< */
 uint8_t isLinear; /*< */
 uint8_t filter_type; /*< */
}) mavlink_visual_setting_t;

#define MAVLINK_MSG_ID_VISUAL_SETTING_LEN 3
#define MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN 3
#define MAVLINK_MSG_ID_158_LEN 3
#define MAVLINK_MSG_ID_158_MIN_LEN 3

#define MAVLINK_MSG_ID_VISUAL_SETTING_CRC 164
#define MAVLINK_MSG_ID_158_CRC 164



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VISUAL_SETTING { \
	158, \
	"VISUAL_SETTING", \
	3, \
	{  { "visual_test", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_visual_setting_t, visual_test) }, \
         { "isLinear", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_visual_setting_t, isLinear) }, \
         { "filter_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_visual_setting_t, filter_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VISUAL_SETTING { \
	"VISUAL_SETTING", \
	3, \
	{  { "visual_test", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_visual_setting_t, visual_test) }, \
         { "isLinear", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_visual_setting_t, isLinear) }, \
         { "filter_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_visual_setting_t, filter_type) }, \
         } \
}
#endif

/**
 * @brief Pack a visual_setting message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param visual_test 
 * @param isLinear 
 * @param filter_type 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_visual_setting_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t visual_test, uint8_t isLinear, uint8_t filter_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VISUAL_SETTING_LEN];
	_mav_put_uint8_t(buf, 0, visual_test);
	_mav_put_uint8_t(buf, 1, isLinear);
	_mav_put_uint8_t(buf, 2, filter_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VISUAL_SETTING_LEN);
#else
	mavlink_visual_setting_t packet;
	packet.visual_test = visual_test;
	packet.isLinear = isLinear;
	packet.filter_type = filter_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VISUAL_SETTING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VISUAL_SETTING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
}

/**
 * @brief Pack a visual_setting message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param visual_test 
 * @param isLinear 
 * @param filter_type 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_visual_setting_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t visual_test,uint8_t isLinear,uint8_t filter_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VISUAL_SETTING_LEN];
	_mav_put_uint8_t(buf, 0, visual_test);
	_mav_put_uint8_t(buf, 1, isLinear);
	_mav_put_uint8_t(buf, 2, filter_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VISUAL_SETTING_LEN);
#else
	mavlink_visual_setting_t packet;
	packet.visual_test = visual_test;
	packet.isLinear = isLinear;
	packet.filter_type = filter_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VISUAL_SETTING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VISUAL_SETTING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
}

/**
 * @brief Encode a visual_setting struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param visual_setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_visual_setting_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_visual_setting_t* visual_setting)
{
	return mavlink_msg_visual_setting_pack(system_id, component_id, msg, visual_setting->visual_test, visual_setting->isLinear, visual_setting->filter_type);
}

/**
 * @brief Encode a visual_setting struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param visual_setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_visual_setting_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_visual_setting_t* visual_setting)
{
	return mavlink_msg_visual_setting_pack_chan(system_id, component_id, chan, msg, visual_setting->visual_test, visual_setting->isLinear, visual_setting->filter_type);
}

/**
 * @brief Send a visual_setting message
 * @param chan MAVLink channel to send the message
 *
 * @param visual_test 
 * @param isLinear 
 * @param filter_type 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_visual_setting_send(mavlink_channel_t chan, uint8_t visual_test, uint8_t isLinear, uint8_t filter_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VISUAL_SETTING_LEN];
	_mav_put_uint8_t(buf, 0, visual_test);
	_mav_put_uint8_t(buf, 1, isLinear);
	_mav_put_uint8_t(buf, 2, filter_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VISUAL_SETTING, buf, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
#else
	mavlink_visual_setting_t packet;
	packet.visual_test = visual_test;
	packet.isLinear = isLinear;
	packet.filter_type = filter_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VISUAL_SETTING, (const char *)&packet, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
#endif
}

/**
 * @brief Send a visual_setting message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_visual_setting_send_struct(mavlink_channel_t chan, const mavlink_visual_setting_t* visual_setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_visual_setting_send(chan, visual_setting->visual_test, visual_setting->isLinear, visual_setting->filter_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VISUAL_SETTING, (const char *)visual_setting, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
#endif
}

#if MAVLINK_MSG_ID_VISUAL_SETTING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_visual_setting_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t visual_test, uint8_t isLinear, uint8_t filter_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, visual_test);
	_mav_put_uint8_t(buf, 1, isLinear);
	_mav_put_uint8_t(buf, 2, filter_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VISUAL_SETTING, buf, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
#else
	mavlink_visual_setting_t *packet = (mavlink_visual_setting_t *)msgbuf;
	packet->visual_test = visual_test;
	packet->isLinear = isLinear;
	packet->filter_type = filter_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VISUAL_SETTING, (const char *)packet, MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_LEN, MAVLINK_MSG_ID_VISUAL_SETTING_CRC);
#endif
}
#endif

#endif

// MESSAGE VISUAL_SETTING UNPACKING


/**
 * @brief Get field visual_test from visual_setting message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_visual_setting_get_visual_test(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field isLinear from visual_setting message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_visual_setting_get_isLinear(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field filter_type from visual_setting message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_visual_setting_get_filter_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a visual_setting message into a struct
 *
 * @param msg The message to decode
 * @param visual_setting C-struct to decode the message contents into
 */
static inline void mavlink_msg_visual_setting_decode(const mavlink_message_t* msg, mavlink_visual_setting_t* visual_setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	visual_setting->visual_test = mavlink_msg_visual_setting_get_visual_test(msg);
	visual_setting->isLinear = mavlink_msg_visual_setting_get_isLinear(msg);
	visual_setting->filter_type = mavlink_msg_visual_setting_get_filter_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VISUAL_SETTING_LEN? msg->len : MAVLINK_MSG_ID_VISUAL_SETTING_LEN;
        memset(visual_setting, 0, MAVLINK_MSG_ID_VISUAL_SETTING_LEN);
	memcpy(visual_setting, _MAV_PAYLOAD(msg), len);
#endif
}
