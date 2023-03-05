#pragma once
// MESSAGE USV_STATE PACKING

#define MAVLINK_MSG_ID_USV_STATE 151

MAVPACKED(
typedef struct __mavlink_usv_state_t {
 int32_t lat; /*< [degE7] */
 int32_t lon; /*< [degE7] */
 float x; /*< [m] */
 float y; /*< [m] */
 float yaw; /*< [degree] */
 float course; /*< [degree] */
 int16_t vel; /*< [m/sE3] */
 int16_t roll; /*< [degE2] */
 int16_t pitch; /*< [degE2] */
 int16_t HDOP; /*< [E2] Horizontal Dilution of Precision*/
 uint8_t SVs; /*<  Number of satellites used for positioning*/
}) mavlink_usv_state_t;

#define MAVLINK_MSG_ID_USV_STATE_LEN 33
#define MAVLINK_MSG_ID_USV_STATE_MIN_LEN 33
#define MAVLINK_MSG_ID_151_LEN 33
#define MAVLINK_MSG_ID_151_MIN_LEN 33

#define MAVLINK_MSG_ID_USV_STATE_CRC 138
#define MAVLINK_MSG_ID_151_CRC 138



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_STATE { \
    151, \
    "USV_STATE", \
    11, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_state_t, lon) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_usv_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_usv_state_t, y) }, \
         { "vel", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_usv_state_t, vel) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_usv_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_usv_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_state_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_state_t, course) }, \
         { "HDOP", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_usv_state_t, HDOP) }, \
         { "SVs", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_usv_state_t, SVs) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_STATE { \
    "USV_STATE", \
    11, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_state_t, lon) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_usv_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_usv_state_t, y) }, \
         { "vel", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_usv_state_t, vel) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_usv_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_usv_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_state_t, yaw) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_state_t, course) }, \
         { "HDOP", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_usv_state_t, HDOP) }, \
         { "SVs", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_usv_state_t, SVs) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat [degE7] 
 * @param lon [degE7] 
 * @param x [m] 
 * @param y [m] 
 * @param vel [m/sE3] 
 * @param roll [degE2] 
 * @param pitch [degE2] 
 * @param yaw [degree] 
 * @param course [degree] 
 * @param HDOP [E2] Horizontal Dilution of Precision
 * @param SVs  Number of satellites used for positioning
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t lat, int32_t lon, float x, float y, int16_t vel, int16_t roll, int16_t pitch, float yaw, float course, int16_t HDOP, uint8_t SVs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, course);
    _mav_put_int16_t(buf, 24, vel);
    _mav_put_int16_t(buf, 26, roll);
    _mav_put_int16_t(buf, 28, pitch);
    _mav_put_int16_t(buf, 30, HDOP);
    _mav_put_uint8_t(buf, 32, SVs);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATE_LEN);
#else
    mavlink_usv_state_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.course = course;
    packet.vel = vel;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.HDOP = HDOP;
    packet.SVs = SVs;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
}

