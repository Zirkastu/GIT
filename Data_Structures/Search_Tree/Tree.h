#ifndef TREE_H
#define TREE_H




typedef int TREE_TYPE;

typedef struct Tree {
    TREE_TYPE value;    
    struct Tree *prev;
    struct Tree *left;
    struct Tree *right;    
} Tree;

void Tr_Delete(Tree*);
Tree* Tr_Create(TREE_TYPE);
void Tr_AddLeft(Tree*,Tree*);
void Tr_AddRight(Tree*,Tree*);
Tree* Tr_CutRight(Tree*);
Tree* Tr_CutLeft(Tree*);
Tree* Go_Left(Tree*);
Tree* Go_Right(Tree*);
Tree* Go_Back(Tree*);
void Tr_Cut(Tree*);



#endif



