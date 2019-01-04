#include <cstdio>
#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int Max = 1005;
vector<int> g[Max];

bool used[Max];
int dist[Max];
//图的编号依旧是从1到n，很正常
void DFS(vector<int> g[],int start,int dist[],int n,int end){
    for(int i = 1;i<=n;i++) dist[i] = -1;
    for(int i = 1;i<=n;i++) used[i] = false;
    queue<int> que;
    while(!que.empty()) que.pop();
    que.push(start);
    used[start] = true;
    dist[start] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(auto item : g[u]){
            if(!used[item]){
                used[item]=true;
                que.push(item);
                dist[item] = dist[u] + 1;
            }
            if(item == end) return;
        }
    }
}