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

struct edge{
public:
    int u;
    int v;
    int cost;
    edge(int u,int v,int cost):u(u),v(v),cost(cost){}
    bool operator < (const edge & b) const {
        return cost<b.cost;
    }
};

vector<edge> g;
const int Max = 10005;
int Find[Max];

int find(int x){
    if(Find[x] == -1)
        return x;
    else
        return Find[x] = find(Find[x]);
}


//返回最小生成树的最小费用
int Kruskal(int n){
    memset(Find,-1, sizeof(Find));
    sort(g.begin(),g.end());
    int cnt = 0;
    int ans = 0;
    for(auto item : g){
        int u = item.u;
        int v = item.v;
        int cost = item.cost;
        int t1 = find(u);
        int t2 = find(v);
        if(t1!=t2){
            ans += cost;
            Find[t1] = t2;
            cnt ++;
        }
        if(cnt == n-1)
            break;
    }
    if(cnt<n-1) return -1;
    else return ans;
}