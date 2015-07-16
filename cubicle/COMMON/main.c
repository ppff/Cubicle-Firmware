/**
 ******************************************************************************
 * File Name          : main.c
 * Date               : 26/05/2015 17:32:30
 * Description        : Main program body
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
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "fatfs.h"
#include "sdio.h"
#include "spi.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "stm32f4xx_hal_conf.h"
#include "CUB.h"
#include "CUB_text.h"
#include "fatfs.h"
#include "constant.h"
#include "string.h"
#include "jsmn.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
typedef struct point {
	uint8_t x, y, z;
	struct point* next;
} point_t;

typedef struct option {
	char* name;
	int value;
	struct option* next;
} option_t;

typedef struct motif {
	char* name;
	char* desc;
	char* image;
	point_t* points;
	option_t* options;
	struct motif* next;
} motif_t;

typedef struct group {
	char* name;
	uint32_t nb_motifs;
	motif_t* motifs;
	struct group* next;
} group_t;

typedef struct database {
	char* name;
	uint32_t nb_groups;
	group_t* groups;
} database_t;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

/* USER CODE BEGIN PFP */
point_t* new_point_head(uint8_t x, uint8_t y, uint8_t z, point_t* old_head);
point_t* free_point(point_t* point);
option_t* new_option_head(char* name, int val, option_t* old_head);
option_t* free_option(option_t* option);
motif_t* new_motif_head(char* name, char* desc, char* image, point_t* points, option_t* options, motif_t* old_head);
motif_t* free_motif(motif_t* motif);
group_t* new_group_head(char* name, uint32_t nb_motifs, motif_t* motifs, group_t* old_head);
group_t* free_group(group_t* group);
database_t* new_database(char* name, uint32_t nb_groups, group_t* groups);
void free_database(database_t* database);



point_t* new_point_head(uint8_t x, uint8_t y, uint8_t z, point_t* old_head)
{
	point_t* p = MALLOC(sizeof(point_t));
	p->x = x;
	p->y = y;
	p->z = z;
	p->next = old_head;
	return p;
}

point_t* free_point(point_t* point)
{
	point_t* next = point->next;
	FREE(point);
	return next;
}

option_t* new_option_head(char* name, int val, option_t* old_head)
{
	option_t* o = MALLOC(sizeof(option_t));
	o->name = MALLOC(strlen(name));
	o->name = strcpy(o->name, name);
	o->value = val;
	o->next = old_head;
	return o;
}

option_t* free_option(option_t* option)
{
	option_t* next = option->next;
	FREE(option->name);
	FREE(option);
	return next;
}

motif_t* new_motif_head(char* name, char* desc, char* image, point_t* points, option_t* options, motif_t* old_head)
{
	motif_t* m = MALLOC(sizeof(motif_t));
	m->name = MALLOC(strlen(name));
	m->name = strcpy(m->name, name);
	m->desc = MALLOC(strlen(desc));
	m->desc = strcpy(m->desc, desc);
	m->image = MALLOC(strlen(image));
	m->image = strcpy(m->image, image);
	m->points = points;
	m->options = options;
	m->next = old_head;
	return m;
}

motif_t* free_motif(motif_t* motif)
{
	motif_t* next = motif->next;
	FREE(motif->name);
	FREE(motif->desc);
	FREE(motif->image);
	point_t* p = motif->points;
	while (p != NULL)
		p = free_point(p);
	option_t* o = motif->options;
	while (o != NULL)
		o = free_option(o);
	FREE(motif);
	return next;
}

group_t* new_group_head(char* name, uint32_t nb_motifs, motif_t* motifs, group_t* old_head)
{
	group_t* g = MALLOC(sizeof(group_t));
	g->name = MALLOC(strlen(name));
	g->name = strcpy(g->name, name);
	g->nb_motifs = nb_motifs;
	g->motifs = motifs;
	g->next = old_head;
	return g;
}

group_t* free_group(group_t* group)
{
	group_t* next = group->next;
	FREE(group->name);
	motif_t* m = group->motifs;
	while (m != NULL)
		m = free_motif(m);
	return next;
}

