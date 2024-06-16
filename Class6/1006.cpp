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

void DP(int n, int w, vector<vector<int>> &dp, vector<vector<int>> c){
    for(int i = 2; i <= n; ++i){
        int up = 2 - (c[i][0] + c[i - 1][0] <= w), dw = 2 - (c[i][1] + c[i - 1][1] <= w);
        int cur = 2 - (c[i][0] + c[i][1] <= w);
        dp[i][0] = min({dp[i - 1][0] + cur, dp[i - 1][1] + 1 + dw, dp[i - 1][2] + 1 + up, dp[i - 2][0] + up + dw});
        dp[i][1] = min({dp[i - 1][0] + 1, dp[i - 1][2] + up});
        dp[i][2] = min({dp[i - 1][0] + 1, dp[i - 1][1] + dw});
    }
}

void solve(){
    int n, w; cin >> n >> w;
    vector<vector<int>> dp(n + 5, vector<int>(3, 1e18)), c(n + 1, vector<int>(2));
    for(int i = 0; i < 2; ++i){
        for(int j = 1; j <= n; ++j)
            cin >> c[j][i];
    }
    if(n == 1){
        cout << (c[1][0] + c[1][1] <= w ? 1 : 2) << '\n';
        return;
    }
    dp[0].assign(3, 0);
    dp[1][0] = 2;
    if(c[1][0] + c[1][1] <= w) dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 1;
    int ans = n * 2;
    DP(n, w, dp, c);
    ans = min(ans, dp[n][0]);
    if(c[1][0] + c[n][0] <= w){
        int t = c[1][0];
        dp[1][0] = 2;
        dp[1][1] = dp[1][2] = 1;
        c[1][0] = 1e18;
        DP(n, w, dp, c);
        ans = min(ans, dp[n][2]);
        c[1][0] = t;
    }
    if(c[1][1] + c[n][1] <= w){
        int t = c[1][1];
        dp[1][0] = 2;
        dp[1][1] = dp[1][2] = 1;
        c[1][1] = 1e18;
        DP(n, w, dp, c);
        ans = min(ans, dp[n][1]);
        c[1][1] = t;
    }
    if(c[1][0] + c[n][0] <= w && c[1][1] + c[n][1] <= w){
        dp[1][0] = 2;
        dp[1][1] = dp[1][2] = 1;
        c[1][0] = 1e18;
        c[1][1] = 1e18;
        DP(n, w, dp, c);
        ans = min(ans, dp[n - 1][0]);
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
