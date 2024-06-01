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

int dsu[maxn];

int root(int u){
    return (dsu[u] == u ? u : dsu[u] = root(dsu[u]));
}

bool join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return 0;
    dsu[u] = v;
    return 1;
}

void solve(){
    int n, m, k; 
    while(cin >> n >> m >> k){
        if(n == 0 && m == 0 && k == 0) return;
        vector<pii> R, B;
        for(int i = 0; i < m; ++i){
            char c; cin >> c;
            int u, v; cin >> u >> v;
            if(c == 'R') R.pb(mp(u, v));
            else B.pb(mp(u, v));
        }
        int mn = 0, mx = 0;
        for(int i = 1; i <= n; ++i) dsu[i] = i;
        for(auto [u, v]:R){
            join(u, v);
        }
        for(auto [u, v]:B){
            mn += join(u, v);
        }
        for(int i = 1; i <= n; ++i) dsu[i] = i;
        for(auto [u, v]:B){
            mx += join(u, v);
        }
        for(auto [u, v]:R){
            join(u, v);
        }
        if(mn <= k && k <= mx) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
