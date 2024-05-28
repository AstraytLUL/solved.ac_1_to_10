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

int n, m, ans = 0;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<vector<int>> G;

void calc(int d){
    if(d == 0){
        vector<vector<int>> g = G;
        queue<pii> bfs;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == 2){
                    bfs.push(mp(i, j));
                }
            }
        }
        while(bfs.size()){
            auto [x, y] = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(g[nx][ny] != 0) continue; 
                g[nx][ny] = 2;
                bfs.push(mp(nx, ny));
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == 0){
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(G[i][j] == 0){
                G[i][j] = 1;
                calc(d - 1);
                G[i][j] = 0;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    G.assign(n, vector<int> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> G[i][j];
        }
    }
    calc(3);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
