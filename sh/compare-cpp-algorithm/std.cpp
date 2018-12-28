#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 200000;

void work(int n,int a[],int b[],int target)
{
    sort(a,a+n);
    sort(b,b+n);
    int flag=0;
    int tmp;
    for (int i = 0; i < n; ++i) {
        if (a[i]+b[0]>target)
            break;
        if (a[i]==a[i-1])
            continue;
        tmp=target-a[i];
        if (binary_search(b,b+n,tmp))
        {
            printf("%d %d\n",a[i],tmp);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("OTZ\n\n");
        return ;
    }
    printf("\n");
    return ;
}

int a[MAX];
int b[MAX];

void shuru(int a[],int n)
{
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    return ;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    int target;
    while(scanf("%d",&n)!=EOF)
    {
        shuru(a,n);
        shuru(b,n);
        scanf("%d",&target);
        work(n,a,b,target);
    }
    return 0;
}