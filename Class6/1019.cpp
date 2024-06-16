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

int C[15][15];

void solve(){
    int n; cin >> n;
    C[0][0] = 1;
    for(int i = 1; i <= 10; ++i){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j < i; ++j){
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    vector<int> ans(10, 0);
    int d = 0, t = 1;
    while(t * 10 <= n){
        d++, t *= 10;
        for(int c = 1; c <= d; ++c){
            int tmp = 1;
            for(int i = 1; i <= d - c; ++i){
                tmp *= 9;
            }
            for(int i = 1; i <= 9; ++i){
                ans[i] += c * C[d - 1][c - 1] * tmp;
            }
            if(c != d){
                ans[0] += c * C[d - 1][c] * tmp;
                tmp = tmp / 9 * 8;
                for(int i = 1; i <= 9; ++i){
                    ans[i] += c * C[d - 1][c] * tmp;
                }
            }
        }
    }    
    int cur = t;
    while(cur < n){
        int k = (cur / t) % 10;
        if(cur + t > n){
            ans[k] += (n - cur + 1);
            t /= 10;
            d--;
        }else{
            ans[k] += t;
            for(int c = 1; c <= d; ++c){
                int tmp = 1;
                for(int i = 1; i <= d - c; ++i) tmp *= 9;
                for(int i = 0; i <= 9; ++i){
                    ans[i] += c * C[d][c] * tmp;
                }
            }
            cur += t;
        }
    }
    while(t != 0){
        int k = (cur / t) % 10;
        ans[k]++;
        t /= 10;
    }
    for(int i = 0; i <= 9; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
