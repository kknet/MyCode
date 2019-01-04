#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
#define Max 10005
#define INF 0x7ffffff

int flow[Max],father[Max],vertex,E;
vector<pair<int,int>> g[Max];
inline void change_element_add(int a,int b,int c){
    int i=0;
    int len = (int) g[a].size();
    for(;i<len;i++)
        if(g[a][i].first == b)
            break;
    if(i<len)
        g[a][i].second += c;
    else
        g[a].emplace_back(b,c);
}

inline void change_element_sub(int a,int b,int c){
    int i=0;
    int len = (int) g[a].size();
    for(;i<len;i++)
        if(g[a][i].first == b){
            g[a][i].second -= c;
            break;
        }
}

inline int BFS(int s,int t){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(father,-1, sizeof(int)*(vertex+5));
    flow[s] = INF;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto item:g[v]){
            int i=item.first;
            if(father[i]==-1 && item.second>0){
                flow[i] = min(flow[v],item.second);
                father[i] = v;
                if(i==t)
                    return flow[t];
                q.push(i);
            }
        }
    }
    if(father[t] == -1)
        return -1;
    else
        return flow[t];
}

int EK(int s,int t){
    int ans = 0;
    int increase= BFS(s,t),k=t,last;
    while(increase!=-1){
        while(k!=s){
            last = father[k];
            change_element_sub(last,k,increase);
            change_element_add(k,last,increase);
            k=last;
        }
        ans += increase;
        k=t;
        increase= BFS(s,t);
    }
    return ans;
}