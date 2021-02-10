/*      �⺻ ����

  * Ex_07_Timer_easy
  * 2021-02-11
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  Ÿ�̸Ӹ� �̿��Ͽ� 0.5�� �ֱ�� LED�� ON/OFF�ϴ� ���α׷��Դϴ�.

*/

#include "inc.h"

void TIM2_IRQHandler(void) {    // TIM2�� ���� Handler�Դϴ�.
  TIM2 -> SR = 0;       // TIM2�� SR�� 0��° ��Ʈ�� �������� 1�̸� ���ͷ�Ʈ�� �߻���Ű�� ������ �ٽ� 0���� �ʱ�ȭ�մϴ�.(�������� �ʱ�ȭ �ؾ���)
  GPIOF -> ODR ^= (1 << 6);     // PF6�� Toggle�մϴ�.
}

int main(void) {
  RCC -> CFGR = (1 << PLLXTPRE) | (1 << PLLSRC) | (7 << PLLMUL) | (2 << SW) | (4 << HPRE);      // APB1�� 18 MHz�� �����մϴ�.
  RCC -> CR = (1 << PLLON) | (1 << HSEON) | (16 << HSITRIM);            // PLL, HSE�� ON�մϴ�.
  RCC -> APB1ENR = 0x00000001;  // TIM2 Ȱ��ȭ
  
  TIM2 -> PSC = 36000 - 1;      // 36000000 / (36000 - 1 + 1) -> 1000  Hz
  TIM2 -> ARR = 500 - 1;        // (500 - 1 + 1) / 1000 -> 0.5 sec
  TIM2 -> CNT = 0;              // TIM2 �ʱⰪ�� �ʱ�ȭ�մϴ�.
  TIM2 -> SR = 0;                
  
  RCC -> APB2ENR = (1 << IOPFEN);               // GPIOF�� Ŭ���� �ΰ��մϴ�.
  GPIOF -> CRL = (1 << MODE6);          // PF6�� Push-pull mode�� �����մϴ�.
  
  TIM2 -> DIER = (1 << 0);      //  TIM2  interrupt�� Ȱ��ȭ�մϴ�.
  NVIC_ISER0 = (1 << 28);       // NVIC�� TIM2�� �����մϴ�.
  
  TIM2 -> EGR = (1 << 0);       // �������Ͱ� update �Ǿ��ٴ� ���� �˷��ݴϴ�. (�ڼ��� ���� �� �˾ƺ����մϴ�...)
  TIM2 -> CR1 = (1 << 0);       // TIM2 ����
  
  while(1);
  
  return 0;
}