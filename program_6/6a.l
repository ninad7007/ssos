%{
#include<stdio.h>yyl
int comment, state;
%}
%%
"/*" {state = 1;}
"*/" {if(state == 1) {
    comment++;
    state = 0;
}}
\n|. {
    if(state == 0) {
        fprintf(yyout, "%s", yytext);
    }
}x
%%
int main() {
    char infile[20], outfile[20];
    printf("Enter the input file name:\n");
    scanf("%s", infile);
    printf("Enter the output file name:\n");
    scanf("%s", outfile);
    yyin = fopen(infile, "r");
    yyout = fopen(outfile, "w");
    yylex();
    printf("Number of comment lines : %d\n", comment);
}
