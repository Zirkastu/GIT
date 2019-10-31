#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include "List.h"


int Check(List*, int (*)(Item*,Item*));
void Li_Print(List*);
void Li_Scan(List*,int);
void Li_fScan(List* ,char[10],int );
void FGen(char[10],int);

#endif

