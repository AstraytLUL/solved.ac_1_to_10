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

void solve(){
    int n; cin >> n;
    vector<vector<pii>> dp(n, vector<pii>(1<<n, mp(1e18, 0)));
    vector<vector<int>>g(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; ++i) dp[i][(1<<i)].ff = 0, dp[i][(1<<i)].ss = i;
    for(int s = 0; s < (1<<n); ++s){
        for(int i = 0; i < n; ++i){
            if((s & (1<<i)) == 0) continue;
            for(int j = 0; j < n; ++j){
                if(g[i][j] == 0 || (s & (1<<j)) == 0) continue;
                dp[j][s] = min(dp[j][s], mp(dp[i][s ^ (1<<j)].ff + g[i][j], dp[i][s ^ (1<<j)].ss));
            }
        }
    }
    int ans = 1e18;
    for(int i = 0; i < n; ++i){
        int s = (1<<n) - 1;
        int p = dp[i][s].ss;
        if(g[i][p] != 0)
            ans = min(ans, dp[i][s].ff + g[i][p]);
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
