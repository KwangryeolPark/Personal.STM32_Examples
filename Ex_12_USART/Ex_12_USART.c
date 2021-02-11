/*      기본 정보

  * Ex_12_USART
  * 2021-02-11
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  

*/

#include "inc.h"

int main(void) {
  
  RCC -> CFGR = (1 << PLLXTPRE) | (1 << PLLSRC) | (7 << PLLMUL) | (2 << SW);     // Set APB2 36 MHz
  RCC -> CR = (1 << PLLON) | (1 << HSEON) | (16 << HSITRIM);            // Set PLL, HSE on
  RCC -> APB2ENR = (1 << AFIOEN) | (1 << IOPAEN);
  GPIOA -> CRL = (11 << MODE2) | (4 << MODE3);
  RCC -> APB1ENR = (1 << USART2EN);
  
  
  USART2 -> BRR = 19 << 4;
  USART2 -> BRR |= 8;

  USART2 -> CR1 = (1 << UE) | (1 << TE);    // USART enable, Transmit & Receive enable
  
  char *helloWorld = "HelloWorl%d\n";
  while(true) {
    for(int i = 0; *(helloWorld + i) != '\0'; i++) {
      putc(USART2, *(helloWorld + i));
    }
  }
  
  return 0;
}