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

struct pt{
    int x, y, z;
    pt(int a, int b, int c):x(a), y(b), z(c){}
};

int g[105][105][105], dist[105][105][105];
int dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

void solve(){
    int n, m, h; cin >> n >> m >> h;
    queue<pt> que;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= m; ++j){
            for(int k = 1; k <= n; ++k){
                cin >> g[k][j][i];
                if(g[k][j][i] == 1) que.push(pt(k, j, i));
            }
        }
    }
    while(que.size()){
        auto [x, y, z] = que.front();
        que.pop();
        for(int i = 0; i < 6; ++i){
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if(nx < 1 || ny < 1 || nz < 1 || nx > n || ny > m || nz > h) continue;
            if(g[nx][ny][nz] != 0) continue;
            g[nx][ny][nz] = 1;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            que.push(pt(nx, ny, nz));
        }
    }
    int ans = 0;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= m; ++j){
            for(int k = 1; k <= n; ++k){
                if(g[k][j][i] == 0){
                    cout << "-1\n";
                    return;
                }
                ans = max(ans, dist[k][j][i]);
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
