#pragma once
// MESSAGE CONTROL_PARAM PACKING

#define MAVLINK_MSG_ID_CONTROL_PARAM 153

MAVPACKED(
typedef struct __mavlink_control_param_t {
 float kp; /*< */
 float ki; /*< */
 float kd; /*< */
 float los; /*< */
 float threshold_dis; /*< */
 uint32_t xunhang_pwm; /*< */
 float los2; /*< */
 float kp_Visual; /*< */
 float ki_Visual; /*< */
 float kd_Visual; /*< */
 float kp_Vel; /*< */
 float ki_Vel; /*< */
 float kd_Vel; /*< */
 float desired_vel; /*< */
}) mavlink_control_param_t;

#define MAVLINK_MSG_ID_CONTROL_PARAM_LEN 56
#define MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN 56
#define MAVLINK_MSG_ID_153_LEN 56
#define MAVLINK_MSG_ID_153_MIN_LEN 56

#define MAVLINK_MSG_ID_CONTROL_PARAM_CRC 91
#define MAVLINK_MSG_ID_153_CRC 91



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL_PARAM { \
	153, \
	"CONTROL_PARAM", \
	14, \
	{  { "kp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_param_t, kp) }, \
         { "ki", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_param_t, ki) }, \
         { "kd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_param_t, kd) }, \
         { "los", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_param_t, los) }, \
         { "threshold_dis", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_param_t, threshold_dis) }, \
         { "xunhang_pwm", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_control_param_t, xunhang_pwm) }, \
         { "los2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_control_param_t, los2) }, \
         { "kp_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_control_param_t, kp_Visual) }, \
         { "ki_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_control_param_t, ki_Visual) }, \
         { "kd_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_control_param_t, kd_Visual) }, \
         { "kp_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_control_param_t, kp_Vel) }, \
         { "ki_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_control_param_t, ki_Vel) }, \
         { "kd_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_control_param_t, kd_Vel) }, \
         { "desired_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_control_param_t, desired_vel) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL_PARAM { \
	"CONTROL_PARAM", \
	14, \
	{  { "kp", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_control_param_t, kp) }, \
         { "ki", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_control_param_t, ki) }, \
         { "kd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_control_param_t, kd) }, \
         { "los", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_control_param_t, los) }, \
         { "threshold_dis", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_control_param_t, threshold_dis) }, \
         { "xunhang_pwm", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_control_param_t, xunhang_pwm) }, \
         { "los2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_control_param_t, los2) }, \
         { "kp_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_control_param_t, kp_Visual) }, \
         { "ki_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_control_param_t, ki_Visual) }, \
         { "kd_Visual", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_control_param_t, kd_Visual) }, \
         { "kp_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_control_param_t, kp_Vel) }, \
         { "ki_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_control_param_t, ki_Vel) }, \
         { "kd_Vel", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_control_param_t, kd_Vel) }, \
         { "desired_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_control_param_t, desired_vel) }, \
         } \
}
#endif

/**
 * @brief Pack a control_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param kp 
 * @param ki 
 * @param kd 
 * @param los 
 * @param threshold_dis 
 * @param xunhang_pwm 
 * @param los2 
 * @param kp_Visual 
 * @param ki_Visual 
 * @param kd_Visual 
 * @param kp_Vel 
 * @param ki_Vel 
 * @param kd_Vel 
 * @param desired_vel 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float kp, float ki, float kd, float los, float threshold_dis, uint32_t xunhang_pwm, float los2, float kp_Visual, float ki_Visual, float kd_Visual, float kp_Vel, float ki_Vel, float kd_Vel, float desired_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CONTROL_PARAM_LEN];
	_mav_put_float(buf, 0, kp);
	_mav_put_float(buf, 4, ki);
	_mav_put_float(buf, 8, kd);
	_mav_put_float(buf, 12, los);
	_mav_put_float(buf, 16, threshold_dis);
	_mav_put_uint32_t(buf, 20, xunhang_pwm);
	_mav_put_float(buf, 24, los2);
	_mav_put_float(buf, 28, kp_Visual);
	_mav_put_float(buf, 32, ki_Visual);
	_mav_put_float(buf, 36, kd_Visual);
	_mav_put_float(buf, 40, kp_Vel);
	_mav_put_float(buf, 44, ki_Vel);
	_mav_put_float(buf, 48, kd_Vel);
	_mav_put_float(buf, 52, desired_vel);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
#else
	mavlink_control_param_t packet;
	packet.kp = kp;
	packet.ki = ki;
	packet.kd = kd;
	packet.los = los;
	packet.threshold_dis = threshold_dis;
	packet.xunhang_pwm = xunhang_pwm;
	packet.los2 = los2;
	packet.kp_Visual = kp_Visual;
	packet.ki_Visual = ki_Visual;
	packet.kd_Visual = kd_Visual;
	packet.kp_Vel = kp_Vel;
	packet.ki_Vel = ki_Vel;
	packet.kd_Vel = kd_Vel;
	packet.desired_vel = desired_vel;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CONTROL_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
}

/**
 * @brief Pack a control_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param kp 
 * @param ki 
 * @param kd 
 * @param los 
 * @param threshold_dis 
 * @param xunhang_pwm 
 * @param los2 
 * @param kp_Visual 
 * @param ki_Visual 
 * @param kd_Visual 
 * @param kp_Vel 
 * @param ki_Vel 
 * @param kd_Vel 
 * @param desired_vel 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float kp,float ki,float kd,float los,float threshold_dis,uint32_t xunhang_pwm,float los2,float kp_Visual,float ki_Visual,float kd_Visual,float kp_Vel,float ki_Vel,float kd_Vel,float desired_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CONTROL_PARAM_LEN];
	_mav_put_float(buf, 0, kp);
	_mav_put_float(buf, 4, ki);
	_mav_put_float(buf, 8, kd);
	_mav_put_float(buf, 12, los);
	_mav_put_float(buf, 16, threshold_dis);
	_mav_put_uint32_t(buf, 20, xunhang_pwm);
	_mav_put_float(buf, 24, los2);
	_mav_put_float(buf, 28, kp_Visual);
	_mav_put_float(buf, 32, ki_Visual);
	_mav_put_float(buf, 36, kd_Visual);
	_mav_put_float(buf, 40, kp_Vel);
	_mav_put_float(buf, 44, ki_Vel);
	_mav_put_float(buf, 48, kd_Vel);
	_mav_put_float(buf, 52, desired_vel);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
#else
	mavlink_control_param_t packet;
	packet.kp = kp;
	packet.ki = ki;
	packet.kd = kd;
	packet.los = los;
	packet.threshold_dis = threshold_dis;
	packet.xunhang_pwm = xunhang_pwm;
	packet.los2 = los2;
	packet.kp_Visual = kp_Visual;
	packet.ki_Visual = ki_Visual;
	packet.kd_Visual = kd_Visual;
	packet.kp_Vel = kp_Vel;
	packet.ki_Vel = ki_Vel;
	packet.kd_Vel = kd_Vel;
	packet.desired_vel = desired_vel;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CONTROL_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
}

/**
 * @brief Encode a control_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_param_t* control_param)
{
	return mavlink_msg_control_param_pack(system_id, component_id, msg, control_param->kp, control_param->ki, control_param->kd, control_param->los, control_param->threshold_dis, control_param->xunhang_pwm, control_param->los2, control_param->kp_Visual, control_param->ki_Visual, control_param->kd_Visual, control_param->kp_Vel, control_param->ki_Vel, control_param->kd_Vel, control_param->desired_vel);
}

/**
 * @brief Encode a control_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_param_t* control_param)
{
	return mavlink_msg_control_param_pack_chan(system_id, component_id, chan, msg, control_param->kp, control_param->ki, control_param->kd, control_param->los, control_param->threshold_dis, control_param->xunhang_pwm, control_param->los2, control_param->kp_Visual, control_param->ki_Visual, control_param->kd_Visual, control_param->kp_Vel, control_param->ki_Vel, control_param->kd_Vel, control_param->desired_vel);
}

/**
 * @brief Send a control_param message
 * @param chan MAVLink channel to send the message
 *
 * @param kp 
 * @param ki 
 * @param kd 
 * @param los 
 * @param threshold_dis 
 * @param xunhang_pwm 
 * @param los2 
 * @param kp_Visual 
 * @param ki_Visual 
 * @param kd_Visual 
 * @param kp_Vel 
 * @param ki_Vel 
 * @param kd_Vel 
 * @param desired_vel 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_param_send(mavlink_channel_t chan, float kp, float ki, float kd, float los, float threshold_dis, uint32_t xunhang_pwm, float los2, float kp_Visual, float ki_Visual, float kd_Visual, float kp_Vel, float ki_Vel, float kd_Vel, float desired_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CONTROL_PARAM_LEN];
	_mav_put_float(buf, 0, kp);
	_mav_put_float(buf, 4, ki);
	_mav_put_float(buf, 8, kd);
	_mav_put_float(buf, 12, los);
	_mav_put_float(buf, 16, threshold_dis);
	_mav_put_uint32_t(buf, 20, xunhang_pwm);
	_mav_put_float(buf, 24, los2);
	_mav_put_float(buf, 28, kp_Visual);
	_mav_put_float(buf, 32, ki_Visual);
	_mav_put_float(buf, 36, kd_Visual);
	_mav_put_float(buf, 40, kp_Vel);
	_mav_put_float(buf, 44, ki_Vel);
	_mav_put_float(buf, 48, kd_Vel);
	_mav_put_float(buf, 52, desired_vel);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_PARAM, buf, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
#else
	mavlink_control_param_t packet;
	packet.kp = kp;
	packet.ki = ki;
	packet.kd = kd;
	packet.los = los;
	packet.threshold_dis = threshold_dis;
	packet.xunhang_pwm = xunhang_pwm;
	packet.los2 = los2;
	packet.kp_Visual = kp_Visual;
	packet.ki_Visual = ki_Visual;
	packet.kd_Visual = kd_Visual;
	packet.kp_Vel = kp_Vel;
	packet.ki_Vel = ki_Vel;
	packet.kd_Vel = kd_Vel;
	packet.desired_vel = desired_vel;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_PARAM, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
#endif
}

/**
 * @brief Send a control_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_param_send_struct(mavlink_channel_t chan, const mavlink_control_param_t* control_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_param_send(chan, control_param->kp, control_param->ki, control_param->kd, control_param->los, control_param->threshold_dis, control_param->xunhang_pwm, control_param->los2, control_param->kp_Visual, control_param->ki_Visual, control_param->kd_Visual, control_param->kp_Vel, control_param->ki_Vel, control_param->kd_Vel, control_param->desired_vel);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_PARAM, (const char *)control_param, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float kp, float ki, float kd, float los, float threshold_dis, uint32_t xunhang_pwm, float los2, float kp_Visual, float ki_Visual, float kd_Visual, float kp_Vel, float ki_Vel, float kd_Vel, float desired_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, kp);
	_mav_put_float(buf, 4, ki);
	_mav_put_float(buf, 8, kd);
	_mav_put_float(buf, 12, los);
	_mav_put_float(buf, 16, threshold_dis);
	_mav_put_uint32_t(buf, 20, xunhang_pwm);
	_mav_put_float(buf, 24, los2);
	_mav_put_float(buf, 28, kp_Visual);
	_mav_put_float(buf, 32, ki_Visual);
	_mav_put_float(buf, 36, kd_Visual);
	_mav_put_float(buf, 40, kp_Vel);
	_mav_put_float(buf, 44, ki_Vel);
	_mav_put_float(buf, 48, kd_Vel);
	_mav_put_float(buf, 52, desired_vel);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_PARAM, buf, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
#else
	mavlink_control_param_t *packet = (mavlink_control_param_t *)msgbuf;
	packet->kp = kp;
	packet->ki = ki;
	packet->kd = kd;
	packet->los = los;
	packet->threshold_dis = threshold_dis;
	packet->xunhang_pwm = xunhang_pwm;
	packet->los2 = los2;
	packet->kp_Visual = kp_Visual;
	packet->ki_Visual = ki_Visual;
	packet->kd_Visual = kd_Visual;
	packet->kp_Vel = kp_Vel;
	packet->ki_Vel = ki_Vel;
	packet->kd_Vel = kd_Vel;
	packet->desired_vel = desired_vel;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_PARAM, (const char *)packet, MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_LEN, MAVLINK_MSG_ID_CONTROL_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL_PARAM UNPACKING


/**
 * @brief Get field kp from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ki from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_ki(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field kd from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kd(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field los from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_los(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field threshold_dis from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_threshold_dis(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field xunhang_pwm from control_param message
 *
 * @return 
 */
static inline uint32_t mavlink_msg_control_param_get_xunhang_pwm(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field los2 from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_los2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field kp_Visual from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kp_Visual(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field ki_Visual from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_ki_Visual(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field kd_Visual from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kd_Visual(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field kp_Vel from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kp_Vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field ki_Vel from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_ki_Vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field kd_Vel from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_kd_Vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field desired_vel from control_param message
 *
 * @return 
 */
static inline float mavlink_msg_control_param_get_desired_vel(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Decode a control_param message into a struct
 *
 * @param msg The message to decode
 * @param control_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_param_decode(const mavlink_message_t* msg, mavlink_control_param_t* control_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	control_param->kp = mavlink_msg_control_param_get_kp(msg);
	control_param->ki = mavlink_msg_control_param_get_ki(msg);
	control_param->kd = mavlink_msg_control_param_get_kd(msg);
	control_param->los = mavlink_msg_control_param_get_los(msg);
	control_param->threshold_dis = mavlink_msg_control_param_get_threshold_dis(msg);
	control_param->xunhang_pwm = mavlink_msg_control_param_get_xunhang_pwm(msg);
	control_param->los2 = mavlink_msg_control_param_get_los2(msg);
	control_param->kp_Visual = mavlink_msg_control_param_get_kp_Visual(msg);
	control_param->ki_Visual = mavlink_msg_control_param_get_ki_Visual(msg);
	control_param->kd_Visual = mavlink_msg_control_param_get_kd_Visual(msg);
	control_param->kp_Vel = mavlink_msg_control_param_get_kp_Vel(msg);
	control_param->ki_Vel = mavlink_msg_control_param_get_ki_Vel(msg);
	control_param->kd_Vel = mavlink_msg_control_param_get_kd_Vel(msg);
	control_param->desired_vel = mavlink_msg_control_param_get_desired_vel(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_PARAM_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_PARAM_LEN;
        memset(control_param, 0, MAVLINK_MSG_ID_CONTROL_PARAM_LEN);
	memcpy(control_param, _MAV_PAYLOAD(msg), len);
#endif
}
