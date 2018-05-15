%{
#include<stdio.h>
#include<stdlib.h>
int id=0, key=0, op=0, dig = 0;
%}
%token DIGIT ID KEY OP
%%
input : DIGIT input {dig++;}
| ID input {id ++;}
| KEY input {key ++;}
| OP input {op ++;}
| DIGIT {dig++;}
| ID {id++;}
| KEY {key++;}
| OP {op++;}
;
%%
#include<stdio.h>
extern FILE *yyin;
int main() {
    FILE *myfile = fopen("input.c", "r");
    if(!myfile) {
        printf("Can't open the file\n");
        return 0;
    }
    yyin = myfile;
    do {
        yyparse();
    }while(!feof(yyin));
    printf("Keywords = %d\nIdentifiers = %d\nOperators = %d\nNumbers = %d\n", key, id, op, dig);
}

int yyerror() {
    printf("Error\n");
    exit(0);
}