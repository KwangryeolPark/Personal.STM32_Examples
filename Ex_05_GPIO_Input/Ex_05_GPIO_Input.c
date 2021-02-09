/*      �⺻ ����

  * Ex_05_GPIO_Input
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  GPIO�� �ٷ�� �����Դϴ�.
  PG6���� Input pull-up ���� �Ͽ� Open103Z�� USERKEY ��ư ���¸� �а�,
  PF7�ɿ� ��ư�� ���¸� �����ݴϴ�.

  ��ư�� ������ PF7 LED�� ON, �׷��� ������ OFF�� �� �����Դϴ�.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN) | (1 << IOPGEN);       // GPIOF�� Ŭ���� �ΰ��մϴ�.

  GPIOF -> CRL = (1 << MODE7);          // PF7���� Push-pull ���� �����մϴ�.
  GPIOF -> ODR = (1 << 7);              // PF7�ɿ� HIGH ��ȣ�� �����ϴ�.
  
  GPIOG -> CRL = (8 << MODE6);          // PG6���� pull-up / pull-down ���(8)�� �����մϴ�.
  GPIOG -> ODR = (1 << 6);              // PG6���� pull-up ���� �����մϴ�.
  
  while(1) {
    if( !(GPIOG -> IDR & (1 << 6))) GPIOF -> ODR = (1 << 7);    //��ư�� ������ ��
    else GPIOF -> ODR = 0;      //��ư�� �� ������ ��
  }
  
  return 0;
}