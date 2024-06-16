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

int dep[maxn], par[maxn][20];
vector<int> adj[maxn];

void dfs(int u = 1, int p = 1, int d = 1){
    par[u][0] = p;
    dep[u] = d;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= n; ++j){
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    int q; cin >> q;
    for(; q; q--){
        int u, v; cin >> u >> v;
        if(dep[u] < dep[v]) swap(u, v);
        for(int i = 19; i >= 0; --i){
            int to = par[u][i];
            if(dep[to] >= dep[v]) u = to;
        }
        if(u == v){
            cout << u << '\n';
            continue;
        }
        for(int i = 19; i >= 0; --i){
            int to_u = par[u][i], ho_u = par[v][i];
            if(to_u != ho_u) u = to_u, v = ho_u;
        }
        cout << par[u][0] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
