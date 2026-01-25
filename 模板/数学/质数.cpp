#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ull = unsigned long long;       
using i128 = __int128;    
using db=long double;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=1001;
#define ll i128
ll ksm(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret % mod;
}

vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isprime(ll n) {
    if(n < 3 || n % 2 == 0) return n == 2;
    ll u = n - 1, t = 0;
    while(u % 2 == 0) u /= 2, ++ t;
    for(auto a : p) {
        if(n == a) return 1;
        if(n % a == 0) return 0;
        ll v = ksm(a, u, n);
        if(v == 1) continue;
        ll s = 1;
        for(; s <= t; ++ s) {
            if(v == n - 1) break;
            v = v * v % n;
        }
        if(s > t) return 0; 
    }
    return 1;
}
int prime[maxn];
int cnt=0;
bool v[maxn]={false};
void olshai(){
   for(int i=2;i<maxn;i++){
       if(!v[i]){
         prime[++cnt]=i;
       }
       for(int j=1;j<=cnt;j++){
          if(i*prime[j]>maxn){
            break;
          }
          v[i*prime[j]]=true;
            if(i%prime[j]==0){
              break;
            }
       }
   }
   cout<<cnt<<endl;
}
void solve(){
      cout<<cnt<<endl;
}
signed main(signed argc,char const *argv[]){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
#endif 
    //======================
    int T;
    T=1;
   olshai();
   cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}