#pragma once
?ifndef _DIR
#define _DIR

typedef struct Path {
    char* name;         /* Name of directory */
    int           refCount;     /* Number of paths with this directory */
    int       hits;         /* the number of times a file in this
                 * directory has been found */
    Hash_Table    files;        /* Hash table of files in directory */
} Path; */

void Dir_Init(void);
void Dir_InitDot(void);
void Dir_End(void);
Boolean Dir_HasWildcards(char*);
void Dir_Expand(char*, Lst, Lst);
char* Dir_FindFile(char*, Lst);
int Dir_MTime(GNode*);
void Dir_AddDir(Lst, char*);
char* Dir_MakeFlags(char*, Lst);
void Dir_ClearPath(Lst);
void Dir_Concat(Lst, Lst);
void Dir_PrintDirectories(void);
void Dir_PrintPath(Lst);
void Dir_Destroy(void*);
void* Dir_CopyDir(void*);

#endif /* _DIR */