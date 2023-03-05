#pragma once
// MESSAGE USV_HEARTBEAT PACKING

#define MAVLINK_MSG_ID_USV_HEARTBEAT 150

MAVPACKED(
typedef struct __mavlink_usv_heartbeat_t {
 uint8_t mode; /*<  */
 uint8_t task_id; /*<  */
 uint8_t autoWorking; /*<  */
}) mavlink_usv_heartbeat_t;

#define MAVLINK_MSG_ID_USV_HEARTBEAT_LEN 3
#define MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN 3
#define MAVLINK_MSG_ID_150_LEN 3
#define MAVLINK_MSG_ID_150_MIN_LEN 3

#define MAVLINK_MSG_ID_USV_HEARTBEAT_CRC 41
#define MAVLINK_MSG_ID_150_CRC 41



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_HEARTBEAT { \
    150, \
    "USV_HEARTBEAT", \
    3, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_heartbeat_t, mode) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_heartbeat_t, task_id) }, \
         { "autoWorking", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_usv_heartbeat_t, autoWorking) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_HEARTBEAT { \
    "USV_HEARTBEAT", \
    3, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_heartbeat_t, mode) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_heartbeat_t, task_id) }, \
         { "autoWorking", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_usv_heartbeat_t, autoWorking) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mode, uint8_t task_id, uint8_t autoWorking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, task_id);
    _mav_put_uint8_t(buf, 2, autoWorking);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN);
#else
    mavlink_usv_heartbeat_t packet;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
}

/**
 * @brief Pack a usv_heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mode,uint8_t task_id,uint8_t autoWorking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, task_id);
    _mav_put_uint8_t(buf, 2, autoWorking);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN);
#else
    mavlink_usv_heartbeat_t packet;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
}

/**
 * @brief Encode a usv_heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_heartbeat_t* usv_heartbeat)
{
    return mavlink_msg_usv_heartbeat_pack(system_id, component_id, msg, usv_heartbeat->mode, usv_heartbeat->task_id, usv_heartbeat->autoWorking);
}

/**
 * @brief Encode a usv_heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_heartbeat_t* usv_heartbeat)
{
    return mavlink_msg_usv_heartbeat_pack_chan(system_id, component_id, chan, msg, usv_heartbeat->mode, usv_heartbeat->task_id, usv_heartbeat->autoWorking);
}

/**
 * @brief Send a usv_heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_heartbeat_send(mavlink_channel_t chan, uint8_t mode, uint8_t task_id, uint8_t autoWorking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_HEARTBEAT_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, task_id);
    _mav_put_uint8_t(buf, 2, autoWorking);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_HEARTBEAT, buf, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
#else
    mavlink_usv_heartbeat_t packet;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a usv_heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_usv_heartbeat_t* usv_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_heartbeat_send(chan, usv_heartbeat->mode, usv_heartbeat->task_id, usv_heartbeat->autoWorking);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_HEARTBEAT, (const char *)usv_heartbeat, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, uint8_t task_id, uint8_t autoWorking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, task_id);
    _mav_put_uint8_t(buf, 2, autoWorking);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_HEARTBEAT, buf, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
#else
    mavlink_usv_heartbeat_t *packet = (mavlink_usv_heartbeat_t *)msgbuf;
    packet->mode = mode;
    packet->task_id = task_id;
    packet->autoWorking = autoWorking;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN, MAVLINK_MSG_ID_USV_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_HEARTBEAT UNPACKING


/**
 * @brief Get field mode from usv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_usv_heartbeat_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field task_id from usv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_usv_heartbeat_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field autoWorking from usv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_usv_heartbeat_get_autoWorking(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a usv_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param usv_heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_heartbeat_decode(const mavlink_message_t* msg, mavlink_usv_heartbeat_t* usv_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_heartbeat->mode = mavlink_msg_usv_heartbeat_get_mode(msg);
    usv_heartbeat->task_id = mavlink_msg_usv_heartbeat_get_task_id(msg);
    usv_heartbeat->autoWorking = mavlink_msg_usv_heartbeat_get_autoWorking(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_USV_HEARTBEAT_LEN;
        memset(usv_heartbeat, 0, MAVLINK_MSG_ID_USV_HEARTBEAT_LEN);
    memcpy(usv_heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
