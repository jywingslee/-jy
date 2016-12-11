#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node * next;
    int data;
}_node;


_node* creatNode(int data){

    _node* node = (_node *)malloc(sizeof(_node));
    node->data = data;
    
    return node;
}
int push(_node** head, _node* node){
    if(*head == NULL){
        *head = node;
        return 1;
    }
    _node* current = *head;
    while(current)
    {
        if(current->next == NULL){
            current->next = node;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int pop(_node** head){
    _node* current = *head;
    if(current==NULL) return 1;
    
    while(current){
        if(current->next == NULL){
            free(current->next);
            current->next = NULL;
            return 1;
        }
    }
    return 0;
}


int main(int argc, const char * argv[]) {

    _node* head = NULL;
    head = createNode(1);
    
    push(&head, createNode(2));
    push(&head, createNode(3));
    
    return 0;
}
