#include "pgm.h"

int criterion(struct Image*, int, int, int, int);
void encoder(char*);
void decoder(char*);
void divideByCriterion(struct Image*, struct Image*, int, int, int, int);
void writeBitstream(struct Image*, char*);