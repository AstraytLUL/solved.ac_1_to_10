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

int val[505][505];

void solve(){
    int n, m; cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> val[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j + 3 < m) ans = max(ans, val[i][j] + val[i][j + 1]+ val[i][j + 2]+ val[i][j + 3]);
            if(i + 3 < n) ans = max(ans, val[i][j] + val[i + 1][j]+ val[i + 2][j]+ val[i + 3][j]);
            if(j + 2 < m){
                int t = val[i][j] + val[i][j + 1] + val[i][j + 2];
                if(i + 1 < n) {
                    ans = max(ans, t + max({val[i + 1][j], val[i + 1][j + 1], val[i + 1][j + 2]}));
                    ans = max(ans, val[i][j] + val[i][j + 1] + val[i + 1][j + 1] + val[i + 1][j + 2]);
                }
                if(i - 1 >= 0) {
                    ans = max(ans, t + max({val[i - 1][j], val[i - 1][j + 1], val[i - 1][j + 2]}));
                    ans = max(ans, val[i][j] + val[i][j + 1] + val[i - 1][j + 1] + val[i - 1][j + 2]);
                }
            }
            if(i + 2 < n){
                int t = val[i][j] + val[i + 1][j] + val[i + 2][j];
                if(j + 1 < m) {
                    ans = max(ans, t + max({val[i][j + 1], val[i + 1][j + 1], val[i + 2][j + 1]}));
                    ans = max(ans, val[i][j] + val[i + 1][j] + val[i + 1][j + 1] + val[i + 2][j + 1]);
                }
                if(j - 1 >= 0) {
                    ans = max(ans, t + max({val[i][j - 1], val[i + 1][j - 1], val[i + 2][j - 1]}));
                    ans = max(ans, val[i][j] + val[i + 1][j] + val[i + 1][j - 1] + val[i + 2][j - 1]);
                }
            }
            if(i > 0 && j > 0){
                ans = max(ans, val[i][j] + val[i - 1][j] + val[i][j - 1] + val[i - 1][j - 1]);
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
