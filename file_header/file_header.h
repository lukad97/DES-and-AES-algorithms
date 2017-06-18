#ifndef _FILE_HEADER_H_
#define _FILE_HEADER_H_

#include <stdint.h>
#include <stdlib.h>

#define FILENAME_LEN_MAX 256

#define ALLOC_CHECK(p)  if (!(p)) exit(1)
#define FILE_CHECK(p)   if (!(p)) return(2)

#define ALLOC_ERR    1
#define FILE_ERR     2
#define CRC_MISMATCH 3

typedef struct
{
	int8_t fileName[FILENAME_LEN_MAX];
	uint64_t byteLength;
	uint32_t crc, pad;
	uint8_t IV[16];
} fileheader_t;


fileheader_t headerCreate(FILE *file, const char *fileName);
int          headerCheck(FILE *file, fileheader_t *header);
void headerPrint(fileheader_t *header);
char* get_filename_from_path(char *file_path);

#endif // _FILE_HEADER_H_
