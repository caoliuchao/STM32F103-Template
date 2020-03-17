/************************************************************************
* @�ļ�  : sys.h
* @����  : caochao
* @����  : 10-1-2018
* @ժҪ  : ���ͷ�ļ�������systick��غ�������
* �޸��� :
*  ����  :
*
* �޸��� :
*  ����  :
************************************************************************/
/* �����ֹ�ݹ�İ��� */
#ifndef _SYS_H
#define _SYS_H

#ifdef __cplusplus
 extern "C" {
#endif

#define SYSTEM_SUPPORT_OS		1   //����ϵͳ�ļ����Ƿ�֧��UCOS
     
/*---------------------------��Ҫ��ͷ�ļ�-------------------------------*/     
#include "stm32f10x.h"
 
/*---------------------------ȫ�ֱ����궨��-----------------------------*/     
#ifdef  DELAY_GLOBALS   
#define DELAY_GLOBALS      
#else   
#define DELAY_GLOBALS  extern
#endif
 
/*---------------------------------------------------------------------*/
DELAY_GLOBALS uint8_t  fac_us;      //us��ʱ������
DELAY_GLOBALS uint16_t fac_ms;      //ms��ʱ������

/*
��Ϊû�ж���DELAY_GLOBALS����� ��ʽ�ȼ�����������

extern uint8_t  fac_us;      //us��ʱ������
extern uint16_t fac_ms;      //ms��ʱ������
*/

/*----------------------------����������--------------------------------*/     
void Systick_Init(void);   
     
#ifdef __cplusplus
}
#endif

#endif /*sys.h*/
/***************************�ļ�����**************************************/

