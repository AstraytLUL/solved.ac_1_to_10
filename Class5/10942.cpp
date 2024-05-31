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

int dp[2005][2005];

void solve(){
    int n; cin >> n;
    vector<int> v(n + 1, -1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i]; dp[i][i] = 1;
        if(v[i] == v[i - 1]) dp[i - 1][i] = 1;
    }
    for(int len = 3; len <= n; ++len){
        for(int l = 1, r = len; r <= n; ++l, ++r){
            dp[l][r] = (dp[l + 1][r - 1]) && (v[l] == v[r]);
        }
    }
    int q; cin >> q;
    for(; q; q--){
        int l, r; cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
