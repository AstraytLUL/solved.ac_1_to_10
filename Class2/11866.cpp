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
    int n, k; cin >> n >> k;
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < n; ++i) q.push(i + 1);
    int cnt = 0;
    while(q.size()){
        cnt++;
        if(cnt % k == 0){
            ans.pb(q.front());
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
        }
    }
    cout << "<";
    for(int i = 0; i < n - 1; ++i) cout << ans[i] << ", ";
    cout << ans[n - 1] << ">\n";
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
