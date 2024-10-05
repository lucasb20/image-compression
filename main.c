#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/funcs.h"

int main(int argc,char **argv){
    if(argc != 4){
        printf("Formato: %s <num_op alg1 (1) ou alg2 (2)> <image> <directory>\n",*argv);
        exit(1);
    }

    srand(time(0));

    int op = atoi(*(argv+1));
    char *image = *(argv+2);
    char *directory = *(argv+3);

    clock_t begin,end;

    switch(op){
        case 1:
            begin = clock();
            alg1(image,directory);
            end = clock();
            double tempo_total = (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo total: %lfs\n(%lf min)",tempo_total,tempo_total/60);
            break;

        case 2:
            begin = clock();
            alg2(image,directory);
            end = clock();
            double tempo_total = (double)(end - begin)/CLOCKS_PER_SEC;
            printf("Tempo total: %lfs\n(%lf min)",tempo_total,tempo_total/60);
            break;
    }

    return 0;
}