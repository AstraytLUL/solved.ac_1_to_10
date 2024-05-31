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
#define maxn 105
#define mod 1000000007

char G[maxn][maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i){
        for(int j = 0; j <= m + 1; ++j){
            G[i][j] = '.';
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    string s; cin >> s;
    deque<char> keys;
    if(s != "0")
        for(auto c:s) keys.pb(c);
    int ans = 0;
    do{
        vector<vector<bool>> vis(n + 2, vector<bool> (m + 2, 0));
        while(keys.size()){
            char c = keys.front();
            keys.pop_front();
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    if(G[i][j] == c || G[i][j] == c - 'a' + 'A') G[i][j] = '.';
                }
            }
        }
        queue<pii> bfs;
        bfs.push(mp(0, 0));
        vis[0][0] = 1;
        while(bfs.size()){
            auto [x, y] = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1) continue;
                if(G[nx][ny] == '*' || ('A' <= G[nx][ny] && G[nx][ny] <= 'Z') || vis[nx][ny]) continue;
                if('a' <= G[nx][ny] && G[nx][ny] <= 'z') keys.pb(G[nx][ny]);
                if(G[nx][ny] == '$'){
                    G[nx][ny] = '.';
                    ans++;
                }
                vis[nx][ny] = 1;
                bfs.push(mp(nx, ny));
            }
        }
    }while(keys.size());
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
