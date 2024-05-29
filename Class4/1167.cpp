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
#define maxn 100005
#define mod 1000000007

int dp[maxn][2];
vector<pii> adj[maxn];

void dfs(int u, int p){
    for(auto [v, w]:adj[u]){
        if(v == p) continue;
        dfs(v, u);
        int d = dp[v][0] + w;
        if(d > dp[u][0]) swap(d, dp[u][0]);
        if(d > dp[u][1]) swap(d, dp[u][1]);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int u; cin >> u;
        int v, w;
        while(cin >> v && v != -1){
            cin >> w;
            adj[u].pb(mp(v, w));
        }
    }
    dfs(1, 1);
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, dp[i][0] + dp[i][1]);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}