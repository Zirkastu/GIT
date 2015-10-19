#include <assert.h>
#include <stdio.h>
#include "Search_Tree.h"


Tree* ST_Add (Tree* tr,Tree* elem ,int (*cmp)(Tree*,Tree*))
{
    Tree* pos, *old;
    int dir;

    
    assert(elem);       
    if  ( tr == NULL)
        return elem;

    assert ( ST_Search(elem, tr, cmp) == 0 );    
      
    for ( pos = tr; pos!=NULL; )
    {
        old = pos;
        if ( cmp(elem, pos) == -1 )
        {         
            pos = Go_Left(pos);
            dir = 0;
        }
        else
        {
            pos = Go_Right(pos);
            dir = 1;
        }
    }        
   
    if (dir==0)
    {
        Tr_AddLeft(old,elem);        
    }
    else
    {
        Tr_AddRight(old,elem);        
    }   
    return tr;
 }
    
    
Tree* ST_Search(Tree* x, Tree* start, int (*cmp)(Tree*,Tree*) )
{   
    int tmp;
    assert(x);
    
    if ( start == NULL )
        return NULL;

    while ( start != NULL )     
    {
        tmp=cmp(start,x);
        switch ( tmp )
        {
            case 0:
                return start;
            case 1:
                start=Go_Left(start);                
                break;
            case -1:
                start=Go_Right(start);       
        }         
        
    }
    return NULL;
}

int ST_Check(Tree * root, int (*cmp)(Tree*,Tree*) ) 
{    
    Tree* elem=root,*tmp,*next;        
    assert(root);
    assert( Go_Back(root)==NULL ); 
    if ( ( Go_Right(root)==NULL ) && ( Go_Left(root)==NULL ) )
    {
        return 0;
    }   
    while ( Go_Left(elem)!=NULL )
    {
       elem=Go_Left(elem);
    }
    next=elem;
    while ( 1 )
    {                                       
        if ( Go_Right(next)!=NULL )
        {                   
            next=Go_Right(next);
            while (Go_Left(next) !=NULL )
            {
                next=Go_Left(next);
            }                                                                                              
        }
        else
        {
            tmp=next;
            next=Go_Back(next);
            if ( next==NULL )
            {
                return 0;
            }
            while ( Go_Right(next)==tmp )
            {
                tmp=next;
                next=Go_Back(next);
                if ( next==NULL )
                {                                               
                    return 0;
                }                                      
            }                                   
            
        }                                                                               
      
                            
        printf("CMP: %p %p\n", (void*) elem, (void*)next);
        if ( cmp(elem,next)!=-1 )
        {
            return 1;             
        }
        elem=next;
    }
    return 0;     
}


Tree* ST_Cut( Tree* elem ,Tree* root)
{
    Tree *max,*tmp1,*tmp2;    
    assert(elem);
    assert(root);
    assert( Go_Back(root)==NULL ); 
    if ( ( Go_Left(elem)==NULL ) && ( Go_Right(elem)==NULL ) )
    {
        if ( elem==root )
        {            
            return NULL;    
        }        
        Tr_Cut(elem);
        return root;          
    }
    if ( ( Go_Left(elem)==NULL ) && ( Go_Right(elem)!=NULL ) )
    {        
        if ( root==elem )
        {
            root=Tr_CutRight(elem);
            return root;        
        }
        tmp1=Go_Back( elem );        
        if ( Go_Right(tmp1)==elem )
        {
            elem=Tr_CutRight(tmp1);
            tmp2=Tr_CutRight(elem);
            Tr_AddRight(tmp1,tmp2);
            return root;
        }
        else
        {
            elem=Tr_CutLeft(tmp1);
            tmp2=Tr_CutRight(elem);
            Tr_AddLeft(tmp1,tmp2);
            return root;
        }        
     }
     if ( ( Go_Left(elem)!=NULL ) && ( Go_Right(elem)==NULL ) )
     {        
         if ( root==elem )
         {
             root=Tr_CutLeft(elem);
             return root;        
         }  
         tmp1=Go_Back( elem );      
         if ( Go_Right(tmp1)==elem )
         {
             elem=Tr_CutRight(tmp1);
             tmp2=Tr_CutLeft(elem);
             Tr_AddRight(tmp1,tmp2);
             return root;
         }
         else
         {
             elem=Tr_CutLeft(tmp1);
             tmp2=Tr_CutLeft(elem);
             Tr_AddLeft(tmp1,tmp2);
             return root;
         }       
     }
     max=Go_Left(elem);     
     while ( Go_Right(max)!=NULL )
     {
         max=Go_Right(max);
     }
     tmp1=Go_Back(max);    
     if ( Go_Right(tmp1)==max )
     {
         if ( Go_Left(max)!=NULL )
         {
             tmp2=Tr_CutLeft(max);
             Tr_Cut(max);
             Tr_AddRight(tmp1,tmp2);
         }
         else
         {
             Tr_Cut(max);
         }
     }
     else
     {
         if ( Go_Left(max)!=NULL )
         {
             tmp2=Tr_CutLeft(max);
             Tr_Cut(max);
             Tr_AddLeft(tmp1,tmp2);
         }
         else
         {
             Tr_Cut(max);
         }
     }
     if ( Go_Left(elem) == NULL )
     {
         tmp2=Tr_CutRight (elem);
         Tr_AddRight(max,tmp2);
     }
     else
     {
         tmp1=Tr_CutLeft (elem);
         tmp2=Tr_CutRight (elem);
         Tr_AddLeft(max,tmp1);
         Tr_AddRight(max,tmp2);
     }
     if (elem==root)
     {         
         return max;
     }
     tmp1=Go_Back(elem);
     if ( Go_Left(tmp1)==elem )
     {         
         Tr_Cut(elem);
         Tr_AddLeft(tmp1,max);
     }
     else
     {
         Tr_Cut(elem);
         Tr_AddRight(tmp1,max);
     }
     return root;  
}    
 


