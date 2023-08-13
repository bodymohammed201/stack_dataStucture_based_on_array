#include <stdio.h>
#include <stdlib.h>
#include "stack_ds_t.h"
#include "stack_ds_t.c"

my_stack_t my_stack1;
my_stack_t my_stack2;
uint32_t top = 0;
uint32_t stack_size_element = 0;
int main()
{
    return_status_t ret = R_NOK;
    ret = stack_init(&my_stack1);
    if(ret == R_NOK){
        printf("stack1 failed to be initialization\n");
    }
    else{
        ret = stack_push(&my_stack1,11);
        ret = stack_push(&my_stack1,22);
        ret = stack_push(&my_stack1,33);
        ret = stack_push(&my_stack1,44);
        ret = stack_push(&my_stack1,55);
        ret = stack_push(&my_stack1,66);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret = stack_push(&my_stack1,66);
        ret = stack_push(&my_stack1,33);
        ret = stack_push(&my_stack1,44);
        ret = stack_push(&my_stack1,55);
        ret = stack_push(&my_stack1,11);
        ret = stack_push(&my_stack1,22);


        ret =  stack_top(&my_stack1,&top);
                if(ret == R_OK){
                       printf("top = %d\n",top);
                }
        ret = stack_size(&my_stack1,&stack_size_element);
        ret = display_stack(&my_stack1);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret =  stack_pop(&my_stack1,&top);
        ret = display_stack(&my_stack1);
       }


      ret = stack_init(&my_stack2);
     if(ret == R_NOK){
         printf("stack2 failed to be initialization\n");
    }
    else{}

    return 0;

}
