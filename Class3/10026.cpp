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

char cg[105][105], pg[105][105];
bool cv[105][105], pv[105][105];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void solve(){
    int n; cin >> n;
    int cc = 0, pc = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> pg[i][j];
            cg[i][j] = (pg[i][j] == 'B' ? 'B' : 'R');
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(cv[i][j] == 0){
                cc++;
                queue<pii> bfs;
                bfs.push(mp(i, j));
                cv[i][j] = 1;
                while(bfs.size()){
                    auto [x, y] = bfs.front();
                    bfs.pop();
                    for(int i = 0; i < 4; ++i){
                        int nx = x + dx[i], ny = y + dy[i];
                        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if(cv[nx][ny]) continue;
                        if(cg[nx][ny] != cg[x][y]) continue;
                        cv[nx][ny] = 1;
                        bfs.push(mp(nx, ny));
                    }
                }
            }
            if(pv[i][j] == 0){
                pc++;
                queue<pii> bfs;
                bfs.push(mp(i, j));
                pv[i][j] = 1;
                while(bfs.size()){
                    auto [x, y] = bfs.front();
                    bfs.pop();
                    for(int i = 0; i < 4; ++i){
                        int nx = x + dx[i], ny = y + dy[i];
                        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if(pv[nx][ny]) continue;
                        if(pg[nx][ny] != pg[x][y]) continue;
                        pv[nx][ny] = 1;
                        bfs.push(mp(nx, ny));
                    }
                }
            }
        }
    }
    cout << pc << ' ' << cc << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
