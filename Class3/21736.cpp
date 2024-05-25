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

char g[605][605];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve(){
    int n, m; cin >> n >> m;
    queue<pii> bfs;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> g[i][j];
            if(g[i][j] == 'I') bfs.push(mp(i, j));
        }
    }
    int ans = 0;
    while(bfs.size()){
        auto [x, y] = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(g[nx][ny] == 'I' || g[nx][ny] == 'X') continue;
            if(g[nx][ny] == 'P') ans++;
            g[nx][ny] = 'I';
            bfs.push(mp(nx, ny));
        }
    }
    if(ans == 0) cout << "TT\n";
    else cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
