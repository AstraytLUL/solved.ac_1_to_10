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

vector<pii> adj[maxn], rev[maxn];

void solve(){
    int n, m, x; cin >> n >> m >> x;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        rev[v].pb(mp(u, w));
    }
    int ans = 0;
    vector<vector<int>> t(n + 1, vector<int> (2, 1e18));
    t[x][0] = t[x][1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, x));
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > t[u][0]) continue;
        for(auto [v, w]:adj[u]){
            if(d + w < t[v][0]){
                t[v][0] = d + w;
                pq.push(mp(d + w, v));
            }
        }
    }
    pq.push(mp(0, x));
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > t[u][1]) continue;
        for(auto [v, w]:rev[u]){
            if(d + w < t[v][1]){
                t[v][1] = d + w;
                pq.push(mp(d + w, v));
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        ans = max(ans, t[i][0] + t[i][1]);
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
