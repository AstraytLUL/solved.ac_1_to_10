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

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, dist[1005][1005][2];
char G[1005][1005];
bool vis[1005][1005][2];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
            dist[i][j][0] = dist[i][j][1] = 1e18;
        }
    }
    queue<tuple<int, int, int>> bfs;
    vis[1][1][0] = 1;
    dist[1][1][0] = 1;
    bfs.push({1, 1, 0});
    while(bfs.size()){
        auto [x, y, z] = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(z && G[nx][ny] == '1') continue;
            if(G[nx][ny] == '1' && vis[nx][ny][1] == 0){
                dist[nx][ny][1] = dist[x][y][0] + 1;
                vis[nx][ny][1] = 1;
                bfs.push({nx, ny, 1});
            }
            if(G[nx][ny] == '0' && vis[nx][ny][z] == 0){
                dist[nx][ny][z] = dist[x][y][z] + 1;
                vis[nx][ny][z] = 1;
                bfs.push({nx, ny, z});
            }
        }
    }
    int ans = min(dist[n][m][0], dist[n][m][1]);
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
