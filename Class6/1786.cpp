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
    string T, P; 
    getline(cin, T);
    getline(cin, P);
    string s = P + "$" + T;
    int n = T.size(), m = P.size();
    vector<int> kmp(n + m + 1, 0);
    vector<int> ans;
    for(int i = 1; i < n + m + 1; ++i){
        int j = kmp[i - 1];
        while(s[j] != s[i] && j != 0){
            j = kmp[j - 1];
        }
        if(s[j] == s[i]) j++;
        kmp[i] = j;
        if(kmp[i] == m){
            ans.pb(i - 2 * m + 1);
        }
    }
    cout << ans.size() << '\n';
    for(auto &x:ans) cout << x << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
