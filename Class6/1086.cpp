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

int gcd(int a, int b){
    if(a < b) swap(a, b);
    while(b != 0){
        a = a % b;
        swap(a, b);
    }
    return a;
}

void solve(){
    int n; cin >> n;
    int a = 0, b = 1;
    vector<string> tmp(n);
    vector<int> pw(51, 1), v(n, 0);
    for(auto &x:tmp) cin >> x;
    int k; cin >> k;
    vector<vector<int>> dp(k, vector<int>((1<<n), 0));
    for(int i = 1; i <= 50; ++i) pw[i] = pw[i - 1] * 10 % k;
    for(int i = 0; i < n; ++i){
        b *= (i + 1);
        reverse(tmp[i].begin(), tmp[i].end());
        for(int j = 0; j < tmp[i].size(); ++j){
            int t = tmp[i][j] - '0';
            t *= pw[j];
            t %= k;
            v[i] = (v[i] + t) % k;
        }
        dp[v[i]][(1<<i)]++;
    }
    for(int s = 0; s < (1<<n); ++s){
        for(int i = 0; i < n; ++i){
            if((s & (1<<i)) == 0) continue;
            for(int j = 0; j < k; ++j){
                int x = tmp[i].length();
                int t = (pw[x] * j + v[i]) % k;
                dp[t][s] += dp[j][s ^ (1<<i)];
            }
        }
    }
    a = dp[0][(1<<n) - 1];
    int g = gcd(a, b);
    a /= g, b /= g;
    cout << a << '/' << b << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
