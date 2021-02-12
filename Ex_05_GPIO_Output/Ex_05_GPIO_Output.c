/*      기본 정보

  * Ex_05_GPIO_Output
  * 2021-02-09
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  GPIO를 다루는 예제입니다.
  
  Open103Z 보드 우측 LED 부분의 위에서 2 번째 LED를 사용합니다.  
  해당 LED는 STM32 칩의 PF7핀에 연결되어 있습니다.
  
  PF7핀을 사용하기 위해 GPIOF에 클럭을 인가하고, 많이 사용되는 Push-pull, 100 MHz 모드로 설정합니다. 
  설정이 끝났다면 PF7에 HIGH 신호를 인가합니다.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF에 클럭을 인가합니다.

  GPIOF -> CRL = (1 << MODE7);          // PF7핀을 Push-pull, 10 MHz 모드로 설정합니다.
  GPIOF -> ODR = (1 << 7);              // PF7핀에 HIGH 신호를 보냅니다.
  
  return 0;
}
