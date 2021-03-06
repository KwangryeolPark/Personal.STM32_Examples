/*      기본 정보

  * Ex_07_Timer_easy
  * 2021-02-11
  * 박광렬
  * @copyright Copyright (c) Park Kwangryeol All right reserved.
  * target: stm32f103zet6 (open103 board)

*/
/*      설명

    Timer Compare 기능을 활용하여 LED의 상태를 High / Low / Toggle 중 한 상태로 만드는 코드입니다.

    C언어로 되어 있는 분들은 extern "C"부분의 주석을 그대로 놔두시고,
    C++로 되어 있는 분들은 주석을 삭제해 주세요.

*/

#include "inc.h"

void initRCC(void);
void initTimClk(void);
void initTim(void);
void setTimCntDir(void);
void setTimCmpMode(void);
void initTimFlg(void);
void enbTim(void);
void initGPIO(void);
/*
extern "C" {
  void TIM2_IRQHandler(void);
};*/

void TIM2_IRQHandler(void) {
    TIM2 -> SR &= ~(1 << 2);
  
    GPIOF -> ODR ^= (1 << 6);
    
    TIM2 -> CNT = 0;
}

int main(void) {
  
  initRCC();
  initTimClk();
  initTim();
  setTimCntDir();
  setTimCmpMode();
  initTimFlg();
  enbTim();
  initGPIO();
  NVIC_ISER0 = (1 << 28);
  
  while(true);
  
  return 0;
}

void initRCC(void) {
  RCC -> CFGR = 0x001F8402;
  RCC -> CR = 0x01010082;
}

void initTimClk(void) {
  RCC -> APB1ENR = 0x0001;              // Activate Timer 2
  TIM2 -> PSC = 3600 - 1;           //36,000,000 / (3,600) = 10,000 Hz
  //TIM2 -> PSC = 36000 - 1;           //36,000,000 / (36,000) = 1,000 Hz
}

void initTim(void) {
  TIM2 -> ARR = 2000;
  TIM2 -> CRR1 = 2000;
  TIM2 -> DIER |= 0x0004;
}

void setTimCntDir(void) {
  TIM2 -> CR1 = 0x0100;
  TIM2 -> CR2 = 0x0000;
}

void setTimCmpMode(void) {
  TIM2 -> CCER = 0x0000;
  TIM2 -> CCMR1 = 0x0018;
  
  TIM2 -> CCER |= 0x0001;
}

void initTimFlg(void) {
  TIM2 -> SR = 0x0000;
  TIM2 -> CNT = 0x0000;
}

void enbTim(void) {
  TIM2 -> CR1 |= 0x0001;
}

void initGPIO(void) {
  RCC -> APB2ENR = (1 << IOPFEN);
  GPIOF -> CRL = (1 << MODE6);
}