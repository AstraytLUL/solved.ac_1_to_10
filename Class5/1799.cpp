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

int n, ans1 = 0, ans2 = 0, G[15][15];

void calc(int d, int cnt){
    if(d == 2*n+1){
        ans1 = max(ans1, cnt);
        return;
    }
    if(d == 2*n+2){
        ans2 = max(ans2, cnt);
        return;
    }
    calc(d + 2, cnt);
    for(int i = max(1ll, d - n); i <= min(d - 1, n); ++i){
        int j = d - i;
        if(G[i][j] > 0){
            for(int k = 0; k <= n; ++k){
                if(i + k <= n && j + k <= n) G[i + k][j + k]--;
                if(i + k <= n && j - k >= 1) G[i + k][j - k]--;
            }
            calc(d + 2, cnt + 1);
            for(int k = 0; k <= n; ++k){
                if(i + k <= n && j + k <= n) G[i + k][j + k]++;
                if(i + k <= n && j - k >= 1) G[i + k][j - k]++;
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> G[i][j];
        }
    }
    calc(1, 0);
    calc(2, 0);
    cout << ans1 + ans2 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}

/*
0 0 1 0 0 
0 0 1 0 0 
0 1 1 0 0 
0 1 0 1 0
1 0 1 0 1
*/