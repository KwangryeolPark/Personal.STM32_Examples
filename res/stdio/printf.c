#ifndef _PRINTF_C
#define _PRINTF_C

#include "typedef.h"
#include "usart.h"

#define EOF	255

uint8_t putc(struct _USART volatile *usart, uint8_t c) {
  
  if((c == '\n') || (c == '\r')) {
    while(!(usart -> SR & (1 << TXE))); // 전송 가능해질 때까지 기다립니다.
    usart -> DR = '\n';

    while(!(usart -> SR & (1 << TXE))); // 전송 가능해질 때까지 기다립니다.
    usart -> DR = '\r';
  } else {
    while(!(usart -> SR & (1 << TXE))); // 전송 가능해질 때까지 기다립니다.
    usart -> DR = c;    
  }

  return c;
}

uint8_t getc(struct _USART volatile *usart) {
    while(!(usart -> SR & (1 << RXNE))); // 
    
    uint8_t c = (usart -> DR);
    putc(usart, c);
    
    return c;
}

uint8_t getc_nb(struct _USART volatile *usart) {
	uint8_t c;
	if((usart -> SR & (1 << RXEN))) {
		c = (usart -> DR);
		putc(usart, c);
		return c;
	}
	
	putc(usart, 0);
	return 0;
}
  
  

#endif
