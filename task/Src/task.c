/********************************************************************
* @文件  : task.c
* @作者  : caochao
* @日期  : 14-2-2017
* @摘要  : 这个c文件包含各个任务
* 修改人 :
*  日期  :
*
* 修改人 :
*  日期  :
*********************************************************************/
#include "stm32f10x.h"
#include "includes.h"
#include "task.h"

/*-----------------开始任务堆栈-------------------------------------*/
__align(8) OS_STK START_TASK_STK[START_STK_SIZE];   //创建任务堆栈空间

/*-----------------串口打印堆栈-------------------------------------*/
__align(8) OS_STK USART1_TASK_STK[USART1_STK_SIZE]; //创建任务堆栈空间	

/*******************************************************************
*   函数名：start_task(void *pdata)
*   功  能：开始任务，建立其他任务
*   输  入：
*          pdata 指针
*   输  出：
*          无
*******************************************************************/
void start_task(void *pdata)
{
    uint8_t status;
    OS_CPU_SR cpu_sr = 0;
	
    SYSBSP_Init();   //系统硬件初始化       
    Systick_Init();  //启动UCOSII系统节拍 
    
	OSStatInit();		  //初始化统计任务.这里会延时1秒钟左右	
 	OS_ENTER_CRITICAL();  //进入临界区(无法被中断打断)   
	
    OSTaskCreate(usart1_task,(void *)0,(OS_STK*)&USART1_TASK_STK[USART1_STK_SIZE-1],USART1_TASK_PRIO);  

    status = OSTaskDelReq(OS_PRIO_SELF);	//请求删除起始任务.
    if (status == OS_ERR_NONE)
    {
		status = OSTaskDel(OS_PRIO_SELF);
        if (status == OS_ERR_NONE)
        {
            printf("删除开始任务成功 \r\n");
        }
        else
        {
            printf("开始任务删除失败 \r\n");
        }
    }
    else
    {
        printf("请求开始任务删除失败 \r\n");
    }
    
    OS_EXIT_CRITICAL();	   //退出临界区(可以被中断打断)    	
}

/*********************************************************************
*   函数名：usart1_task(void *pdata)
*   功  能：usart1串口打印任务
*   输  入：
*          pdata 指针
*   输  出：
*          无
**********************************************************************/
void usart1_task(void *pdata)
{  
    while (1)
    {  	
        printf("CPU的使用率为：%d%%  \r\n",OSCPUUsage);  //打印出CPU的使用率
		Delay1ms(1000);	
    }
}
				
/*****************************文件结束********************************/
                


