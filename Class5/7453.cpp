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
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
//#define int ll
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
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cnt[-a[i] - b[j]]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int x = c[i] + d[j];
            auto it = cnt.find(x);
            if(it == cnt.end()) continue;
            else ans += (*it).ss;
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
