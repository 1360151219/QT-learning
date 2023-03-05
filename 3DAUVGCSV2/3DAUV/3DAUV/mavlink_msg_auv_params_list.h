#pragma once
// MESSAGE AUV_PARAMS_LIST PACKING

#define MAVLINK_MSG_ID_AUV_PARAMS_LIST 167

MAVPACKED(
typedef struct __mavlink_auv_params_list_t {
 float param; /*<  */
 uint8_t index; /*<  */
}) mavlink_auv_params_list_t;

#define MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN 5
#define MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN 5
#define MAVLINK_MSG_ID_167_LEN 5
#define MAVLINK_MSG_ID_167_MIN_LEN 5

#define MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC 229
#define MAVLINK_MSG_ID_167_CRC 229



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_PARAMS_LIST { \
    167, \
    "AUV_PARAMS_LIST", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_auv_params_list_t, index) }, \
         { "param", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_params_list_t, param) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_PARAMS_LIST { \
    "AUV_PARAMS_LIST", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_auv_params_list_t, index) }, \
         { "param", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_params_list_t, param) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_params_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  
 * @param param  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_params_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, float param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN];
    _mav_put_float(buf, 0, param);
    _mav_put_uint8_t(buf, 4, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN);
#else
    mavlink_auv_params_list_t packet;
    packet.param = param;
    packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_PARAMS_LIST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
}

/**
 * @brief Pack a auv_params_list message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  
 * @param param  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_params_list_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,float param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN];
    _mav_put_float(buf, 0, param);
    _mav_put_uint8_t(buf, 4, index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN);
#else
    mavlink_auv_params_list_t packet;
    packet.param = param;
    packet.index = index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_PARAMS_LIST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
}

/**
 * @brief Encode a auv_params_list struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_params_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_params_list_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_params_list_t* auv_params_list)
{
    return mavlink_msg_auv_params_list_pack(system_id, component_id, msg, auv_params_list->index, auv_params_list->param);
}

/**
 * @brief Encode a auv_params_list struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_params_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_params_list_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_params_list_t* auv_params_list)
{
    return mavlink_msg_auv_params_list_pack_chan(system_id, component_id, chan, msg, auv_params_list->index, auv_params_list->param);
}

/**
 * @brief Send a auv_params_list message
 * @param chan MAVLink channel to send the message
 *
 * @param index  
 * @param param  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_params_list_send(mavlink_channel_t chan, uint8_t index, float param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN];
    _mav_put_float(buf, 0, param);
    _mav_put_uint8_t(buf, 4, index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST, buf, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
#else
    mavlink_auv_params_list_t packet;
    packet.param = param;
    packet.index = index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST, (const char *)&packet, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
#endif
}

/**
 * @brief Send a auv_params_list message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_params_list_send_struct(mavlink_channel_t chan, const mavlink_auv_params_list_t* auv_params_list)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_params_list_send(chan, auv_params_list->index, auv_params_list->param);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST, (const char *)auv_params_list, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_params_list_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, float param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param);
    _mav_put_uint8_t(buf, 4, index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST, buf, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
#else
    mavlink_auv_params_list_t *packet = (mavlink_auv_params_list_t *)msgbuf;
    packet->param = param;
    packet->index = index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_PARAMS_LIST, (const char *)packet, MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN, MAVLINK_MSG_ID_AUV_PARAMS_LIST_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_PARAMS_LIST UNPACKING


/**
 * @brief Get field index from auv_params_list message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_auv_params_list_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field param from auv_params_list message
 *
 * @return  
 */
static inline float mavlink_msg_auv_params_list_get_param(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a auv_params_list message into a struct
 *
 * @param msg The message to decode
 * @param auv_params_list C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_params_list_decode(const mavlink_message_t* msg, mavlink_auv_params_list_t* auv_params_list)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_params_list->param = mavlink_msg_auv_params_list_get_param(msg);
    auv_params_list->index = mavlink_msg_auv_params_list_get_index(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN? msg->len : MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN;
        memset(auv_params_list, 0, MAVLINK_MSG_ID_AUV_PARAMS_LIST_LEN);
    memcpy(auv_params_list, _MAV_PAYLOAD(msg), len);
#endif
}
