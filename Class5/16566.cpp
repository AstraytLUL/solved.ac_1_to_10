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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 4000005
#define mod 1000000007

int dsu[maxn];

int root(int u){
    return (u == dsu[u] ? u : dsu[u] = root(dsu[u]));
}

void join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    dsu[v] = u;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) dsu[i] = i;
    vector<int> v(m);
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    for(; k; k--){
        int x; cin >> x;
        int id = upper_bound(v.begin(), v.end(), x) - v.begin();
        id = root(id);
        cout << v[id] << '\n';
        join(id, id + 1);
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
