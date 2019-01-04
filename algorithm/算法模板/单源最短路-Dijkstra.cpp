#include <cstdio>
#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int Max = 10005;
const int INF = 0x3f3f3f3f;

struct edge{
    int to;
    int cost;
    edge(int first,int to):to(first),cost(to){}
    edge(){}
    bool operator < (const edge & b) const {
        return cost>b.cost;
    }
};

vector<edge> g[Max];   //这个图本身
int dist[Max];  //最终每个点对应的距离
int Path[Max];  //记录路径
int vis[Max];   //记录是不是已经判断过了



//节点编号从1到n
void Dijkstra(int n,int start){
    memset(Path,-1, sizeof(Path));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++) dist[i] = INF;
    priority_queue<edge> que;
    while(!que.empty()) que.pop();
    dist[start] = 0;
    que.push(edge(start,0));
    edge tmp;
    while(!que.empty()){
        tmp = que.top();
        que.pop();
        int u = tmp.to;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto item:g[u]){
            int v = item.to;
            int cost = item.cost;
            if(!vis[v] && dist[v]>dist[u]+cost){
                dist[v] = dist[u] + cost;
                que.push(edge(v,dist[v]));
                Path[v] = u;
            }
        }
    }
}