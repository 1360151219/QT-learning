#pragma once
// MESSAGE AUV_ARM_WIRELESS_FEED PACKING

#define MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED 163

MAVPACKED(
typedef struct __mavlink_auv_arm_wireless_feed_t {
 uint16_t joint1Pos; /*<  */
 uint16_t joint2Pos; /*<  */
 uint16_t joint3Pos; /*<  */
 uint16_t joint4Pos; /*<  */
}) mavlink_auv_arm_wireless_feed_t;

#define MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN 8
#define MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN 8
#define MAVLINK_MSG_ID_163_LEN 8
#define MAVLINK_MSG_ID_163_MIN_LEN 8

#define MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC 165
#define MAVLINK_MSG_ID_163_CRC 165



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_ARM_WIRELESS_FEED { \
    163, \
    "AUV_ARM_WIRELESS_FEED", \
    4, \
    {  { "joint1Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_auv_arm_wireless_feed_t, joint1Pos) }, \
         { "joint2Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_auv_arm_wireless_feed_t, joint2Pos) }, \
         { "joint3Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_auv_arm_wireless_feed_t, joint3Pos) }, \
         { "joint4Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_auv_arm_wireless_feed_t, joint4Pos) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_ARM_WIRELESS_FEED { \
    "AUV_ARM_WIRELESS_FEED", \
    4, \
    {  { "joint1Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_auv_arm_wireless_feed_t, joint1Pos) }, \
         { "joint2Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_auv_arm_wireless_feed_t, joint2Pos) }, \
         { "joint3Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_auv_arm_wireless_feed_t, joint3Pos) }, \
         { "joint4Pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_auv_arm_wireless_feed_t, joint4Pos) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_arm_wireless_feed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param joint1Pos  
 * @param joint2Pos  
 * @param joint3Pos  
 * @param joint4Pos  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t joint1Pos, uint16_t joint2Pos, uint16_t joint3Pos, uint16_t joint4Pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN];
    _mav_put_uint16_t(buf, 0, joint1Pos);
    _mav_put_uint16_t(buf, 2, joint2Pos);
    _mav_put_uint16_t(buf, 4, joint3Pos);
    _mav_put_uint16_t(buf, 6, joint4Pos);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN);
#else
    mavlink_auv_arm_wireless_feed_t packet;
    packet.joint1Pos = joint1Pos;
    packet.joint2Pos = joint2Pos;
    packet.joint3Pos = joint3Pos;
    packet.joint4Pos = joint4Pos;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
}

