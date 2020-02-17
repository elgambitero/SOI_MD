#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_BUF 1024

#define PX_BLANK 0

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
SOI_Frame current_frame;
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
        if( (i + 1) % 8 == 0 ) printf("\r\n");
    }

    printf("\r\n");

    for(uint32_t i = 0; i < header.frames; i++){

        printf("============\r\n");

        fseek(fin, *(header.frame_offset + i), SEEK_SET);

        fread(&(current_frame.width), sizeof(uint16_t), 1, fin);
        current_frame.width = swap_endian_16(current_frame.width);
        fread(&(current_frame.height), sizeof(uint16_t), 1, fin);
        current_frame.height = swap_endian_16(current_frame.height);

        fseek(fin, sizeof(uint32_t), SEEK_CUR);

        fread(&(current_frame.h_length), sizeof(uint32_t), 1, fin);
        current_frame.h_length = swap_endian_32(current_frame.h_length);


        printf("Extracting frame number: %d\r\n", i);

        printf("with width: %d, and height: %d\r\n", 
            current_frame.width, current_frame.height);

        printf("frame header size is %d\r\n", current_frame.h_length);


        current_frame.pixel_skip = 
            (uint8_t*) malloc(sizeof(uint8_t) * (current_frame.h_length - 12));

        for(uint32_t j = 0; j < (current_frame.h_length - 12); j++){
            fread(current_frame.pixel_skip + j, sizeof(uint8_t), 1, fin);
        }

        uint32_t skipsum, count;
        skipsum = 0;
        count = 0;

        for(uint32_t j = 0; j < (current_frame.h_length - 12); j++){
            skipsum += *(current_frame.pixel_skip + j);
            count++;
            if(skipsum == current_frame.width * current_frame.height){
                break;
            }
            if(skipsum > current_frame.width * current_frame.height){
                skipsum = 0;
                break;
            }
        }

        if(skipsum) printf("and it's frame skips get even at %d\r\n", count);
        else{ printf("and it's frame EXCEEDS at %d", count); return 1;}
        printf(", with %d remaining.\r\n", current_frame.h_length - 12 - count );

        current_frame.pixel = 
            (uint8_t*) malloc( (current_frame.width * current_frame.height) * sizeof(uint8_t) );

        int painting = 0;
        int px_count = 0;
        int k = 0;

        for(uint32_t j = 0; j < count; j++){
            px_count = *(current_frame.pixel_skip + j);
            while(px_count){
                if(painting){
                    fread(current_frame.pixel + k, sizeof(uint8_t), 1, fin);
                }else{
                    *(current_frame.pixel + k) = PX_BLANK;
                }
                px_count--;
                k++;
            }
            painting = !painting;
        }

        fpalette = fopen(argv[2], "r");

        sprintf(filename, "%s", argv[3]);
        sprintf(filename + strlen(filename), "%04X.bmp", i);

        printf("Opening %s\r\n", filename);

        free(current_frame.pixel_skip);
        free(current_frame.pixel);

    }

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