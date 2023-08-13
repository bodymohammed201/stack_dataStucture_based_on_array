#ifndef STACK_DS_T_H_INCLUDED
#define STACK_DS_T_H_INCLUDED
#include "std.h"
#define MAX_SIZE 5



 typedef struct my_stack{
 uint32_t stack_pointer;
 uint32_t stack_arr[MAX_SIZE];

 }my_stack_t;

   typedef enum stack_status{
    FULL,
    EMPTY,
    NOT_FULL
   } stack_status_t;


 /**
   * @brief        this function initialize the stack pointer
   * @param        mystack1 is a pointer to stack
   * @retval       return_status_t  status of the initialization process
   */
 return_status_t stack_init(my_stack_t *mystack1);
 return_status_t stack_push(my_stack_t *mystack1,uint32_t value);

#endif // STACK_DS_T_H_INCLUDED
