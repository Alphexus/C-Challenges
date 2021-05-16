#include <stdlib.h>
#include <stdio.h> 
#include "linked_list.h"
// stdio.h for NULL

// O(1)
void linked_list_init(linked_list* list) { 
    list = (linked_list*) malloc(sizeof(linked_list));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
}

// O(n)
void linked_list_copy(linked_list* dest, const linked_list* src) {
    node *srcNode = src->first; 
    while (srcNode != NULL) {
        linked_list_push_back(dest, srcNode->value);
        srcNode = srcNode->next;
    }
}

// O(|n-newSize|)
void linked_list_resize(linked_list* list, size_t newSize, value_t value) { 
    size_t listSize = list->size;
    node *currentNode = list->last;
    
    for (int index = 0; index <= abs(listSize-newSize); index++) {
        if ((listSize-newSize) < 0) {
            free(currentNode);
        } else { 
            linked_list_push_front(list, value);
        }
        currentNode = currentNode->prev;
    }
}

// O(1)
void linked_list_push_front(linked_list* list, value_t value) { 
    node *front = list->first;
    node *newFront = (node*) malloc(sizeof(node));
    
    if (newFront == NULL) { 
        return;
    }

    newFront->prev = NULL;
    newFront->next = front;
    newFront->value = value;
    
    front->prev = newFront;

    list->first = newFront;
    list->size++;
}

// O(1)
void linked_list_push_back(linked_list* list, value_t value) {
    node *back = list->last;
    node *newBack = (node*) malloc(sizeof(node));
    
    if (newBack == NULL) { 
        return;
    }

    newBack->prev = back;
    newBack->next = NULL;
    newBack->value = value;
    
    back->next = newBack;

    list->last = newBack;
    list->size++;
}

// O(1)
value_t linked_list_pop_front(linked_list* list) {
    value_t value = list->first->value;
    node *newFront = list->first->next;
    free(list->first);
    list->first = newFront;

    return value;
}

// O(1)
value_t linked_list_pop_back(linked_list* list) { 
    value_t value = list->last->value;
    node *newBack = list->last->prev;
    free(list->last);
    list->last = newBack;

    return value;
}

// O(1)
value_t linked_list_front(linked_list* list) {
    return list->first->value;
}

// O(1)
value_t linked_list_back(linked_list* list) {
    return list->last->value;
}

// O(1)
size_t linked_list_size(const linked_list* list) {
    return list->size;
}

// O(idx)
value_t linked_list_get(const linked_list* list, size_t idx) { 
    node *currentNode = list->first;
    size_t index = 0;
    while (currentNode != NULL) {
        if (index == idx) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
        index++;
    }
}

// O(idx)
value_t linked_list_set(linked_list* list, size_t idx, value_t newValue) {
    node *currentNode = list->first;
    size_t index = 0;
    while (currentNode != NULL) {
        if (index == idx) {
            value_t oldValue = currentNode->value;
            currentNode->value = newValue;
            return oldValue;
        }
        currentNode = currentNode->next;
        index++;
    }
}