#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int Max = 705;
long long nums[Max][Max];
int n;
struct unit{
public:
    long long sum;
    int index;
    unit(long long sum,int index):sum(sum),index(index){}
    bool operator < (const unit& b) const {
        return sum>b.sum;
    }
};

//合并第i行到第1行，保证第1行总是记录当前最大的n个值
void merge(long long a[],long long b[]){
    priority_queue<unit> q;
    for(int i = 1;i<=n;i++){
        q.emplace(a[i]+b[1],1);
    }
    unit tmp(0,0);
    for(int i=1;i<=n;i++){
        tmp = q.top();
        a[i] = tmp.sum;
        q.pop();
        q.emplace(tmp.sum+b[tmp.index+1]-b[tmp.index],tmp.index+1);
    }
}

int main() {
   // freopen("in.txt","r",stdin);
    while(cin>>n){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cin>>nums[i][j];
            sort(nums[i]+1,nums[i]+n+1);
        }
        for(int i=2;i<=n;i++)
            merge(nums[1],nums[i]);
        for(int i=1;i<=n;i++)
            cout<<nums[1][i]<<" ";
        cout<<endl;
    }
    return 0;
}