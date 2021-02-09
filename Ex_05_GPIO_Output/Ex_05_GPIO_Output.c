/*      기본 정보

  * Ex_05_GPIO_Output
  * 2021-02-09
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  GPIO를 다루는 예제입니다.
  PF7핀을 사용하기 위해 GPIOF에 클럭을 입력하고, PF7핀을 Push-pull 모드로 설정합니다.
  PF7에 HIGH 신호를 인가합니다.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF에 클럭을 인가합니다.

  GPIOF -> CRL = (1 << MODE7);          // PF7핀을 Push-pull 모드로 설정합니다.
  GPIOF -> ODR = (1 << 7);              // PF7핀에 HIGH 신호를 보냅니다.
  
  return 0;
}