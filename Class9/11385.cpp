/*
今ここから始まる　新しい旅に
Hello! Hello!
I Say Hello! Hello!
なんか反省ばっかしちゃってた　昨日の自分に
Good Bye! Good Bye!
One More Good Bye! Good Bye!
走り出しちゃったこの想いに　理由なんていらないよ
眩しい太陽を浴びて
目的地まだ見えないけれど
靴ひもを結んで　Walk This Way!
*/
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
#include <complex>
using namespace std;
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define int ll
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define si stack<int>
#define qi queue<int>
#define upb upper_bound
#define lwb lower_bound
#define pf push_front
#define pb push_back
#define pp push
#define pof pop_front
#define pob pop_back
#define ff first
#define ss second
#define modd inf
#define gcd __gcd
#define skip(x) if(x)continue;

int N = 1 << 21, logN = 21, r[(1<<21)];
int mod1 = 998244353, mod2 = 1004535809;

int fastpow(int a, int b, int mod){
    a %= mod;
    int ret = 1;
    for(; b; b>>=1){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

int MUL(int a, int b, int mod){
    if(a == 0 || b == 0) return 0;
    __int128_t A = a, B = b, MOD = mod;
    A = A * B % MOD;
    int ret = A;
    return ret;
}

vector<int> NTT(vector<int> v, int inv, int mod){
    for(int i = 0; i < N; ++i){
        if(i < r[i]) swap(v[i], v[r[i]]);
    }

    for(int len = 2; len <= N; len <<= 1){
        int wn = (inv == 0 ? 3 : fastpow(3, mod - 2, mod));
        wn = fastpow(wn, mod / len, mod);
        for(int i = 0; i < N; i += len){
            for(int j = 0, w = 1; j < len / 2; ++j, w = w * wn % mod){
                int x = v[i + j], y = v[i + j + len / 2] * w % mod;
                v[i + j] = (x + y) % mod;
                v[i + j + len / 2] = (x - y + mod) % mod;
            }
        }
    }

    if(inv == 0) return v;

    int invN = fastpow(N, mod - 2, mod);
    for(int i = 0; i < N; ++i) v[i] = v[i] * invN % mod; 
    return v;
}

vector<int> CRT(vector<int> a, vector<int> b){
    vector<int> ret(N, 0);
    int M = mod1 * mod2;
    for(int i = 0; i < N; ++i){
        ret[i] += MUL(a[i], MUL(mod2, fastpow(mod2, mod1 - 2, mod1), M), M);
        ret[i] += MUL(b[i], MUL(mod1, fastpow(mod1, mod2 - 2, mod2), M), M);
        ret[i] %= M;
    }
    return ret;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> f(N, 0), g(N, 0);

    for(int i = 0; i <= n; ++i) cin >> f[i];
    for(int i = 0; i <= m; ++i) cin >> g[i];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < logN; ++j){
            if(i & (1<<j)) r[i] |= (1 << (logN - j - 1));
        }
    }


    vector<int> F1 = NTT(f, 0, mod1), F2 = NTT(f, 0, mod2);
    vector<int> G1 = NTT(g, 0, mod1), G2 = NTT(g, 0, mod2);
    vector<int> H1(N, 0), H2(N, 0);

    for(int i = 0; i < N; ++i){
        H1[i] = F1[i] * G1[i] % mod1;
        H2[i] = F2[i] * G2[i] % mod2;
    }

    H1 = NTT(H1, 1, mod1), H2 = NTT(H2, 1, mod2);
    vector<int> ans = CRT(H1, H2);

    int out = 0;
    for(int i = 0; i <= n + m; ++i){
        out ^= ans[i];
    }
    cout << out << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
