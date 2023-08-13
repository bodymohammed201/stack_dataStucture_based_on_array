#include "stack_dynamic.h"
#include <stdio.h>
#include <stdlib.h>
static uint8 StackIsEmpty (Stack_t* stack_obj);
static uint8 StackIsFull (Stack_t* stack_obj);

static uint8 StackIsFull (Stack_t* stack_obj){

  return (stack_obj->ElementCount ==stack_obj->StackMaxSize);

}
static uint8 StackIsEmpty (Stack_t* stack_obj){

  return(stack_obj->ElementCount ==0);

}

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret_status){
        Stack_t* my_stack = NULL;
       if(NULL==ret_status){
        *ret_status=STACK_NULL_POINTER;
       }
       else{
             my_stack=(Stack_t*)(malloc(sizeof(Stack_t)));
             if(!my_stack){
                *ret_status=STACK_NOK;
                my_stack=NULL;
             }
             else{

                my_stack->StackTop=-1;
                my_stack->ElementCount=0;
                my_stack->StackMaxSize=maxSize;
                my_stack->StackArray=(void**)(calloc(maxSize,sizeof(void*)));
                if(!my_stack->StackArray){
                    free(my_stack);  /* Free the stack object as the Array not created successfully */
                    my_stack = NULL; /* Array not created successfully */
                   *ret_status = STACK_NOK;
                }
                else{
                    *ret_status = STACK_OK;
                }
             }
       }
       return my_stack;
}

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status){

    if((NULL==ret_status)||(NULL==stack_obj)){
        *ret_status=STACK_NULL_POINTER;
       }
       else{
            free(stack_obj->StackArray);
            free(stack_obj);

            *ret_status=STACK_OK;


       }
       return NULL;

}

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr){
    StackStatus_t ret_s_t=STACK_NOK;
 if((NULL==itemPtr)||(NULL==stack_obj)){
        ret_s_t=STACK_NULL_POINTER;
       }
       else{
            if(StackIsFull(stack_obj)){
                ret_s_t = STACK_FULL;
            }
            else{
                (stack_obj->StackTop)++;
                stack_obj->StackArray[stack_obj->StackTop]=itemPtr;
                 (stack_obj->ElementCount)++;
                 ret_s_t=STACK_OK;
            }


       }
       return ret_s_t;
}

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status){
    void *element_poped=NULL;
    if((NULL==ret_status)||(NULL==stack_obj)){
        *ret_status=STACK_NULL_POINTER;
        element_poped=NULL;
       }
       else{
           if(StackIsEmpty(stack_obj)){
            *ret_status=STACK_NOK;
            element_poped=NULL;
           }
           else{
            element_poped= stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
            *ret_status=STACK_OK;
           }
       }
      return element_poped;
}

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status){
 void *element_poped=NULL;
    if((NULL==ret_status)||(NULL==stack_obj)){
        *ret_status=STACK_NULL_POINTER;
        element_poped=NULL;
       }
       else{
           if(StackIsEmpty(stack_obj)){
            *ret_status=STACK_NOK;
            element_poped=NULL;
           }
           else{
            element_poped= stack_obj->StackArray[stack_obj->StackTop];

            *ret_status=STACK_OK;
           }
       }
      return element_poped;
}

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount (Stack_t* stack_obj, uint32 *stack_count){
    StackStatus_t ret_s_t=STACK_NOK;
 if((NULL==stack_count)||(NULL==stack_obj)){
        ret_s_t=STACK_NULL_POINTER;
       }
       else{
           *stack_count = stack_obj->ElementCount;
         ret_s_t=STACK_OK;
       }
       return ret_s_t;
}





