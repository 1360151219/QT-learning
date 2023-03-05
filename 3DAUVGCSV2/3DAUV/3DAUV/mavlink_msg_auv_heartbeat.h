#pragma once
// MESSAGE AUV_HEARTBEAT PACKING

#define MAVLINK_MSG_ID_AUV_HEARTBEAT 150

MAVPACKED(
typedef struct __mavlink_auv_heartbeat_t {
 float voltage; /*<  */
 uint8_t mode; /*<  */
 uint8_t task_id; /*<  */
 uint8_t autoWorking; /*<  */
 uint8_t leak; /*<  */
 uint8_t humi; /*<  */
 uint8_t temp; /*<  */
}) mavlink_auv_heartbeat_t;

#define MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN 10
#define MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN 10
#define MAVLINK_MSG_ID_150_LEN 10
#define MAVLINK_MSG_ID_150_MIN_LEN 10

#define MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC 8
#define MAVLINK_MSG_ID_150_CRC 8



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_HEARTBEAT { \
    150, \
    "AUV_HEARTBEAT", \
    7, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_auv_heartbeat_t, mode) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_auv_heartbeat_t, task_id) }, \
         { "autoWorking", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_auv_heartbeat_t, autoWorking) }, \
         { "leak", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_auv_heartbeat_t, leak) }, \
         { "humi", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_auv_heartbeat_t, humi) }, \
         { "temp", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_auv_heartbeat_t, temp) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_heartbeat_t, voltage) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_HEARTBEAT { \
    "AUV_HEARTBEAT", \
    7, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_auv_heartbeat_t, mode) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_auv_heartbeat_t, task_id) }, \
         { "autoWorking", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_auv_heartbeat_t, autoWorking) }, \
         { "leak", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_auv_heartbeat_t, leak) }, \
         { "humi", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_auv_heartbeat_t, humi) }, \
         { "temp", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_auv_heartbeat_t, temp) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_heartbeat_t, voltage) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 * @param leak  
 * @param humi  
 * @param temp  
 * @param voltage  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mode, uint8_t task_id, uint8_t autoWorking, uint8_t leak, uint8_t humi, uint8_t temp, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_uint8_t(buf, 4, mode);
    _mav_put_uint8_t(buf, 5, task_id);
    _mav_put_uint8_t(buf, 6, autoWorking);
    _mav_put_uint8_t(buf, 7, leak);
    _mav_put_uint8_t(buf, 8, humi);
    _mav_put_uint8_t(buf, 9, temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN);
#else
    mavlink_auv_heartbeat_t packet;
    packet.voltage = voltage;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;
    packet.leak = leak;
    packet.humi = humi;
    packet.temp = temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
}

