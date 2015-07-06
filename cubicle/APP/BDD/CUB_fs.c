/**
 * @file   CUB_fs.c
 * @brief  Simplified file management function's implementation
 * @author Yassine El Khadiri 
 */

#include "CUB_fs.h"
#include "fatfs.h"
#include <stdint.h>


CUB_FS_ERR CUB_fs_open(CUB_FILE* fp, const char* path, uint8_t mode)
{
    return (CUB_FS_ERR) f_open((FIL*)fp, path, mode);
}

CUB_FS_ERR CUB_fs_close(CUB_FILE* fp)
{
    return (CUB_FS_ERR) f_close((FIL*)fp);
}

CUB_FS_ERR CUB_fs_seek(CUB_FILE* fp, uint32_t offset)
{
    return (CUB_FS_ERR) f_lseek((FIL*)fp, offset);
}

char* CUB_fs_read_line(char* buff, int len, CUB_FILE* fp)
{
    return f_gets((TCHAR*)buff, len, (FIL*)fp);
}