/**
 * @brief Pack a usv_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat [degE7] 
 * @param lon [degE7] 
 * @param x [m] 
 * @param y [m] 
 * @param vel [m/sE3] 
 * @param roll [degE2] 
 * @param pitch [degE2] 
 * @param yaw [degree] 
 * @param course [degree] 
 * @param HDOP [E2] Horizontal Dilution of Precision
 * @param SVs  Number of satellites used for positioning
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t lat,int32_t lon,float x,float y,int16_t vel,int16_t roll,int16_t pitch,float yaw,float course,int16_t HDOP,uint8_t SVs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, course);
    _mav_put_int16_t(buf, 24, vel);
    _mav_put_int16_t(buf, 26, roll);
    _mav_put_int16_t(buf, 28, pitch);
    _mav_put_int16_t(buf, 30, HDOP);
    _mav_put_uint8_t(buf, 32, SVs);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATE_LEN);
#else
    mavlink_usv_state_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.course = course;
    packet.vel = vel;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.HDOP = HDOP;
    packet.SVs = SVs;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
}

/**
 * @brief Encode a usv_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_state_t* usv_state)
{
    return mavlink_msg_usv_state_pack(system_id, component_id, msg, usv_state->lat, usv_state->lon, usv_state->x, usv_state->y, usv_state->vel, usv_state->roll, usv_state->pitch, usv_state->yaw, usv_state->course, usv_state->HDOP, usv_state->SVs);
}

/**
 * @brief Encode a usv_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_state_t* usv_state)
{
    return mavlink_msg_usv_state_pack_chan(system_id, component_id, chan, msg, usv_state->lat, usv_state->lon, usv_state->x, usv_state->y, usv_state->vel, usv_state->roll, usv_state->pitch, usv_state->yaw, usv_state->course, usv_state->HDOP, usv_state->SVs);
}

/**
 * @brief Send a usv_state message
 * @param chan MAVLink channel to send the message
 *
 * @param lat [degE7] 
 * @param lon [degE7] 
 * @param x [m] 
 * @param y [m] 
 * @param vel [m/sE3] 
 * @param roll [degE2] 
 * @param pitch [degE2] 
 * @param yaw [degree] 
 * @param course [degree] 
 * @param HDOP [E2] Horizontal Dilution of Precision
 * @param SVs  Number of satellites used for positioning
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_state_send(mavlink_channel_t chan, int32_t lat, int32_t lon, float x, float y, int16_t vel, int16_t roll, int16_t pitch, float yaw, float course, int16_t HDOP, uint8_t SVs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATE_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, course);
    _mav_put_int16_t(buf, 24, vel);
    _mav_put_int16_t(buf, 26, roll);
    _mav_put_int16_t(buf, 28, pitch);
    _mav_put_int16_t(buf, 30, HDOP);
    _mav_put_uint8_t(buf, 32, SVs);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, buf, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#else
    mavlink_usv_state_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.course = course;
    packet.vel = vel;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.HDOP = HDOP;
    packet.SVs = SVs;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)&packet, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}

/**
 * @brief Send a usv_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_state_send_struct(mavlink_channel_t chan, const mavlink_usv_state_t* usv_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_state_send(chan, usv_state->lat, usv_state->lon, usv_state->x, usv_state->y, usv_state->vel, usv_state->roll, usv_state->pitch, usv_state->yaw, usv_state->course, usv_state->HDOP, usv_state->SVs);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)usv_state, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lat, int32_t lon, float x, float y, int16_t vel, int16_t roll, int16_t pitch, float yaw, float course, int16_t HDOP, uint8_t SVs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_float(buf, 8, x);
    _mav_put_float(buf, 12, y);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, course);
    _mav_put_int16_t(buf, 24, vel);
    _mav_put_int16_t(buf, 26, roll);
    _mav_put_int16_t(buf, 28, pitch);
    _mav_put_int16_t(buf, 30, HDOP);
    _mav_put_uint8_t(buf, 32, SVs);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, buf, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#else
    mavlink_usv_state_t *packet = (mavlink_usv_state_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->x = x;
    packet->y = y;
    packet->yaw = yaw;
    packet->course = course;
    packet->vel = vel;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->HDOP = HDOP;
    packet->SVs = SVs;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATE, (const char *)packet, MAVLINK_MSG_ID_USV_STATE_MIN_LEN, MAVLINK_MSG_ID_USV_STATE_LEN, MAVLINK_MSG_ID_USV_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_STATE UNPACKING


/**
 * @brief Get field lat from usv_state message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_usv_state_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lon from usv_state message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_usv_state_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field x from usv_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_usv_state_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from usv_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_usv_state_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vel from usv_state message
 *
 * @return [m/sE3] 
 */
static inline int16_t mavlink_msg_usv_state_get_vel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field roll from usv_state message
 *
 * @return [degE2] 
 */
static inline int16_t mavlink_msg_usv_state_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field pitch from usv_state message
 *
 * @return [degE2] 
 */
static inline int16_t mavlink_msg_usv_state_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field yaw from usv_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_usv_state_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field course from usv_state message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_usv_state_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field HDOP from usv_state message
 *
 * @return [E2] Horizontal Dilution of Precision
 */
static inline int16_t mavlink_msg_usv_state_get_HDOP(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field SVs from usv_state message
 *
 * @return  Number of satellites used for positioning
 */
static inline uint8_t mavlink_msg_usv_state_get_SVs(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a usv_state message into a struct
 *
 * @param msg The message to decode
 * @param usv_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_state_decode(const mavlink_message_t* msg, mavlink_usv_state_t* usv_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_state->lat = mavlink_msg_usv_state_get_lat(msg);
    usv_state->lon = mavlink_msg_usv_state_get_lon(msg);
    usv_state->x = mavlink_msg_usv_state_get_x(msg);
    usv_state->y = mavlink_msg_usv_state_get_y(msg);
    usv_state->yaw = mavlink_msg_usv_state_get_yaw(msg);
    usv_state->course = mavlink_msg_usv_state_get_course(msg);
    usv_state->vel = mavlink_msg_usv_state_get_vel(msg);
    usv_state->roll = mavlink_msg_usv_state_get_roll(msg);
    usv_state->pitch = mavlink_msg_usv_state_get_pitch(msg);
    usv_state->HDOP = mavlink_msg_usv_state_get_HDOP(msg);
    usv_state->SVs = mavlink_msg_usv_state_get_SVs(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_STATE_LEN? msg->len : MAVLINK_MSG_ID_USV_STATE_LEN;
        memset(usv_state, 0, MAVLINK_MSG_ID_USV_STATE_LEN);
    memcpy(usv_state, _MAV_PAYLOAD(msg), len);
#endif
}
