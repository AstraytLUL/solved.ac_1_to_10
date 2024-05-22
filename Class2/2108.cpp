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
    map<int, int> cnt;
    int t = 0;
    vector<int> val;
    for(auto &x:v) cin >> x, cnt[x]++, t = max(t, cnt[x]);
    sort(v.begin(), v.end());
    int avg = 0;
    for(auto &x:v) avg += x;
    avg = round(1.0 * avg / n);
    for(auto [x, y]:cnt) {
        if(y == t) val.pb(x);
    }
    cout << avg << '\n' << v[n / 2] << '\n';
    if(val.size() == 1) cout << val[0] << '\n';
    else cout << val[1] << '\n';
    cout << v[n - 1] - v[0] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
