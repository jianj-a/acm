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
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=100001;
ll ksm(ll a,ll n){
      ll ans=1;
      while(n){
       if(n&1)ans=ans*a%mod;
       a=a*a%mod;
         n/=2;
         }
   return ans;
 }
ll la(vector<int>x,vector<int>y,int k){//x=k时n-1次方程多项式求近似解
  int n=x.size();
  ll ans=0;
   for(int i=0;i<=n;i++){
        ll a=y[i],b=1;
      for(int j=0;j<=n;j++){
         if(i==j)continue ;
           a=a*(k-x[j])%mod;
           b=b*(x[i]-x[j])%mod;
        }
        b=(b+mod)%mod;
           a=(a+mod)%mod;
           ans=(ans+(a*ksm(b,mod-2)%mod)+mod)%mod;
         }
         return ans;
}
void solve(){
  
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
  // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}