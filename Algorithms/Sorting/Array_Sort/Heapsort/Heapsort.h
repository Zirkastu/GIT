#ifndef HEAPSORT_H
#define HEAPSORT_H

typedef int ARRTYPE;

void Sift(ARRTYPE*,int,int,int (*cmp)(ARRTYPE,ARRTYPE));
void Heapsort(ARRTYPE*,int,int (*cmp)(ARRTYPE,ARRTYPE));

#endif


