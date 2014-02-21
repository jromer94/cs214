/*
 * sorted-list.c
 */

#include <stdlib.h>
#include <stddef.h>
#include "sorted-list.h"

/*
 * SLCreate creates a new, empty sorted list.  The caller must provide
 * a comparator function that can be used to order objects that will be
 * kept in the list, and a destruct function that gets rid of the objects
 * once they are no longer in the list or referred to in an iterator.
 *
 * If the function succeeds, it returns a (non-NULL) SortedListT object,
 * otherwise, it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
    if ((cf == NULL) || (df == NULL)) {
        return NULL;
    }
    else{
    SortedListPtr head;
    head = malloc(sizeof(struct SortedList));
    head->reference = 1;
    head->CompareFuncT = cf;
    head->DestructFuncT = df;
    head->inList = 1;
    
    return head;
    }
}

/*
 * SLDestroy destroys a list, freeing all dynamically allocated memory.
 *
 * You need to fill in this function as part of your implementation.
 */
void SLDestroy(SortedListPtr list){
    SortedListPtr temp = list;
    if (temp->next != NULL){
        temp = list->next;
        temp->DestructFuncT(list->data);
        free(list);
        SLDestroy(temp);
    }
    else {
        temp->DestructFuncT(list->data);
        free(list);
    }
}


/*
 * SLInsert inserts a given object into a sorted list, maintaining sorted
 * order of all objects in the list.  If the new object is equal to a subset
 * of existing objects in the list, then the subset can be kept in any
 * order.
 *
 * If the function succeeds, it returns 1, othrewise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLInsert(SortedListPtr list, void *newObj){
    if ((list == NULL) || (newObj == NULL))
        return 0;
    
    if (list->data == NULL){
        list->data = newObj;
        }
    
    else{
        int i = list->CompareFuncT(list->data, newObj);
        if (i < 0) {
            SortedListPtr new = SLCreate(list->CompareFuncT, list->DestructFuncT);
            new->reference = 1;
            new->data = newObj;
            new->next = list;
            new->inList = 1;
            list = new;
        }
        
        else if(i == 0){
            SortedListPtr new = SLCreate(list->CompareFuncT, list->DestructFuncT);
            new->reference = 1;
            new->data = newObj;
            new->next = list->next;
            new->inList = 1;
            list->next = new;
        }
        
        else{
            if (list->next == NULL){
                SortedListPtr new = SLCreate(list->CompareFuncT, list->DestructFuncT);
                new->reference = 1;
                new->data = newObj;
                new->next = list->next;
                new->inList = 1;
                list->next = new;
            }
            int j = list->CompareFuncT(list->next->data, newObj);
            if (j <= 0){
                SortedListPtr new = SLCreate(list->CompareFuncT, list->DestructFuncT);
                new->reference = 1;
                new->data = newObj;
                new->next = list->next;
                new->inList = 1;
                list->next = new;
            }
            
            return SLInsert(list->next, newObj);
        }
    }
    return 1;
}


/*
 * SLRemove removes a given object from a sorted list.  Sorted ordering
 * should be maintained.  SLRemove may not change the object whose
 * pointer is passed as the second argument.  This allows you to pass
 * a pointer to a temp object equal to the object in the sorted list you
 * want to remove.
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLRemove(SortedListPtr list, void *newObj){
    if ((list == NULL) || (newObj == NULL))
        return 0;
    
    int i = list->CompareFuncT(list->data, newObj);
    if (i == 0) {
        list->reference--;
        list->inList = 0;
        if (list->reference == 0){
            list->DestructFuncT(list->data);
            }
        list = list->next;
        return 1;
    }
    
    else if ( list->next == NULL)
        return 0;
    
    else{
        int j = list->CompareFuncT(list->next->data, newObj);
        if (j == 0){
            list->next->reference --;
            list->inList = 0;
            if (list->next->reference == 0){
                list->DestructFuncT(list->next->data);
                }
            list->next = list->next->next;
            return 1;
        }

        return SLRemove(list->next, newObj);
    }
    
    
    return 1;
}


/*
 * SLCreateIterator creates an iterator object that will allow the caller
 * to "walk" through the list from beginning to the end using SLNextItem.
 *
 * If the function succeeds, it returns a non-NULL pointer to a
 * SortedListIterT object, otherwise it returns NULL.  The SortedListT
 * object should point to the first item in the sorted list, if the sorted
 * list is not empty.  If the sorted list object is empty, then the iterator
 * should have a null pointer.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){

    SortedListIteratorPtr iterator;
    iterator = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator));
    iterator->head = list;
    iterator->head->reference++;
    return iterator;
}

/*
 * SLDestroyIterator destroys an iterator object that was created using
 * SLCreateIterator().  Note that this function should destroy the
 * iterator but should NOT affect the original list used to create
 * the iterator in any way.
 *
 * You need to fill in this function as part of your implementation.
 */

void SLDestroyIterator(SortedListIteratorPtr iter){

    if(iter->head != NULL){

        iter->head->reference--;

    }
    free(iter);

}


/*
 * SLNextItem returns the next object in the list encapsulated by the
 * given iterator.  It should return a NULL when the end of the list
 * has been reached.
 *
 * One complication you MUST consider/address is what happens if a
 * sorted list encapsulated within an iterator is modified while that
 * iterator is active.  For example, what if an iterator is "pointing"
 * to some object in the list as the next one to be returned but that
 * object is removed from the list using SLRemove() before SLNextItem()
 * is called.
 *
 * You need to fill in this function as part of your implementation.
 */

void *SLNextItem(SortedListIteratorPtr iter){

    SortedListPtr curr;

    while(inter->head != NULL && iter->head->inList != 1 ){

	curr = iter->head;
        iter->head = iter->head->next;
        probably not needed
        if(iter->head != NULL)
	    iter->head->reference++;

        if(curr != NULL){

            curr->reference--;
            if(curr->reference == 0){

                //code for free goes here

            }

        }
    }

    curr = iter->head;


    if(iter->head != NULL)
        iter->head->reference--;
        iter->head = iter->head->next; 
    if(iter->head != NULL)
        iter->head-reference++;

    return curr;
    }
