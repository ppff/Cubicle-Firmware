/**
  ******************************************************************************
  * File Name          : freertos.c
  * Date               : 29/05/2015 10:25:40
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "spi.h"
#include <stdint.h>
#include "stm32f4xx_hal_conf.h"
#include "CUB.h"
#include "fatfs.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;

/* USER CODE BEGIN Variables */
#define SPI_TIMEOUT 15
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);

extern void MX_FATFS_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */
/* USER CODE END FunctionPrototypes */
/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
	CUB_Init();
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityHigh, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{
  /* init code for FATFS */
  MX_FATFS_Init();

  /* USER CODE BEGIN StartDefaultTask */
    FATFS fs;
    CUB_FILE file;
    char buff[64];
    f_mount(&fs, (TCHAR const*)SD_Path, 0);
    if (CUB_fs_open(&file, "hello.txt", CUB_FILE_READ) != CUB_FS_OK)
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
    else {
        if (CUB_fs_read_line(buff, sizeof(buff), &file) == NULL)
            HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
        else {
            HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
        }
        if (CUB_fs_close(&file) != CUB_FS_OK) {
            HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET); 
        } else {
            HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET); 
            if (CUB_fs_open(&file, "hello.txt", CUB_FILE_WRITE) != CUB_FS_OK)
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET); 
            if (CUB_fs_seek(&file, f_size((FIL*)&file)) != CUB_FS_OK)
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET); 
            if (f_printf((FIL*)&file, "hey %d\n", 123) == -1)
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET); 
            if (CUB_fs_close(&file) != CUB_FS_OK)
                        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET); 
        }
    }

    CUB_ApplicationRun();
    /* Infinite loop */
    for(;;)
    {
        HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
        osDelay(3000);
    }
  /* USER CODE END StartDefaultTask */
}

/* StartTask02 function */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
    uint8_t pData0[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000000, 0b00000000, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000000, 0b00000000, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00000001  // Selection plan
                      };
    uint8_t pData1[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000000, 0b00000000, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000001, 0b11111111, // 4ème rangée de colones
                       0b00000001, 0b11111111, // 5ème rangée de colones
                       0b00000001, 0b11111111, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000000, 0b00000000, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00000010  // Selection plan
                      };
    uint8_t pData2[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000000, 0b00000000, // 2ème rangée de colones
                       0b00000001, 0b11111111, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000001, 0b11111111, // 7ème rangée de colones
                       0b00000000, 0b00000000, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00000100  // Selection plan
                      };
    uint8_t pData3[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000001, 0b11111111, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000001, 0b11111111, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00001000  // Selection plan
                      };
    uint8_t pData4[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000001, 0b11111111, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000001, 0b11111111, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00010000  // Selection plan
                      };
    uint8_t pData5[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000001, 0b11111111, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000001, 0b11111111, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b00100000  // Selection plan
                      };
    uint8_t pData6[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000000, 0b00000000, // 2ème rangée de colones
                       0b00000001, 0b11111111, // 3ème rangée de colones
                       0b00000000, 0b00000000, // 4ème rangée de colones
                       0b00000000, 0b00000000, // 5ème rangée de colones
                       0b00000000, 0b00000000, // 6ème rangée de colones
                       0b00000001, 0b11111111, // 7ème rangée de colones
                       0b00000000, 0b00000000, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000000, 0b01000000  // Selection plan
                      };
    uint8_t pData7[] = {
                       0b00000000, 0b00000001, // 1ère rangée de colones
                       0b00000000, 0b00000001, // 2ème rangée de colones
                       0b00000000, 0b00000001, // 3ème rangée de colones
                       0b00000001, 0b11111111, // 4ème rangée de colones
                       0b00000001, 0b11111111, // 5ème rangée de colones
                       0b00000001, 0b11111111, // 6ème rangée de colones
                       0b00000000, 0b00000001, // 7ème rangée de colones
                       0b00000000, 0b00000001, // 8ème rangée de colones
                       0b00000000, 0b00000001, // 9ème rangée de colones
                       0b00000000, 0b10000000  // Selection plan
                      };
    uint8_t pData8[] = {
                       0b00000000, 0b00000000, // 1ère rangée de colones
                       0b00000000, 0b00000000, // 2ème rangée de colones
                       0b00000000, 0b00000000, // 3ème rangée de colones
                       0b00000001, 0b11111111, // 4ème rangée de colones
                       0b00000001, 0b11111111, // 5ème rangée de colones
                       0b00000001, 0b11111111, // 6ème rangée de colones
                       0b00000000, 0b00000000, // 7ème rangée de colones
                       0b00000000, 0b00000000, // 8ème rangée de colones
                       0b00000000, 0b00000000, // 9ème rangée de colones
                       0b00000001, 0b00000000  // Selection plan
                      };
  /* Infinite loop */
    uint8_t plan = 0;
    uint8_t* cercle[] = {pData0, pData1, pData2, pData3, pData4, pData5, pData6, pData7, pData8};
  for(;;)
  {
    HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi4, *(cercle+plan), 20, 15);
    while (status != HAL_OK)
        status = HAL_SPI_Transmit(&hspi4, *(cercle+plan), 20, 15);
    for (int i=0; i < 8000; i++) ; 
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
    for (int i=0; i < 8000; i++) ; // 40 tours de boucles == 3 µs
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
    plan = (plan + 1)%9;
    osDelay(10000);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
