/*      기본 정보

  * Ex_06_Exception_easy
  * 2021-02-09
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  외부 인터럽트를 처리하는 간단한 예제입니다.

  EXTI6 인터럽트가 발생되면 PF7에 연결된 LED가 ON됩니다.
*/

#include "inc.h"

void EXTI9_5_IRQHandler(void) { // EXTI6이 발생되면 호출되는 Handler입니다. (정확히는 EXTI9 ~ 5 중 하나라도 발생한다면)
  //Handler이름은 startup_stm32f10x_hd_vl.s에 정의되어 있습니다. 
  if(EXTI -> PR & (1 << 6)) {   // EXTI9 ~ 5중에 EXTI6가 발생된 것인지 확인합니다.
    EXTI -> PR |= (1 << 6);     // EXTI6가 한 번 발생되었기 때문에 다시 0으로 만들어 줍니다. (1을 write하면 하드웨어적으로 0으로 초기화 됩니다.)
    GPIOF -> ODR = (1 << 6);   // PF6 LED를  ON합니다.
  }
}

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPGEN) | (1 << IOPFEN) | (1 << AFIOEN);        // GPIOG, F에 클럭을 인가합니다. AFIO에 클럭을 인가합니다.
  
  GPIOG -> CRL = (8 << MODE6);      // PG6를 pull-up/pull-down 모드로 설정합니다.
  GPIOG -> ODR = (1 << 6);      // PG6을 pull-up 모드로 설정합니다. (Open103Z 보드에 Pull-up 모드를 사용하도록 설계 되어 있습니다.)
  GPIOF -> CRL = (1 << MODE6);  //PF6을 Push-pull 모드로 설정합니다.
  
  AFIO -> EXTICR2 = (6 << 8);   // EXTI6에 PG6를 연결합니다.
  
  EXTI -> FTSR = (1 << 6);   // Falling edge에서 EXTI6을 발생시킵니다.
  EXTI -> RTSR = 0x00000000;            // 그 어떤 것도 Raising edge에서 인터럽트를 발생시키지 않습니다.
  EXTI -> IMR = (1 << 6);    // EXTI6을 활성화 시킵니다.
  
  NVIC_ISER0 = (1 << 23);    //NVIC에 EXTI6을 연결합니다.
  
  while(true);          //인터럽트는 동작해야하기 때문에 프로그램을 종료하지 않습니다.
  
  return 0;
}