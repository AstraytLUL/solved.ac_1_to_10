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

int dsu[105], sz[105];

int root(int u){
    return (u == dsu[u] ? u : dsu[u] = root(dsu[u]));
}

void join(int u, int v){
    int uu = root(u), vv = root(v);
    if(uu == vv) return;
    if(uu < vv) swap(uu, vv);
    dsu[uu] = vv;
    sz[vv] += sz[uu];
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        dsu[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        join(u, v);
    }
    cout << sz[1] - 1 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
