#include <stdio.h>
#include "stack.h"
#include <string.h>

int solve(char *expr, int *result){
    stack s = stack_new();
    int op1, op2;
    for (int i = 0; i < strlen(expr); i++){
        char c = expr[i];
        if (c >= '0' && '0'){
            stack_push(s, c - '0');
        }else {
            if (c == '+'){
                if (stack_pop(s, &op1) != 0)
                    return -1;
                if (stack_pop(s, &op2) != 0)
                    return -1;
                stack_push(s, (op1+op2));
            }else if (c == '-'){
                if (stack_pop(s, &op1) != 0)
                    return -1;
                if (stack_pop(s, &op2) != 0)
                    return -1;
                stack_push(s, (op1-op2));
            }else if (c == '*'){
                if (stack_pop(s, &op1) != 0)
                    return -1;
                if (stack_pop(s, &op2) != 0)
                    return -1;
                stack_push(s, (op1*op2));
            }else if (c == '/'){
                if (stack_pop(s, &op1) != 0)
                    return -1;
                if (stack_pop(s, &op2) != 0)
                    return -1;
                stack_push(s, (op1/op2));
            }else{
                return -1;
            }
        }
    }
    if (stack_pop(s, result) != 0)
        return -1;
    if (!stack_is_empty(s))
        return -1;
    else 
        return 0;
    
}
//? ('1', '4', '+', '5', '*', '6', '/')


int main() {
    /* stack s = stack_new();
    int answer;
    do
    {
        printf("\nInserisci un elemento della pila o 999 per uscire: ");
        scanf("%d", &answer);
        if (answer != 999) {
            stack_push(s, answer);
        }
    } while (answer != 999);

    printf("Size: %d\n", stack_size(s));

    while(!stack_is_empty(s)){
        int result;
        stack_pop(s, &result);
        printf("%d\n", result);
    }

    stack_destroy(s);
    */
    char answer[100];
    printf("\nInserisci a frase: ");
    scanf("%s", answer);
    int result;
    int  code = solve(answer, &result);
    printf("%d, %d\n",code,  result);

    return 0;
}