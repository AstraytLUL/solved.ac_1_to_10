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

bool check(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        string t = "";
        for(int j = i; j >= 1; --j){
            t += s[j - 1];
            if(check(t)) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
