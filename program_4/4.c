#include<stdio.h>
#include<string.h>
void check();
char a[20], act[20], stk[20], ac[20];
int c, k, j, i, z;
int main() {
    printf("Enter input string:\n");
    gets(a);
    c = strlen(a);
    strcpy(act, "SHIFT -> ");
    printf("Stack \t Input \t Action\n");
    for(k=0, i=0; j < c; i ++,k++,j++) {
        if(a[j] == 'i' && a[j+1] == 'd') {
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        }
        else {
            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbols", stk, a, act);
            check();
        }
    }
    printf("\n");
}
void check() {
    strcpy(ac, "REDUCE TO E");
    for(z = 0; z < c; z++) {
        if(stk[z] == 'i' && stk[z+1] == 'd') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            j++;
        }
    }
    for(z = 0; z < c; z++) {
        if(stk[z] == 'E' && stk[z+1] == '+' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i -2;
        }
    }
    for(z = 0; z < c; z++) {
        if(stk[z] == 'E' && stk[z+1] == '*' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i -2;
        }
    }
    for(z = 0; z < c; z++) {
        if(stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i -2;
        }
    }
    
    
}