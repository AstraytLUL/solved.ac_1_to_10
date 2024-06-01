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
#include <cassert>
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

char G[15][15];
bool vis[15][15][15][15];
int dist[15][15][15][15];

struct position{
    int rx, ry, bx, by;
    position(){}
    position(int a, int b, int c, int d):rx(a), ry(b), bx(c), by(d){}
};

position calcU(position cur){
    auto [rx, ry, bx, by] = cur;
    while(G[rx - 1][ry] == '.') rx--;
    while(G[bx - 1][by] == '.') bx--;
    if(G[rx - 1][ry] == 'O') rx--;
    if(G[bx - 1][by] == 'O') bx--;
    if(rx == bx && ry == by && G[rx][ry] != 'O'){
        if(cur.rx < cur.bx) bx++;
        else rx++;
    }
    return position(rx, ry, bx, by);
}

position calcD(position cur){
    auto [rx, ry, bx, by] = cur;
    while(G[rx + 1][ry] == '.') rx++;
    while(G[bx + 1][by] == '.') bx++;
    if(G[rx + 1][ry] == 'O') rx++;
    if(G[bx + 1][by] == 'O') bx++;
    if(rx == bx && ry == by && G[rx][ry] != 'O'){
        if(cur.rx > cur.bx) bx--;
        else rx--;
    }
    return position(rx, ry, bx, by);
}

position calcL(position cur){
    auto [rx, ry, bx, by] = cur;
    while(G[rx][ry - 1] == '.') ry--;
    while(G[bx][by - 1] == '.') by--;
    if(G[rx][ry - 1] == 'O') ry--;
    if(G[bx][by - 1] == 'O') by--;
    if(rx == bx && ry == by && G[rx][ry] != 'O'){
        if(cur.ry < cur.by) by++;
        else ry++;
    }
    return position(rx, ry, bx, by);
}

position calcR(position cur){
    auto [rx, ry, bx, by] = cur;
    while(G[rx][ry + 1] == '.') ry++;
    while(G[bx][by + 1] == '.') by++;
    if(G[rx][ry + 1] == 'O') ry++;
    if(G[bx][by + 1] == 'O') by++;
    if(rx == bx && ry == by && G[rx][ry] != 'O'){
        if(cur.ry > cur.by) by--;
        else ry--;
    }
    return position(rx, ry, bx, by);
}

void solve(){
    int n, m; cin >> n >> m;
    position start;
    pii O(0, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
            if(G[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
                G[i][j] = '.';
            }
            if(G[i][j] == 'B') {
                start.bx = i;
                start.by = j;
                G[i][j] = '.';
            }
            if(G[i][j] == 'O') {
                O = mp(i, j);
            }
        }
    }
    if(O == mp(0ll, 0ll)) {
        cout << -1 << '\n';
        return;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            for(int x = 1; x <= n; ++x){
                for(int y = 1; y <= m; ++y){
                    dist[i][j][x][y] = 1e9;
                }
            }
        }
    }
    vis[start.rx][start.ry][start.bx][start.by] = 1;
    dist[start.rx][start.ry][start.bx][start.by] = 0;
    queue<position> bfs;
    bfs.push(start);
    while(bfs.size()){
        position cur = bfs.front();
        bfs.pop();
        position nxt = cur;
        auto &[rx, ry, bx, by] = nxt;
        if(dist[rx][ry][bx][by] >= 10) continue;

        nxt = calcU(cur);
        if(!vis[rx][ry][bx][by] && G[bx][by] != 'O') {
            if(G[rx][ry] != 'O') bfs.push(nxt);
            vis[rx][ry][bx][by] = 1;
            dist[rx][ry][bx][by] = min(dist[rx][ry][bx][by], dist[cur.rx][cur.ry][cur.bx][cur.by] + 1);
        }

        nxt = calcD(cur);
        if(!vis[rx][ry][bx][by] && G[bx][by] != 'O') {
            if(G[rx][ry] != 'O') bfs.push(nxt);
            vis[rx][ry][bx][by] = 1;
            dist[rx][ry][bx][by] = min(dist[rx][ry][bx][by], dist[cur.rx][cur.ry][cur.bx][cur.by] + 1);
        }

        nxt = calcL(cur);
        if(!vis[rx][ry][bx][by] && G[bx][by] != 'O') {
            if(G[rx][ry] != 'O') bfs.push(nxt);
            vis[rx][ry][bx][by] = 1;
            dist[rx][ry][bx][by] = min(dist[rx][ry][bx][by], dist[cur.rx][cur.ry][cur.bx][cur.by] + 1);
        }

        nxt = calcR(cur);
        if(!vis[rx][ry][bx][by] && G[bx][by] != 'O') {
            if(G[rx][ry] != 'O') bfs.push(nxt);
            vis[rx][ry][bx][by] = 1;
            dist[rx][ry][bx][by] = min(dist[rx][ry][bx][by], dist[cur.rx][cur.ry][cur.bx][cur.by] + 1);
        }

    }
    int ans = 1e18;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == O.ff && j == O.ss) continue;
            ans = min(ans, dist[O.ff][O.ss][i][j]);
        }
    }
    cout << (ans >= 1e9 ? -1 : ans) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
