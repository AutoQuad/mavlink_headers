// MESSAGE PARAM_WRITE PACKING

#define MAVLINK_MSG_ID_PARAM_WRITE 80

typedef struct __param_write_t 
{
	uint16_t param_id; ///< Onboard parameter id
	float param_value; ///< Onboard parameter value

} param_write_t;

/**
 * @brief Send a param_write message
 *
 * @param param_id Onboard parameter id
 * @param param_value Onboard parameter value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t message_param_write_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t param_id, float param_value)
{
	msg->msgid = MAVLINK_MSG_ID_PARAM_WRITE;
	uint16_t i = 0;

	i += put_uint16_t_by_index(param_id, i, msg->payload); //Onboard parameter id
	i += put_float_by_index(param_value, i, msg->payload); //Onboard parameter value

	return finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t message_param_write_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const param_write_t* param_write)
{
	return message_param_write_pack(system_id, component_id, msg, param_write->param_id, param_write->param_value);
}

#if !defined(_WIN32) && !defined(__linux) && !defined(__APPLE__)

#include "global_data.h"

static inline void message_param_write_send(mavlink_channel_t chan, uint16_t param_id, float param_value)
{
	mavlink_message_t msg;
	message_param_write_pack(global_data.param[PARAM_SYSTEM_ID], global_data.param[PARAM_COMPONENT_ID], &msg, param_id, param_value);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE PARAM_WRITE UNPACKING

/**
 * @brief Get field param_id from param_write message
 *
 * @return Onboard parameter id
 */
static inline uint16_t message_param_write_get_param_id(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field param_value from param_write message
 *
 * @return Onboard parameter value
 */
static inline float message_param_write_get_param_value(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint16_t))[0];
	r.b[2] = (msg->payload+sizeof(uint16_t))[1];
	r.b[1] = (msg->payload+sizeof(uint16_t))[2];
	r.b[0] = (msg->payload+sizeof(uint16_t))[3];
	return (float)r.f;
}

static inline void message_param_write_decode(const mavlink_message_t* msg, param_write_t* param_write)
{
	param_write->param_id = message_param_write_get_param_id(msg);
	param_write->param_value = message_param_write_get_param_value(msg);
}
