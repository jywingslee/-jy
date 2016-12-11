#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node *next;
} node_t;

node_t *head = NULL, *tail = NULL;

void insert_node(int n)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    
    new_node->key = n;
    new_node->next = NULL;
    
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int delete_node()
{
    node_t *node;
    
    int r;
    
    if(head == NULL)
        return -1;
    
    node = head;
    head = head->next;
    
    if(head == NULL)
        tail = NULL;
    
    r = node->key;
    
    free(node);
    
    return r;
}

void print_all_List_v1()
{
    node_t* current = head;
    
    while(current != NULL)
    {
        printf("%d ", (*current).key);
        
        current = current->next;
    }
}

void print_all_List_v2_order_1(node_t* current)
{
    if(current == NULL)return;
    
    printf("%d ", current->key);
    print_all_List_v2_order_1(current->next);
}

void print_all_List_v2_order_2(node_t* current)
{
    if(current == NULL)return;
    
    printf("%d ", current->key);
    print_all_List_v2_order_2(current->next);
}

int main(int argc, const char * argv[]) {
 
    int number, r;
    int i = 0;
    
    while(++i<1000000000){
        //printf("input number: ");
        //scanf("%d", &number);
        number = 1;
        if(number > 0){
            insert_node(number);
        }
        else if(number == 0){
            r = delete_node();
            printf("[%d]\n", r);
        }
    }
    //while(number >= 0);
    
    //print_all_List_v1(head);
    //print_all_List_v2_order_1(head);
    
    
    return 0;
}
