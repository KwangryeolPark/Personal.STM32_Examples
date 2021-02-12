/*      �⺻ ����

  * Ex_05_GPIO_Output_Open_drain.c
  * 2021-02-12
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.
  * https://pkr7098.tistory.com/165
  * pkr7098@gmail.com

*/
/*      ����

  GPIO�� �ٷ�� �����Դϴ�.
  
  Open103Z ���� ���� LED �κ��� ������ 2 ��° LED�� ����մϴ�.  
  �ش� LED�� STM32 Ĩ�� PF7�ɿ� ����Ǿ� �ֽ��ϴ�.
  
  PF7���� ����ϱ� ���� GPIOF�� Ŭ���� �ΰ��ϰ�, Open-drain, 100 MHz ���� �����մϴ�. 
  
  ��� ������ �������� PF7�� HIGH�� LOW ��ȣ�� �ݺ������� �����ϴ�.
*/

#include "gpio.h"
#include "rcc.h"

void Delay(unsigned long delay);        // �ӽ÷� ���� Delay �Լ��Դϴ�.

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF�� Ŭ���� �ΰ��մϴ�.

  GPIOF -> CRL = (5 << MODE7);          // PF7���� Push-pull, 10 MHz ���� �����մϴ�.
  
  while(1) {
    GPIOF -> ODR = (1 << 7);              // PF7�ɿ� HIGH ��ȣ�� �����ϴ�.
    Delay(0xFFFFFF);
    GPIOF -> ODR = 0;              // PF7�ɿ� HIGH ��ȣ�� �����ϴ�.
    Delay(0xFFFFFF);
  }
  
  return 0;
}


void Delay(unsigned long delay) {
  for(; delay; delay--) ;
}
