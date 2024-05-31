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

struct edge{
    int u, v, w;
    bool operator< (edge E){
        return w < E.w;
    }
};

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
    int n; cin >> n;
    vector<pii> X(n), Y(n), Z(n);
    vector<edge> E;
    for(int i = 0; i < n; ++i){
        dsu[i] = i;
        cin >> X[i].ff >> Y[i].ff >> Z[i].ff;
        X[i].ss = Y[i].ss = Z[i].ss = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    for(int i = 1; i < n; ++i){
        edge ex, ey, ez;
        ex.u = X[i - 1].ss, ex.v = X[i].ss, ex.w = X[i].ff - X[i - 1].ff;
        ey.u = Y[i - 1].ss, ey.v = Y[i].ss, ey.w = Y[i].ff - Y[i - 1].ff;
        ez.u = Z[i - 1].ss, ez.v = Z[i].ss, ez.w = Z[i].ff - Z[i - 1].ff;
        E.pb(ex), E.pb(ey), E.pb(ez);
    }
    sort(E.begin(), E.end());
    int ans = 0;
    for(auto [u, v, w]:E){
        if(join(u, v)) ans += w;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
