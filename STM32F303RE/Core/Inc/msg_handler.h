/*
 * library created by drlz0
 *
 */

#ifndef MSG_HANDLER_H
#define MSG_HANDLER_H

#include "main.h"
#include <string.h>

// Declare the buffer and buffer_index variables
extern uint8_t buffer[40];
extern uint16_t buffer_index;
extern char first_string[17];
extern char second_string[17];
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;

void send_to_uart(UART_HandleTypeDef *huart);
void display_msg_on_lcd();

#endif /* MSG_HANDLER_H */
