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

using namespace std;
const int Max = 50005;

int main() {
    long long n,t;
    while(cin>>n){
        vector<long long> a,b;
        a.clear();b.clear();
        long long tmp;
        for(int i = 1;i<=n;i++){
            cin>>tmp;
            a.push_back(tmp);
        }
        for(int i = 1;i<=n;i++){
            cin>>tmp;
            b.push_back(tmp);
        }
        cin>>t;
        a.erase(unique(a.begin(),a.end()),a.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int len1 = (int)a.size();
        int len2 = (int)b.size();
        int i = 0;
        int j = len2-1;
        bool flag = false;
        for(;i<len1;i++){
            if(j<0) break;
            if(a[i]+b[j]<t) continue;
            while(j>0 && a[i]+b[j]>t) j--;
            if(j>=0 && a[i]+b[j]==t) {
                flag = true;
                cout<<a[i]<<" "<<b[j]<<endl;
            }
        }
        if(!flag) cout<<"OTZ"<<endl<<endl;
        else cout<<endl;
    }
    return 0;
}