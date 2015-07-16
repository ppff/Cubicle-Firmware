#ifndef _DATABASE_UTILS_H_
#define _DATABASE_UTILS_H_

#include "stdbool.h"

/**
 * Mounting stuff'n shit
 * call this before any operation on storage!
 * return true if everything's alright
 */
bool init_storage();

/**
 * Don't forget to free ressources you don't need! :p
 * returns NULL if shit got real
 */
char* file2string(char* filename);

#endif
