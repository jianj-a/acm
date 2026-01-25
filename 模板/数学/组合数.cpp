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
const int maxn=100005;
#define int ll
int ksm(int a,int n){
    int ans=1;
    while(n){
        if(n&1)ans=ans*a%mod;
        a=a*a%mod;
        n/=2;
    }
    return ans;
} 
int fac[maxn];
int inv[maxn];
void init(){
    fac[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[maxn-1]=ksm(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
int C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
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
    init();
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}