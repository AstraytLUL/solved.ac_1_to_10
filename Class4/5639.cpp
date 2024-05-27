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
#include <stack>
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

struct Node{
    int val;
    Node *ls = nullptr, *rs = nullptr;
};

Node *root = nullptr;

void insert(Node *&n, int val){
    if(n == nullptr){
        n = new Node();
        n->val = val;
        return;
    }
    if(val < n->val){
        insert(n->ls, val);
    }else{
        insert(n->rs, val);
    }
}

void print(Node* n){
    if(n->ls != nullptr){
        print(n->ls);
    }
    if(n->rs != nullptr){
        print(n->rs);
    }
    cout << n->val << '\n';
}

void solve(){
    int x; 
    while(cin >> x){
        insert(root, x);
    }
    print(root);
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
