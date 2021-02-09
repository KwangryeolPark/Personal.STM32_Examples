#ifndef _RCC_H
#define _RCC_H

#include "typedef.h"

struct _RCC {
  uint32_t        CR;
  uint32_t        CFGR;
  uint32_t        CIR;
  uint32_t        APB2RSTR;
  uint32_t        APB1RSTR;
  uint32_t        AHBENR;
  uint32_t        APB2ENR;
  uint32_t        APB1ENR;
  uint32_t        BDCR;
  uint32_t        CSR;
};

volatile struct _RCC *RCC = (struct _RCC*) 0x40021000;

////////////////////////////////////////////////////////////////////////////////////////

#define TIM11EN 21
#define TIM10EN 20
#define TIM9EN  19
#define ADC3EN  15
#define USART1EN        14
#define TIM8EN  13
#define SPI1EN  12
#define TIM1EN  11
#define ADC2EN  10
#define ADC1EN  9
#define IOPGEN  8
#define IOPFEN  7
#define IOPEEN  6
#define IOPDEN  5
#define IOPCEN  4
#define IOPBEN  3
#define IOPAEN  2
#define AFIOEN  0

#endif