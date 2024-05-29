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
    vector<pii> item(n);
    vector<int> bag(k);
    for(auto &[m, v]:item) cin >> m >> v;
    for(auto &c:bag) cin >> c;
    sort(item.begin(), item.end());
    sort(bag.begin(), bag.end());
    int ans = 0;
    priority_queue<int> pq;
    for(int i = 0, j = 0; i < k; ++i){
        while(j < n && item[j].ff <= bag[i]) pq.push(item[j].ss), ++j;
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
