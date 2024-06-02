//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int cost[1005][3], dp[1005][3][3];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 3; ++k)
                dp[i][j][k] = 1e18;
    }
    dp[2][0][1] = cost[1][0] + cost[2][1];
    dp[2][0][2] = cost[1][0] + cost[2][2];
    dp[2][1][0] = cost[1][1] + cost[2][0];
    dp[2][1][2] = cost[1][1] + cost[2][2];
    dp[2][2][0] = cost[1][2] + cost[2][0];
    dp[2][2][1] = cost[1][2] + cost[2][1];
    for(int i = 3; i <= n; ++i){
        dp[i][0][0] = min(dp[i - 1][0][1], dp[i - 1][0][2]) + cost[i][0];
        dp[i][1][0] = min(dp[i - 1][1][1], dp[i - 1][1][2]) + cost[i][0];
        dp[i][2][0] = min(dp[i - 1][2][1], dp[i - 1][2][2]) + cost[i][0];
        dp[i][0][1] = min(dp[i - 1][0][0], dp[i - 1][0][2]) + cost[i][1];
        dp[i][1][1] = min(dp[i - 1][1][0], dp[i - 1][1][2]) + cost[i][1];
        dp[i][2][1] = min(dp[i - 1][2][0], dp[i - 1][2][2]) + cost[i][1];
        dp[i][0][2] = min(dp[i - 1][0][0], dp[i - 1][0][1]) + cost[i][2];
        dp[i][1][2] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + cost[i][2];
        dp[i][2][2] = min(dp[i - 1][2][0], dp[i - 1][2][1]) + cost[i][2];
    }
    cout << min({dp[n][0][1], dp[n][0][2], dp[n][1][0], dp[n][1][2], dp[n][2][0], dp[n][2][1]}) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
