#include <cstdio>
#include <cstring>

int n, sum;
int V;//背包体积
int N[1005];//把数量同时看作物品的体积和价值
int dp[50005];

int main()
{
    while(~scanf("%d", &n))
    {
        sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &N[i]);
            sum += N[i];
        }

        V = sum / 2;//背包的体积
        //01背包
        for (int i = 1; i <= n; ++i) {
            for (int j = V; j >= N[i]; --j) {
                int temp = dp[j - N[i]] + N[i];
                if(dp[j] < temp) dp[j] = temp;
            }
        }

        if(sum - 2 * dp[V] == 0) printf("GF&SI\n");
        else printf("%d\n", sum - 2 * dp[V]);
    }
}