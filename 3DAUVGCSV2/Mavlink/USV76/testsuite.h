/** @file
 *    @brief MAVLink comm protocol testsuite generated from USV76.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef USV76_TESTSUITE_H
#define USV76_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_USV76(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_USV76(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_usv_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_heartbeat_t packet_in = {
        5,72,139
    };
    mavlink_usv_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mode = packet_in.mode;
        packet1.task_id = packet_in.task_id;
        packet1.autoWorking = packet_in.autoWorking;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_heartbeat_pack(system_id, component_id, &msg , packet1.mode , packet1.task_id , packet1.autoWorking );
    mavlink_msg_usv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.task_id , packet1.autoWorking );
    mavlink_msg_usv_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_heartbeat_send(MAVLINK_COMM_1 , packet1.mode , packet1.task_id , packet1.autoWorking );
    mavlink_msg_usv_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

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
        963497464,963497672,73.0,101.0,129.0,157.0,18483,18587,18691,18795,101
    };
    mavlink_usv_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.yaw = packet_in.yaw;
        packet1.course = packet_in.course;
        packet1.vel = packet_in.vel;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.HDOP = packet_in.HDOP;
        packet1.SVs = packet_in.SVs;
        
        
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
    mavlink_msg_usv_state_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
    mavlink_msg_usv_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
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
    mavlink_msg_usv_state_send(MAVLINK_COMM_1 , packet1.lat , packet1.lon , packet1.x , packet1.y , packet1.vel , packet1.roll , packet1.pitch , packet1.yaw , packet1.course , packet1.HDOP , packet1.SVs );
    mavlink_msg_usv_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_usv_actuator_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_actuator_control_t packet_in = {
        17.0,17443
    };
    mavlink_usv_actuator_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rudder_angle = packet_in.rudder_angle;
        packet1.propeller_pwm = packet_in.propeller_pwm;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_ACTUATOR_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_actuator_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_actuator_control_pack(system_id, component_id, &msg , packet1.propeller_pwm , packet1.rudder_angle );
    mavlink_msg_usv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_actuator_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.propeller_pwm , packet1.rudder_angle );
    mavlink_msg_usv_actuator_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_actuator_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_actuator_control_send(MAVLINK_COMM_1 , packet1.propeller_pwm , packet1.rudder_angle );
    mavlink_msg_usv_actuator_control_decode(last_msg, &packet2);
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
        963497464,963497672,29
    };
    mavlink_gcs_set_waypoints_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.waypoint_lng = packet_in.waypoint_lng;
        packet1.waypoint_lat = packet_in.waypoint_lat;
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
    mavlink_msg_gcs_set_waypoints_pack(system_id, component_id, &msg , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat );
    mavlink_msg_gcs_set_waypoints_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_waypoints_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat );
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
    mavlink_msg_gcs_set_waypoints_send(MAVLINK_COMM_1 , packet1.waypoint_index , packet1.waypoint_lng , packet1.waypoint_lat );
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
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,18691
    };
    mavlink_gcs_set_control_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.kp_psi = packet_in.kp_psi;
        packet1.ki_psi = packet_in.ki_psi;
        packet1.kd_psi = packet_in.kd_psi;
        packet1.kp_vel = packet_in.kp_vel;
        packet1.ki_vel = packet_in.ki_vel;
        packet1.kd_vel = packet_in.kd_vel;
        packet1.Los = packet_in.Los;
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
    mavlink_msg_gcs_set_control_param_pack(system_id, component_id, &msg , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_vel , packet1.ki_vel , packet1.kd_vel , packet1.Los );
    mavlink_msg_gcs_set_control_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_control_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_vel , packet1.ki_vel , packet1.kd_vel , packet1.Los );
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
    mavlink_msg_gcs_set_control_param_send(MAVLINK_COMM_1 , packet1.xunhang_pwm , packet1.kp_psi , packet1.ki_psi , packet1.kd_psi , packet1.kp_vel , packet1.ki_vel , packet1.kd_vel , packet1.Los );
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
        17.0,45.0,17651,163
    };
    mavlink_gcs_set_task_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.course = packet_in.course;
        packet1.xunhang_pwm = packet_in.xunhang_pwm;
        packet1.time_allow = packet_in.time_allow;
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
    mavlink_msg_gcs_set_task_pack(system_id, component_id, &msg , packet1.tasktype , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
    mavlink_msg_gcs_set_task_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_task_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tasktype , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
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
    mavlink_msg_gcs_set_task_send(MAVLINK_COMM_1 , packet1.tasktype , packet1.course , packet1.time_allow , packet1.xunhang_pwm );
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
        17235,17339
    };
    mavlink_gcs_set_servo_param_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.propeller_left_pwm = packet_in.propeller_left_pwm;
        packet1.propeller_right_pwm = packet_in.propeller_right_pwm;
        
        
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
    mavlink_msg_gcs_set_servo_param_pack(system_id, component_id, &msg , packet1.propeller_left_pwm , packet1.propeller_right_pwm );
    mavlink_msg_gcs_set_servo_param_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_servo_param_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.propeller_left_pwm , packet1.propeller_right_pwm );
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
    mavlink_msg_gcs_set_servo_param_send(MAVLINK_COMM_1 , packet1.propeller_left_pwm , packet1.propeller_right_pwm );
    mavlink_msg_gcs_set_servo_param_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_usv_params_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_PARAMS_LIST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_params_list_t packet_in = {
        17.0,17
    };
    mavlink_usv_params_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param = packet_in.param;
        packet1.index = packet_in.index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_PARAMS_LIST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_PARAMS_LIST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_params_list_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_params_list_pack(system_id, component_id, &msg , packet1.index , packet1.param );
    mavlink_msg_usv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_params_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.param );
    mavlink_msg_usv_params_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_params_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_params_list_send(MAVLINK_COMM_1 , packet1.index , packet1.param );
    mavlink_msg_usv_params_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_USV76(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_usv_heartbeat(system_id, component_id, last_msg);
    mavlink_test_usv_state(system_id, component_id, last_msg);
    mavlink_test_usv_actuator_control(system_id, component_id, last_msg);
    mavlink_test_gcs_set_waypoints(system_id, component_id, last_msg);
    mavlink_test_gcs_set_control_param(system_id, component_id, last_msg);
    mavlink_test_gcs_set_or_rpi_ack(system_id, component_id, last_msg);
    mavlink_test_gcs_set_task(system_id, component_id, last_msg);
    mavlink_test_gcs_set_servo_param(system_id, component_id, last_msg);
    mavlink_test_usv_params_list(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // USV76_TESTSUITE_H
