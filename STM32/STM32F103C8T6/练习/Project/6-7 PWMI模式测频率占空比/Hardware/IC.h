#ifndef __IC
#define __IC
#define CLOCK 72000000
void IC_Init();
uint32_t IC_GetFreq(void);
uint32_t IC_GetDuty(void);
#endif
