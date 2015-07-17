#include "database_utils.h"
#include "fatfs.h"
#include "inttypes.h"
#include "constant.h"

FATFS SDFatFs;

bool init_storage()
{
	FRESULT res = f_mount(&SDFatFs, (TCHAR const*)SD_Path, 0);
	return res == FR_OK;
}


char* file2string(char* filename)
{
	FIL my_file;
	if (f_open(&my_file, filename, FA_READ) != FR_OK)
	{
		return NULL;
	} else {
		// kwerky way to get clean file size
		uint32_t file_size = f_size(&my_file);
		char* str = malloc(file_size);
		
		// read the file in a buffer
		f_lseek(&my_file, 0);
		uint32_t bytesread; // TODO check bytesead agains lenght
		FRESULT res = f_read(&my_file, str, file_size, (UINT*)&bytesread);
		str[file_size-1] = '\0';
		f_close(&my_file);
		if (res != FR_OK)
		{
			return NULL;
		} else {
			return str;
		}
	}
}
