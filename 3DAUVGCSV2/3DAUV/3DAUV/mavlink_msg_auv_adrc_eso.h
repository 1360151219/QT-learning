#pragma once
// MESSAGE AUV_ADRC_ESO PACKING

#define MAVLINK_MSG_ID_AUV_ADRC_ESO 161

MAVPACKED(
typedef struct __mavlink_auv_adrc_eso_t {
 float eso_pitch; /*<  */
 float eso_q; /*<  */
 float eso_z3; /*<  */
 float q; /*<  */
}) mavlink_auv_adrc_eso_t;

#define MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN 16
#define MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN 16
#define MAVLINK_MSG_ID_161_LEN 16
#define MAVLINK_MSG_ID_161_MIN_LEN 16

#define MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC 236
#define MAVLINK_MSG_ID_161_CRC 236



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_ADRC_ESO { \
    161, \
    "AUV_ADRC_ESO", \
    4, \
    {  { "eso_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_adrc_eso_t, eso_pitch) }, \
         { "eso_q", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_adrc_eso_t, eso_q) }, \
         { "eso_z3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_adrc_eso_t, eso_z3) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_adrc_eso_t, q) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_ADRC_ESO { \
    "AUV_ADRC_ESO", \
    4, \
    {  { "eso_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_adrc_eso_t, eso_pitch) }, \
         { "eso_q", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_adrc_eso_t, eso_q) }, \
         { "eso_z3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_adrc_eso_t, eso_z3) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_adrc_eso_t, q) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_adrc_eso message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param eso_pitch  
 * @param eso_q  
 * @param eso_z3  
 * @param q  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_adrc_eso_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float eso_pitch, float eso_q, float eso_z3, float q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN];
    _mav_put_float(buf, 0, eso_pitch);
    _mav_put_float(buf, 4, eso_q);
    _mav_put_float(buf, 8, eso_z3);
    _mav_put_float(buf, 12, q);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN);
#else
    mavlink_auv_adrc_eso_t packet;
    packet.eso_pitch = eso_pitch;
    packet.eso_q = eso_q;
    packet.eso_z3 = eso_z3;
    packet.q = q;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ADRC_ESO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
}

/**
 * @brief Pack a auv_adrc_eso message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param eso_pitch  
 * @param eso_q  
 * @param eso_z3  
 * @param q  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_adrc_eso_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float eso_pitch,float eso_q,float eso_z3,float q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN];
    _mav_put_float(buf, 0, eso_pitch);
    _mav_put_float(buf, 4, eso_q);
    _mav_put_float(buf, 8, eso_z3);
    _mav_put_float(buf, 12, q);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN);
#else
    mavlink_auv_adrc_eso_t packet;
    packet.eso_pitch = eso_pitch;
    packet.eso_q = eso_q;
    packet.eso_z3 = eso_z3;
    packet.q = q;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ADRC_ESO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
}

/**
 * @brief Encode a auv_adrc_eso struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_adrc_eso C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_adrc_eso_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_adrc_eso_t* auv_adrc_eso)
{
    return mavlink_msg_auv_adrc_eso_pack(system_id, component_id, msg, auv_adrc_eso->eso_pitch, auv_adrc_eso->eso_q, auv_adrc_eso->eso_z3, auv_adrc_eso->q);
}

/**
 * @brief Encode a auv_adrc_eso struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_adrc_eso C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_adrc_eso_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_adrc_eso_t* auv_adrc_eso)
{
    return mavlink_msg_auv_adrc_eso_pack_chan(system_id, component_id, chan, msg, auv_adrc_eso->eso_pitch, auv_adrc_eso->eso_q, auv_adrc_eso->eso_z3, auv_adrc_eso->q);
}

/**
 * @brief Send a auv_adrc_eso message
 * @param chan MAVLink channel to send the message
 *
 * @param eso_pitch  
 * @param eso_q  
 * @param eso_z3  
 * @param q  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_adrc_eso_send(mavlink_channel_t chan, float eso_pitch, float eso_q, float eso_z3, float q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN];
    _mav_put_float(buf, 0, eso_pitch);
    _mav_put_float(buf, 4, eso_q);
    _mav_put_float(buf, 8, eso_z3);
    _mav_put_float(buf, 12, q);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_ESO, buf, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
#else
    mavlink_auv_adrc_eso_t packet;
    packet.eso_pitch = eso_pitch;
    packet.eso_q = eso_q;
    packet.eso_z3 = eso_z3;
    packet.q = q;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_ESO, (const char *)&packet, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
#endif
}

/**
 * @brief Send a auv_adrc_eso message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_adrc_eso_send_struct(mavlink_channel_t chan, const mavlink_auv_adrc_eso_t* auv_adrc_eso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_adrc_eso_send(chan, auv_adrc_eso->eso_pitch, auv_adrc_eso->eso_q, auv_adrc_eso->eso_z3, auv_adrc_eso->q);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_ESO, (const char *)auv_adrc_eso, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_adrc_eso_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float eso_pitch, float eso_q, float eso_z3, float q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, eso_pitch);
    _mav_put_float(buf, 4, eso_q);
    _mav_put_float(buf, 8, eso_z3);
    _mav_put_float(buf, 12, q);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_ESO, buf, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
#else
    mavlink_auv_adrc_eso_t *packet = (mavlink_auv_adrc_eso_t *)msgbuf;
    packet->eso_pitch = eso_pitch;
    packet->eso_q = eso_q;
    packet->eso_z3 = eso_z3;
    packet->q = q;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_ESO, (const char *)packet, MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN, MAVLINK_MSG_ID_AUV_ADRC_ESO_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_ADRC_ESO UNPACKING


/**
 * @brief Get field eso_pitch from auv_adrc_eso message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_eso_get_eso_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field eso_q from auv_adrc_eso message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_eso_get_eso_q(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field eso_z3 from auv_adrc_eso message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_eso_get_eso_z3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field q from auv_adrc_eso message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_eso_get_q(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a auv_adrc_eso message into a struct
 *
 * @param msg The message to decode
 * @param auv_adrc_eso C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_adrc_eso_decode(const mavlink_message_t* msg, mavlink_auv_adrc_eso_t* auv_adrc_eso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_adrc_eso->eso_pitch = mavlink_msg_auv_adrc_eso_get_eso_pitch(msg);
    auv_adrc_eso->eso_q = mavlink_msg_auv_adrc_eso_get_eso_q(msg);
    auv_adrc_eso->eso_z3 = mavlink_msg_auv_adrc_eso_get_eso_z3(msg);
    auv_adrc_eso->q = mavlink_msg_auv_adrc_eso_get_q(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN? msg->len : MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN;
        memset(auv_adrc_eso, 0, MAVLINK_MSG_ID_AUV_ADRC_ESO_LEN);
    memcpy(auv_adrc_eso, _MAV_PAYLOAD(msg), len);
#endif
}
