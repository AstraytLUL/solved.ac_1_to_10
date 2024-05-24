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
#define maxn 1005
#define mod 1000000007

int vis[maxn];
vector<int> adj[maxn];

void dfs(int u){
    cout << u << ' ';
    for(auto v:adj[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> que;
    que.push(s);
    vis[s] = 1;
    while(que.size()){
        int u = que.front();
        cout << u << ' ';
        que.pop();
        for(auto &v:adj[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            que.push(v);
        }
    }
}

void solve(){
    int n, m, s; cin >> n >> m >> s;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    vis[s] = 1;
    dfs(s);
    cout << '\n';
    for(int i = 1; i <= n; ++i){
        vis[i] = 0;
    }
    bfs(s);
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
