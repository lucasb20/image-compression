#include <math.h>
#include "lib/funcs.h"
#include "lib/pgm.h"

int criterion(struct Image img){
    int mean = 0;
    int n = img.height * img.width;
    for (int i = 0; i < img.height * img.width; i++){
        mean += img.Data[i];
    }
    mean /= img.height * img.width;
    int var = 0;
    for (int i = 0; i < img.height * img.width; i++){
        int dif = img.Data[i] - mean;
        var += dif*dif;
    }
    var /= img.height * img.width - 1;
    return sqrt(var) < 10 ? mean : 0;
}

void encoder(char* filename){
    struct Image src, des;
    readPGMImage(&src, filename);
    des.width = src.width;
    des.height = src.height;
    des.maxval = src.maxval;
    if (!(des.Data = (unsigned char *) calloc(des.width * des.height, sizeof(unsigned char)))){
        printf("Falta de memória.\n");
        exit(1);
    }
    divideByCriterion(&src, &des, 0, src.width, 0, src.height);
    writeBitstream(&des, "bitstream.bin");
    free(des.Data);
}

void decoder(char* filename){}
void divideByCriterion(struct Image *src, struct Image *des, int low_width, int high_width, int low_height, int high_height){};
void writeBitstream(struct Image *img, char* filename){};