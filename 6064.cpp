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
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void solve(){
    int m, n, x, y; cin >> m >> n >> x >> y;
    int ans = y;
    for(int i = 0; i <= m; ++i){
        if(ans % m == x % m) break;
        if(i == m){
            ans = -1;
            break;
        }
        ans += n;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
