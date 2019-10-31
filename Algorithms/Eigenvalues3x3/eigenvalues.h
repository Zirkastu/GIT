#ifndef _INVERSE_H_
#define _INVERSE_H_
#include <stdio.h>
#include <stdlib.h>
void MatrMyltiply(double(*)[size], double*, double* , int );
int Gauss(double(*)[size+1],int ,double*);
int ROOTS(double*  ,double*  ,int );
double dfunc (double ,double*  , int );
void CHECK(double(*)[size],double*,double ,int);
#endif
