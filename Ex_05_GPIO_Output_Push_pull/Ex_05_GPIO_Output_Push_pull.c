/*      기본 정보

  * Ex_05_GPIO_Output_Push_pull.c
  * 2021-02-12
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.
  * https://pkr7098.tistory.com/164
  * pkr7098@gmail.com

*/
/*      설명

  GPIO를 다루는 예제입니다.
  
  Open103Z 보드 우측 LED 부분의 위에서 2 번째 LED를 사용합니다.  
  해당 LED는 STM32 칩의 PF7핀에 연결되어 있습니다.
  
  PF7핀을 사용하기 위해 GPIOF에 클럭을 인가하고, 많이 사용되는 Push-pull, 100 MHz 모드로 설정합니다. 
  
  모든 설정이 끝났으면 PF7에 HIGH와 LOW 신호를 반복적으로 보냅니다.
*/

#include "gpio.h"
#include "rcc.h"

void Delay(unsigned long delay);        // 임시로 만든 Delay 함수입니다.

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF에 클럭을 인가합니다.

  GPIOF -> CRL = (1 << MODE7);          // PF7핀을 Push-pull, 10 MHz 모드로 설정합니다.
  
  while(1) {
    GPIOF -> ODR = (1 << 7);              // PF7핀에 HIGH 신호를 보냅니다.
    Delay(0xFFFFF);
    GPIOF -> ODR = 0;              // PF7핀에 HIGH 신호를 보냅니다.
    Delay(0xFFFFF);
  }
  
  return 0;
}


void Delay(unsigned long delay) {
  for(; delay; delay--) ;
}
