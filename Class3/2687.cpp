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

int d[4] = {0, 0, 1, -1};

void solve(){
    int n; cin >> n;
    vector<vector<char>> g(n, vector<char> (n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }
    int ans = 0;
    queue<pii> bfs;
    vector<int> cnt;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] == '0') continue;
            ans++;
            bfs.push(mp(i, j));
            g[i][j] = '0';
            int c = 0;
            while(bfs.size()){
                int x = bfs.front().ff, y = bfs.front().ss;
                bfs.pop();
                c++;
                for(int t = 0; t < 4; ++t){
                    int nx = x + d[t], ny = y + d[3 - t];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(g[nx][ny] == '0') continue;
                    g[nx][ny] = '0';
                    bfs.push(mp(nx, ny));
                }
            }
            cnt.pb(c);
        }
    }
    sort(cnt.begin(), cnt.end());
    cout << ans << '\n';
    for(int c:cnt){
        cout << c << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
