#include "database_utils.h"
#include "fatfs.h"
#include "inttypes.h"
#include "constant.h"
#include "jsmn.h"
#include "database_structures.h"
#include "mem_management.h"
#include "string.h"
#include "stdbool.h"
#include "simple_utils.h"

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


// TODO return some different error codes for different problems
// instead of just a freaking NULL
database_t* string2database(char* json)
{	
	database_t* db;

	// Parsing database
	jsmn_parser json_parser;
	int32_t read_tokens;
	size_t tokcount = 2;
	jsmntok_t *tok;
	tok = malloc(sizeof(*tok)*tokcount);
	jsmn_init(&json_parser);
again:
	read_tokens = jsmn_parse(&json_parser, json, strlen(json)+1, tok, tokcount);

	if (read_tokens < 0)
	{
		switch(read_tokens){
		case JSMN_ERROR_NOMEM:
			tokcount *= 2;
			tok = realloc(tok, sizeof(*tok)*tokcount);
			goto again;
			break;
		case JSMN_ERROR_INVAL:
			return NULL;
			break;
		case JSMN_ERROR_PART:
			return NULL;
			break;
		}
	} else {

		// check file version number
		char ver[tok[1].end-tok[1].start+1];
		memcpy(ver, json+tok[1].start, tok[1].end-tok[1].start+1);
		ver[tok[1].end-tok[1].start] = '\0';
		bool ver_ok = !strcmp(ver, "1.00");

		if (!ver_ok) {
			return NULL;
		} else {
			// get database name and number of groups
			char db_name[tok[2].end-tok[2].start+1];
			memcpy(db_name, json+tok[2].start, tok[2].end-tok[2].start+1);
			db_name[tok[2].end-tok[2].start] = '\0';
			group_t *groups = NULL;
			uint32_t err = parse_groups(json, tok, 3, &groups);
			if (err < 0)
				return NULL;
			db = new_database(db_name, tok[3].size, groups);
			point_t* points = NULL;
			uint32_t options_index = parse_points(json,tok,15,&points);
			if (options_index != 48)
				return NULL;
		}
	}

	return db;
}


uint32_t parse_points(char* json, jsmntok_t* tok, uint32_t index, point_t** points)
{
	uint32_t nb_points = tok[index].size;
	*points = NULL;

	for (int i=0; i<nb_points; i++)
	{
		index += 2; // selecting the next x point

		char x_c[tok[index].end-tok[index].start+1];
		memcpy(x_c, json+tok[index].start,tok[index].end-tok[index].start+1);
		x_c[tok[index].end-tok[index].start] = '\0';
		uint8_t x = atoi(x_c);
		
		index++;

		char y_c[tok[index].end-tok[index].start+1];
		memcpy(y_c, json+tok[index].start,tok[index].end-tok[index].start+1);
		y_c[tok[index].end-tok[index].start] = '\0';
		uint8_t y = atoi(y_c);

		index++;

		char z_c[tok[index].end-tok[index].start+1];
		memcpy(z_c, json+tok[index].start,tok[index].end-tok[index].start+1);
		z_c[tok[index].end-tok[index].start] = '\0';
		uint8_t z = atoi(z_c);		
		
		new_point_queue(x,y,z,points);	
	}

	index++;

	return index;
}

uint32_t parse_options(char* json, jsmntok_t* tok, uint32_t index, option_t** options)
{
	
	return 0;
}

uint32_t parse_motifs(char* json, jsmntok_t* tok, uint32_t index, motif_t** motifs)
{
	return 0;
}

uint32_t parse_groups(char* json, jsmntok_t* tok, uint32_t index, group_t** groups)
{
	return 0;
}
