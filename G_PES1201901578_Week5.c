#include "5a.h"
#include<string.h>

static Node* create_Node(int data, Node* link)
{
// TODO - create and allocate dynamic space
    Node* new= (Node*)malloc(sizeof(Node));
    new->data=data;
    new->link=link;
    return new;
}

void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
	print("pull req\n");
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;
}

void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
    Node* new=create_Node(data,ptr_list->head);
    ptr_list->head=new;
    ptr_list->number_of_Nodes ++;

}

const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    return Node_ptr->data;

}

void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
    if (ptr_list->head != NULL)
	{
	    struct Node* del = ptr_list->head;
	    ptr_list->head = del->link;
	    ptr_list->number_of_Nodes --;
        free(del);
	}

}

void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
	for(int i=0;i<ptr_list->number_of_Nodes;i++)
    {
        list_delete_front(ptr_list);
	}
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    ptr_Stack->ptr_list=(List*)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
    if(ptr_Stack->ptr_list->number_of_Nodes!=0){
        return 0;
    }
    else{
        return 1;
    }
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
    return ptr_Stack->ptr_list->head->data;
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
}

int match_parenthesis(const char* string)
{
	printf("yo boii");
    Stack* s=(Stack*) malloc(sizeof(Stack*));
    Stack_initialize(s);
    int l=strlen(string);
    for(int i=0;i<l;i++)
    {
        if(string[i]=='{'||string[i]=='('||string[i]=='[')
            Stack_push(s,(int) string[i]);
        else if(string[i]=='}'||string[i]==')'||string[i]==']')
        {
            if (Stack_is_empty(s))
            {
                Stack_destroy(s);
                return 0;
            }
            else if((int)string[i]==Stack_peek(s)+2)
                Stack_pop(s);
            else if(string[i]==')' && (char) Stack_peek(s)=='(')
                Stack_pop(s);
            else
            {
                Stack_destroy(s);
                return 0;
            }   
        }
    }
    if (Stack_is_empty(s))
    {
        Stack_destroy(s);
        return 1;
    }
}		


 

