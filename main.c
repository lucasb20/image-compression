#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/funcs.h"

int main(int argc,char **argv){
    if(argc != 4){
        printf("Operações disponíveis:\n");
        printf("%s 1 <image>\n", *argv);
        printf("%s 2 <bitstream>\n", *argv);
        printf("Obs:\n1 - Encoder\n2 - Decoder\n");
        exit(1);
    }

    srand(time(0));

    int op = atoi(*(argv+1));
    char *image = *(argv+2);

    double tempo_total;
    clock_t begin,end;

    switch(op){
        case 1:
            begin = clock();
            encoder(image);
            end = clock();
            tempo_total = (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo total: %lfs\n(%lf min)\n",tempo_total,tempo_total/60);
            break;

        case 2:
            begin = clock();
            decoder(image);
            end = clock();
            tempo_total = (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo total: %lfs\n(%lf min)\n",tempo_total,tempo_total/60);
            break;
    }

    return 0;
}