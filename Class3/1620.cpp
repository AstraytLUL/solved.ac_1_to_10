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
    int n, m; cin >> n >> m;
    vector<string> no_to_name(n + 1);
    map<string, int> name_to_no;
    for(int i = 1; i <= n; ++i){
        cin >> no_to_name[i];
        name_to_no[no_to_name[i]] = i;
    }
    for(int i = 0; i < m; ++i){
        string q; cin >> q;
        if(q[0] <= '9' && q[0] >= '0'){
            int x = 0;
            for(auto c:q){
                x = x * 10 + c - '0';
            }
            cout << no_to_name[x] << '\n'; 
        }else{
            cout << name_to_no[q] << '\n';
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
