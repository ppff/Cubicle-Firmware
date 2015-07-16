#ifndef _DATABASE_STRUCTURES_H_
#define _DATABASE_STRUCTURES_H_

#include "inttypes.h"


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

#endif
