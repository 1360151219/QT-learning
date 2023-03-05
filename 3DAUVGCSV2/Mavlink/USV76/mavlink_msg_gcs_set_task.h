#pragma once
// MESSAGE GCS_SET_TASK PACKING

#define MAVLINK_MSG_ID_GCS_SET_TASK 156

MAVPACKED(
typedef struct __mavlink_gcs_set_task_t {
 float course; /*< [degree] */
 float xunhang_pwm; /*< [m/s] */
 uint16_t time_allow; /*< [s] */
 uint8_t tasktype; /*<  */
}) mavlink_gcs_set_task_t;

#define MAVLINK_MSG_ID_GCS_SET_TASK_LEN 11
#define MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN 11
#define MAVLINK_MSG_ID_156_LEN 11
#define MAVLINK_MSG_ID_156_MIN_LEN 11

#define MAVLINK_MSG_ID_GCS_SET_TASK_CRC 215
#define MAVLINK_MSG_ID_156_CRC 215



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SET_TASK { \
    156, \
    "GCS_SET_TASK", \
    4, \
    {  { "tasktype", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_gcs_set_task_t, tasktype) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_task_t, course) }, \
         { "time_allow", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gcs_set_task_t, time_allow) }, \
         { "xunhang_pwm", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_task_t, xunhang_pwm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SET_TASK { \
    "GCS_SET_TASK", \
    4, \
    {  { "tasktype", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_gcs_set_task_t, tasktype) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_set_task_t, course) }, \
         { "time_allow", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_gcs_set_task_t, time_allow) }, \
         { "xunhang_pwm", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_set_task_t, xunhang_pwm) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_set_task message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tasktype  
 * @param course [degree] 
 * @param time_allow [s] 
 * @param xunhang_pwm [m/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_task_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t tasktype, float course, uint16_t time_allow, float xunhang_pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_TASK_LEN];
    _mav_put_float(buf, 0, course);
    _mav_put_float(buf, 4, xunhang_pwm);
    _mav_put_uint16_t(buf, 8, time_allow);
    _mav_put_uint8_t(buf, 10, tasktype);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_TASK_LEN);
#else
    mavlink_gcs_set_task_t packet;
    packet.course = course;
    packet.xunhang_pwm = xunhang_pwm;
    packet.time_allow = time_allow;
    packet.tasktype = tasktype;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_TASK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_TASK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
}

/**
 * @brief Pack a gcs_set_task message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tasktype  
 * @param course [degree] 
 * @param time_allow [s] 
 * @param xunhang_pwm [m/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_set_task_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t tasktype,float course,uint16_t time_allow,float xunhang_pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_TASK_LEN];
    _mav_put_float(buf, 0, course);
    _mav_put_float(buf, 4, xunhang_pwm);
    _mav_put_uint16_t(buf, 8, time_allow);
    _mav_put_uint8_t(buf, 10, tasktype);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SET_TASK_LEN);
#else
    mavlink_gcs_set_task_t packet;
    packet.course = course;
    packet.xunhang_pwm = xunhang_pwm;
    packet.time_allow = time_allow;
    packet.tasktype = tasktype;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SET_TASK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SET_TASK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
}

/**
 * @brief Encode a gcs_set_task struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_task C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_task_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_set_task_t* gcs_set_task)
{
    return mavlink_msg_gcs_set_task_pack(system_id, component_id, msg, gcs_set_task->tasktype, gcs_set_task->course, gcs_set_task->time_allow, gcs_set_task->xunhang_pwm);
}

/**
 * @brief Encode a gcs_set_task struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_set_task C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_set_task_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_set_task_t* gcs_set_task)
{
    return mavlink_msg_gcs_set_task_pack_chan(system_id, component_id, chan, msg, gcs_set_task->tasktype, gcs_set_task->course, gcs_set_task->time_allow, gcs_set_task->xunhang_pwm);
}

/**
 * @brief Send a gcs_set_task message
 * @param chan MAVLink channel to send the message
 *
 * @param tasktype  
 * @param course [degree] 
 * @param time_allow [s] 
 * @param xunhang_pwm [m/s] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_set_task_send(mavlink_channel_t chan, uint8_t tasktype, float course, uint16_t time_allow, float xunhang_pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SET_TASK_LEN];
    _mav_put_float(buf, 0, course);
    _mav_put_float(buf, 4, xunhang_pwm);
    _mav_put_uint16_t(buf, 8, time_allow);
    _mav_put_uint8_t(buf, 10, tasktype);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_TASK, buf, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
#else
    mavlink_gcs_set_task_t packet;
    packet.course = course;
    packet.xunhang_pwm = xunhang_pwm;
    packet.time_allow = time_allow;
    packet.tasktype = tasktype;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_TASK, (const char *)&packet, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
#endif
}

/**
 * @brief Send a gcs_set_task message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_set_task_send_struct(mavlink_channel_t chan, const mavlink_gcs_set_task_t* gcs_set_task)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_set_task_send(chan, gcs_set_task->tasktype, gcs_set_task->course, gcs_set_task->time_allow, gcs_set_task->xunhang_pwm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_TASK, (const char *)gcs_set_task, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SET_TASK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_set_task_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t tasktype, float course, uint16_t time_allow, float xunhang_pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, course);
    _mav_put_float(buf, 4, xunhang_pwm);
    _mav_put_uint16_t(buf, 8, time_allow);
    _mav_put_uint8_t(buf, 10, tasktype);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_TASK, buf, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
#else
    mavlink_gcs_set_task_t *packet = (mavlink_gcs_set_task_t *)msgbuf;
    packet->course = course;
    packet->xunhang_pwm = xunhang_pwm;
    packet->time_allow = time_allow;
    packet->tasktype = tasktype;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SET_TASK, (const char *)packet, MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_LEN, MAVLINK_MSG_ID_GCS_SET_TASK_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SET_TASK UNPACKING


/**
 * @brief Get field tasktype from gcs_set_task message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_gcs_set_task_get_tasktype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field course from gcs_set_task message
 *
 * @return [degree] 
 */
static inline float mavlink_msg_gcs_set_task_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field time_allow from gcs_set_task message
 *
 * @return [s] 
 */
static inline uint16_t mavlink_msg_gcs_set_task_get_time_allow(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field xunhang_pwm from gcs_set_task message
 *
 * @return [m/s] 
 */
static inline float mavlink_msg_gcs_set_task_get_xunhang_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a gcs_set_task message into a struct
 *
 * @param msg The message to decode
 * @param gcs_set_task C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_set_task_decode(const mavlink_message_t* msg, mavlink_gcs_set_task_t* gcs_set_task)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_set_task->course = mavlink_msg_gcs_set_task_get_course(msg);
    gcs_set_task->xunhang_pwm = mavlink_msg_gcs_set_task_get_xunhang_pwm(msg);
    gcs_set_task->time_allow = mavlink_msg_gcs_set_task_get_time_allow(msg);
    gcs_set_task->tasktype = mavlink_msg_gcs_set_task_get_tasktype(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SET_TASK_LEN? msg->len : MAVLINK_MSG_ID_GCS_SET_TASK_LEN;
        memset(gcs_set_task, 0, MAVLINK_MSG_ID_GCS_SET_TASK_LEN);
    memcpy(gcs_set_task, _MAV_PAYLOAD(msg), len);
#endif
}
