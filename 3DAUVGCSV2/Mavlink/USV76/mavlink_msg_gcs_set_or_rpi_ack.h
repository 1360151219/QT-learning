#pragma once
// MESSAGE GCS_SET_OR_RPI_ACK PACKING

#define MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK 155

MAVPACKED(
typedef struct __mavlink_gcs_set_or_rpi_ack_t {
 uint16_t content; /*<  */
 uint8_t type; /*<  */
}) mavlink_gcs_set_or_rpi_ack_t;

#define MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN 3
#define MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN 3
#define MAVLINK_MSG_ID_155_LEN 3
#define MAVLINK_MSG_ID_155_MIN_LEN 3

#define MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC 205
#define MAVLINK_MSG_ID_155_CRC 205



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_OR_RPI_ACK { \
    155, \
    "GCS_SET_OR_RPI_ACK", \
    2, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_gcs_set_or_rpi_ack_t, type) }, \
         { "content", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_gcs_set_or_rpi_ack_t, content) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_OR_RPI_ACK { \
    "GCS_SET_OR_RPI_ACK", \
    2, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_gcs_set_or_rpi_ack_t, type) }, \
         { "content", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_gcs_set_or_rpi_ack_t, content) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_or_rpi_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  
 * @param content  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_or_rpi_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint16_t content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN];
    _mav_put_uint16_t(buf, 0, content);
    _mav_put_uint8_t(buf, 2, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN);
#else
    mavlink_gcs_set_or_rpi_ack_t packet;
    packet.content = content;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
}

/**
 * @brief Pack a gcs_set_or_rpi_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  
 * @param content  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_or_rpi_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint16_t content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN];
    _mav_put_uint16_t(buf, 0, content);
    _mav_put_uint8_t(buf, 2, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN);
#else
    mavlink_gcs_set_or_rpi_ack_t packet;
    packet.content = content;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
}

/**
 * @brief Encode a gcs_set_or_rpi_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_or_rpi_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_or_rpi_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_or_rpi_ack_t* gcs_set_or_rpi_ack)
{
    return mavlink_msg_gcs_set_or_rpi_ack_pack(system_id, component_id, msg, gcs_set_or_rpi_ack->type, gcs_set_or_rpi_ack->content);
}

/**
 * @brief Encode a gcs_set_or_rpi_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_or_rpi_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_or_rpi_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_or_rpi_ack_t* gcs_set_or_rpi_ack)
{
    return mavlink_msg_gcs_set_or_rpi_ack_pack_chan(system_id, component_id, chan, msg, gcs_set_or_rpi_ack->type, gcs_set_or_rpi_ack->content);
}

/**
 * @brief Send a gcs_set_or_rpi_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param type  
 * @param content  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_or_rpi_ack_send(mavlink_channel_t chan, uint8_t type, uint16_t content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN];
    _mav_put_uint16_t(buf, 0, content);
    _mav_put_uint8_t(buf, 2, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK, buf, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
#else
    mavlink_gcs_set_or_rpi_ack_t packet;
    packet.content = content;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
#endif
}

/**
 * @brief Send a gcs_set_or_rpi_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_or_rpi_ack_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_or_rpi_ack_t* gcs_set_or_rpi_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_or_rpi_ack_send(chan, gcs_set_or_rpi_ack->type, gcs_set_or_rpi_ack->content);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK, (const char *)gcs_set_or_rpi_ack, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_or_rpi_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint16_t content)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, content);
    _mav_put_uint8_t(buf, 2, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK, buf, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
#else
    mavlink_gcs_set_or_rpi_ack_t *packet = (mavlink_gcs_set_or_rpi_ack_t *)msgbuf;
    packet->content = content;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_OR_RPI_ACK UNPACKING


/**
 * @brief Get field type from gcs_set_or_rpi_ack message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_gcs_set_or_rpi_ack_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field content from gcs_set_or_rpi_ack message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_gcs_set_or_rpi_ack_get_content(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a gcs_set_or_rpi_ack message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_or_rpi_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_or_rpi_ack_decode(const mavlink_message_t* msg, mavlink_gcs_set_or_rpi_ack_t* gcs_set_or_rpi_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_or_rpi_ack->content = mavlink_msg_gcs_set_or_rpi_ack_get_content(msg);
    gcs_set_or_rpi_ack->type = mavlink_msg_gcs_set_or_rpi_ack_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN;
        memset(gcs_set_or_rpi_ack, 0, MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_LEN);
    memcpy(gcs_set_or_rpi_ack, _MAV_PAYLOAD(msg), len);
#endif
}
