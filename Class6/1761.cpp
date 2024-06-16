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
#define maxn 40005
#define mod 1000000007

int d[maxn], layer[maxn], par[maxn][20];
vector<pii> adj[maxn];

void dfs(int u, int p){
    for(auto [v, w]:adj[u]){
        if(v == p) continue;
        par[v][0] = u;
        d[v] = d[u] + w;
        layer[v] = layer[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v){
    if(layer[u] < layer[v]) swap(u, v);
    for(int j = 19; j >= 0; --j){
        int to = par[u][j];
        if(layer[to] >= layer[v]) u = to;
    }
    if(u == v) return u;
    for(int j = 19; j >= 0; --j){
        int u_to = par[u][j], v_to = par[v][j];
        if(u_to != v_to) {
            u = u_to;
            v = v_to;
        }
    }
    return par[u][0];
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dfs(1, 1);
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i <= n; ++i){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    int q; cin >> q;
    for(; q; q--){
        int u, v; cin >> u >> v;
        int lca = LCA(u, v);
        cout << d[u] + d[v] - d[lca] * 2 << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
