#include <stdio.h>
#include "stack.h"
#include <string.h>

void reverse_string (char *string){
    stack s = stack_new();
    for (int i = 0; i < strlen(string); i++)
    {
        stack_push(s, string[i]);
    }
    int i = 0;
    while (!stack_is_empty(s)){
        char c;
        stack_pop(s, &c);
        string[i]= c;
        i++;
    }
    
}

int main() {
    stack s = stack_new();
    char answer[100];

    printf("\nInserisci a frase: ");
    scanf("%[^\n]s", answer);
    reverse_string(answer);
    printf("%s\n", answer);
    return 0;
}