/*      기본 정보

  * Ex_07_Timer_easy
  * 2021-02-11
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      설명

  타이머를 이용하여 0.5초 주기로 LED를 ON/OFF하는 프로그램입니다.

*/

#include "inc.h"

void TIM2_IRQHandler(void) {    // TIM2에 대한 Handler입니다.
  TIM2 -> SR = 0;       // TIM2가 SR의 0번째 비트를 기준으로 1이면 인터럽트를 발생시키기 때문에 다시 0으로 초기화합니다.(수동으로 초기화 해야함)
  GPIOF -> ODR ^= (1 << 6);     // PF6를 Toggle합니다.
}

int main(void) {
  RCC -> CFGR = (1 << PLLXTPRE) | (1 << PLLSRC) | (7 << PLLMUL) | (2 << SW) | (4 << HPRE);      // APB1에 18 MHz를 공급합니다.
  RCC -> CR = (1 << PLLON) | (1 << HSEON) | (16 << HSITRIM);            // PLL, HSE를 ON합니다.
  RCC -> APB1ENR = 0x00000001;  // TIM2 활성화
  
  TIM2 -> PSC = 36000 - 1;      // 36000000 / (36000 - 1 + 1) -> 1000  Hz
  TIM2 -> ARR = 500 - 1;        // (500 - 1 + 1) / 1000 -> 0.5 sec
  TIM2 -> CNT = 0;              // TIM2 초기값을 초기화합니다.
  TIM2 -> SR = 0;                
  
  RCC -> APB2ENR = (1 << IOPFEN);               // GPIOF에 클럭을 인가합니다.
  GPIOF -> CRL = (1 << MODE6);          // PF6를 Push-pull mode로 설정합니다.
  
  TIM2 -> DIER = (1 << 0);      //  TIM2  interrupt를 활성화합니다.
  NVIC_ISER0 = (1 << 28);       // NVIC에 TIM2를 연결합니다.
  
  TIM2 -> EGR = (1 << 0);       // 레지스터가 update 되었다는 것을 알려줍니다. (자세한 것은 더 알아봐야합니다...)
  TIM2 -> CR1 = (1 << 0);       // TIM2 시작
  
  while(1);
  
  return 0;
}