/**
 * @brief Pack a auv_heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 * @param leak  
 * @param humi  
 * @param temp  
 * @param voltage  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mode,uint8_t task_id,uint8_t autoWorking,uint8_t leak,uint8_t humi,uint8_t temp,float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_uint8_t(buf, 4, mode);
    _mav_put_uint8_t(buf, 5, task_id);
    _mav_put_uint8_t(buf, 6, autoWorking);
    _mav_put_uint8_t(buf, 7, leak);
    _mav_put_uint8_t(buf, 8, humi);
    _mav_put_uint8_t(buf, 9, temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN);
#else
    mavlink_auv_heartbeat_t packet;
    packet.voltage = voltage;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;
    packet.leak = leak;
    packet.humi = humi;
    packet.temp = temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
}

/**
 * @brief Encode a auv_heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_heartbeat_t* auv_heartbeat)
{
    return mavlink_msg_auv_heartbeat_pack(system_id, component_id, msg, auv_heartbeat->mode, auv_heartbeat->task_id, auv_heartbeat->autoWorking, auv_heartbeat->leak, auv_heartbeat->humi, auv_heartbeat->temp, auv_heartbeat->voltage);
}

/**
 * @brief Encode a auv_heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_heartbeat_t* auv_heartbeat)
{
    return mavlink_msg_auv_heartbeat_pack_chan(system_id, component_id, chan, msg, auv_heartbeat->mode, auv_heartbeat->task_id, auv_heartbeat->autoWorking, auv_heartbeat->leak, auv_heartbeat->humi, auv_heartbeat->temp, auv_heartbeat->voltage);
}

/**
 * @brief Send a auv_heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param mode  
 * @param task_id  
 * @param autoWorking  
 * @param leak  
 * @param humi  
 * @param temp  
 * @param voltage  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_heartbeat_send(mavlink_channel_t chan, uint8_t mode, uint8_t task_id, uint8_t autoWorking, uint8_t leak, uint8_t humi, uint8_t temp, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_uint8_t(buf, 4, mode);
    _mav_put_uint8_t(buf, 5, task_id);
    _mav_put_uint8_t(buf, 6, autoWorking);
    _mav_put_uint8_t(buf, 7, leak);
    _mav_put_uint8_t(buf, 8, humi);
    _mav_put_uint8_t(buf, 9, temp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_HEARTBEAT, buf, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
#else
    mavlink_auv_heartbeat_t packet;
    packet.voltage = voltage;
    packet.mode = mode;
    packet.task_id = task_id;
    packet.autoWorking = autoWorking;
    packet.leak = leak;
    packet.humi = humi;
    packet.temp = temp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a auv_heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_auv_heartbeat_t* auv_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_heartbeat_send(chan, auv_heartbeat->mode, auv_heartbeat->task_id, auv_heartbeat->autoWorking, auv_heartbeat->leak, auv_heartbeat->humi, auv_heartbeat->temp, auv_heartbeat->voltage);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_HEARTBEAT, (const char *)auv_heartbeat, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, uint8_t task_id, uint8_t autoWorking, uint8_t leak, uint8_t humi, uint8_t temp, float voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, voltage);
    _mav_put_uint8_t(buf, 4, mode);
    _mav_put_uint8_t(buf, 5, task_id);
    _mav_put_uint8_t(buf, 6, autoWorking);
    _mav_put_uint8_t(buf, 7, leak);
    _mav_put_uint8_t(buf, 8, humi);
    _mav_put_uint8_t(buf, 9, temp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_HEARTBEAT, buf, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
#else
    mavlink_auv_heartbeat_t *packet = (mavlink_auv_heartbeat_t *)msgbuf;
    packet->voltage = voltage;
    packet->mode = mode;
    packet->task_id = task_id;
    packet->autoWorking = autoWorking;
    packet->leak = leak;
    packet->humi = humi;
    packet->temp = temp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN, MAVLINK_MSG_ID_AUV_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_HEARTBEAT UNPACKING


/**
 * @brief Get field mode from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field task_id from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field autoWorking from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_autoWorking(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field leak from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_leak(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field humi from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_humi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field temp from auv_heartbeat message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_heartbeat_get_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field voltage from auv_heartbeat message
 *
 * @return  
 */
static inline float mavlink_msg_auv_heartbeat_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a auv_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param auv_heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_heartbeat_decode(const mavlink_message_t* msg, mavlink_auv_heartbeat_t* auv_heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_heartbeat->voltage = mavlink_msg_auv_heartbeat_get_voltage(msg);
    auv_heartbeat->mode = mavlink_msg_auv_heartbeat_get_mode(msg);
    auv_heartbeat->task_id = mavlink_msg_auv_heartbeat_get_task_id(msg);
    auv_heartbeat->autoWorking = mavlink_msg_auv_heartbeat_get_autoWorking(msg);
    auv_heartbeat->leak = mavlink_msg_auv_heartbeat_get_leak(msg);
    auv_heartbeat->humi = mavlink_msg_auv_heartbeat_get_humi(msg);
    auv_heartbeat->temp = mavlink_msg_auv_heartbeat_get_temp(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN;
        memset(auv_heartbeat, 0, MAVLINK_MSG_ID_AUV_HEARTBEAT_LEN);
    memcpy(auv_heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
