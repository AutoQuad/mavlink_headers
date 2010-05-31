// MESSAGE DEBUG_VECT PACKING

#define MAVLINK_MSG_ID_DEBUG_VECT 60

typedef struct __mavlink_debug_vect_t 
{
	int8_t name[10]; ///< Name
	float x; ///< x
	float y; ///< y
	float z; ///< z

} mavlink_debug_vect_t;

#define MAVLINK_MSG_DEBUG_VECT_FIELD_NAME_LEN 10

/**
 * @brief Send a debug_vect message
 *
 * @param name Name
 * @param x x
 * @param y y
 * @param z z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_vect_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const int8_t* name, float x, float y, float z)
{
	msg->msgid = MAVLINK_MSG_ID_DEBUG_VECT;
	uint16_t i = 0;

	i += put_array_by_index(name, 10, i, msg->payload); //Name
	i += put_float_by_index(x, i, msg->payload); //x
	i += put_float_by_index(y, i, msg->payload); //y
	i += put_float_by_index(z, i, msg->payload); //z

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_debug_vect_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_debug_vect_t* debug_vect)
{
	return mavlink_msg_debug_vect_pack(system_id, component_id, msg, debug_vect->name, debug_vect->x, debug_vect->y, debug_vect->z);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_debug_vect_send(mavlink_channel_t chan, const int8_t* name, float x, float y, float z)
{
	mavlink_message_t msg;
	mavlink_msg_debug_vect_pack(mavlink_system.sysid, mavlink_system.compid, &msg, name, x, y, z);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE DEBUG_VECT UNPACKING

/**
 * @brief Get field name from debug_vect message
 *
 * @return Name
 */
static inline uint16_t mavlink_msg_debug_vect_get_name(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload, 10);
	return 10;
}

/**
 * @brief Get field x from debug_vect message
 *
 * @return x
 */
static inline float mavlink_msg_debug_vect_get_x(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+10)[0];
	r.b[2] = (msg->payload+10)[1];
	r.b[1] = (msg->payload+10)[2];
	r.b[0] = (msg->payload+10)[3];
	return (float)r.f;
}

/**
 * @brief Get field y from debug_vect message
 *
 * @return y
 */
static inline float mavlink_msg_debug_vect_get_y(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+10+sizeof(float))[0];
	r.b[2] = (msg->payload+10+sizeof(float))[1];
	r.b[1] = (msg->payload+10+sizeof(float))[2];
	r.b[0] = (msg->payload+10+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field z from debug_vect message
 *
 * @return z
 */
static inline float mavlink_msg_debug_vect_get_z(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+10+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+10+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+10+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+10+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

static inline void mavlink_msg_debug_vect_decode(const mavlink_message_t* msg, mavlink_debug_vect_t* debug_vect)
{
	mavlink_msg_debug_vect_get_name(msg, debug_vect->name);
	debug_vect->x = mavlink_msg_debug_vect_get_x(msg);
	debug_vect->y = mavlink_msg_debug_vect_get_y(msg);
	debug_vect->z = mavlink_msg_debug_vect_get_z(msg);
}
