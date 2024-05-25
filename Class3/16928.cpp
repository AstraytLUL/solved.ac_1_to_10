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

int to[105], dist[105];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= 100; ++i) dist[i] = 100;
    dist[1] = 1;
    for(int i = 1; i <= n; ++i){
        int u, v; cin >> u >> v;
        to[u] = v;
    }
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        to[u] = v;
    }
    queue<int> bfs;
    bfs.push(1);
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        for(int i = 1; i <= 6; ++i){
            if(u + i > 100) continue;
            if(dist[u + i] <= dist[u] + 1) continue;
            dist[u + i] = min(dist[u + i], dist[u] + 1);
            if(to[u + i] != 0){
                if(dist[to[u + i]] < dist[u + i]) continue;
                dist[to[u + i]] = dist[u + i];
                bfs.push(to[u + i]);
            }else{
                bfs.push(u + i);
            }
        }
    }
    cout << dist[100] - 1 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
