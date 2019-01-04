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
#include <stack>
#include <climits>

using namespace std;


long long count(string s){
    int n = (int)s.length();
    vector<long long> dp(n+5,0);
    if(n>0) dp[n] = 1;
    if(s[n-1]!='0') dp[n-1] = 1;
    for(int i = n-2;i>=0;i--){
        if(s[i] == '0') continue;
        else {
            int tmp = (s[i]-'0')*10+s[i+1]-'0';
            if(tmp>=10 && tmp<=26) dp[i] = dp[i+1]+dp[i+2];
            else dp[i] = dp[i+1];
        }
    }
    return dp[0];
}
int main() {
    string s;
    while(cin>>s){
        if(s=="0") return 0;
        long long ans = 1;
        int len = (int)s.length();
        int left = 0;
        for(int i = 0;i<len;i++){
            if(s[i] == '#'){
                if(i>left){
                    ans *= count(s.substr(left,i-left));
                    left = i+1;
                }
                else left = i+1;
            }
        }
        if(len>left)
        ans *= count(s.substr(left,len-left));
        cout<<ans<<endl;
    }
    return 0;
}