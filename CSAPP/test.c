#include <stdio.h>
int g(){
    static int x = 1;
    x++;
    return x;
}

int main(){
    printf("%d\n",g());
    printf("%d\n",g());
    return 0;
}