#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>

using namespace std;
#define Max 20
unsigned long long nums[Max][Max];
unsigned long long dp[Max][Max];

//主要使用的字符串,其实输入的是tmp,father是经过简单处理之后的
string father;
unsigned long long my_atoull(int left,int right){
    unsigned long long ans=0;
    for(int i=left;i<=right;i++){
        ans *= 10;
        ans+=(father[i]-'0');
    }
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    int m,n;
    while(cin>>m){
        string tmp;
        cin>>tmp;
        father = "0"+tmp;
        n=(int)tmp.length();

        //nums[i][j]表示从第i个字符到第j个字符组成的整数的大小
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                nums[i][j]=my_atoull(i,j);


        //初始化dp数组
        for(int j=1;j<=n;j++){
            dp[0][j]=nums[1][j];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=i;j++)
                dp[i][j]=0;
        }

        //打表开始
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                unsigned long long now=0;
                unsigned long long now_tmp;
                for(int k=i;k<=j-1;k++){
                    now_tmp = dp[i-1][k]*nums[k+1][j];
                    if(now_tmp>now)
                        now=now_tmp;
                }
                dp[i][j]=now;
            }
        }


        cout<<dp[m][n]<<endl;
    }
    return 0;
}

