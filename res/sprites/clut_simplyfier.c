#include <stdio.h>
#include <stdint.h>

#define INDEX 3
#define RED 0
#define GREEN 1
#define BLUE 2

uint16_t old_color[4];
uint8_t new_color[3];

uint32_t first_index;
uint32_t last_index;

FILE *inf;
FILE *outf;

size_t wr_test;

uint8_t i_cant_believe_i_have_to_declare_zero = 0;

uint16_t swap_endian_16(uint16_t num);
uint32_t swap_endian_32(uint32_t num);

int main(int argc, char **argv){

    uint32_t test_32 = 0x11223344;
    uint16_t test_16 = 0x1122;

    test_32 = swap_endian_32(test_32);
    test_16 = swap_endian_16(test_16);

    printf("16: %04X, 32: %08X\r\n",test_16,test_32);

    if(argc != 3){
        printf("You must specify an input file, and an output file. (argc = %d)\r\n", argc);
        return 1;
    }

    inf = fopen(argv[1],"r");
    outf = fopen(argv[2], "w");

    if(outf == NULL) {
        printf("OUTFILE ERROR\r\n");
        return 1;
    }

    if(inf == NULL) {
        printf("INFILE ERROR\r\n");
        return 1;
    }

    wr_test = fread(&first_index, sizeof(uint32_t), 1, inf);
    if(wr_test != 1){
        printf("INREAD ERROR\r\n");
        return 1;
    }
    wr_test = fread(&last_index, sizeof(uint32_t), 1, inf);
    if(wr_test != 1){
        printf("INREAD ERROR\r\n");
        return 1;
    }

    last_index = swap_endian_32(last_index);
    first_index = swap_endian_32(first_index);

    printf("first index %08X, last index %08X\r\n", first_index, last_index);

    printf("first index %d, last index %d\r\n", first_index, last_index);

    for(int i = 0; i < (last_index - first_index); i++){
        fread(old_color + INDEX, sizeof(uint16_t), 1, inf);
        fread(old_color + RED, sizeof(uint16_t), 1, inf);
        fread(old_color + GREEN, sizeof(uint16_t), 1, inf);
        fread(old_color + BLUE, sizeof(uint16_t), 1, inf);

        for(int j = 0; j < 3; j++) old_color[j] = swap_endian_16(old_color[j]);

        printf("in goes %d,%d,%d,%d\r\n", old_color[RED], old_color[GREEN], old_color[BLUE], old_color[INDEX]);

        for(int j = 0; j < 3; j++){
            old_color[j] + swap_endian_16(old_color[j]);
            new_color[j] = old_color[j] / 256;
        }

        printf("out goes %d,%d,%d,%d\r\n", new_color[RED], new_color[GREEN], new_color[BLUE], new_color[INDEX]);

        for(int j = 0; j < 3; j++){

            wr_test = fwrite(&new_color[j], sizeof(uint8_t), 1, outf);
            if(wr_test < 1) {
                printf("OUTWRITE ERROR\r\n");
                return 1;
            }
        }

        wr_test = fwrite( &i_cant_believe_i_have_to_declare_zero, sizeof(uint8_t), 1, outf);
        if(wr_test < 1) {
            printf("OUTWRITE ERROR\r\n");
            return 1;
        }

    }

    fclose(inf);
    fclose(outf);

    return 0;
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