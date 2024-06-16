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
#define maxn 10005
#define mod 1000000007

int dp[maxn], deg[maxn];
int W[100005];
vector<pii> adj[maxn];
bitset<100005> dp2[maxn];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(v, i));
        W[i] = w;
        deg[v]++;
    }
    int s, t; cin >> s >> t;
    queue<int> bfs;
    bfs.push(s);
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        for(auto [v, id]:adj[u]){
            int w = W[id];
            if(dp[u] + w > dp[v]){
                dp[v] = dp[u] + w;
                dp2[v] = dp2[u];
                dp2[v][id] = 1;
            }else if(dp[u] + w == dp[v]){
                dp2[v] |= dp2[u];
                dp2[v][id] = 1;
            }
            deg[v]--;
            if(deg[v] == 0) bfs.push(v);
        }
    }
    cout << dp[t] << '\n';
    cout << dp2[t].count() << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
