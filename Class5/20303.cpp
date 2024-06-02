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
#define maxn 30005
#define mod 1000000007

int dsu[maxn], sz[maxn], c[maxn];

int root(int u){
    return (u == dsu[u] ? u : dsu[u] = root(dsu[u]));
}

void join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    dsu[u] = v;
    sz[v] += sz[u];
    c[v] += c[u];
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
        sz[i] = 1;
        dsu[i] = i;
    }
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        join(u, v);
    }
    set<int> st;
    for(int i = 1; i <= n; ++i){
        int u = root(i);
        if(st.find(u) != st.end()) continue;
        st.insert(u);
        for(int j = sz[u]; j < k; ++j){
            dp[1][j] = max(dp[1][j], dp[0][j - sz[u]] + c[u]);
        }
        dp[0] = dp[1];
    }
    cout << dp[1][k - 1] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
