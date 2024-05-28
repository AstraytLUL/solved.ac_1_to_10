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
#define maxn 25
#define mod 1000000007

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int G[maxn][maxn], dist[maxn][maxn];

bool check(int sz, int n){
    bool ok = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(G[i][j] < sz && G[i][j] > 0) ok = 1;
        }
    }
    return ok;
}

void solve(){
    int n; cin >> n;
    int x, y, sz = 2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> G[i][j];
            if(G[i][j] == 9){
                G[i][j] = 0;
                x = i, y = j;
            }
        }
    }
    int ans = 0, eaten = 0;
    queue<pii> bfs;
    while(x != 0 && y != 0){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = 1e6;
            }
        }
        dist[x][y] = 0;
        bfs.push(mp(x, y));
        while(bfs.size()){
            auto [tx, ty] = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int nx = tx + dx[i], ny = ty + dy[i];
                if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if(G[nx][ny] > sz) continue;
                if(dist[nx][ny] < 1e6) continue;
                dist[nx][ny] = dist[tx][ty] + 1;
                bfs.push(mp(nx, ny));
            }
        }
        int nx = 0, ny = 0, min_dist = 1e6;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] < min_dist && G[i][j] > 0 && G[i][j] < sz) {
                    min_dist = dist[i][j];
                    nx = i, ny = j;
                }
            }
        }
        if(nx == 0 && ny == 0) break;
        eaten++;
        if(eaten == sz) sz++, eaten = 0;
        ans += min_dist;
        x = nx, y = ny;
        G[nx][ny] = 0;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
