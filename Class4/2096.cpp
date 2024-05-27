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

int dp_mx[2][3], dp_mn[2][3];

void solve(){
    int n; cin >> n;
    int c = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> dp_mx[c][j];
            dp_mn[c][j] = dp_mx[c][j];
        }
        dp_mx[c][0] += max(dp_mx[c ^ 1][0], dp_mx[c ^ 1][1]);
        dp_mn[c][0] += min(dp_mn[c ^ 1][0], dp_mn[c ^ 1][1]);
        dp_mx[c][1] += max({dp_mx[c ^ 1][0], dp_mx[c ^ 1][1], dp_mx[c ^ 1][2]});
        dp_mn[c][1] += min({dp_mn[c ^ 1][0], dp_mn[c ^ 1][1], dp_mn[c ^ 1][2]});
        dp_mx[c][2] += max(dp_mx[c ^ 1][2], dp_mx[c ^ 1][1]);
        dp_mn[c][2] += min(dp_mn[c ^ 1][2], dp_mn[c ^ 1][1]);
        c ^= 1;
    }
    c ^= 1;
    cout << max({dp_mx[c][0], dp_mx[c][1], dp_mx[c][2]}) << ' ';
    cout << min({dp_mn[c][0], dp_mn[c][1], dp_mn[c][2]}) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
