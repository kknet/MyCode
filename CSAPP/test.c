#include <stdio.h>
int g(){
    static int x = 1;
    x++;
    return x;
}

int b = 7;
int yu = 8;

int main(){
    printf("%d\n",g());
    printf("%d\n",g());
    return 0;
}
