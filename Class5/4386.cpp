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
#define pdd pair<double,double>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

struct edge{
    int u, v;
    double w;
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
    vector<pdd> v(n);
    for(auto &p:v) cin >> p.ff >> p.ss;
    vector<edge> E;
    for(int i = 0; i < n; ++i){
        dsu[i] = i;
        for(int j = i + 1; j < n; ++j){
            double dx = v[i].ff - v[j].ff, dy = v[i].ss - v[j].ss;
            double dist = sqrt(dx * dx + dy * dy);
            edge e;
            e.u = i, e.v = j, e.w = dist;
            E.pb(e);
        }
    }
    sort(E.begin(), E.end());
    double ans = 0;
    for(auto [u, v, w]:E){
        if(join(u, v)) ans += w;
    }
    sort(E.begin(), E.end());
    cout << fixed << setprecision(2) << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
