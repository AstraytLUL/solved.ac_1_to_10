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
#define maxn 100005
#define mod 1000000007

void solve(){
    int n, m; cin >> n >> m;
    vector<int> g(m + 1);
    for(int i = 1; i <= m; ++i) cin >> g[i];
    int lb = 0, rb = m;
    while(lb != rb){
        int mid = 1 + (lb + rb) / 2;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= mid; ++i) dp[g[i]]++;
        for(int i = n, carry = 0; i >= 0; --i){
            dp[i] += carry;
            carry = 0;
            if(dp[i] <= 1 || i == 0) continue;
            carry = dp[i] - 1;
            dp[i] = 1;
        }
        if(dp[0] == 0) lb = mid;
        else rb = mid - 1;
    }
    cout << lb << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
