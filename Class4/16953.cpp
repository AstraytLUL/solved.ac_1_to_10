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

void solve(){
    int a, b; cin >> a >> b;
    map<int, int> dist;
    queue<int> bfs;
    bfs.push(a);
    dist[a] = 1;
    while(bfs.size()){
        int x = bfs.front();
        bfs.pop();
        if(x * 2 <= b && (dist.find(x * 2) == dist.end() || dist[x * 2] == -1)){
            dist[x * 2] = dist[x] + 1;
            bfs.push(x * 2);
        }
        if(x * 10 + 1 <= b && (dist.find(x * 10 + 1) == dist.end() || dist[x * 10 + 1] == -1)){
            dist[x * 10 + 1] = dist[x] + 1;
            bfs.push(x * 10 + 1);
        }
    }
    if(dist.find(b) == dist.end()) cout << -1 << '\n';
    else cout << dist[b] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
