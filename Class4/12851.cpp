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
    int s, t; cin >> s >> t;
    vector<int> dist(maxn, 1e18), dp(maxn, 0);
    dist[s] = 0;
    dp[s] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, s));
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        if(2 * u < maxn && dist[2 * u] >= d + 1) {
            if(dist[2 * u] == dist[u] + 1) {
                dp[2 * u] += dp[u];
            }else{
                dp[u * 2] = dp[u];
                dist[2 * u] = dist[u] + 1;
                pq.push(mp(d + 1, 2 * u));
            }
        }
        if(u != 0 && dist[u - 1] >= d + 1){
            if(dist[u - 1] == dist[u] + 1) {
                dp[u - 1] += dp[u];
            }else{
                dp[u - 1] = dp[u];
                dist[u - 1] = dist[u] + 1;
                pq.push(mp(d + 1, u - 1));
            }
        }
        if(u != maxn - 1 && dist[u + 1] >= d + 1){
            if(dist[u + 1] == dist[u] + 1) {
                dp[u + 1] += dp[u];
            }else{
                dp[u + 1] = dp[u];
                dist[u + 1] = dist[u] + 1;
                pq.push(mp(d + 1, u + 1));
            }
        }
    }
    cout << dist[t] << '\n';
    cout << dp[t] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
