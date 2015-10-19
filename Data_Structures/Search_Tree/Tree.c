#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "Tree.h"

Tree* Tr_Create(TREE_TYPE value)
{
    Tree* tmp;
   
    tmp=(Tree*)malloc(sizeof(Tree));
   // printf("ALLOC: %p\n", (void*) tmp);
    tmp->prev=NULL;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->value=value;

    return tmp;
}
void Tr_Delete(Tree* tr)
{
    assert(tr);
    assert(tr->left==NULL);
    assert(tr->right==NULL);
    assert(tr->prev==NULL);
  //  printf("FREE: %p\n", (void*) tr);    
    free(tr);
}
void Tr_AddLeft(Tree* tr,Tree* elem)
{
    assert(tr);
    assert(elem);
    assert(tr->left==NULL);
    assert(elem->prev==NULL);
    elem->prev=tr;
    tr->left=elem;
}
void Tr_AddRight(Tree* tr,Tree* elem)
{
    assert(tr);
    assert(elem);
    assert(tr->right==NULL);
    assert(elem->prev==NULL);
    elem->prev=tr;
    tr->right=elem;
}
Tree* Go_Back(Tree* tr)
{
    assert(tr);
    return tr->prev;
}
Tree* Go_Right(Tree* tr)
{
    assert(tr);
    return (tr->right);
}
Tree* Go_Left(Tree* tr)
{
    assert(tr);
    return(tr->left);
}
Tree* Tr_CutLeft(Tree* tr)
{ 
    Tree* tmp;
   
    assert(tr);
    assert(tr->left);   
    tmp=tr->left;    
    tmp->prev=NULL;
    tr->left=NULL;
  
    return tmp;
}
Tree* Tr_CutRight(Tree* tr)
{ 
    Tree* tmp;
   
    assert(tr);
    assert(tr->right);    
    tmp=tr->right;    
    tmp->prev=NULL;
    tr->right=NULL;
    
    return tmp;
}
void Tr_Cut(Tree* tr)
{    
    assert(tr);  

    if (tr->prev==NULL)
    {
        return;
    }
    if (tr->prev->left==tr)
    {
        tr->prev->left=NULL;
    }
    else
    {
        tr->prev->right=NULL;
    }
    tr->prev=NULL;   
}

