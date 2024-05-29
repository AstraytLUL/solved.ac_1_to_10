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

int n, ans = 0, cnt[16][16];

void NQueen(int x){
    if(x == n + 1) {
        ans++;
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(cnt[x][i]) continue;
        for(int j = 0; j < n; ++j){
            cnt[x][j + 1]++;
            cnt[j + 1][i]++;
            if(x + j <= n && i + j <= n) cnt[x + j][i + j]++;
            if(x + j <= n && i - j >= 1) cnt[x + j][i - j]++;
        }
        NQueen(x + 1);
        for(int j = 0; j < n; ++j){
            cnt[x][j + 1]--;
            cnt[j + 1][i]--;
            if(x + j <= n && i + j <= n) cnt[x + j][i + j]--;
            if(x + j <= n && i - j >= 1) cnt[x + j][i - j]--;
        }
    }
}

void solve(){
    cin >> n;
    NQueen(1);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}