#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_BUF 1024

#define PAL_SIZE 256

#define RSRC_OFFSET 0x156

#define PX_BLANK 255

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

typedef struct{
    char head[2];
    uint32_t filesize;
    uint32_t px_offset;
}BMP_header;

typedef struct{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t byte_size;
    uint32_t x_px_meter;
    uint32_t y_px_meter;
    uint32_t colors_used;
    uint32_t colors_important;
}DIB_header;

Sssf_Header header;
SOI_Frame current_frame;
uint32_t palette[PAL_SIZE];
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

    fseek(fin, RSRC_OFFSET, SEEK_SET);

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


    fpalette = fopen(argv[2], "r");
    if(!fpalette) {printf("FAILED TO OPEN PALETTE\r\n"); return 1;}

    fread(palette, sizeof(uint32_t), PAL_SIZE, fpalette);

    for(uint32_t i = 0; i < header.frames; i++){

        printf("============\r\n");

        fseek(fin, *(header.frame_offset + i) + RSRC_OFFSET, SEEK_SET);

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
        uint32_t byte_size = current_frame.width * current_frame.height;

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

        uint8_t * invert;
        invert =
            (uint8_t*) malloc( (current_frame.width * current_frame.height) * sizeof(uint8_t) );
        
        for(int k = 0; k < byte_size; k++){
            *(invert + k) = *(current_frame.pixel + byte_size - 1 - k);
        }

        for(int k = 0; k < byte_size; k++){
            *(current_frame.pixel + k) = *(invert + k);
        }

        free(invert);
        
        sprintf(filename, "%s", argv[3]);
        sprintf(filename + strlen(filename), "%d.bmp", i);

        printf("Opening %s\r\n", filename);

        fout = fopen(filename, "w");
        if(!fout) {printf("FAILED TO CREATE BMP\r\n"); return 1;}

        BMP_header bmp_header;

        bmp_header.head[0] = 'B';
        bmp_header.head[1] = 'M';
        bmp_header.filesize = current_frame.width * current_frame.height +
        0x400 + 0x07A;
        bmp_header.px_offset 
            = bmp_header.filesize - current_frame.width * current_frame.height;

        DIB_header dib_header;

        dib_header.size = 108;
        dib_header.width = current_frame.width;
        dib_header.height = current_frame.height;
        dib_header.planes = 1;
        dib_header.bit_count = 8;
        dib_header.compression = 0;
        dib_header.byte_size = current_frame.width * current_frame.height;
        dib_header.x_px_meter = 0xb13;
        dib_header.y_px_meter = 0xb13;
        dib_header.colors_used = PAL_SIZE;
        dib_header.colors_important = PAL_SIZE;

        printf("Headers ready\r\n");

        fwrite(&(bmp_header.head), sizeof(char), 2, fout);
        fwrite(&(bmp_header.filesize), sizeof(uint32_t), 1, fout);
        for (int k = 0; k < 4; k++) fwrite("\0", sizeof(uint8_t), 1, fout);
        fwrite(&(bmp_header.px_offset), sizeof(uint32_t), 1, fout);

        printf("BMP header done\r\n");

        fwrite(&(dib_header), sizeof(DIB_header), 1, fout);

        printf("DIB header done\r\n");

        for (int k = 0; k < 0x44; k++) fwrite("\0", sizeof(uint8_t), 1, fout);

        printf("padding done \r\n");
        
        fwrite(palette, sizeof(uint32_t), PAL_SIZE - 1, fout);
        for (int k = 0; k < 4; k++) fwrite("\0", sizeof(uint8_t), 1, fout);

        fwrite(current_frame.pixel, sizeof(uint8_t), 
            current_frame.width * current_frame.height, fout);

        fclose(fout);
        free(current_frame.pixel_skip);
        free(current_frame.pixel);

    }

    fclose(fin);
    fclose(fpalette);
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
