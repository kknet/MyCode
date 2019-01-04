#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int Max_volume=100005;
int dp[Max_volume];
int V;  //背包的最大容量


inline void ZeroOnePack(int value, int volume){
    for(int v=V;v>=volume;v--)
        if(v>=volume)
            dp[v]=dp[v]>dp[v-volume]+value?dp[v]:dp[v-volume]+value;
}

inline void CompletePack(int value, int volume){
    for(int v=volume;v<=V;v++)
            dp[v]=dp[v]>dp[v-volume]+value?dp[v]:dp[v-volume]+value;
}

inline void MultiplePack(int value,int volume, int number){
    if(volume*number>=V){
        CompletePack(value,volume);
        return;
    }
    int k=1;
    while(k<number){
        ZeroOnePack(value*k,volume*k);
        number-=k;
        k<<=1;
    }
    if(number)
        ZeroOnePack(value*number,volume*number);
}