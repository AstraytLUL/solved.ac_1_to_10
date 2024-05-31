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

int to_number(string s){
    int ret = 0;
    for(auto c:s){
        ret *= 10;
        ret += c - '0';
    }
    return ret;
}

void FizzBuzz(int x){
    if(x % 15 == 0){
        cout << "FizzBuzz\n";
    }else if(x % 5 == 0){
        cout << "Buzz\n";
    }else if(x % 3 == 0){
        cout << "Fizz\n";
    }else{
        cout << x << "\n";
    }
}

void solve(){
    string a, b, c; cin >> a >> b >> c;
    if('0' <= a[0] && a[0] <= '9'){
        int x = to_number(a);
        FizzBuzz(x + 3);
    }
    else if('0' <= b[0] && b[0] <= '9'){
        int x = to_number(b);
        FizzBuzz(x + 2);
    }
    else if('0' <= c[0] && c[0] <= '9'){
        int x = to_number(c);
        FizzBuzz(x + 1);
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
