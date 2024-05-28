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

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<pair<char, int>> stk;
    for(int i = 0; i < n; ++i){
        int k = (stk.empty() ? 0 : stk.back().ss);
        if(s[i] == t[k]) k++;
        else if(s[i] == t[0]) k = 1;
        else k = 0;
        if(k == m){
            k--;
            while(k--){
                stk.pop_back();
            }
        }else{
            stk.pb(mp(s[i], k));
        }
    }
    if(stk.empty()) cout << "FRULA\n";
    else {
        for(auto [c, x]:stk) cout << c;
        cout << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
