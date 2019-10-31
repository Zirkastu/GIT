#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "Tree.h"


Tree* ST_Add(Tree*,Tree* ,int (*)(Tree*,Tree*));
Tree* ST_Search(Tree*,Tree*,int (*)(Tree*,Tree*));
Tree* ST_Cut( Tree*,Tree* );
int ST_Check( Tree*,int (*)(Tree*,Tree*) );


#endif

