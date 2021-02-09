/*      �⺻ ����

  * Ex_06_Exception
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  �ܺ� ���ͷ�Ʈ�� ó���ϴ� �����Դϴ�.
  PC0�� EXTI0�� ����Ǿ� ������, PG6�� EXTI6�� ����Ǿ� �ֽ��ϴ�.
  EXTI0�� EXTI6 �� ��� Falling Edge������ ���ͷ�Ʈ�� �߻��˴ϴ�.

  EXTI0 ���ͷ�Ʈ�� �߻��Ǹ� PF7�� ����� LED�� ON�˴ϴ�.
  EXTI6 ���ͷ�Ʈ�� �߻��Ǹ� PF6�� ����� LED�� TOGGLE�˴ϴ�.

  NVIC�� �̿��� �ܺ� ���ͷ�Ʈ ó���̸�, EXIT0 ���ͷ�Ʈ�� �߻��Ǹ� 
  startup_stm32f10x_hd_vl.s�� ����� �ٿ� ���� EXTI0_IRQHandler�� �߻��˴ϴ�.
  EXIT5 ~ 9�� ���� ���� �ֱ� ������ EXTI6 ���ͷ�Ʈ�� EXTI9_5_IRQHandler�� �߻���ŵ�ϴ�.

  PC0�� Open103Z ���� ���̽�ƽ ������ ���⿡ Pull-up ���·� ����Ǿ� �ֽ��ϴ�.
  PG6�� Open103Z ���� USERKEY ��ư�� Pull-up ���·� ����Ǿ� �ֽ��ϴ�.
*/

#include "inc.h"

void EXTI0_IRQHandler(void) {   // EXTI0�� �߻��Ǹ� ȣ��Ǵ� Handler�Դϴ�.
  //Handler�̸��� startup_stm32f10x_hd_vl.s�� ���ǵǾ� �ֽ��ϴ�. 
  if(EXTI -> PR & (1 << 0)) {   // EXTI0�� �߻��� ������ �� �� �� Ȯ���մϴ�.
    EXTI -> PR |= (1 << 0);     // EXTI0�� �� �� �߻��Ǿ��� ������ �ٽ� 0���� ����� �ݴϴ�. (1�� write�ϸ� �ϵ���������� 0���� �ʱ�ȭ �˴ϴ�.)
    GPIOF -> ODR |= (1 << 7);   // PF7 LED�� ON�մϴ�.
  }
}

void EXTI9_5_IRQHandler(void) { // EXTI6�� �߻��Ǹ� ȣ��Ǵ� Handler�Դϴ�. (��Ȯ���� EXTI9 ~ 5 �� �ϳ��� �߻��Ѵٸ�)
  //Handler�̸��� startup_stm32f10x_hd_vl.s�� ���ǵǾ� �ֽ��ϴ�. 
  if(EXTI -> PR & (1 << 6)) {   // EXTI9 ~ 5�߿� EXTI6�� �߻��� ������ Ȯ���մϴ�.
    EXTI -> PR |= (1 << 6);     // EXTI6�� �� �� �߻��Ǿ��� ������ �ٽ� 0���� ����� �ݴϴ�. (1�� write�ϸ� �ϵ���������� 0���� �ʱ�ȭ �˴ϴ�.)
    GPIOF -> ODR ^= (1 << 6);   // PF6 LED�� TOGGLE�մϴ�.
  }
}


int main(void) {
  
  RCC -> APB2ENR = (1 << IOPGEN) | (1 << IOPFEN) | (1 << IOPCEN) | (1 << AFIOEN);        // GPIOG, F, C�� Ŭ���� �ΰ��մϴ�. AFIO�� Ŭ���� �ΰ��մϴ�.
  
  GPIOC -> CRL = (8 << MODE0);      // PC0�� pull-up/pull-down ���� �����մϴ�.
  GPIOC -> ODR = (1 << 0);      // PC0�� pull-up ���� �����մϴ�. (Open103Z ���忡 Pull-up ��带 ����ϵ��� ���� �Ǿ� �ֽ��ϴ�.)
  GPIOG -> CRL = (8 << MODE6);      // PG6�� pull-up/pull-down ���� �����մϴ�.
  GPIOG -> ODR = (1 << 6);      // PG6�� pull-up ���� �����մϴ�. (Open103Z ���忡 Pull-up ��带 ����ϵ��� ���� �Ǿ� �ֽ��ϴ�.)
  GPIOF -> CRL = (1 << MODE6) | (1 << MODE7);   //PF6, 7�� Push-pull ���� �����մϴ�.
  
  AFIO -> EXTICR1 = (2 << 0);   // EXTI0�� PC0�� �����մϴ�.
  AFIO -> EXTICR2 = (6 << 8);   // EXTI6�� PG6�� �����մϴ�.
  
  EXTI -> FTSR = (1 << 0) | (1 << 6);   // Falling edge���� EXTI0, 6�� �߻���ŵ�ϴ�.
  EXTI -> RTSR = 0x00000000;            // �� � �͵� Raising edge���� ���ͷ�Ʈ�� �߻���Ű�� �ʽ��ϴ�.
  EXTI -> IMR = (1 << 0) | (1 << 6);    // EXTI0�� EXTI6�� Ȱ��ȭ ��ŵ�ϴ�.
  
  NVIC_ISER0 = (1 << 6) | (1 << 23);    //NVIC�� EXTI0, EXTI6�� �����մϴ�.
  
  while(true);          //���ͷ�Ʈ�� �����ؾ��ϱ� ������ ���α׷��� �������� �ʽ��ϴ�.
  
  return 0;
}