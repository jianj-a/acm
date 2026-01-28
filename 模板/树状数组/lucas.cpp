#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
#define il inline
using ull = unsigned long long;       
using i128 = __int128;    
using ldb=long double;
using db=double;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=998244353;
const ll INF = 1e18;
#define int ll
const int inf=1e9+7;
const int maxn=100005;
//求c(n,m)%p,n,m是大数，p是小质数
int fac[maxn];
int inv[maxn];
int ksm(int a,int n,int p){
    int ans=1;
    while(n){
        if(n&1)ans=ans*a%p;
        n/=2;
        a=a*a%p;
    }
    return ans;
}
void init(int p){
    fac[0]=inv[0]=1;
    for(int i=1;i<=p;i++){
        fac[i]=fac[i-1]*i%p;
        inv[i]=ksm(fac[i],p-2,p);
    }
}
int C(int n,int m,int p){
    if(n<m){
        return 0;
    }
    return fac[n]*inv[n-m]%p*inv[m]%p;
}
int lucas(int n,int m,int p){
    if(n<m){
        return 0;
    }
    if(m==0)return 1;
    return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
void solve(){
    int n,m,p;
    cin>>n>>m>>p;
    init(p);
    cout<<lucas(n+m,n,p)<<endl;
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