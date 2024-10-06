#include <stdio.h>
#include <math.h>
#include "lib/funcs.h"
#include "lib/pgm.h"

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

int criterion(struct Image *img, int low_width, int high_width, int low_height, int high_height){
    int mean = 0;
    int n = (high_height - low_height) * (high_width - low_width);
    for(int j = low_width; j < high_width; j++){
        for (int i = low_height; i < high_height; i++){
            mean += img.Data[i + j*img->width];
        }
    }
    mean /= n;
    int var = 0;
    for(int j = low_width; j < high_width; j++){
        for (int i = low_height; i < high_height; i++){
            int dif = img.Data[i + j*img->width] - mean;
            var += dif*dif;
        }
    }
    var /= n - 1;
    return sqrt(var) < 10 ? mean : 0;
}

void divideByCriterion(struct Image *src, struct Image *des, int low_width, int high_width, int low_height, int high_height){
    int c = criterion(src, low_width, high_width, low_height, high_height);
    if(c != 0){
        for(int j = low_width; j < high_width; j++){
            for (int i = low_height; i < high_height; i++){
                des.Data[i + j*des->width] = c;
            }
        }
        return;
    }
    int mid_width = (high_width - low_width) / 2;
    int mid_height = (high_height - low_height) / 2;
    divideByCriterion(src, des, low_width, mid_width, low_height, mid_height);
    divideByCriterion(src, des, mid_width, high_width, low_height, mid_height);
    divideByCriterion(src, des, low_width, mid_width, mid_height, high_height);
    divideByCriterion(src, des, mid_width, high_width, mid_height, high_height);
}

void writeBitstream(struct Image *img, char* filename){
    FILE *file_ptr;
    if(!(file_ptr = fopen(filename, "wb"))){
        printf("Falha ao criar o arquivo de bitstream.");
        exit(1);
    }
    int n = img->width * img->height;
    int i = 0;
    while(i < n){
        unsigned char key = img->Data[i];
        int count = 1;
        i++;
        while(i < n && img->Data[i] == key){
            count++;
            i++;
        }
        fwrite(&count, sizeof(int), 1, fp);
        fwrite(&key, sizeof(unsigned char), 1, fp);
    }
}