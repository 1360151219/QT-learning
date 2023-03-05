#pragma once
// MESSAGE AUV_ADRC_PARAM PACKING

#define MAVLINK_MSG_ID_AUV_ADRC_PARAM 160

MAVPACKED(
typedef struct __mavlink_auv_adrc_param_t {
 float eso_beta01; /*<  */
 float eso_beta02; /*<  */
 float eso_beta03; /*<  */
 float nlsef_r; /*<  */
 float nlsef_c; /*<  */
 float nlsef_h; /*<  */
}) mavlink_auv_adrc_param_t;

#define MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN 24
#define MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN 24
#define MAVLINK_MSG_ID_160_LEN 24
#define MAVLINK_MSG_ID_160_MIN_LEN 24

#define MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC 102
#define MAVLINK_MSG_ID_160_CRC 102



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_ADRC_PARAM { \
    160, \
    "AUV_ADRC_PARAM", \
    6, \
    {  { "eso_beta01", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_adrc_param_t, eso_beta01) }, \
         { "eso_beta02", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_adrc_param_t, eso_beta02) }, \
         { "eso_beta03", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_adrc_param_t, eso_beta03) }, \
         { "nlsef_r", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_adrc_param_t, nlsef_r) }, \
         { "nlsef_c", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_adrc_param_t, nlsef_c) }, \
         { "nlsef_h", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_adrc_param_t, nlsef_h) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_ADRC_PARAM { \
    "AUV_ADRC_PARAM", \
    6, \
    {  { "eso_beta01", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_auv_adrc_param_t, eso_beta01) }, \
         { "eso_beta02", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_auv_adrc_param_t, eso_beta02) }, \
         { "eso_beta03", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_auv_adrc_param_t, eso_beta03) }, \
         { "nlsef_r", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_auv_adrc_param_t, nlsef_r) }, \
         { "nlsef_c", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_auv_adrc_param_t, nlsef_c) }, \
         { "nlsef_h", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_auv_adrc_param_t, nlsef_h) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_adrc_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param eso_beta01  
 * @param eso_beta02  
 * @param eso_beta03  
 * @param nlsef_r  
 * @param nlsef_c  
 * @param nlsef_h  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_adrc_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float eso_beta01, float eso_beta02, float eso_beta03, float nlsef_r, float nlsef_c, float nlsef_h)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN];
    _mav_put_float(buf, 0, eso_beta01);
    _mav_put_float(buf, 4, eso_beta02);
    _mav_put_float(buf, 8, eso_beta03);
    _mav_put_float(buf, 12, nlsef_r);
    _mav_put_float(buf, 16, nlsef_c);
    _mav_put_float(buf, 20, nlsef_h);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN);
#else
    mavlink_auv_adrc_param_t packet;
    packet.eso_beta01 = eso_beta01;
    packet.eso_beta02 = eso_beta02;
    packet.eso_beta03 = eso_beta03;
    packet.nlsef_r = nlsef_r;
    packet.nlsef_c = nlsef_c;
    packet.nlsef_h = nlsef_h;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ADRC_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
}

