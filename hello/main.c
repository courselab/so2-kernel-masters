/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 João Pedro Gomes <joaop.gomes@usp.br>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  João Pedro Gomes <joaop.gomes@usp.br>
 */

#include <stdio.h>

int main(void)   
{
  printf("Hello, World!\n\r");

  while (1) {
    int time = rtc_read();

    char str_hex_time[9];
    for(int i = 0; i < 8; i++) {
      str_hex_time[i] = (time >> (28 - i * 4)) & 0xF;
      if (str_hex_time[i] < 10) {
        str_hex_time[i] += '0'; // Convert to ASCII
      } else {
        str_hex_time[i] += 'A' - 10; // Convert to ASCII for A-F
      }
    }

    int hours = (time & 0xFF);         // AL contains hours in BCD
    int minutes = ((time >> 8) & 0xFF); // AH contains minutes in BCD
    int seconds = ((time >> 16) & 0xFF); // DL contains seconds in BCD

    // Convert BCD directly to string
    char dec_hours[3], dec_minutes[3], dec_seconds[3];
    
    dec_hours[0] = ((hours & 0xF0) >> 4) + '0';
    dec_hours[1] = (hours & 0x0F) + '0';
    dec_hours[2] = '\0';
    
    dec_minutes[0] = ((minutes & 0xF0) >> 4) + '0';
    dec_minutes[1] = (minutes & 0x0F) + '0';
    dec_minutes[2] = '\0';
    
    dec_seconds[0] = ((seconds & 0xF0) >> 4) + '0';
    dec_seconds[1] = (seconds & 0x0F) + '0';
    dec_seconds[2] = '\0';

    printf("Current time: ");
    printf(dec_hours);
    printf(":");
    printf(dec_minutes);
    printf(":");
    printf(dec_seconds);
    printf("\n\r");

    printf("Current time in hex: ");
    printf(str_hex_time);
    printf("\n\r");

    for(int i = 0; i < 1000000000; i++); 
  }
  
  
  return 0;
}





