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

vector<int> in, post;

void find_pre(int l1, int r1, int l2, int r2){
    cout << post[r2] << ' ';
    if(l1 == r1) return;
    int pos_in = -1;
    for(int i = l1; i <= r1; ++i){
        if(in[i] == post[r2]) pos_in = i;
    }
    if(pos_in == r1){
        find_pre(l1, r1 - 1, l2, r2 - 1);
    }else if(pos_in == l1){
        find_pre(l1 + 1, r1, l2, r2 - 1);
    }else{
        int pos_post = -1;
        for(int i = l2; i <= r2; ++i){
            if(post[i] == in[pos_in + 1]) pos_post = i;
        }   
        find_pre(l1, pos_in - 1, l2, pos_post - 1);
        find_pre(pos_in + 1, r1, pos_post, r2 - 1);
    }
}

void solve(){
    int n; cin >> n;
    in.assign(n, 0);
    post.assign(n, 0);
    for(auto &x:in) cin >> x;
    for(auto &x:post) cin >> x;
    find_pre(0, n - 1, 0, n - 1);
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
