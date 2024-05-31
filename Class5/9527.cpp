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

int popcount(int x){
    int ret = 0;
    for(; x; x >>= 1) ret += (x & 1);
    return ret;
}

int C[56][56];
int calc(int x){
    int hb = 0, ret = 0, pc = popcount(x);
    ret += pc;
    for(int i = 0; i <= 60; ++i){
        if(x & (1ll << i)) {
            hb = i;
        }
    }
    for(int i = hb - 1; i >= 0; --i){
        ret++;
        for(int j = 1; j <= i; ++j){
            ret += (j + 1) * C[i][j];
        }
    }
    for(int pos = 0; pos < hb; ++pos){
        if(x & (1ll << pos)) {
            pc--;
            for(int i = 0; i <= pos; ++i){
                ret += (pc + i) * C[pos][i];
            }
        }
    }
    return ret;
}

void solve(){
    int a, b; cin >> a >> b;
    for(int i = 0; i <= 55; ++i){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j <= i - 1; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    cout << calc(b) - calc(a - 1) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
