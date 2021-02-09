/*      �⺻ ����

  * Ex_06_Exception_easy
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  �ܺ� ���ͷ�Ʈ�� ó���ϴ� ������ �����Դϴ�.

  EXTI6 ���ͷ�Ʈ�� �߻��Ǹ� PF7�� ����� LED�� ON�˴ϴ�.
*/

#include "inc.h"

void EXTI9_5_IRQHandler(void) { // EXTI6�� �߻��Ǹ� ȣ��Ǵ� Handler�Դϴ�. (��Ȯ���� EXTI9 ~ 5 �� �ϳ��� �߻��Ѵٸ�)
  //Handler�̸��� startup_stm32f10x_hd_vl.s�� ���ǵǾ� �ֽ��ϴ�. 
  if(EXTI -> PR & (1 << 6)) {   // EXTI9 ~ 5�߿� EXTI6�� �߻��� ������ Ȯ���մϴ�.
    EXTI -> PR |= (1 << 6);     // EXTI6�� �� �� �߻��Ǿ��� ������ �ٽ� 0���� ����� �ݴϴ�. (1�� write�ϸ� �ϵ���������� 0���� �ʱ�ȭ �˴ϴ�.)
    GPIOF -> ODR = (1 << 6);   // PF6 LED��  ON�մϴ�.
  }
}

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPGEN) | (1 << IOPFEN) | (1 << AFIOEN);        // GPIOG, F�� Ŭ���� �ΰ��մϴ�. AFIO�� Ŭ���� �ΰ��մϴ�.
  
  GPIOG -> CRL = (8 << MODE6);      // PG6�� pull-up/pull-down ���� �����մϴ�.
  GPIOG -> ODR = (1 << 6);      // PG6�� pull-up ���� �����մϴ�. (Open103Z ���忡 Pull-up ��带 ����ϵ��� ���� �Ǿ� �ֽ��ϴ�.)
  GPIOF -> CRL = (1 << MODE6);  //PF6�� Push-pull ���� �����մϴ�.
  
  AFIO -> EXTICR2 = (6 << 8);   // EXTI6�� PG6�� �����մϴ�.
  
  EXTI -> FTSR = (1 << 6);   // Falling edge���� EXTI6�� �߻���ŵ�ϴ�.
  EXTI -> RTSR = 0x00000000;            // �� � �͵� Raising edge���� ���ͷ�Ʈ�� �߻���Ű�� �ʽ��ϴ�.
  EXTI -> IMR = (1 << 6);    // EXTI6�� Ȱ��ȭ ��ŵ�ϴ�.
  
  NVIC_ISER0 = (1 << 23);    //NVIC�� EXTI6�� �����մϴ�.
  
  while(true);          //���ͷ�Ʈ�� �����ؾ��ϱ� ������ ���α׷��� �������� �ʽ��ϴ�.
  
  return 0;
}