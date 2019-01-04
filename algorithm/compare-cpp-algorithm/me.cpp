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

bool cmp(const int a,const int b){return a>=b;};

class Solution {
public:
    inline bool max2_vector(vector<int> & a,vector<int> & b,int n){
        for(int i = 0;i<n;i++) if(a[i]<0) return false;
        for(int i = 0;i<n;i++) if(b[i]<0) return true;
        for(int i = 0;i<n;i++)
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        return false;
    }

    inline void compute(vector<int>& nums,int n,vector<vector<int>>& data){
        data[n] = nums;
        for(int i = n-1;i>0;i--){
            data[i].clear();
            int j;
            for(j = 0;j<i;j++){
                if(data[i+1][j]<data[i+1][j+1]) break;
                else data[i].push_back(data[i+1][j]);
            }
            if(j!=i)
                for(j++;j<i+1;j++)
                    data[i].push_back(data[i+1][j]);
        }
        data[0].clear();
    }

    inline void merge(vector<int>& a,vector<int>& b,vector<int>& ans){
        int n = (int)a.size();
        int m = (int)b.size();
        for(int i = max(n,m);i>=1;i--) a.push_back(0),b.push_back(0);
        ans.clear();
        int p1 = 0,p2 = 0;
        while(p1<n && p2<m){
            if(a[p1]>b[p2]) ans.push_back(a[p1++]);
            else if(a[p1]==b[p2]){
                int t1 = p1+1;
                int t2 = p2+1;
                while((t1<n || t2<m) && a[t1]==b[t2]) t1++,t2++;
                if(a[t1]>b[t2]) ans.push_back(a[p1++]);
                else ans.push_back(b[p2++]);
            }
            else ans.push_back(b[p2++]);
        }
        while(p1<n) ans.push_back(a[p1++]);
        while(p2<m) ans.push_back(b[p2++]);
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        vector<vector<int>> data1(n+1);
        vector<vector<int>> data2(m+1);
        compute(nums1,n,data1);
        compute(nums2,m,data2);
        vector<int> res(k,-10);
        vector<int> tmp;
        for(int i = 0;i<=k;i++){
            if(i>n || (k-i)>m) continue;
            vector<int>& a1 = data1[i];
            vector<int>& a2 = data2[k-i];
            merge(a1,a2,tmp);
            if(!max2_vector(res,tmp,k)) res = tmp;
        }
        return res;
    }
};

int main() {
    int n,m,k;
    while(cin>>n>>m>>k){
        vector<int> nums1(n),nums2(m);
        for(int i = 0;i<n;i++) cin>>nums1[i];
        for(int i = 0;i<m;i++) cin>>nums2[i];
        Solution t;
        vector<int> tmp = t.maxNumber(nums1,nums2,k);
        for(auto item:tmp) cout<<item<<" ";
        cout<<endl;
    }
    return 0;
}