/*      �⺻ ����

  * Ex_07_Timer
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  Ÿ�̸Ӹ� �̿��Ͽ� 1�� ���ֱ� LED�� ON/OFF�ϴ� ���α׷��Դϴ�.

*/

#include "inc.h"

void TIM2_IRQHandler(void) {
  TIM2 -> SR = 0;
  GPIOF -> ODR ^= (1 << 6);
}

int main(void) {
  RCC -> CFGR = (1 << PLLXTPRE) | (1 << PLLSRC) | (7 << PLLMUL) | (2 << SW) | (4 << HPRE);
  RCC -> CR = (1 << PLLON) | (1 << HSEON) | (16 << HSITRIM);
  RCC -> APB1ENR = 0x00000001;
  
  TIM2 -> PSC = 36000 - 1;
  TIM2 -> ARR = 500 - 1;
  TIM2 -> CNT = 0;
  TIM2 -> SR = 0;
  
  RCC -> APB2ENR = (1 << IOPFEN);
  GPIOF -> CRL = (1 << MODE6);
  
  TIM2 -> DIER = (1 << 0);
  NVIC_ISER0 = (1 << 28);
  
  TIM2 -> EGR = (1 << 0);
  TIM2 -> CR1 = (1 << 0);
  
  RCC -> APB2ENR |= (1 << IOPGEN);
  GPIOG -> CRL = (1 << MODE6);
  GPIOG -> ODR = (1 << 6);
  GPIOF -> CRL |= (1 << MODE7);
  
  uint8_t flag = false;

  while(1) {
    if( !(GPIOG -> IDR & (1 << 6))) {
      flag = (flag == false) ? true : false;
      
      if(flag) {
        GPIOF -> ODR |= (1 << 7);
        TIM2 -> ARR = 250 - 1;
        TIM2 -> CNT = 0;
      } else {
        GPIOF -> ODR &= ~(1<< 7);
        TIM2 -> ARR = 500 - 1;
        TIM2 -> CNT = 0;
      }
      
      while( !(GPIOG -> IDR & (1 << 6)));
    }
  }
  
  return 0;
}
