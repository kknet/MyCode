#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <queue>
#include <functional>

using namespace std;
const int maxx = 1e6+5;
int Left[maxx],Right[maxx];
int thinking[maxx];
int main()
{
     int n,x;
    while(~scanf("%d",&n))
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&thinking[i]);
        }
        for(int i = 0;i<n;i++)
        {
            Left[i]=1;Right[i]=1;
        }

        for(int i= 1;i<n;i++)
        {
            if(thinking[i]>thinking[i-1])
                Left[i]=Left[i-1]+1;
        }
        for(int i = n-2;i>=0;i--)
        {
            if(thinking[i]>thinking[i+1])
                Right[i]=Right[i+1]+1;
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            cout<<max(Left[i],Right[i])<<" ";
            res += max(Left[i],Right[i]);
        }
        cout<<endl;
        printf("%d\n",res);
    }

}