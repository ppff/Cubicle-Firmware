/**
 * @file   CUB_fs.h
 * @brief  Wrapper module around FatFs' API for simplified file management
 * @author Yassine El Khadiri
 */

#ifndef _CUB_FS_H_
#define _CUB_FS_H_

#include "fatfs.h"

#define CUB_FILE_READ          FA_READ          /**< Open file with read access (can be combined with CUB_FILE_WRITE) @hideinitializer */
#define CUB_FILE_WRITE         FA_WRITE         /**< Open file with write access (can be combined with CUB_FILE_READ) @hideinitializer */
#define CUB_FILE_OPEN_EXISTING FA_OPEN_EXISTING /**< Open file or fail if not existing                                @hideinitializer */
#define CUB_FILE_CREATE_NEW    FA_CREATE_NEW    /**< Create new file or fail if already existing                      @hideinitializer */ 
#define CUB_FILE_OPEN_ALWAYS   FA_OPEN_ALWAYS   /**< Open file or create a new file. Use CUB_fs_seek to append data   @hideinitializer */
#define CUB_FILE_CREATE_ALWAYS FA_CREATE_ALWAYS /**< Open new file or truncate and overwrite if existing              @hideinitializer */

typedef FIL CUB_FILE;                           /**< Use FatFs' file structure */

/// Possible error codes returned by file functions
typedef enum {
    /// (0) Succeeded
    CUB_FS_OK = 0,
    /// (1) A hard error occurred in the low level disk I/O layer
    CUB_FS_DISK_ERR,
    /// (2) Assertion failed
    CUB_FS_INT_ERR,
    /// (3) The physical drive cannot work
    CUB_FS_NOT_READY,
    /// (4) Could not find the file
    CUB_FS_NO_FILE,
    /// (5) Could not find the path
    CUB_FS_NO_PATH,
    /// (6) The path name format is invalid
    CUB_FS_INVALID_NAME,
    /// (7) Access denied due to prohibited access or directory full
    CUB_FS_DENIED,
    /// (8) Access denied due to prohibited access
    CUB_FS_EXIST,
    /// (9) The file/directory object is invalid
    CUB_FS_INVALID_OBJECT,
    /// (10) The physical drive is write protected
    CUB_FS_WRITE_PROTECTED,
    /// (11) The logical drive number is invalid
    CUB_FS_INVALID_DRIVE,
    /// (12) The volume has no work area
    CUB_FS_NOT_ENABLED,
    /// (13) There is no valid FAT volume
    CUB_FS_NO_FILESYSTEM,
    /// (14) The f_mkfs() aborted due to any parameter error
    CUB_FS_MKFS_ABORTED,
    /// (15) Could not get a grant to access the volume within defined period
    CUB_FS_TIMEOUT,
    /// (16) The operation is rejected according to the file sharing policy
    CUB_FS_LOCKED,
    /// (17) LFN working buffer could not be allocated
    CUB_FS_NOT_ENOUGH_CORE,
    /// (18) Number of open files > _FS_SHARE
    CUB_FS_TOO_MANY_OPEN_FILES,
    /// (19) Given parameter is invalid
    CUB_FS_INVALID_PARAMETER
} CUB_FS_ERR;

/**
 * @brief Create a file object to access the file
 * @param fp   Pointer to the file object structure
 * @param path File name
 * @param mode Open flags (see defines in CUB_fs.h)
 * @return Error value
 */
CUB_FS_ERR CUB_fs_open(CUB_FILE* fp, const char* path, uint8_t mode);

/**
 * @brief Close an open file
 * @param fp Pointer to the file object structure
 * @return Error value
 */
CUB_FS_ERR CUB_fs_close(CUB_FILE* fp);

/**
 * @brief Move the file read/write pointer
 * @param fp     Pointer to the file object structure
 * @param offset Byte offset from the top of the file
 * @return Error value
 */
CUB_FS_ERR CUB_fs_seek(CUB_FILE* fp, uint32_t offset);

/**
 * @brief Read a string from file
 * This function continues to read until it hits an '\n' or eof or the buffer is filled
 * with len - 1 characters. The read string is terminated with '\0'.
 * In case of failure or no character to read the status of EOF and error can be checked
 * with CUB_fs_eof and CUB_fs_error functions.
 * @param buff Buffer where to write read characters
 * @param len  Buffer size in unit of character
 * @param fp   Pointer to file object structure
 * @return the read buffer or a null pointer in case of failure
 */
char* CUB_fs_read_line(char* buff, int len, CUB_FILE* fp);

#endif
