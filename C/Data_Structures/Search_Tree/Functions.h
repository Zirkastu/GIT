#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include "Search_Tree.h"



void Tr_Scan(Tree*,int,int (*cmp)(Tree*,Tree*));
void Tr_fScan(Tree* ,char[10],int ,int (*)(Tree*,Tree*));
void FGen(char[10],int);

#endif

