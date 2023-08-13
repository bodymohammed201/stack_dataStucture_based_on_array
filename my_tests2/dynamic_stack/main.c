#include <stdio.h>
#include <stdlib.h>
#include "stack_dynamic.h"
#define SIZE 5
void *poped_value = NULL;
void *top_value = NULL;
Stack_t* my_stack=NULL;
StackStatus_t  my_status=STACK_NOK;
uint32 var1 = 35 , stack_counter = 0;
char var2 = 'a';
float var3= 23.5;
int main()
{
    my_stack = CreateStack(3,&my_status);
    if(my_stack!=NULL){
        printf("stack has been created\n");
    }
    else
         printf("stack has not  been created\n");



    my_status=  PushStack(my_stack ,&var1); printf("stack status %d \n",my_status);
    my_status=  PushStack(my_stack ,&var2); printf("stack status %d \n",my_status);
    my_status=  PushStack(my_stack ,&var3); printf("stack status %d \n",my_status);
    my_status=  PushStack(my_stack ,&var3); printf("stack status %d \n",my_status);
    my_status = StackCount(my_stack,&stack_counter) ;printf("stack status %d \n",my_status);
       printf("StackCount %d \n",stack_counter);
       poped_value = PopStack(my_stack,&my_status); printf("stack status %d \n",my_status);
       printf("value has peen poped is : %f \n",*((float*)poped_value));
       my_status = StackCount(my_stack,&stack_counter) ;printf("stack status %d \n",my_status);
       printf("StackCount %d \n",stack_counter);
        top_value = StackTop(my_stack,&my_status);printf("stack status %d \n",my_status);
        printf("value at top = %c \n",*((char*)top_value));
        poped_value = PopStack(my_stack,&my_status); printf("stack status %d \n",my_status);
       printf("value has peen poped is : %c \n",*((char*)poped_value));
       poped_value = PopStack(my_stack,&my_status); printf("stack status %d \n",my_status);
       printf("value has peen poped is : %d \n",*((uint32*)poped_value));
       poped_value = PopStack(my_stack,&my_status); printf("stack status %d \n",my_status);
       top_value = StackTop(my_stack,&my_status);printf("stack status %d \n",my_status);
         my_status = StackCount(my_stack,&stack_counter) ;printf("stack status %d \n",my_status);
       printf("StackCount %d \n",stack_counter);


     my_stack = DestroyStack(my_stack,&my_status);
     if(!my_stack) {
        printf("stack has been destroyed\n");
     }
     printf("status is %d\n",my_status);

    return 0;
}
