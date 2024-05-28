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

int par[maxn];
vector<pii> adj[maxn];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
    }
    int s, t; cin >> s >> t;
    vector<int> dist(n + 1, 1e18);
    dist[s] = 0;
    par[s] = s;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, s));
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]:adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push(mp(d + w, v));
                par[v] = u;
            }
        }
    }
    vector<int> path(1, t);
    int tmp = t;
    while(tmp != s){
        tmp = par[tmp];
        path.pb(tmp);
    }
    reverse(path.begin(), path.end());
    cout << dist[t] << '\n';
    cout << path.size() << '\n';
    for(auto &x:path) cout << x << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
