#include "lib/funcs.h"
#include <math.h>

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

void encoder(char* filename){}
void decoder(char* filename){}