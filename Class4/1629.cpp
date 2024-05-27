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
#define maxn 20005
#define mod 1000000007

vector<pii> adj[maxn];

void solve(){
    int n, m; cin >> n >> m;
    int k; cin >> k;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
    }
    vector<int> dist(n + 1, 1e18);
    dist[k] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, k));
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]:adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push(mp(d + w, v));
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(dist[i] == 1e18) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
