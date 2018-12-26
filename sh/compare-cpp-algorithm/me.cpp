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

using namespace std;
const int Max = 6000005;
int dp[Max];  //dp[i]存放的是长度为i的间隔为k的递增序列最后一个元素可能的最小值
vector<int> nums;
int location[Max];  //location[i]存放的是如果把当前的元素插入到最终的递增序列中应该插入的位置

int LIS_k(int k,vector<int>& nums){
    k--;
    int n = (int)nums.size();
    for(int i = 1;i<=n;i++) dp[i] = INT32_MAX;
    dp[0] = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        location[i] = int(lower_bound(dp+1,dp+ans+1,nums[i-1]) - dp) ;
        ans = max(location[i],ans);
        int j = i-k;
        if(j>0 && dp[location[j]] > nums[j-1]) dp[location[j]] = nums[j-1];
    }
    return ans;
}

int main() {
    int n,k;
    while(cin>>n>>k){
        int tmp;
        for(int i = 1;i<=n;i++){
            cin>>tmp;
            nums.push_back(tmp);
        }
        cout<<LIS_k(k,nums)<<endl;
    }
    return 0;
}