#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/funcs.h"
#include "lib/pgm.h"

void encoder(char* filename){
    struct Image src, des;
    readPGMImage(&src, filename);
    des.width = src.width;
    des.height = src.height;
    if (!(des.Data = (unsigned char *) malloc(des.width * des.height * sizeof(unsigned char)))){
        printf("Falta de memória.\n");
        exit(1);
    }
    divideByCriterion(&src, &des, 0, src.width, 0, src.height);
    writeBitstream(&des, "bitstream.bin");
    free(des.Data);
}

void decoder(char* filename){
    FILE *file_ptr;
    if(!(file_ptr = fopen(filename, "rb"))){
        printf("Falha ao abrir o arquivo de bitstream.");
        exit(1);
    }
    struct Image img;
    img.maxval = 255;
    fread(&(img.width), sizeof(int), 1, file_ptr);
    fread(&(img.height), sizeof(int), 1, file_ptr);
    if(!(img.Data = (unsigned char *) malloc(img.width * img.height * sizeof(unsigned char)))){
        printf("Falta de memória.\n");
        exit(1);
    }
    int i = 0;
    int count;
    unsigned char key;
    while(i < img.width * img.height){
        fread(&count, sizeof(int), 1, file_ptr);
        fread(&key, sizeof(unsigned char), 1, file_ptr);
        count+=i;
        while(i < count){
            img.Data[i] = key;
            i++;
        }
    }
    writePGMImage(&img, "image.pgm");
    fclose(file_ptr);
}

int criterion(struct Image *img, int low_width, int high_width, int low_height, int high_height){
    int mean = 0;
    int n = (high_height - low_height) * (high_width - low_width);
    if(n == 1)
        return img->Data[low_width + low_height*img->width];
    for(int j = low_width; j < high_width; j++){
        for (int i = low_height; i < high_height; i++){
            mean += img->Data[i + j*img->width];
        }
    }
    mean /= n;
    int var = 0;
    for(int j = low_width; j < high_width; j++){
        for (int i = low_height; i < high_height; i++){
            int dif = img->Data[i + j*img->width] - mean;
            var += dif*dif;
        }
    }
    return sqrt(var/(n - 1)) < 25.5 ? mean : -1;
}

void divideByCriterion(struct Image *src, struct Image *des, int low_width, int high_width, int low_height, int high_height){
    int c = criterion(src, low_width, high_width, low_height, high_height);
    if(c != -1){
        for(int j = low_width; j < high_width; j++){
            for (int i = low_height; i < high_height; i++){
                des->Data[i + j*des->width] = c;
            }
        }
        return;
    }
    int mid_width = (high_width + low_width) / 2;
    int mid_height = (high_height + low_height) / 2;
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
    fwrite(&(img->width), sizeof(int), 1, file_ptr);
    fwrite(&(img->height), sizeof(int), 1, file_ptr);
    while(i < n){
        unsigned char key = img->Data[i];
        int count = 1;
        i++;
        while(i < n && img->Data[i] == key){
            count++;
            i++;
        }
        fwrite(&count, sizeof(int), 1, file_ptr);
        fwrite(&key, sizeof(unsigned char), 1, file_ptr);
    }
    fclose(file_ptr);
}