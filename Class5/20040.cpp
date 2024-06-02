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
#define maxn 500005
#define mod 1000000007

int dsu[maxn];

int root(int u){
    return (u == dsu[u] ? u : dsu[u] = root(dsu[u]));
}

bool join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return 0;
    dsu[u] = v;
    return 1;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i) dsu[i] = i;
    int ans = 0;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        if(ans != 0) continue;
        if(!join(u, v)) ans = i + 1;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
