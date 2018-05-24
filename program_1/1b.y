%{
#include<stdio.h>
#include<stdlib.h>
int result;
//<STACKOVERFLOW>
int yylex();
//</STACKOVERFLOW>
%}
%token N
%left '+' '-'
%left '*' '/'
%%
S : E {result = $1;}
E : E '+' E {$$ = $1 + $3;}
| E '*' E {$$ = $1 * $3;}
| E '-' E {$$ = $1 - $3;}
| E '/' E {if($3 == 0) {
printf("Division by 0 not possible\n");
exit(0);
}
else 
$$ = $1 / $3;}
| '(' E ')' {$$ = $2;}
| N {$$ = $1;}
%%
#include<stdio.h>
int main() {
    printf("Enter the expression\n");
    yyparse();
    printf("Valid String\n");
    printf("The result is %d\n", result);
}
int yyerror() {
    printf("Error Detected\n");
    exit(0);
}