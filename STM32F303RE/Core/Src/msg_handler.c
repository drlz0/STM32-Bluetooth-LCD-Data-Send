/*
 * library created by drlz0
 *
 */

#include <msg_handler.h>
#include <LCD1602.h>

// Define a buffer to store received data
uint8_t buffer[40];

// Define an index to keep track of data position in the buffer
uint16_t buffer_index = 0;

// Arrays for characters of first line and second line in LCD
char first_string[17]; // +1 for null terminator
char second_string[17]; // +1 for null terminator

void send_to_uart(UART_HandleTypeDef *huart)
{
  // Toggle a GPIO pin which is green LED
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

  // Transmit the data in the buffer to UART
  HAL_UART_Transmit(huart, buffer, buffer_index, 10);

  // Reset the buffer index
  buffer_index = 0;

  // Clear the buffer
  memset(buffer, 0, sizeof(buffer));
}

void display_msg_on_lcd()
{
// Find the position of '\n' in the buffer
    // Find the position of '\n' in the buffer
    char* newline_position = (char *)strchr((char *)buffer, '\n');

    if (newline_position != NULL) {
        // Calculate the length of the first substring
        int first_string_length = newline_position - (char *)buffer;

        // Copy the first substring to the firstString variable
        strncpy(first_string, (char *)buffer, first_string_length);
        first_string[first_string_length] = '\0';

        // Copy the second substring to the secondString variable
        strcpy(second_string, newline_position + 1);

        // Fill the first and second strings with spaces to reach 16 characters
        int space_count = 16 - strlen(first_string);
        for (int i = 0; i < space_count; i++) {
            strcat(first_string, " ");
        }

        space_count = 16 - strlen(second_string);
        for (int i = 0; i < space_count; i++) {
            strcat(second_string, " ");
        }

		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		// Instructions for LCD
		//lcd_clear();
		lcd_put_cur(0, 0);
		lcd_send_string(first_string);
		lcd_put_cur(1, 0);
		lcd_send_string(second_string);

		// Clear the buffer
		memset(buffer, 0, sizeof(buffer));
		buffer_index = 0;

    }
}
