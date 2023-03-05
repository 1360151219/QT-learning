#pragma once
// MESSAGE AUV_THRUSTERS_INDIRECT_CONTROL PACKING

#define MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL 165

MAVPACKED(
typedef struct __mavlink_auv_thrusters_indirect_control_t {
 int8_t heave; /*<  */
 int8_t pitch; /*<  */
 int8_t surge; /*<  */
 int8_t yaw; /*<  */
}) mavlink_auv_thrusters_indirect_control_t;

#define MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN 4
#define MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN 4
#define MAVLINK_MSG_ID_165_LEN 4
#define MAVLINK_MSG_ID_165_MIN_LEN 4

#define MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC 169
#define MAVLINK_MSG_ID_165_CRC 169



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUV_THRUSTERS_INDIRECT_CONTROL { \
    165, \
    "AUV_THRUSTERS_INDIRECT_CONTROL", \
    4, \
    {  { "heave", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_auv_thrusters_indirect_control_t, heave) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_auv_thrusters_indirect_control_t, pitch) }, \
         { "surge", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_auv_thrusters_indirect_control_t, surge) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_auv_thrusters_indirect_control_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUV_THRUSTERS_INDIRECT_CONTROL { \
    "AUV_THRUSTERS_INDIRECT_CONTROL", \
    4, \
    {  { "heave", NULL, MAVLINK_TYPE_INT8_T, 0, 0, offsetof(mavlink_auv_thrusters_indirect_control_t, heave) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT8_T, 0, 1, offsetof(mavlink_auv_thrusters_indirect_control_t, pitch) }, \
         { "surge", NULL, MAVLINK_TYPE_INT8_T, 0, 2, offsetof(mavlink_auv_thrusters_indirect_control_t, surge) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_auv_thrusters_indirect_control_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a auv_thrusters_indirect_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param heave  
 * @param pitch  
 * @param surge  
 * @param yaw  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_thrusters_indirect_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t heave, int8_t pitch, int8_t surge, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, heave);
    _mav_put_int8_t(buf, 1, pitch);
    _mav_put_int8_t(buf, 2, surge);
    _mav_put_int8_t(buf, 3, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN);
#else
    mavlink_auv_thrusters_indirect_control_t packet;
    packet.heave = heave;
    packet.pitch = pitch;
    packet.surge = surge;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
}

/**
 * @brief Pack a auv_thrusters_indirect_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heave  
 * @param pitch  
 * @param surge  
 * @param yaw  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auv_thrusters_indirect_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t heave,int8_t pitch,int8_t surge,int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, heave);
    _mav_put_int8_t(buf, 1, pitch);
    _mav_put_int8_t(buf, 2, surge);
    _mav_put_int8_t(buf, 3, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN);
#else
    mavlink_auv_thrusters_indirect_control_t packet;
    packet.heave = heave;
    packet.pitch = pitch;
    packet.surge = surge;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
}

/**
 * @brief Encode a auv_thrusters_indirect_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auv_thrusters_indirect_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_thrusters_indirect_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auv_thrusters_indirect_control_t* auv_thrusters_indirect_control)
{
    return mavlink_msg_auv_thrusters_indirect_control_pack(system_id, component_id, msg, auv_thrusters_indirect_control->heave, auv_thrusters_indirect_control->pitch, auv_thrusters_indirect_control->surge, auv_thrusters_indirect_control->yaw);
}

/**
 * @brief Encode a auv_thrusters_indirect_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auv_thrusters_indirect_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auv_thrusters_indirect_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auv_thrusters_indirect_control_t* auv_thrusters_indirect_control)
{
    return mavlink_msg_auv_thrusters_indirect_control_pack_chan(system_id, component_id, chan, msg, auv_thrusters_indirect_control->heave, auv_thrusters_indirect_control->pitch, auv_thrusters_indirect_control->surge, auv_thrusters_indirect_control->yaw);
}

/**
 * @brief Send a auv_thrusters_indirect_control message
 * @param chan MAVLink channel to send the message
 *
 * @param heave  
 * @param pitch  
 * @param surge  
 * @param yaw  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auv_thrusters_indirect_control_send(mavlink_channel_t chan, int8_t heave, int8_t pitch, int8_t surge, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN];
    _mav_put_int8_t(buf, 0, heave);
    _mav_put_int8_t(buf, 1, pitch);
    _mav_put_int8_t(buf, 2, surge);
    _mav_put_int8_t(buf, 3, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL, buf, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
#else
    mavlink_auv_thrusters_indirect_control_t packet;
    packet.heave = heave;
    packet.pitch = pitch;
    packet.surge = surge;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
#endif
}

/**
 * @brief Send a auv_thrusters_indirect_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auv_thrusters_indirect_control_send_struct(mavlink_channel_t chan, const mavlink_auv_thrusters_indirect_control_t* auv_thrusters_indirect_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auv_thrusters_indirect_control_send(chan, auv_thrusters_indirect_control->heave, auv_thrusters_indirect_control->pitch, auv_thrusters_indirect_control->surge, auv_thrusters_indirect_control->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL, (const char *)auv_thrusters_indirect_control, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auv_thrusters_indirect_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t heave, int8_t pitch, int8_t surge, int8_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int8_t(buf, 0, heave);
    _mav_put_int8_t(buf, 1, pitch);
    _mav_put_int8_t(buf, 2, surge);
    _mav_put_int8_t(buf, 3, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL, buf, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
#else
    mavlink_auv_thrusters_indirect_control_t *packet = (mavlink_auv_thrusters_indirect_control_t *)msgbuf;
    packet->heave = heave;
    packet->pitch = pitch;
    packet->surge = surge;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL, (const char *)packet, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE AUV_THRUSTERS_INDIRECT_CONTROL UNPACKING


/**
 * @brief Get field heave from auv_thrusters_indirect_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_indirect_control_get_heave(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Get field pitch from auv_thrusters_indirect_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_indirect_control_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  1);
}

/**
 * @brief Get field surge from auv_thrusters_indirect_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_indirect_control_get_surge(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  2);
}

/**
 * @brief Get field yaw from auv_thrusters_indirect_control message
 *
 * @return  
 */
static inline int8_t mavlink_msg_auv_thrusters_indirect_control_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Decode a auv_thrusters_indirect_control message into a struct
 *
 * @param msg The message to decode
 * @param auv_thrusters_indirect_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_auv_thrusters_indirect_control_decode(const mavlink_message_t* msg, mavlink_auv_thrusters_indirect_control_t* auv_thrusters_indirect_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    auv_thrusters_indirect_control->heave = mavlink_msg_auv_thrusters_indirect_control_get_heave(msg);
    auv_thrusters_indirect_control->pitch = mavlink_msg_auv_thrusters_indirect_control_get_pitch(msg);
    auv_thrusters_indirect_control->surge = mavlink_msg_auv_thrusters_indirect_control_get_surge(msg);
    auv_thrusters_indirect_control->yaw = mavlink_msg_auv_thrusters_indirect_control_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN;
        memset(auv_thrusters_indirect_control, 0, MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_LEN);
    memcpy(auv_thrusters_indirect_control, _MAV_PAYLOAD(msg), len);
#endif
}
