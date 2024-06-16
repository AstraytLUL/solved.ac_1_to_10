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

char G[12][12];

void solve(){
    int n, m, ans = 0; cin >> n >> m;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int>(1<<(m + 1), 0)));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i - 1][m];
        for(int j = 1; j <= m; ++j){
            for(int s = 0; s < (1<<(m + 1)); ++s){
                if((s & 1) && G[i][j] == '.'){
                    int t = 0, prev = s >> 1;
                    if((prev & 1) && j != 1) continue;
                    if((s & (1<<(m - 1))) && j != m) continue;
                    if(j == 1){
                        t = dp[i][j - 1][prev ^ (1 << m)] + 1;
                    }
                    t = max(t, dp[i][j - 1][prev] + 1);
                    dp[i][j][s] = max(t, dp[i][j][s]);
                }else if((s & 1) == 0){
                    int prev = (s >> 1), t = 0;
                    t = max(dp[i][j - 1][prev ^ (1<<m)], dp[i][j - 1][prev]);
                    dp[i][j][s] = max(t, dp[i][j][s]);
                }
                ans = max(ans, dp[i][j][s]);
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
