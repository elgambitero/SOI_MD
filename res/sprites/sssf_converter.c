#include <stdio.h>
#include <fileio.h>

typedef struct{
    uint32_t frames;
    uint32_t * frame_offset;
}sssf_header;

sssf_header header;
FILE *fp;

int main(int argc, char **argv){
    if(argc != 2){
        printf("You must specify only a file\r\n");
        return 1;
    }

    fp = fopen(argv[0],"r");

    FILE * cursor = fp;

    fread(&header.frames, sizeof(uint32_), 1, cursor);
    fseek(cursor, 12, SEEK_SET);

}