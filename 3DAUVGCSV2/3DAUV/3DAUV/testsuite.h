/** @file
 *    @brief MAVLink comm protocol testsuite generated from 3DAUV.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef 3DAUV_TESTSUITE_H
#define 3DAUV_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_3DAUV(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_3DAUV(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_auv_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_heartbeat_t packet_in = {
        17.0,17,84,151,218,29,96
    };
    mavlink_auv_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage = packet_in.voltage;
        packet1.mode = packet_in.mode;
        packet1.task_id = packet_in.task_id;
        packet1.autoWorking = packet_in.autoWorking;
        packet1.leak = packet_in.leak;
        packet1.humi = packet_in.humi;
        packet1.temp = packet_in.temp;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_heartbeat_pack(system_id, component_id, &msg , packet1.mode , packet1.task_id , packet1.autoWorking , packet1.leak , packet1.humi , packet1.temp , packet1.voltage );
    mavlink_msg_auv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.task_id , packet1.autoWorking , packet1.leak , packet1.humi , packet1.temp , packet1.voltage );
    mavlink_msg_auv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_heartbeat_send(MAVLINK_COMM_1 , packet1.mode , packet1.task_id , packet1.autoWorking , packet1.leak , packet1.humi , packet1.temp , packet1.voltage );
    mavlink_msg_auv_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_field_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_FIELD_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_field_state_t packet_in = {
        963497464,963497672,73.0,101.0,129.0,157.0,18483,18587,18691,18795,18899,235
    };
    mavlink_auv_field_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.yaw = packet_in.yaw;
        packet1.course = packet_in.course;
        packet1.depth = packet_in.depth;
        packet1.vel = packet_in.vel;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.HDOP = packet_in.HDOP;
        packet1.SVs = packet_in.SVs;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_FIELD_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_FIELD_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_field_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_field_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_field_state_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
    mavlink_msg_auv_field_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_field_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
    mavlink_msg_auv_field_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_field_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_field_state_send(MAVLINK_COMM_1 , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.depth , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
    mavlink_msg_auv_field_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_tack_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_TACK_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_tack_state_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0
    };
    mavlink_auv_tack_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.desiredDepth = packet_in.desiredDepth;
        packet1.desidredPitch = packet_in.desidredPitch;
        packet1.desiredCourse = packet_in.desiredCourse;
        packet1.depth = packet_in.depth;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_TACK_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_tack_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_tack_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_tack_state_pack(system_id, component_id, &msg , packet1.desiredDepth , packet1.desidredPitch , packet1.desiredCourse , packet1.depth , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_auv_tack_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_tack_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.desiredDepth , packet1.desidredPitch , packet1.desiredCourse , packet1.depth , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_auv_tack_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_tack_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_tack_state_send(MAVLINK_COMM_1 , packet1.desiredDepth , packet1.desidredPitch , packet1.desiredCourse , packet1.depth , packet1.roll , packet1.pitch , packet1.yaw );
    mavlink_msg_auv_tack_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_actuator_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_actuator_control_t packet_in = {
        17235,17339,17443,17547,17651
    };
    mavlink_auv_actuator_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.propeller_pwm = packet_in.propeller_pwm;
        packet1.stern_up = packet_in.stern_up;
        packet1.stern_down = packet_in.stern_down;
        packet1.stern_right = packet_in.stern_right;
        packet1.stern_left = packet_in.stern_left;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_ACTUATOR_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_actuator_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_actuator_control_pack(system_id, component_id, &msg , packet1.propeller_pwm , packet1.stern_up , packet1.stern_down , packet1.stern_right , packet1.stern_left );
    mavlink_msg_auv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_actuator_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.propeller_pwm , packet1.stern_up , packet1.stern_down , packet1.stern_right , packet1.stern_left );
    mavlink_msg_auv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_actuator_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_actuator_control_send(MAVLINK_COMM_1 , packet1.propeller_pwm , packet1.stern_up , packet1.stern_down , packet1.stern_right , packet1.stern_left );
    mavlink_msg_auv_actuator_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_waypoints(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_WAYPOINTS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_waypoints_t packet_in = {
        963497464,963497672,73.0,41
    };
    mavlink_gcs_set_waypoints_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.waypoint_lng = packet_in.waypoint_lng;
        packet1.waypoint_lat = packet_in.waypoint_lat;
        packet1.waypoint_depth = packet_in.waypoint_depth;
        packet1.waypoint_index = packet_in.waypoint_index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_WAYPOINTS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_waypoints_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_waypoints_pack(system_id, component_id, &msg , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat , packet1.waypoint_depth );
    mavlink_msg_gcs_set_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_waypoints_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat , packet1.waypoint_depth );
    mavlink_msg_gcs_set_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_waypoints_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_waypoints_send(MAVLINK_COMM_1 , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat , packet1.waypoint_depth );
    mavlink_msg_gcs_set_waypoints_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_control_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_control_param_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,18899
    };
    mavlink_gcs_set_control_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.kp_psi = packet_in.kp_psi;
        packet1.ki_psi = packet_in.ki_psi;
        packet1.kd_psi = packet_in.kd_psi;
        packet1.kp_theta = packet_in.kp_theta;
        packet1.ki_theta = packet_in.ki_theta;
        packet1.kd_theta = packet_in.kd_theta;
        packet1.k_psi_guid = packet_in.k_psi_guid;
        packet1.k_theta_guid = packet_in.k_theta_guid;
        packet1.xunhang_pwm = packet_in.xunhang_pwm;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_pack(system_id, component_id, &msg , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_theta , packet1.ki_theta , packet1.kd_theta , packet1.k_psi_guid , packet1.k_theta_guid );
    mavlink_msg_gcs_set_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_theta , packet1.ki_theta , packet1.kd_theta , packet1.k_psi_guid , packet1.k_theta_guid );
    mavlink_msg_gcs_set_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_control_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_send(MAVLINK_COMM_1 , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_theta , packet1.ki_theta , packet1.kd_theta , packet1.k_psi_guid , packet1.k_theta_guid );
    mavlink_msg_gcs_set_control_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_or_rpi_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_or_rpi_ack_t packet_in = {
        17235,139
    };
    mavlink_gcs_set_or_rpi_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.content = packet_in.content;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_OR_RPI_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_rpi_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_or_rpi_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_rpi_ack_pack(system_id, component_id, &msg , packet1.type , packet1.content );
    mavlink_msg_gcs_set_or_rpi_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_rpi_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.content );
    mavlink_msg_gcs_set_or_rpi_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_or_rpi_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_rpi_ack_send(MAVLINK_COMM_1 , packet1.type , packet1.content );
    mavlink_msg_gcs_set_or_rpi_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_task(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_TASK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_task_t packet_in = {
        17.0,45.0,17651,17755,41
    };
    mavlink_gcs_set_task_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.depth = packet_in.depth;
        packet1.course = packet_in.course;
        packet1.time_allow = packet_in.time_allow;
        packet1.xunhang_pwm = packet_in.xunhang_pwm;
        packet1.tasktype = packet_in.tasktype;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_TASK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_task_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_task_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_task_pack(system_id, component_id, &msg , packet1.tasktype , packet1.depth , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
    mavlink_msg_gcs_set_task_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_task_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tasktype , packet1.depth , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
    mavlink_msg_gcs_set_task_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_task_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_task_send(MAVLINK_COMM_1 , packet1.tasktype , packet1.depth , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
    mavlink_msg_gcs_set_task_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_servo_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_servo_param_t packet_in = {
        17235,17339,17443,17547,17651,163,230
    };
    mavlink_gcs_set_servo_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.propeller_mid_pwm = packet_in.propeller_mid_pwm;
        packet1.stern_up_mid_pwm = packet_in.stern_up_mid_pwm;
        packet1.stern_down_mid_pwm = packet_in.stern_down_mid_pwm;
        packet1.stern_right_mid_pwm = packet_in.stern_right_mid_pwm;
        packet1.stern_left_mid_pwm = packet_in.stern_left_mid_pwm;
        packet1.offset_rudder = packet_in.offset_rudder;
        packet1.offset_stern = packet_in.offset_stern;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_SERVO_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_servo_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_servo_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_servo_param_pack(system_id, component_id, &msg , packet1.propeller_mid_pwm , packet1.stern_up_mid_pwm , packet1.stern_down_mid_pwm , packet1.stern_right_mid_pwm , packet1.stern_left_mid_pwm , packet1.offset_rudder , packet1.offset_stern );
    mavlink_msg_gcs_set_servo_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_servo_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.propeller_mid_pwm , packet1.stern_up_mid_pwm , packet1.stern_down_mid_pwm , packet1.stern_right_mid_pwm , packet1.stern_left_mid_pwm , packet1.offset_rudder , packet1.offset_stern );
    mavlink_msg_gcs_set_servo_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_servo_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_servo_param_send(MAVLINK_COMM_1 , packet1.propeller_mid_pwm , packet1.stern_up_mid_pwm , packet1.stern_down_mid_pwm , packet1.stern_right_mid_pwm , packet1.stern_left_mid_pwm , packet1.offset_rudder , packet1.offset_stern );
    mavlink_msg_gcs_set_servo_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_adrc_param(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_ADRC_PARAM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_adrc_param_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_auv_adrc_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.eso_beta01 = packet_in.eso_beta01;
        packet1.eso_beta02 = packet_in.eso_beta02;
        packet1.eso_beta03 = packet_in.eso_beta03;
        packet1.nlsef_r = packet_in.nlsef_r;
        packet1.nlsef_c = packet_in.nlsef_c;
        packet1.nlsef_h = packet_in.nlsef_h;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_ADRC_PARAM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_param_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_adrc_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_param_pack(system_id, component_id, &msg , packet1.eso_beta01 , packet1.eso_beta02 , packet1.eso_beta03 , packet1.nlsef_r , packet1.nlsef_c , packet1.nlsef_h );
    mavlink_msg_auv_adrc_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.eso_beta01 , packet1.eso_beta02 , packet1.eso_beta03 , packet1.nlsef_r , packet1.nlsef_c , packet1.nlsef_h );
    mavlink_msg_auv_adrc_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_adrc_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_param_send(MAVLINK_COMM_1 , packet1.eso_beta01 , packet1.eso_beta02 , packet1.eso_beta03 , packet1.nlsef_r , packet1.nlsef_c , packet1.nlsef_h );
    mavlink_msg_auv_adrc_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_adrc_eso(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_ADRC_ESO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_adrc_eso_t packet_in = {
        17.0,45.0,73.0,101.0
    };
    mavlink_auv_adrc_eso_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.eso_pitch = packet_in.eso_pitch;
        packet1.eso_q = packet_in.eso_q;
        packet1.eso_z3 = packet_in.eso_z3;
        packet1.q = packet_in.q;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_ADRC_ESO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_eso_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_adrc_eso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_eso_pack(system_id, component_id, &msg , packet1.eso_pitch , packet1.eso_q , packet1.eso_z3 , packet1.q );
    mavlink_msg_auv_adrc_eso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_eso_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.eso_pitch , packet1.eso_q , packet1.eso_z3 , packet1.q );
    mavlink_msg_auv_adrc_eso_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_adrc_eso_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_adrc_eso_send(MAVLINK_COMM_1 , packet1.eso_pitch , packet1.eso_q , packet1.eso_z3 , packet1.q );
    mavlink_msg_auv_adrc_eso_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_arm_control_and_tcp_feed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_ARM_CONTROL_AND_TCP_FEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_arm_control_and_tcp_feed_t packet_in = {
        17235,17339,17443,17547
    };
    mavlink_auv_arm_control_and_tcp_feed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.joint1Pos = packet_in.joint1Pos;
        packet1.joint2Pos = packet_in.joint2Pos;
        packet1.joint3Pos = packet_in.joint3Pos;
        packet1.joint4Pos = packet_in.joint4Pos;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_ARM_CONTROL_AND_TCP_FEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_ARM_CONTROL_AND_TCP_FEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_control_and_tcp_feed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_arm_control_and_tcp_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_control_and_tcp_feed_pack(system_id, component_id, &msg , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_control_and_tcp_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_control_and_tcp_feed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_control_and_tcp_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_arm_control_and_tcp_feed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_control_and_tcp_feed_send(MAVLINK_COMM_1 , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_control_and_tcp_feed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_arm_wireless_feed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_arm_wireless_feed_t packet_in = {
        17235,17339,17443,17547
    };
    mavlink_auv_arm_wireless_feed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.joint1Pos = packet_in.joint1Pos;
        packet1.joint2Pos = packet_in.joint2Pos;
        packet1.joint3Pos = packet_in.joint3Pos;
        packet1.joint4Pos = packet_in.joint4Pos;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_ARM_WIRELESS_FEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_wireless_feed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_arm_wireless_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_wireless_feed_pack(system_id, component_id, &msg , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_wireless_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_wireless_feed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_wireless_feed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_arm_wireless_feed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_arm_wireless_feed_send(MAVLINK_COMM_1 , packet1.joint1Pos , packet1.joint2Pos , packet1.joint3Pos , packet1.joint4Pos );
    mavlink_msg_auv_arm_wireless_feed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_thrusters_direct_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_thrusters_direct_control_t packet_in = {
        5,72,139,206
    };
    mavlink_auv_thrusters_direct_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.bow_ver = packet_in.bow_ver;
        packet1.stern_ver = packet_in.stern_ver;
        packet1.bow_hor = packet_in.bow_hor;
        packet1.stern_hor = packet_in.stern_hor;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_THRUSTERS_DIRECT_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_direct_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_thrusters_direct_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_direct_control_pack(system_id, component_id, &msg , packet1.bow_ver , packet1.stern_ver , packet1.bow_hor , packet1.stern_hor );
    mavlink_msg_auv_thrusters_direct_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_direct_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.bow_ver , packet1.stern_ver , packet1.bow_hor , packet1.stern_hor );
    mavlink_msg_auv_thrusters_direct_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_thrusters_direct_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_direct_control_send(MAVLINK_COMM_1 , packet1.bow_ver , packet1.stern_ver , packet1.bow_hor , packet1.stern_hor );
    mavlink_msg_auv_thrusters_direct_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_thrusters_indirect_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_thrusters_indirect_control_t packet_in = {
        5,72,139,206
    };
    mavlink_auv_thrusters_indirect_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.heave = packet_in.heave;
        packet1.pitch = packet_in.pitch;
        packet1.surge = packet_in.surge;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_THRUSTERS_INDIRECT_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_indirect_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_thrusters_indirect_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_indirect_control_pack(system_id, component_id, &msg , packet1.heave , packet1.pitch , packet1.surge , packet1.yaw );
    mavlink_msg_auv_thrusters_indirect_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_indirect_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.heave , packet1.pitch , packet1.surge , packet1.yaw );
    mavlink_msg_auv_thrusters_indirect_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_thrusters_indirect_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_thrusters_indirect_control_send(MAVLINK_COMM_1 , packet1.heave , packet1.pitch , packet1.surge , packet1.yaw );
    mavlink_msg_auv_thrusters_indirect_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_control_param_thrusters(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_control_param_thrusters_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,19107
    };
    mavlink_gcs_set_control_param_thrusters_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.kp_depth = packet_in.kp_depth;
        packet1.ki_depth = packet_in.ki_depth;
        packet1.kd_depth = packet_in.kd_depth;
        packet1.kp_pitch = packet_in.kp_pitch;
        packet1.ki_pitch = packet_in.ki_pitch;
        packet1.kd_pitch = packet_in.kd_pitch;
        packet1.kp_course = packet_in.kp_course;
        packet1.ki_course = packet_in.ki_course;
        packet1.kd_course = packet_in.kd_course;
        packet1.xunhang_pwm = packet_in.xunhang_pwm;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_CONTROL_PARAM_THRUSTERS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_thrusters_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_control_param_thrusters_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_thrusters_pack(system_id, component_id, &msg , packet1.xunhang_pwm , packet1.kp_depth , packet1.ki_depth , packet1.kd_depth , packet1.kp_pitch , packet1.ki_pitch , packet1.kd_pitch , packet1.kp_course , packet1.ki_course , packet1.kd_course );
    mavlink_msg_gcs_set_control_param_thrusters_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_thrusters_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xunhang_pwm , packet1.kp_depth , packet1.ki_depth , packet1.kd_depth , packet1.kp_pitch , packet1.ki_pitch , packet1.kd_pitch , packet1.kp_course , packet1.ki_course , packet1.kd_course );
    mavlink_msg_gcs_set_control_param_thrusters_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_control_param_thrusters_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_thrusters_send(MAVLINK_COMM_1 , packet1.xunhang_pwm , packet1.kp_depth , packet1.ki_depth , packet1.kd_depth , packet1.kp_pitch , packet1.ki_pitch , packet1.kd_pitch , packet1.kp_course , packet1.ki_course , packet1.kd_course );
    mavlink_msg_gcs_set_control_param_thrusters_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_auv_params_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUV_PARAMS_LIST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_auv_params_list_t packet_in = {
        17.0,17
    };
    mavlink_auv_params_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param = packet_in.param;
        packet1.index = packet_in.index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUV_PARAMS_LIST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_params_list_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_auv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_params_list_pack(system_id, component_id, &msg , packet1.index , packet1.param );
    mavlink_msg_auv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_params_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.param );
    mavlink_msg_auv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_auv_params_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_auv_params_list_send(MAVLINK_COMM_1 , packet1.index , packet1.param );
    mavlink_msg_auv_params_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_3DAUV(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_auv_heartbeat(system_id, component_id, last_msg);
    mavlink_test_auv_field_state(system_id, component_id, last_msg);
    mavlink_test_auv_tack_state(system_id, component_id, last_msg);
    mavlink_test_auv_actuator_control(system_id, component_id, last_msg);
    mavlink_test_gcs_set_waypoints(system_id, component_id, last_msg);
    mavlink_test_gcs_set_control_param(system_id, component_id, last_msg);
    mavlink_test_gcs_set_or_rpi_ack(system_id, component_id, last_msg);
    mavlink_test_gcs_set_task(system_id, component_id, last_msg);
    mavlink_test_gcs_set_servo_param(system_id, component_id, last_msg);
    mavlink_test_auv_adrc_param(system_id, component_id, last_msg);
    mavlink_test_auv_adrc_eso(system_id, component_id, last_msg);
    mavlink_test_auv_arm_control_and_tcp_feed(system_id, component_id, last_msg);
    mavlink_test_auv_arm_wireless_feed(system_id, component_id, last_msg);
    mavlink_test_auv_thrusters_direct_control(system_id, component_id, last_msg);
    mavlink_test_auv_thrusters_indirect_control(system_id, component_id, last_msg);
    mavlink_test_gcs_set_control_param_thrusters(system_id, component_id, last_msg);
    mavlink_test_auv_params_list(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // 3DAUV_TESTSUITE_H
