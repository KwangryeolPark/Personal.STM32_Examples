/*      �⺻ ����

  * Ex_05_GPIO_Output
  * 2021-02-09
  * �ڱ���
  * @copyright Copyright (c) Park Kwangryeol All right reserved.


*/
/*      ����

  GPIO�� �ٷ�� �����Դϴ�.
  PF7���� ����ϱ� ���� GPIOF�� Ŭ���� �Է��ϰ�, PF7���� Push-pull ���� �����մϴ�.
  PF7�� HIGH ��ȣ�� �ΰ��մϴ�.
*/

#include "gpio.h"
#include "rcc.h"

int main(void) {
  
  RCC -> APB2ENR = (1 << IOPFEN);       // GPIOF�� Ŭ���� �ΰ��մϴ�.

  GPIOF -> CRL = (1 << MODE7);          // PF7���� Push-pull ���� �����մϴ�.
  GPIOF -> ODR = (1 << 7);              // PF7�ɿ� HIGH ��ȣ�� �����ϴ�.
  
  return 0;
}