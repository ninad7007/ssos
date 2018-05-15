%{
#include<stdio.h>
#include<string.h>
char iden[10][10], oper[10];
int id=0, op=0, bo=0, bc=0;
%}
%%
[0-9]+ {strcpy(iden[id], yytext);id++;}
[+|\-|*|/] {oper[op] = yytext[0];op++;}
[(] {bo++;}
[)] {bc++;}
%%
void main() {
    printf("Enter the expression:\n");
    yylex();
    if((id == op + 1) && (bo == bc)) {
        printf("Number of identifiers are: %d\n", id);
        printf("Number of operators are: %d\n", op);
        printf("Identifiers: ");
        for(int i = 0; i < id; i ++) {
            printf("%s ", iden[i]);
        }
        printf("\nOperators: ");
        for(int i = 0; i < op; i ++) {
            printf("%c ", oper[i]);
        }
    }
    else {
        printf("Invalid expression");
    }
}