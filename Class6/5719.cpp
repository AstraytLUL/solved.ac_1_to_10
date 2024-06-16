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
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        int s, t; cin >> s >> t;
        vector<vector<int>> dist(n, vector<int> (2, 1e18));
        vector<vector<pii>> adj(n);
        dist[s][0] = 0;
        for(int i = 0; i < m; ++i){
            int u, v, w; cin >> u >> v >> w;
            adj[u].pb(mp(v, w));
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(mp(0, s));
        while(pq.size()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u][1]) continue;
            for(auto [v, w]:adj[u]){
                if(d + w < dist[v][0]){
                    swap(dist[v][0], dist[v][1]);
                    dist[v][0] = d + w;
                    cout << u << ' ' << v << ' ' << dist[v][0] << '\n';
                    pq.push(mp(dist[v][0], v));
                }else if(d + w < dist[v][1] && d + w != dist[v][0]){
                    dist[v][1] = d + w;
                    cout << u << ' ' << v << ' ' << dist[v][1] << '\n';
                    pq.push(mp(dist[v][1], v));
                }
            }
        }
        if(dist[t][1] == 1e18) dist[t][1] = -1;
        cout << dist[t][0] << ' '  << dist[t][1] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
