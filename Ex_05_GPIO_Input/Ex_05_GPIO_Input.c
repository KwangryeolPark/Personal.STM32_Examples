/*      기본 정보

  * Ex_05_GPIO_Input
  * 2021-02-09
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  GPIO를 다루는 예제입니다.
  PG6핀을 Input pull-up 모드로 하여 Open103Z의 USERKEY 버튼 상태를 읽고,
  PF7핀에 버튼의 상태를 보여줍니다.

  버튼이 눌리면 PF7 LED는 ON, 그렇지 않으면 OFF로 될 예정입니다.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN) | (1 << IOPGEN);       // GPIOF에 클럭을 인가합니다.

  GPIOF -> CRL = (1 << MODE7);          // PF7핀을 Push-pull 모드로 설정합니다.
  GPIOF -> ODR = (1 << 7);              // PF7핀에 HIGH 신호를 보냅니다.
  
  GPIOG -> CRL = (8 << MODE6);          // PG6핀을 pull-up / pull-down 모드(8)로 설정합니다.
  GPIOG -> ODR = (1 << 6);              // PG6핀을 pull-up 모드로 설정합니다.
  
  while(1) {
    if( !(GPIOG -> IDR & (1 << 6))) GPIOF -> ODR = (1 << 7);    //버튼이 눌렸을 때
    else GPIOF -> ODR = 0;      //버튼이 안 눌렸을 때
  }
  
  return 0;
}