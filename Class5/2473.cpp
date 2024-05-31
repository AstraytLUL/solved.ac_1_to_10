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
#define maxn 200005
#define mod 1000000007

void solve(){
    int n; cin >> n;
    map<int, pii> mp;
    vector<int> v(n);
    int mn = 1e18;
    vector<int> ans(3);
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            int sum = v[i] + v[j];
            int id = (lower_bound(v.begin(), v.end(), -sum) - v.begin());
            for(int k = max(0ll, id - 5); k < min(n, id + 5); ++k){
                if(k == i || k == j) continue;
                if(abs(v[i] + v[j] + v[k]) < mn){
                    mn = abs(v[i] + v[j] + v[k]);
                    ans[0] = v[i];
                    ans[1] = v[j];
                    ans[2] = v[k];
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
