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
    int t; cin >> t;
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    int m; cin >> m;
    vector<int> b(m);
    for(auto &x:b) cin >> x;
    map<int, int> cnt_a, cnt_b;
    for(int j = 0; j < n; ++j){
        int sum = 0;
        for(int i = j; i >= 0; --i) sum += a[i], cnt_a[sum]++;
    }
    for(int j = 0; j < m; ++j){
        int sum = 0;
        for(int i = j; i >= 0; --i) sum += b[i], cnt_b[sum]++;
    }
    int ans = 0;
    for(auto [x, c1]:cnt_a){
        int y = t - x;
        if(cnt_b.find(y) == cnt_b.end()) continue;
        else ans += c1 * cnt_b[y];
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