database_t* new_database(char* name, uint32_t nb_groups, group_t* groups)
{
	database_t* database = MALLOC(sizeof(database_t));
	database->name = MALLOC(strlen(name));
	database->name = strcpy(database->name, name);
	database->nb_groups = nb_groups;
	database->groups = groups;
	return database;
}

void free_database(database_t* database)
{
	FREE(database->name);
	group_t* g = database->groups;
	while (g != NULL)
		g = free_group(g);
	FREE(database);
}

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration----------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_SDIO_SD_Init();
	MX_SPI4_Init();

	/* USER CODE BEGIN 2 */
	MX_FATFS_Init();
	CUB_TextInit(2,20);
	CUB_TextClear();
	CUB_TextHome();
	FATFS SDFatFs;
	DIR dir;
	FRESULT res;
	FILINFO fno;
	char* fn;
	static char lfn[_MAX_LFN+1];
	fno.lfname = lfn;
	fno.lfsize = sizeof lfn;
	char* dbname = "bd1.json";
	bool db_found = false;

	if (f_mount(&SDFatFs, (TCHAR const*)SD_Path, 0) != FR_OK )
	{
		CUB_TextPrint("Error f_mount");
	} else {
		if (f_opendir(&dir, "/") != FR_OK)
		{
			CUB_TextPrint("Error opening / dir");
		} else {
			for (;;)
			{
				res = f_readdir(&dir, &fno);
				if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
				if (fno.fname[0] == '.') continue;             /* Ignore dot entry */
				fn = *fno.lfname ? fno.lfname : fno.fname;
				if (fno.fattrib & AM_DIR) {                    /* It is a directory */
					// do nothing
				} else {                                       /* It is a file. */
					// check if database
					db_found = !strcmp(fn, dbname);
					if (db_found) break;
				}
			}
			f_closedir(&dir);
			CUB_TextClear();
			CUB_TextHome();
			if (!db_found) {
				CUB_TextPrintf("Data Base not found!");
				HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
			} else {
				// Loading database on the heap
				FIL json_file;
				if (f_open(&json_file, dbname, FA_READ) != FR_OK) {
					CUB_TextPrintf("error opening file");
				} else {
					uint32_t json_size = f_size(&json_file);
					char* json = MALLOC(json_size);
					uint32_t bytesread;
					f_read(&json_file, json, json_size, (UINT*)&bytesread);
					f_close(&json_file);

					// Parsing database
					jsmn_parser json_parser;
					int32_t read_tokens;
					jsmntok_t t[512];
					jsmn_init(&json_parser);
					read_tokens = jsmn_parse(&json_parser, json, json_size, t, 512);
					CUB_TextClear();
					CUB_TextHome();
					if (read_tokens < 0) {
						CUB_TextPrintf("not tokens : -%i", -read_tokens);
					} else {
						CUB_TextPrintf("nb of tokens : %i", read_tokens);
						CUB_TextClear();
						CUB_TextHome();
						//int i = 9;
						//CUB_TextPrintf("%.*s\nsize = %i", t[i].end - t[i].start, json+t[i].start, t[i].size);
						char db_name[t[1].end-t[1].start+1];
						memcpy(db_name, json+t[1].start, t[1].end-t[1].start+1);
						db_name[t[1].end-t[1].start] = '\0';
						database_t* db = new_database(db_name, t[2].size, NULL);
						CUB_TextPrintf("%s\n%i groups", db->name, db->nb_groups);
					}
				}
			}
		}
	}

	/* USER CODE END 2 */

	/* Call init function for freertos objects (in freertos.c) */
	//MX_FREERTOS_Init();

	/* Start scheduler */
	//osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)

	{

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */

	}

	/* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	__PWR_CLK_ENABLE();

	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
		|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
 * @brief Reports the name of the source file and the source line number
 * where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */ 
	/* USER CODE END 6 */

}

#endif

/**
 * @}
 */ 

/**
 * @}
 */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