/**
 * @brief Pack a auv_adrc_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param eso_beta01  
 * @param eso_beta02  
 * @param eso_beta03  
 * @param nlsef_r  
 * @param nlsef_c  
 * @param nlsef_h  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_adrc_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float eso_beta01,float eso_beta02,float eso_beta03,float nlsef_r,float nlsef_c,float nlsef_h)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN];
    _mav_put_float(buf, 0, eso_beta01);
    _mav_put_float(buf, 4, eso_beta02);
    _mav_put_float(buf, 8, eso_beta03);
    _mav_put_float(buf, 12, nlsef_r);
    _mav_put_float(buf, 16, nlsef_c);
    _mav_put_float(buf, 20, nlsef_h);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN);
#else
    mavlink_auv_adrc_param_t packet;
    packet.eso_beta01 = eso_beta01;
    packet.eso_beta02 = eso_beta02;
    packet.eso_beta03 = eso_beta03;
    packet.nlsef_r = nlsef_r;
    packet.nlsef_c = nlsef_c;
    packet.nlsef_h = nlsef_h;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_ADRC_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
}

/**
 * @brief Encode a auv_adrc_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_adrc_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_adrc_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_adrc_param_t* auv_adrc_param)
{
    return mavlink_msg_auv_adrc_param_pack(system_id, component_id, msg, auv_adrc_param->eso_beta01, auv_adrc_param->eso_beta02, auv_adrc_param->eso_beta03, auv_adrc_param->nlsef_r, auv_adrc_param->nlsef_c, auv_adrc_param->nlsef_h);
}

/**
 * @brief Encode a auv_adrc_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_adrc_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_adrc_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_adrc_param_t* auv_adrc_param)
{
    return mavlink_msg_auv_adrc_param_pack_chan(system_id, component_id, chan, msg, auv_adrc_param->eso_beta01, auv_adrc_param->eso_beta02, auv_adrc_param->eso_beta03, auv_adrc_param->nlsef_r, auv_adrc_param->nlsef_c, auv_adrc_param->nlsef_h);
}

/**
 * @brief Send a auv_adrc_param message
 * @param chan MAVLink channel to send the message
 *
 * @param eso_beta01  
 * @param eso_beta02  
 * @param eso_beta03  
 * @param nlsef_r  
 * @param nlsef_c  
 * @param nlsef_h  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_adrc_param_send(mavlink_channel_t chan, float eso_beta01, float eso_beta02, float eso_beta03, float nlsef_r, float nlsef_c, float nlsef_h)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN];
    _mav_put_float(buf, 0, eso_beta01);
    _mav_put_float(buf, 4, eso_beta02);
    _mav_put_float(buf, 8, eso_beta03);
    _mav_put_float(buf, 12, nlsef_r);
    _mav_put_float(buf, 16, nlsef_c);
    _mav_put_float(buf, 20, nlsef_h);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM, buf, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
#else
    mavlink_auv_adrc_param_t packet;
    packet.eso_beta01 = eso_beta01;
    packet.eso_beta02 = eso_beta02;
    packet.eso_beta03 = eso_beta03;
    packet.nlsef_r = nlsef_r;
    packet.nlsef_c = nlsef_c;
    packet.nlsef_h = nlsef_h;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM, (const char *)&packet, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
#endif
}

/**
 * @brief Send a auv_adrc_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_adrc_param_send_struct(mavlink_channel_t chan, const mavlink_auv_adrc_param_t* auv_adrc_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_adrc_param_send(chan, auv_adrc_param->eso_beta01, auv_adrc_param->eso_beta02, auv_adrc_param->eso_beta03, auv_adrc_param->nlsef_r, auv_adrc_param->nlsef_c, auv_adrc_param->nlsef_h);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM, (const char *)auv_adrc_param, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_adrc_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float eso_beta01, float eso_beta02, float eso_beta03, float nlsef_r, float nlsef_c, float nlsef_h)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, eso_beta01);
    _mav_put_float(buf, 4, eso_beta02);
    _mav_put_float(buf, 8, eso_beta03);
    _mav_put_float(buf, 12, nlsef_r);
    _mav_put_float(buf, 16, nlsef_c);
    _mav_put_float(buf, 20, nlsef_h);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM, buf, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
#else
    mavlink_auv_adrc_param_t *packet = (mavlink_auv_adrc_param_t *)msgbuf;
    packet->eso_beta01 = eso_beta01;
    packet->eso_beta02 = eso_beta02;
    packet->eso_beta03 = eso_beta03;
    packet->nlsef_r = nlsef_r;
    packet->nlsef_c = nlsef_c;
    packet->nlsef_h = nlsef_h;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_ADRC_PARAM, (const char *)packet, MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN, MAVLINK_MSG_ID_AUV_ADRC_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_ADRC_PARAM UNPACKING


/**
 * @brief Get field eso_beta01 from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_eso_beta01(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field eso_beta02 from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_eso_beta02(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field eso_beta03 from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_eso_beta03(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field nlsef_r from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_nlsef_r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field nlsef_c from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_nlsef_c(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field nlsef_h from auv_adrc_param message
 *
 * @return  
 */
static inline float mavlink_msg_auv_adrc_param_get_nlsef_h(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a auv_adrc_param message into a struct
 *
 * @param msg The message to decode
 * @param auv_adrc_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_adrc_param_decode(const mavlink_message_t* msg, mavlink_auv_adrc_param_t* auv_adrc_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_adrc_param->eso_beta01 = mavlink_msg_auv_adrc_param_get_eso_beta01(msg);
    auv_adrc_param->eso_beta02 = mavlink_msg_auv_adrc_param_get_eso_beta02(msg);
    auv_adrc_param->eso_beta03 = mavlink_msg_auv_adrc_param_get_eso_beta03(msg);
    auv_adrc_param->nlsef_r = mavlink_msg_auv_adrc_param_get_nlsef_r(msg);
    auv_adrc_param->nlsef_c = mavlink_msg_auv_adrc_param_get_nlsef_c(msg);
    auv_adrc_param->nlsef_h = mavlink_msg_auv_adrc_param_get_nlsef_h(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN? msg->len : MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN;
        memset(auv_adrc_param, 0, MAVLINK_MSG_ID_AUV_ADRC_PARAM_LEN);
    memcpy(auv_adrc_param, _MAV_PAYLOAD(msg), len);
#endif
}
