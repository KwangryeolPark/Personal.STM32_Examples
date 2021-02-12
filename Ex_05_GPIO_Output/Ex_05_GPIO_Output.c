/*      �⺻ ����

  * Ex_05_GPIO_Output
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  GPIO�� �ٷ�� �����Դϴ�.
  
  Open103Z ���� ���� LED �κ��� ������ 2 ��° LED�� ����մϴ�.  
  �ش� LED�� STM32 Ĩ�� PF7�ɿ� ����Ǿ� �ֽ��ϴ�.
  
  PF7���� ����ϱ� ���� GPIOF�� Ŭ���� �ΰ��ϰ�, ���� ���Ǵ� Push-pull, 100 MHz ���� �����մϴ�. 
  ������ �����ٸ� PF7�� HIGH ��ȣ�� �ΰ��մϴ�.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF�� Ŭ���� �ΰ��մϴ�.

  GPIOF -> CRL = (1 << MODE7);          // PF7���� Push-pull, 10 MHz ���� �����մϴ�.
  GPIOF -> ODR = (1 << 7);              // PF7�ɿ� HIGH ��ȣ�� �����ϴ�.
  
  return 0;
}
