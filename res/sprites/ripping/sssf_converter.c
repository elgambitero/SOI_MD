#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FILENAME_BUF 256

typedef struct{
    uint32_t frames;
    uint32_t * frame_offset;
}Sssf_Header;

typedef struct{
    uint16_t width;
    uint16_t height;
    uint32_t h_length;
    uint8_t * pixel_skip;
    uint8_t * pixel;
}SOI_Frame;

Sssf_Header header;
FILE *fin;
FILE *fpalette;
FILE *fout;

char filename[FILENAME_BUF];

uint16_t swap_endian_16(uint16_t num);
uint32_t swap_endian_32(uint32_t num);

int main(int argc, char **argv){
    if(argc != 4){
        printf("You must specify an input file, a converted clut palette file, and a destination folder.\r\n");
        return 1;
    }

    fin = fopen(argv[1],"r");

    fread(&header.frames, sizeof(uint32_t), 1, fin);
    fseek(fin, 8, SEEK_CUR);

    header.frames = swap_endian_32(header.frames);

    printf("There are %d frames:\r\n",header.frames);

    header.frame_offset = (uint32_t*) malloc(sizeof(uint32_t) * header.frames);

    if(header.frame_offset == NULL) {printf("FRAME OFFSET MALLOC ERROR\r\n"); return 1;}

    for(uint32_t i = 0; i < header.frames; i++){
        fread(header.frame_offset + i, sizeof(uint32_t), 1, fin);
        *(header.frame_offset + i) = swap_endian_32(*(header.frame_offset + i));
    }


    for(uint32_t i = 0; i < header.frames; i++){
        printf("%04X, ",*(header.frame_offset + i));
        if(i%8 == 0) printf("\r\n");
    }

    printf("\r\n");

    fclose(fin);
    free(header.frame_offset);

}

uint16_t swap_endian_16(uint16_t num){
    uint16_t _num = num;
    uint16_t result;
    uint8_t *inptr = &_num;
    uint8_t *outptr = &result;
    for(int i = 0; i < 2; i++){
        *(outptr + i) = *(inptr + (1 - i));
    }
    return result;
}

uint32_t swap_endian_32(uint32_t num){
    uint32_t _num = num;
    uint32_t result;
    uint8_t *inptr = &_num;
    uint8_t *outptr = &result;
    for(int i = 0; i < 4; i++){
        *(outptr + i) = *(inptr + (3 - i));
    }
    return result;
}