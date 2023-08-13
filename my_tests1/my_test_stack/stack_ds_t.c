#include "stack_ds_t.h"
#include <stdio.h>

/*============================================================================*/
/**
   * @brief        this function initialization if the stack full
   * @param        mystack1 is a pointer to stack
   * @retval       stack_status_t  status of the stack
*/
/*============================================================================*/

 static stack_status_t stack_full(my_stack_t *mystack1){
 if(mystack1->stack_pointer==(MAX_SIZE-1)){
    return FULL;
 }

 else{
    return NOT_FULL;
 }


 }
/*============================================================================*/

/**
   * @brief        this function initialization if the stack empty
   * @param        mystack1 is a pointer to stack
   * @retval       stack_status_t  status of the stack
*/
/*============================================================================*/

 static stack_status_t stack_empty(my_stack_t *mystack1){
 if(mystack1->stack_pointer==(-1)){
    return EMPTY;
 }

 else{
    return NOT_FULL;
 }


 }

/*============================================================================*/

/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/

return_status_t stack_init(my_stack_t *mystack1){
    return_status_t ret  = R_NOK;
if(mystack1 == NULL){
        printf("invalid address\n");
        ret  = R_NOK;
}
else{
    mystack1->stack_pointer =-1;
    ret  = R_OK;
}

return ret;
}

/*============================================================================*/

/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/
return_status_t stack_push(my_stack_t *mystack1,uint32_t value){
    return_status_t ret = R_NOK;
if(mystack1 == NULL ||stack_full(mystack1)==FULL ){
   ret= R_NOK;
   printf("stack is full\n");
}
else{
    mystack1->stack_pointer++;
    mystack1->stack_arr[mystack1->stack_pointer]=value;
    printf("value pushed to stack %d \n",value);
    ret= R_OK;
}
return ret;

}
/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/
return_status_t stack_pop(my_stack_t *mystack1,uint32_t *value){
    return_status_t ret = R_NOK;
if(mystack1 == NULL||value ==NULL ||stack_empty(mystack1)==EMPTY ){
   ret= R_NOK;
   printf("stack is empty\n");
}
else{
    *value = mystack1->stack_arr[mystack1->stack_pointer];
    mystack1->stack_pointer--;
    printf("value poped is %d \n",*value);
    ret= R_OK;
}
return ret;

}
/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/
return_status_t stack_top(my_stack_t *mystack1,uint32_t *value){
return_status_t ret = R_NOK ;
if(mystack1 == NULL||value ==NULL ||stack_empty(mystack1)==EMPTY ){
   ret= R_NOK;
   printf("stack is empty\n");
}
 else {
   *value = mystack1->stack_arr[mystack1->stack_pointer];
     ret = R_OK;
}
return ret;
}
/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/
return_status_t stack_size(my_stack_t *mystack1,uint32_t *stack_size){
return_status_t ret = R_NOK ;
if(mystack1 == NULL||stack_size ==NULL ||stack_empty(mystack1)==EMPTY ){
   ret= R_NOK;
   printf("stack is empty\n");
}
 else {
   *stack_size = mystack1->stack_pointer+1;
   printf("the number of the element in the stack is %d \n",*stack_size);
     ret = R_OK;
}
return ret;
}
/**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
*/
/*============================================================================*/
return_status_t display_stack(my_stack_t *mystack1){
return_status_t ret = R_NOK ;
if(mystack1 == NULL||stack_empty(mystack1)==EMPTY ){
   ret= R_NOK;
   printf("stack is empty\n");
}
 else {
        printf("elements in the stack: ");
  for(int i = mystack1->stack_pointer;i>=0;i--){
   printf("%d \t", mystack1->stack_arr[i]);
  }
 printf("\n");
     ret = R_OK;
}
return ret;
}










