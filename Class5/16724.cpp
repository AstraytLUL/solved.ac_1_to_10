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
pii dsu[1005][1005];

pii root(int x, int y){
    auto [nx, ny] = dsu[x][y];
    if(dsu[x][y] == mp(x, y)) return mp(x, y);
    else return dsu[x][y] = root(nx, ny);
}

void join(pii a, pii b){
    a = root(a.ff, a.ss), b = root(b.ff, b.ss);
    if(a == b) return;
    dsu[a.ff][a.ss] = b;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dsu[i][j] = mp(i, j);
            cin >> G[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x = i, y = j;
            if(G[i][j] == 'D') x++;
            if(G[i][j] == 'U') x--;
            if(G[i][j] == 'R') y++;
            if(G[i][j] == 'L') y--;
            join(mp(i, j), mp(x, y));
        }
    }
    set<pii> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            st.insert(root(i, j));
        }
    }
    cout << st.size() << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
