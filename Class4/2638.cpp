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

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int G[maxn][maxn], t[maxn][maxn], cnt[maxn][maxn], vis[maxn][maxn];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == 1 || j == 1 || i == n || j == m) 
                pq.push(mp(0, mp(i, j))), vis[i][j] = 1, t[i][j] = 0;
            else
                t[i][j] = 1e18;
        }
    }
    while(pq.size()){
        auto [d, p] = pq.top();
        pq.pop();
        auto [x, y] = p;
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(vis[nx][ny]) continue;
            if(G[nx][ny] == 0){
                vis[nx][ny] = 1;
                t[nx][ny] = d;
                pq.push(mp(d, mp(nx, ny)));
            }else{
                cnt[nx][ny]++;
                if(cnt[nx][ny] == 2){
                    vis[nx][ny] = 1;
                    t[nx][ny] = d + 1;
                    pq.push(mp(d + 1, mp(nx, ny)));
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            ans = max(ans, t[i][j]);
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
