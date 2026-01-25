#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
#define il inline
using ull = unsigned long long;       
using i128 = __int128;    
using db=long double;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+7;
#define int ll
const int maxn=100005;
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
int bmul(int a,int b,int m){
  ull c=(ull)a*(ull)b-(ull)((long double)a/m*b+0.5L)*(ull)m;
  if(c<(ull)m)return c;
  return c+m;//负数
}
int ksm(int a,int n,int m){
  int ans=1;
  while(n){
    if(n&1)ans=bmul(ans,a,m);
    a=bmul(a,a,m);
    n/=2;
  }
  return ans;
}
bool isprime(int n){
  if(n<2){
    return false;
  }
  if(n==2||n==3){
    return true;
  }
  int d=n-1,r=0;
  while(!(d&1)){
    ++r;
    d>>=1;
  }
  for (ll k = 0; k < 10; ++k) {
    ll a = rand() % (n - 2) + 2;
    ll x = ksm(a, d, n);
    if (x == 1 || x == n - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = bmul(x, x, n);
      if (x == n - 1) break;
    }
    if (x != n - 1) return false;
  }
  return true;
}
ll Pollard_Rho(ll x) {
  ll s = 0, t = 0;
  ll c = (ll)rand() % (x - 1) + 1;
  int step = 0, goal = 1;
  ll val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {  // 倍增优化
    for (step = 1; step <= goal; ++step) {
      t = (bmul(t, t, x) + c) % x;
      val = bmul(val, abs(t - s), x);
      if ((step % 127) == 0) {
        ll d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    ll d = gcd(val, x);
    if (d > 1) return d;
  }
}
int max_factor=0;
void fac(ll x) {
  if (x <= max_factor || x < 2) return;
  if (isprime(x)) {              // 如果x为质数
    max_factor = max(max_factor, x);  // 更新答案
    return;
  }
  ll p = x;
  while (p >= x) p = Pollard_Rho(x);  // 使用该算法
  while ((x % p) == 0) x /= p;
  fac(x), fac(p);  // 继续向下分解x和p
}

void solve(){
  max_factor=0;
  int n;
      cin>>n;
      fac(n);
      if (max_factor == n)  
      cout << "Prime\n";
    else
      cout << max_factor << '\n'; 
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
    cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}