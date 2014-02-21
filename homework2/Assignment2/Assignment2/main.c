/*
 * sorted-list.c
 */

#include	<string.h>
#include    <stdio.h>
#include	"sorted-list.h"

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

//Destructor functions
void destroyBasicTypeAlloc(void *p){
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}

void destroyBasicTypeNoAlloc(void *p) {
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}

void printIntList(SortedListPtr list){
    
    SortedListPtr curr = list;
    
    while(curr != NULL){
        
        int* temp = (int*)(curr->data);
        printf("%d\n", *temp);
        curr = curr->next;
        
    }
    printf("\n");
}

int main()
{
    SortedListPtr list = SLCreate(&compareInts, &destroyBasicTypeNoAlloc);
    int i = 2;
    SLInsert(list, (void*) &i);
    printIntList(list);
    
    int j = 1;
    SLInsert(list, (void*) &j);
    printIntList(list);

    int k = 5;
    SLInsert(list, (void*) &k);
    printIntList(list);

    int b = 3;
    SLInsert(list, (void*) &b);
    printIntList(list);

    
    SLRemove(list, (void*) &i);
    printIntList(list);

    SLRemove(list, (void*) &j);
    printIntList(list);

    
    int m = 0;
    SLRemove(list, (void*) &m);
    printIntList(list);

    
    SLInsert(list, (void*) &i);
    SLInsert(list, (void*) &j);
    printIntList(list);

    SLRemove(list, (void*) &k);
    printIntList(list);
    SLInsert(list, (void*) &k);



    SortedListIteratorPtr iter = SLCreateIterator(list);

    SortedListPtr iterP = SLNextItem(iter);
    printIntList(iterP);

    iterP = SLNextItem(iter);
    printIntList(iterP);

    SLRemove(list, (void*) &i);

    iterP = SLNextItem(iter);
    printIntList(iterP);
    
    
    
    SLInsert(list, (void*) &i);
    printIntList(list);
    
    SortedListIteratorPtr iter2 = SLCreateIterator(list);
   
    iterP = SLNextItem(iter2);
    SLRemove(list, (void*) &i);
    SLRemove(list, (void*) &b);
    iterP = SLNextItem(iter2);

    printIntList(iterP);



    
    return 0;

}


