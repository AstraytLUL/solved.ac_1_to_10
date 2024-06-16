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
#define maxn 800005
#define mod 1000000007

bool exist[maxn];

void solve(){
    int w, n; cin >> w >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    bool ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int goal = w - (v[i] + v[j]);
            if(goal < 0) continue;
            ans |= exist[goal];
        }
        for(int j = 0; j < i; ++j){
            exist[v[i] + v[j]] = 1;
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
