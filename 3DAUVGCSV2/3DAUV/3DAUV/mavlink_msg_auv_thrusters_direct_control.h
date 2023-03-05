#pragma once
// MESSAGE AUV_THRUSTERS_DIRECT_CONTROL PACKING

#define MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL 164

MAVPACKED(
typedef struct __mavlink_auv_thrusters_direct_control_t {
 int8_t bow_ver; /*<  */
 int8_t stern_ver; /*<  */
 int8_t bow_hor; /*<  */
 int8_t stern_hor; /*<  */
}) mavlink_auv_thrusters_direct_control_t;

#define MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN 4
#define MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN 4
#define MAVLINK_MSG_ID_164_LEN 4
#define MAVLINK_MSG_ID_164_MIN_LEN 4

#define MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC 50
#define MAVLINK_MSG_ID_164_CRC 50



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_THRUSTERS_DIRECT_CONTROL { \
    164, \
    "AUV_THRUSTERS_DIRECT_CONTROL", \
    4, \
    {  { "bow_ver", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_auv_thrusters_direct_control_t, bow_ver) }, \
         { "stern_ver", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_auv_thrusters_direct_control_t, stern_ver) }, \
         { "bow_hor", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_auv_thrusters_direct_control_t, bow_hor) }, \
         { "stern_hor", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_auv_thrusters_direct_control_t, stern_hor) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_THRUSTERS_DIRECT_CONTROL { \
    "AUV_THRUSTERS_DIRECT_CONTROL", \
    4, \
    {  { "bow_ver", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_auv_thrusters_direct_control_t, bow_ver) }, \
         { "stern_ver", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_auv_thrusters_direct_control_t, stern_ver) }, \
         { "bow_hor", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_auv_thrusters_direct_control_t, bow_hor) }, \
         { "stern_hor", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_auv_thrusters_direct_control_t, stern_hor) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_thrusters_direct_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param bow_ver  
 * @param stern_ver  
 * @param bow_hor  
 * @param stern_hor  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_thrusters_direct_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t bow_ver, int8_t stern_ver, int8_t bow_hor, int8_t stern_hor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, bow_ver);
    _mav_put_int8_t(buf, 1, stern_ver);
    _mav_put_int8_t(buf, 2, bow_hor);
    _mav_put_int8_t(buf, 3, stern_hor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN);
#else
    mavlink_auv_thrusters_direct_control_t packet;
    packet.bow_ver = bow_ver;
    packet.stern_ver = stern_ver;
    packet.bow_hor = bow_hor;
    packet.stern_hor = stern_hor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
}

/**
 * @brief Pack a auv_thrusters_direct_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bow_ver  
 * @param stern_ver  
 * @param bow_hor  
 * @param stern_hor  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_thrusters_direct_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t bow_ver,int8_t stern_ver,int8_t bow_hor,int8_t stern_hor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, bow_ver);
    _mav_put_int8_t(buf, 1, stern_ver);
    _mav_put_int8_t(buf, 2, bow_hor);
    _mav_put_int8_t(buf, 3, stern_hor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN);
#else
    mavlink_auv_thrusters_direct_control_t packet;
    packet.bow_ver = bow_ver;
    packet.stern_ver = stern_ver;
    packet.bow_hor = bow_hor;
    packet.stern_hor = stern_hor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
}

/**
 * @brief Encode a auv_thrusters_direct_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_thrusters_direct_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_thrusters_direct_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_thrusters_direct_control_t* auv_thrusters_direct_control)
{
    return mavlink_msg_auv_thrusters_direct_control_pack(system_id, component_id, msg, auv_thrusters_direct_control->bow_ver, auv_thrusters_direct_control->stern_ver, auv_thrusters_direct_control->bow_hor, auv_thrusters_direct_control->stern_hor);
}

/**
 * @brief Encode a auv_thrusters_direct_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_thrusters_direct_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_thrusters_direct_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_thrusters_direct_control_t* auv_thrusters_direct_control)
{
    return mavlink_msg_auv_thrusters_direct_control_pack_chan(system_id, component_id, chan, msg, auv_thrusters_direct_control->bow_ver, auv_thrusters_direct_control->stern_ver, auv_thrusters_direct_control->bow_hor, auv_thrusters_direct_control->stern_hor);
}

/**
 * @brief Send a auv_thrusters_direct_control message
 * @param chan MAVLink channel to send the message
 *
 * @param bow_ver  
 * @param stern_ver  
 * @param bow_hor  
 * @param stern_hor  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_thrusters_direct_control_send(mavlink_channel_t chan, int8_t bow_ver, int8_t stern_ver, int8_t bow_hor, int8_t stern_hor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, bow_ver);
    _mav_put_int8_t(buf, 1, stern_ver);
    _mav_put_int8_t(buf, 2, bow_hor);
    _mav_put_int8_t(buf, 3, stern_hor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL, buf, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
#else
    mavlink_auv_thrusters_direct_control_t packet;
    packet.bow_ver = bow_ver;
    packet.stern_ver = stern_ver;
    packet.bow_hor = bow_hor;
    packet.stern_hor = stern_hor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
#endif
}

/**
 * @brief Send a auv_thrusters_direct_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_thrusters_direct_control_send_struct(mavlink_channel_t chan, const mavlink_auv_thrusters_direct_control_t* auv_thrusters_direct_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_thrusters_direct_control_send(chan, auv_thrusters_direct_control->bow_ver, auv_thrusters_direct_control->stern_ver, auv_thrusters_direct_control->bow_hor, auv_thrusters_direct_control->stern_hor);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL, (const char *)auv_thrusters_direct_control, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_thrusters_direct_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t bow_ver, int8_t stern_ver, int8_t bow_hor, int8_t stern_hor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, bow_ver);
    _mav_put_int8_t(buf, 1, stern_ver);
    _mav_put_int8_t(buf, 2, bow_hor);
    _mav_put_int8_t(buf, 3, stern_hor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL, buf, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
#else
    mavlink_auv_thrusters_direct_control_t *packet = (mavlink_auv_thrusters_direct_control_t *)msgbuf;
    packet->bow_ver = bow_ver;
    packet->stern_ver = stern_ver;
    packet->bow_hor = bow_hor;
    packet->stern_hor = stern_hor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL, (const char *)packet, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_THRUSTERS_DIRECT_CONTROL UNPACKING


/**
 * @brief Get field bow_ver from auv_thrusters_direct_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_direct_control_get_bow_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field stern_ver from auv_thrusters_direct_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_direct_control_get_stern_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Get field bow_hor from auv_thrusters_direct_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_direct_control_get_bow_hor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field stern_hor from auv_thrusters_direct_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_direct_control_get_stern_hor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Decode a auv_thrusters_direct_control message into a struct
 *
 * @param msg The message to decode
 * @param auv_thrusters_direct_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_thrusters_direct_control_decode(const mavlink_message_t* msg, mavlink_auv_thrusters_direct_control_t* auv_thrusters_direct_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_thrusters_direct_control->bow_ver = mavlink_msg_auv_thrusters_direct_control_get_bow_ver(msg);
    auv_thrusters_direct_control->stern_ver = mavlink_msg_auv_thrusters_direct_control_get_stern_ver(msg);
    auv_thrusters_direct_control->bow_hor = mavlink_msg_auv_thrusters_direct_control_get_bow_hor(msg);
    auv_thrusters_direct_control->stern_hor = mavlink_msg_auv_thrusters_direct_control_get_stern_hor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN;
        memset(auv_thrusters_direct_control, 0, MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_LEN);
    memcpy(auv_thrusters_direct_control, _MAV_PAYLOAD(msg), len);
#endif
}
