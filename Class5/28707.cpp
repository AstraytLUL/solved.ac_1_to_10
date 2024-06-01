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
    int n; cin >> n;
    vector<int> v(n);
    string str = "";
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        str += to_string(i);
    }
    map<string, int> dist;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    dist[str] = 0;
    pq.push(mp(0, str));
    int m; cin >> m;
    vector<int> a(m), b(m), c(m);
    for(int i = 0; i < m; ++i) cin >> a[i] >> b[i] >> c[i];
    while(pq.size()){
        auto [d, s] = pq.top();
        pq.pop();
        if(d > dist[s]) continue;
        for(int i = 0; i < m; ++i){
            string t = s;
            swap(t[a[i] - 1], t[b[i] - 1]);
            if(dist.find(t) == dist.end() || d + c[i] < dist[t]){
                dist[t] = d + c[i];
                pq.push(mp(d + c[i], t));
            }
        }
    } 
    int ans = 1e18;
    for(auto [s, d]:dist){
        bool inc = 1;
        for(int i = 1; i < n; ++i){
            inc &= (v[s[i - 1] - '0'] <= v[s[i] - '0']);
        }
        if(inc == 0) continue;
        ans = min(ans, d);
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
