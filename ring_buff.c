#include "ring_buff.h"

int8_t Ring_buff_push(Ring_buff *ring_buff, uint8_t data)		// truyen du lieu vao ring buffer
{
	uint16_t next;
	next = ring_buff->head ; 
	if(next >= ring_buff->max_len)
	{
		next = 0;
	}
	if(next == ring_buff->tail)
		return -1;
	ring_buff->buffer[ring_buff->head] = data;
	ring_buff->head ++;
	return 0;
}
int8_t ring_buff_pop(Ring_buff *ring_buff, uint8_t *data)
{
	if(ring_buff->head == ring_buff->tail)
		return -1;
	*data = ring_buff->buffer[ring_buff->tail];
	ring_buff->tail++ ;
	
	if(ring_buff->tail >= ring_buff->max_len)
		ring_buff->tail = 0;
	return 0;
}
uint16_t ring_buff_available (Ring_buff *ring_buff)
{
	if(ring_buff->head < ring_buff->tail)
		return ring_buff->max_len - (ring_buff->tail - ring_buff->head);
	return (ring_buff->head - ring_buff->tail);
}

void ring_buff_init(Ring_buff *ring_buff, uint8_t *buff, uint16_t len)
{
	ring_buff->buffer = buff;
	ring_buff->head = 0;
	ring_buff->tail = 0;
	ring_buff->max_len = len;
}
