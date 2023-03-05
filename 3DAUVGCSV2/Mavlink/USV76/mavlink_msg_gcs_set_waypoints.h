#pragma once
// MESSAGE GCS_SET_WAYPOINTS PACKING

#define MAVLINK_MSG_ID_GCS_SET_WAYPOINTS 153

MAVPACKED(
typedef struct __mavlink_gcs_set_waypoints_t {
 int32_t waypoint_lng; /*< [degE7] */
 int32_t waypoint_lat; /*< [degE7] */
 uint8_t waypoint_index; /*<  */
}) mavlink_gcs_set_waypoints_t;

#define MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN 9
#define MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN 9
#define MAVLINK_MSG_ID_153_LEN 9
#define MAVLINK_MSG_ID_153_MIN_LEN 9

#define MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC 27
#define MAVLINK_MSG_ID_153_CRC 27



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_WAYPOINTS { \
    153, \
    "GCS_SET_WAYPOINTS", \
    3, \
    {  { "waypoint_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gcs_set_waypoints_t, waypoint_index) }, \
         { "waypoint_lng", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gcs_set_waypoints_t, waypoint_lng) }, \
         { "waypoint_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gcs_set_waypoints_t, waypoint_lat) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_WAYPOINTS { \
    "GCS_SET_WAYPOINTS", \
    3, \
    {  { "waypoint_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gcs_set_waypoints_t, waypoint_index) }, \
         { "waypoint_lng", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gcs_set_waypoints_t, waypoint_lng) }, \
         { "waypoint_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gcs_set_waypoints_t, waypoint_lat) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_waypoints message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param waypoint_index  
 * @param waypoint_lng [degE7] 
 * @param waypoint_lat [degE7] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_waypoints_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t waypoint_index, int32_t waypoint_lng, int32_t waypoint_lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN];
    _mav_put_int32_t(buf, 0, waypoint_lng);
    _mav_put_int32_t(buf, 4, waypoint_lat);
    _mav_put_uint8_t(buf, 8, waypoint_index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN);
#else
    mavlink_gcs_set_waypoints_t packet;
    packet.waypoint_lng = waypoint_lng;
    packet.waypoint_lat = waypoint_lat;
    packet.waypoint_index = waypoint_index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_WAYPOINTS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
}

/**
 * @brief Pack a gcs_set_waypoints message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param waypoint_index  
 * @param waypoint_lng [degE7] 
 * @param waypoint_lat [degE7] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_waypoints_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t waypoint_index,int32_t waypoint_lng,int32_t waypoint_lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN];
    _mav_put_int32_t(buf, 0, waypoint_lng);
    _mav_put_int32_t(buf, 4, waypoint_lat);
    _mav_put_uint8_t(buf, 8, waypoint_index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN);
#else
    mavlink_gcs_set_waypoints_t packet;
    packet.waypoint_lng = waypoint_lng;
    packet.waypoint_lat = waypoint_lat;
    packet.waypoint_index = waypoint_index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_WAYPOINTS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
}

/**
 * @brief Encode a gcs_set_waypoints struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_waypoints C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_waypoints_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_waypoints_t* gcs_set_waypoints)
{
    return mavlink_msg_gcs_set_waypoints_pack(system_id, component_id, msg, gcs_set_waypoints->waypoint_index, gcs_set_waypoints->waypoint_lng, gcs_set_waypoints->waypoint_lat);
}

/**
 * @brief Encode a gcs_set_waypoints struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_waypoints C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_waypoints_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_waypoints_t* gcs_set_waypoints)
{
    return mavlink_msg_gcs_set_waypoints_pack_chan(system_id, component_id, chan, msg, gcs_set_waypoints->waypoint_index, gcs_set_waypoints->waypoint_lng, gcs_set_waypoints->waypoint_lat);
}

/**
 * @brief Send a gcs_set_waypoints message
 * @param chan MAVLink channel to send the message
 *
 * @param waypoint_index  
 * @param waypoint_lng [degE7] 
 * @param waypoint_lat [degE7] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_waypoints_send(mavlink_channel_t chan, uint8_t waypoint_index, int32_t waypoint_lng, int32_t waypoint_lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN];
    _mav_put_int32_t(buf, 0, waypoint_lng);
    _mav_put_int32_t(buf, 4, waypoint_lat);
    _mav_put_uint8_t(buf, 8, waypoint_index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS, buf, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
#else
    mavlink_gcs_set_waypoints_t packet;
    packet.waypoint_lng = waypoint_lng;
    packet.waypoint_lat = waypoint_lat;
    packet.waypoint_index = waypoint_index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
#endif
}

/**
 * @brief Send a gcs_set_waypoints message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_waypoints_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_waypoints_t* gcs_set_waypoints)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_waypoints_send(chan, gcs_set_waypoints->waypoint_index, gcs_set_waypoints->waypoint_lng, gcs_set_waypoints->waypoint_lat);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS, (const char *)gcs_set_waypoints, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_waypoints_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t waypoint_index, int32_t waypoint_lng, int32_t waypoint_lat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, waypoint_lng);
    _mav_put_int32_t(buf, 4, waypoint_lat);
    _mav_put_uint8_t(buf, 8, waypoint_index);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS, buf, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
#else
    mavlink_gcs_set_waypoints_t *packet = (mavlink_gcs_set_waypoints_t *)msgbuf;
    packet->waypoint_lng = waypoint_lng;
    packet->waypoint_lat = waypoint_lat;
    packet->waypoint_index = waypoint_index;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_WAYPOINTS UNPACKING


/**
 * @brief Get field waypoint_index from gcs_set_waypoints message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_gcs_set_waypoints_get_waypoint_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field waypoint_lng from gcs_set_waypoints message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_gcs_set_waypoints_get_waypoint_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field waypoint_lat from gcs_set_waypoints message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_gcs_set_waypoints_get_waypoint_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a gcs_set_waypoints message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_waypoints C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_waypoints_decode(const mavlink_message_t* msg, mavlink_gcs_set_waypoints_t* gcs_set_waypoints)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_waypoints->waypoint_lng = mavlink_msg_gcs_set_waypoints_get_waypoint_lng(msg);
    gcs_set_waypoints->waypoint_lat = mavlink_msg_gcs_set_waypoints_get_waypoint_lat(msg);
    gcs_set_waypoints->waypoint_index = mavlink_msg_gcs_set_waypoints_get_waypoint_index(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN;
        memset(gcs_set_waypoints, 0, MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_LEN);
    memcpy(gcs_set_waypoints, _MAV_PAYLOAD(msg), len);
#endif
}
