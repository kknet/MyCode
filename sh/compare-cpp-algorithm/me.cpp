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
const int Max = 10000005;
struct data{
public:
    int value;
    int number;
    bool operator < (const data & b) const {
        return value<b.value;
    }
};
struct data nums[Max];
bool used[Max];
int a[Max];
int f[Max];
int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    while(cin>>n){
        for(int i = 1;i<=n;i++) {
            scanf("%d",&nums[i].value);
            nums[i].number = i;
            f[i] = nums[i].value;
        }
        sort(nums+1,nums+1+n);
        memset(used,false,sizeof(used));
        long long ans = 0;
        for(int i = 1;i<=n;i++){
            int t = nums[i].number;
            if(t>1 && f[t]>f[t-1]){
                if(t<n && f[t]>f[t+1])
                    a[t] = max(a[t-1],a[t+1]) + 1;
                else
                    a[t] = a[t-1] + 1;
            } else if (t<n && f[t]>f[t+1])
                a[t] = a[t+1] + 1;
            else
                a[t] = 1;
            ans += a[t];
            used[t] = true;
        }
        //for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}