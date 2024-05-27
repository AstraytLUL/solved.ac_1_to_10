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
    int n, m, k; cin >> n >> m >> k;
    vector<int> dist(n + 1, 1e9);
    vector<pair<pii, int>> edge;
    dist[1] = 0;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        edge.pb(mp(mp(u, v), w));
        edge.pb(mp(mp(v, u), w));
    }
    for(int i = 1; i <= k; ++i){
        int u, v, w; cin >> u >> v >> w;
        edge.pb(mp(mp(u, v), -w));
    }
    for(int i = 1; i <= n; ++i){
        for(auto [p, w]:edge){
            auto [u, v] = p;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    bool ok = 0;
    for(auto [p, w]:edge){
        auto [u, v] = p;
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
            ok = 1;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