/**
 * @brief Pack a auv_arm_wireless_feed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param joint1Pos  
 * @param joint2Pos  
 * @param joint3Pos  
 * @param joint4Pos  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t joint1Pos,uint16_t joint2Pos,uint16_t joint3Pos,uint16_t joint4Pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN];
    _mav_put_uint16_t(buf, 0, joint1Pos);
    _mav_put_uint16_t(buf, 2, joint2Pos);
    _mav_put_uint16_t(buf, 4, joint3Pos);
    _mav_put_uint16_t(buf, 6, joint4Pos);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN);
#else
    mavlink_auv_arm_wireless_feed_t packet;
    packet.joint1Pos = joint1Pos;
    packet.joint2Pos = joint2Pos;
    packet.joint3Pos = joint3Pos;
    packet.joint4Pos = joint4Pos;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
}

/**
 * @brief Encode a auv_arm_wireless_feed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_arm_wireless_feed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_arm_wireless_feed_t* auv_arm_wireless_feed)
{
    return mavlink_msg_auv_arm_wireless_feed_pack(system_id, component_id, msg, auv_arm_wireless_feed->joint1Pos, auv_arm_wireless_feed->joint2Pos, auv_arm_wireless_feed->joint3Pos, auv_arm_wireless_feed->joint4Pos);
}

/**
 * @brief Encode a auv_arm_wireless_feed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_arm_wireless_feed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_arm_wireless_feed_t* auv_arm_wireless_feed)
{
    return mavlink_msg_auv_arm_wireless_feed_pack_chan(system_id, component_id, chan, msg, auv_arm_wireless_feed->joint1Pos, auv_arm_wireless_feed->joint2Pos, auv_arm_wireless_feed->joint3Pos, auv_arm_wireless_feed->joint4Pos);
}

/**
 * @brief Send a auv_arm_wireless_feed message
 * @param chan MAVLink channel to send the message
 *
 * @param joint1Pos  
 * @param joint2Pos  
 * @param joint3Pos  
 * @param joint4Pos  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_arm_wireless_feed_send(mavlink_channel_t chan, uint16_t joint1Pos, uint16_t joint2Pos, uint16_t joint3Pos, uint16_t joint4Pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN];
    _mav_put_uint16_t(buf, 0, joint1Pos);
    _mav_put_uint16_t(buf, 2, joint2Pos);
    _mav_put_uint16_t(buf, 4, joint3Pos);
    _mav_put_uint16_t(buf, 6, joint4Pos);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED, buf, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
#else
    mavlink_auv_arm_wireless_feed_t packet;
    packet.joint1Pos = joint1Pos;
    packet.joint2Pos = joint2Pos;
    packet.joint3Pos = joint3Pos;
    packet.joint4Pos = joint4Pos;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED, (const char *)&packet, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
#endif
}

/**
 * @brief Send a auv_arm_wireless_feed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_arm_wireless_feed_send_struct(mavlink_channel_t chan, const mavlink_auv_arm_wireless_feed_t* auv_arm_wireless_feed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_arm_wireless_feed_send(chan, auv_arm_wireless_feed->joint1Pos, auv_arm_wireless_feed->joint2Pos, auv_arm_wireless_feed->joint3Pos, auv_arm_wireless_feed->joint4Pos);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED, (const char *)auv_arm_wireless_feed, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_arm_wireless_feed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t joint1Pos, uint16_t joint2Pos, uint16_t joint3Pos, uint16_t joint4Pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, joint1Pos);
    _mav_put_uint16_t(buf, 2, joint2Pos);
    _mav_put_uint16_t(buf, 4, joint3Pos);
    _mav_put_uint16_t(buf, 6, joint4Pos);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED, buf, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
#else
    mavlink_auv_arm_wireless_feed_t *packet = (mavlink_auv_arm_wireless_feed_t *)msgbuf;
    packet->joint1Pos = joint1Pos;
    packet->joint2Pos = joint2Pos;
    packet->joint3Pos = joint3Pos;
    packet->joint4Pos = joint4Pos;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED, (const char *)packet, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_ARM_WIRELESS_FEED UNPACKING


/**
 * @brief Get field joint1Pos from auv_arm_wireless_feed message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_get_joint1Pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field joint2Pos from auv_arm_wireless_feed message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_get_joint2Pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field joint3Pos from auv_arm_wireless_feed message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_get_joint3Pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field joint4Pos from auv_arm_wireless_feed message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_auv_arm_wireless_feed_get_joint4Pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a auv_arm_wireless_feed message into a struct
 *
 * @param msg The message to decode
 * @param auv_arm_wireless_feed C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_arm_wireless_feed_decode(const mavlink_message_t* msg, mavlink_auv_arm_wireless_feed_t* auv_arm_wireless_feed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_arm_wireless_feed->joint1Pos = mavlink_msg_auv_arm_wireless_feed_get_joint1Pos(msg);
    auv_arm_wireless_feed->joint2Pos = mavlink_msg_auv_arm_wireless_feed_get_joint2Pos(msg);
    auv_arm_wireless_feed->joint3Pos = mavlink_msg_auv_arm_wireless_feed_get_joint3Pos(msg);
    auv_arm_wireless_feed->joint4Pos = mavlink_msg_auv_arm_wireless_feed_get_joint4Pos(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN? msg->len : MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN;
        memset(auv_arm_wireless_feed, 0, MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_LEN);
    memcpy(auv_arm_wireless_feed, _MAV_PAYLOAD(msg), len);
#endif
}
