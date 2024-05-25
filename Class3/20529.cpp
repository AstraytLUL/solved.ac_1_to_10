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
    int cnt = 0;
    while(x){
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n), cnt(16);
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        if(s[0] == 'E') p[i] ^= 8;
        if(s[1] == 'N') p[i] ^= 4;
        if(s[2] == 'F') p[i] ^= 2;
        if(s[3] == 'P') p[i] ^= 1;
        cnt[p[i]]++;
    }
    int ans = 69;
    for(int i = 0; i < 16; ++i){
        for(int j = i; j < 16; ++j){
            for(int k = j; k < 16; ++k){
                int dist = popcount(i ^ j) + popcount(j ^ k) + popcount(k ^ i);
                cnt[i]--, cnt[j]--, cnt[k]--;
                if(cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) ans = min(ans, dist);
                cnt[i]++, cnt[j]++, cnt[k]++;
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
