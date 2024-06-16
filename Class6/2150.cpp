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

int cnt = 0, t = 0;
int in[maxn], dp[maxn], done[maxn];
vector<int> adj[maxn], stk;
vector<vector<int>> scc;

void dfs(int u, int p){
    in[u] = dp[u] = ++t;
    stk.pb(u);
    for(auto v:adj[u]){
        if(in[v] == 0){
            dfs(v, u);
            dp[u] = min(dp[v], dp[u]);
        }else if(!done[v]){
            dp[u] = min(dp[u], in[v]);
        }
    }
    if(in[u] == dp[u]){
        int k = stk.back();
        scc.pb(vector<int>());
        while(stk.size() && stk.back() != u){
            stk.pop_back();
            done[k] = 1;
            scc[cnt].pb(k);
            k = stk.back();
        }
        done[u] = 1;
        scc[cnt].pb(u);
        stk.pop_back();
        sort(scc[cnt].begin(), scc[cnt].end());
        cnt++;
    }
}  

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0) {
            dfs(i, i);
        }
    }
    sort(scc.begin(), scc.end());
    cout << cnt << '\n';
    for(auto v:scc){
        for(int x:v) cout << x << ' ';
        cout << "-1\n";
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
