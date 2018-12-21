#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MaxN = 1005;
vector<int> g[MaxN];
int linker[MaxN];
bool used[MaxN];
int uN;
bool dfs(int u){
    for(auto v:g[u]){
        if(!used[v]){
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])){
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungry(){
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int  u = 0;u<uN;u++){
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}