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

bool isprime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return 0;
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    vector<int> factor;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            if(isprime(i)) factor.pb(i);
            int k = n / i;
            if(k != i && isprime(k)) factor.pb(k);
        }
    }
    if(isprime(n)) factor.pb(n);
    int ans = n, sz = factor.size();
    for(int s = 1; s < (1<<sz); ++s){
        int d = 1, c = 0;
        for(int i = 0; i < sz; ++i){
            if(s & (1<<i)) d *= factor[i], c++;
        }
        if(c % 2 == 0) ans += n / d;
        else ans -= n / d;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
