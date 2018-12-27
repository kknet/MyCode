#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>

using namespace std;
const int Max = 1000005;
int dp[Max];
int V;
inline void ZeroOnePack(int value,int volume){
    for(int v = V;v>=volume;v--)
        dp[v] = max(dp[v],dp[v-volume]+value);
}
int nums[Max];
int main() {
    int n,sum = 0;
    while(cin>>n){
        sum = 0;
        for(int i = 1;i<=n;i++){
            cin>>nums[i];
            sum += nums[i];
        }
        V = sum/2;
        for(int i = 0;i<=V;i++) dp[i] = 0;
        for(int i = 1;i<=n;i++){
            ZeroOnePack(nums[i],nums[i]);
        }
        int ans = *max_element(dp+1,dp+V+1);
        if(ans*2 == sum) cout<<"GF&SI"<<endl;
        else cout<<sum - ans - ans<<endl;
    }
    return 0;
}