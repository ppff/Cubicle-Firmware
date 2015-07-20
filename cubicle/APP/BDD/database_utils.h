#ifndef _DATABASE_UTILS_H_
#define _DATABASE_UTILS_H_

#include "stdbool.h"
#include "stdint.h"
#include "database_structures.h"
#include "jsmn.h"

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

/**
 * parse string return database. simple.
 * oh and don't forget to free ;p
 */
database_t* string2database(char* json);

uint32_t parse_points(char* json, jsmntok_t* tok, uint32_t index, point_t** points);
uint32_t parse_options(char* json, jsmntok_t* tok, uint32_t index, option_t** options);
uint32_t parse_motifs(char* json, jsmntok_t* tok, uint32_t index, motif_t** motifs);
uint32_t parse_groups(char* json, jsmntok_t* tok, uint32_t index, group_t** groups);

#endif
