#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

typedef struct 
{
		uint8_t * buffer;
		uint16_t head;
		uint16_t tail;
		uint16_t max_len;
}Ring_buff;
void ring_buff_init(Ring_buff *ring_buff, uint8_t *buff, uint16_t len);
int8_t Ring_buff_push(Ring_buff *c, uint8_t data);
int8_t ring_buff_pop(Ring_buff *ring_buff, uint8_t *data);
uint16_t ring_buff_available (Ring_buff *ring_buff);
#endif
