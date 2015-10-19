#ifndef LIST_H
#define LIST_H


typedef int LIST_TYPE;

typedef struct Item {
    LIST_TYPE value;
    struct Item *next;
    struct Item *prev;
} Item;

typedef struct List
{   
    Item base;
    Item *pos;
}List;

List * Li_Create(void);
void Li_Destroy(List*);
void Li_InsBefore(List*,Item*);
void Li_InsAfter(List*,Item*);
void Li_StepForward(List*);
void Li_StepBackward(List*);
void Li_DelBefore(List*);
void Li_DelAfter(List*);
void It_Delete(Item*);
void Li_DivideBefore(List*,List*);
void Li_ToBegin(List*);
Item* It_Create(LIST_TYPE);
Item* Li_TakeBefore(List*);
Item* Li_TakeAfter(List*);
Item* Li_CutBefore(List*);
Item* Li_CutAfter(List*);
int Li_AtEnd(List*);

#endif



