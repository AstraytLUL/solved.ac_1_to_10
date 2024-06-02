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

char G[1005][1005];
int sz[1005][1005];
pii dsu[1005][1005];

pii find(int x, int y){
    return (dsu[x][y] == mp(x, y) ? dsu[x][y] : dsu[x][y] = find(dsu[x][y].ff, dsu[x][y].ss));
}

void join(pii u, pii v){
    u = find(u.ff, u.ss), v = find(v.ff, v.ss);
    if(u == v) return;
    if(u < v) swap(u, v);
    dsu[u.ff][u.ss] = v;
    sz[v.ff][v.ss] += sz[u.ff][u.ss];
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
            sz[i][j] = 1;
            dsu[i][j] = mp(i, j);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(G[i][j] == '1') continue;
            if(G[i][j + 1] == '0' && j != m) {
                join(mp(i, j), mp(i, j + 1));
            }
            if(G[i + 1][j] == '0' && i != n) {
                join(mp(i, j), mp(i + 1, j));
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(G[i][j] == '0') {
                cout << 0;
                continue;
            }
            set<pii> st;
            if(i != 1 && G[i - 1][j] != '1') st.insert(find(i - 1, j));
            if(i != n && G[i + 1][j] != '1') st.insert(find(i + 1, j));
            if(j != 1 && G[i][j - 1] != '1') st.insert(find(i, j - 1));
            if(j != m && G[i][j + 1] != '1') st.insert(find(i, j + 1));
            int ans = 1;
            for(auto [x, y]:st) ans += sz[x][y];
            ans %= 10;
            cout << ans;
        }
        cout << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
