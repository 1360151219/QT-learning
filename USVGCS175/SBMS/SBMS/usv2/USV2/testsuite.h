/** @file
 *	@brief MAVLink comm protocol testsuite generated from USV2.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef USV2_TESTSUITE_H
#define USV2_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_USV2(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_USV2(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_usv_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_STATE >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_usv_state_t packet_in = {
		963497464,963497672,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,125,192,3,70
    };
	mavlink_usv_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lng = packet_in.lng;
        packet1.lat = packet_in.lat;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.yaw = packet_in.yaw;
        packet1.pitch = packet_in.pitch;
        packet1.heel = packet_in.heel;
        packet1.velocity = packet_in.velocity;
        packet1.electric_current = packet_in.electric_current;
        packet1.voltage = packet_in.voltage;
        packet1.mode = packet_in.mode;
        packet1.thrust = packet_in.thrust;
        packet1.rudder = packet_in.rudder;
        packet1.progress = packet_in.progress;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_usv_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_usv_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_usv_state_pack(system_id, component_id, &msg , packet1.mode , packet1.lng , packet1.lat , packet1.x , packet1.y , packet1.yaw , packet1.pitch , packet1.heel , packet1.velocity , packet1.thrust , packet1.rudder , packet1.progress , packet1.electric_current , packet1.voltage );
	mavlink_msg_usv_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_usv_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.lng , packet1.lat , packet1.x , packet1.y , packet1.yaw , packet1.pitch , packet1.heel , packet1.velocity , packet1.thrust , packet1.rudder , packet1.progress , packet1.electric_current , packet1.voltage );
	mavlink_msg_usv_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_usv_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_usv_state_send(MAVLINK_COMM_1 , packet1.mode , packet1.lng , packet1.lat , packet1.x , packet1.y , packet1.yaw , packet1.pitch , packet1.heel , packet1.velocity , packet1.thrust , packet1.rudder , packet1.progress , packet1.electric_current , packet1.voltage );
	mavlink_msg_usv_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_or_usv_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_gcs_set_or_usv_ack_t packet_in = {
		17235,139
    };
	mavlink_gcs_set_or_usv_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.content = packet_in.content;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gcs_set_or_usv_ack_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gcs_set_or_usv_ack_pack(system_id, component_id, &msg , packet1.type , packet1.content );
	mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gcs_set_or_usv_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.content );
	mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_gcs_set_or_usv_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_gcs_set_or_usv_ack_send(MAVLINK_COMM_1 , packet1.type , packet1.content );
	mavlink_msg_gcs_set_or_usv_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_waypoints(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WAYPOINTS >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_waypoints_t packet_in = {
		963497464,963497672,29
    };
	mavlink_waypoints_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lng = packet_in.lng;
        packet1.lat = packet_in.lat;
        packet1.id = packet_in.id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WAYPOINTS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_waypoints_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_waypoints_pack(system_id, component_id, &msg , packet1.id , packet1.lng , packet1.lat );
	mavlink_msg_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_waypoints_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.lng , packet1.lat );
	mavlink_msg_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_waypoints_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_waypoints_send(MAVLINK_COMM_1 , packet1.id , packet1.lng , packet1.lat );
	mavlink_msg_waypoints_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_control_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONTROL_PARAM >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_control_param_t packet_in = {
		17.0,45.0,73.0,101.0,129.0,963498504,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0
    };
	mavlink_control_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.kp = packet_in.kp;
        packet1.ki = packet_in.ki;
        packet1.kd = packet_in.kd;
        packet1.los = packet_in.los;
        packet1.threshold_dis = packet_in.threshold_dis;
        packet1.xunhang_pwm = packet_in.xunhang_pwm;
        packet1.los2 = packet_in.los2;
        packet1.kp_Visual = packet_in.kp_Visual;
        packet1.ki_Visual = packet_in.ki_Visual;
        packet1.kd_Visual = packet_in.kd_Visual;
        packet1.kp_Vel = packet_in.kp_Vel;
        packet1.ki_Vel = packet_in.ki_Vel;
        packet1.kd_Vel = packet_in.kd_Vel;
        packet1.desired_vel = packet_in.desired_vel;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONTROL_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_control_param_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_control_param_pack(system_id, component_id, &msg , packet1.kp , packet1.ki , packet1.kd , packet1.los , packet1.threshold_dis , packet1.xunhang_pwm , packet1.los2 , packet1.kp_Visual , packet1.ki_Visual , packet1.kd_Visual , packet1.kp_Vel , packet1.ki_Vel , packet1.kd_Vel , packet1.desired_vel );
	mavlink_msg_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_control_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.kp , packet1.ki , packet1.kd , packet1.los , packet1.threshold_dis , packet1.xunhang_pwm , packet1.los2 , packet1.kp_Visual , packet1.ki_Visual , packet1.kd_Visual , packet1.kp_Vel , packet1.ki_Vel , packet1.kd_Vel , packet1.desired_vel );
	mavlink_msg_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_control_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_control_param_send(MAVLINK_COMM_1 , packet1.kp , packet1.ki , packet1.kd , packet1.los , packet1.threshold_dis , packet1.xunhang_pwm , packet1.los2 , packet1.kp_Visual , packet1.ki_Visual , packet1.kd_Visual , packet1.kp_Vel , packet1.ki_Vel , packet1.kd_Vel , packet1.desired_vel );
	mavlink_msg_control_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_rc_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RC_CONTROL >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_rc_control_t packet_in = {
		17.0,17443
    };
	mavlink_rc_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.RC_rudder_Angle = packet_in.RC_rudder_Angle;
        packet1.RC_v_PWM = packet_in.RC_v_PWM;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RC_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rc_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_rc_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rc_control_pack(system_id, component_id, &msg , packet1.RC_v_PWM , packet1.RC_rudder_Angle );
	mavlink_msg_rc_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rc_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.RC_v_PWM , packet1.RC_rudder_Angle );
	mavlink_msg_rc_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_rc_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_rc_control_send(MAVLINK_COMM_1 , packet1.RC_v_PWM , packet1.RC_rudder_Angle );
	mavlink_msg_rc_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_neupoint_with_course_follow(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_neupoint_with_course_follow_t packet_in = {
		963497464,963497672,73.0
    };
	mavlink_neupoint_with_course_follow_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.longi_point = packet_in.longi_point;
        packet1.lati_point = packet_in.lati_point;
        packet1.point_course = packet_in.point_course;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NEUPOINT_WITH_COURSE_FOLLOW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_neupoint_with_course_follow_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_neupoint_with_course_follow_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_neupoint_with_course_follow_pack(system_id, component_id, &msg , packet1.longi_point , packet1.lati_point , packet1.point_course );
	mavlink_msg_neupoint_with_course_follow_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_neupoint_with_course_follow_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.longi_point , packet1.lati_point , packet1.point_course );
	mavlink_msg_neupoint_with_course_follow_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_neupoint_with_course_follow_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_neupoint_with_course_follow_send(MAVLINK_COMM_1 , packet1.longi_point , packet1.lati_point , packet1.point_course );
	mavlink_msg_neupoint_with_course_follow_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_maneuverability_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_maneuverability_control_t packet_in = {
		17.0,45.0,73.0
    };
	mavlink_maneuverability_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Z_FI = packet_in.Z_FI;
        packet1.Z_Z5 = packet_in.Z_Z5;
        packet1.huizhuan_Angle = packet_in.huizhuan_Angle;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MANEUVERABILITY_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_maneuverability_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_maneuverability_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_maneuverability_control_pack(system_id, component_id, &msg , packet1.Z_FI , packet1.Z_Z5 , packet1.huizhuan_Angle );
	mavlink_msg_maneuverability_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_maneuverability_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Z_FI , packet1.Z_Z5 , packet1.huizhuan_Angle );
	mavlink_msg_maneuverability_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_maneuverability_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_maneuverability_control_send(MAVLINK_COMM_1 , packet1.Z_FI , packet1.Z_Z5 , packet1.huizhuan_Angle );
	mavlink_msg_maneuverability_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dock_message_transform(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_dock_message_transform_t packet_in = {
		963497464,963497672,73.0,101.0,129.0,157.0,185.0,963498920
    };
	mavlink_dock_message_transform_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lng = packet_in.lng;
        packet1.lat = packet_in.lat;
        packet1.velocity = packet_in.velocity;
        packet1.course = packet_in.course;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.status = packet_in.status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DOCK_MESSAGE_TRANSFORM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dock_message_transform_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_dock_message_transform_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dock_message_transform_pack(system_id, component_id, &msg , packet1.lng , packet1.lat , packet1.velocity , packet1.course , packet1.roll , packet1.pitch , packet1.yaw , packet1.status );
	mavlink_msg_dock_message_transform_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dock_message_transform_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lng , packet1.lat , packet1.velocity , packet1.course , packet1.roll , packet1.pitch , packet1.yaw , packet1.status );
	mavlink_msg_dock_message_transform_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_dock_message_transform_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_dock_message_transform_send(MAVLINK_COMM_1 , packet1.lng , packet1.lat , packet1.velocity , packet1.course , packet1.roll , packet1.pitch , packet1.yaw , packet1.status );
	mavlink_msg_dock_message_transform_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_visual_setting(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VISUAL_SETTING >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_visual_setting_t packet_in = {
		5,72,139
    };
	mavlink_visual_setting_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.visual_test = packet_in.visual_test;
        packet1.isLinear = packet_in.isLinear;
        packet1.filter_type = packet_in.filter_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VISUAL_SETTING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_visual_setting_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_visual_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_visual_setting_pack(system_id, component_id, &msg , packet1.visual_test , packet1.isLinear , packet1.filter_type );
	mavlink_msg_visual_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_visual_setting_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.visual_test , packet1.isLinear , packet1.filter_type );
	mavlink_msg_visual_setting_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_visual_setting_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_visual_setting_send(MAVLINK_COMM_1 , packet1.visual_test , packet1.isLinear , packet1.filter_type );
	mavlink_msg_visual_setting_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_motion_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOTION_INFO >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motion_info_t packet_in = {
		123.0,179.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0
    };
	mavlink_motion_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lng = packet_in.lng;
        packet1.lat = packet_in.lat;
        packet1.depth = packet_in.depth;
        packet1.height = packet_in.height;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.course = packet_in.course;
        packet1.vel = packet_in.vel;
        packet1.p = packet_in.p;
        packet1.q = packet_in.q;
        packet1.r = packet_in.r;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOTION_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motion_info_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motion_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motion_info_pack(system_id, component_id, &msg , packet1.lng , packet1.lat , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel , packet1.p , packet1.q , packet1.r );
	mavlink_msg_motion_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motion_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lng , packet1.lat , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel , packet1.p , packet1.q , packet1.r );
	mavlink_msg_motion_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motion_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motion_info_send(MAVLINK_COMM_1 , packet1.lng , packet1.lat , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel , packet1.p , packet1.q , packet1.r );
	mavlink_msg_motion_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_field_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_FIELD_STATUS >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_auv_field_status_t packet_in = {
		963497464,963497672,73.0,101.0,129.0,157.0,18483,18587,18691,18795,18899
    };
	mavlink_auv_field_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.yaw = packet_in.yaw;
        packet1.course = packet_in.course;
        packet1.depth = packet_in.depth;
        packet1.height = packet_in.height;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.vel = packet_in.vel;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_FIELD_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_auv_field_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_auv_field_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_auv_field_status_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel );
	mavlink_msg_auv_field_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_auv_field_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel );
	mavlink_msg_auv_field_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_auv_field_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_auv_field_status_send(MAVLINK_COMM_1 , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.height , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.vel );
	mavlink_msg_auv_field_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_USV2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_usv_state(system_id, component_id, last_msg);
	mavlink_test_gcs_set_or_usv_ack(system_id, component_id, last_msg);
	mavlink_test_waypoints(system_id, component_id, last_msg);
	mavlink_test_control_param(system_id, component_id, last_msg);
	mavlink_test_rc_control(system_id, component_id, last_msg);
	mavlink_test_neupoint_with_course_follow(system_id, component_id, last_msg);
	mavlink_test_maneuverability_control(system_id, component_id, last_msg);
	mavlink_test_dock_message_transform(system_id, component_id, last_msg);
	mavlink_test_visual_setting(system_id, component_id, last_msg);
	mavlink_test_motion_info(system_id, component_id, last_msg);
	mavlink_test_auv_field_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // USV2_TESTSUITE_H
