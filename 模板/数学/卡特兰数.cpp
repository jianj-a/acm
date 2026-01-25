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
const int mod=998244353;
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=2000001;
#define int ll
// c(2n,n)-c(2n,n-1);
//c(2n,n)/(n+1)
//f(n-1)*(4n-2)/(n+1)
// 所有i n-i-1;
ll fac[maxn];
ll inv[maxn];
ll ksm(ll a,ll n,int p){
    ll ans=1;
    while(n){
        if(n&1)ans=ans*a%p;
        n/=2;
        a=a*a%p;
    }
    return ans;
}
ll ksm(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)ans=ans*a%mod;
        n/=2;
        a=a*a%mod;
    }
    return ans;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=i*fac[i-1]%mod;
    }
    inv[maxn-1]=ksm(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll c(int n,int m){
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
ll kai1(int n){
    return (c(2*n,n)-c(2*n,n-1)+mod)%mod;
}
ll kai2(int n){
        vector<int>f(n+1);
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=n;i++){
            for(int l=0,r=i-1;l<=i-1;l++,r--){
                f[i]=(f[i]+f[l]*f[r]%mod)%mod;
            }
        }
        return f[n];
}
ll kai3(int n){
    return (c(2*n,n)*ksm(n+1,mod-2))%mod;
}
int prime[maxn];
int minpf[maxn]={};
int cnt=0;
void ola(){
    cnt=0;
    for(int i=2;i<maxn;i++){
        if(minpf[i]==0){
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>=maxn)break;
            minpf[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
ll kai3(int n,int p){
    ola();
    vector<int>f(2*n+1);
    for(int i=2;i<=n;i++){
        f[i]=-1;
    }
    for(int i=n+2;i<=2*n;i++){
        f[i]=1;
    }
    for(int i=2*n;i>=1;i--){
        if(minpf[i]==0)continue;
        f[minpf[i]]+=f[i];
        f[i/minpf[i]]+=f[i];
        f[i]=0;
    }
    ll ans=1;
    for(int i=1;i<=2*n;i++){
        if(f[i]){
            ans=(ans*ksm(i,f[i],p))%p;
        }
    }
    return ans;
}
// vector<int>p;
// ll oiji()
// ll kai32(int n){
//     vector<int>f(2*n+1);
//     for(int i=2*n;i>=n-2;i--){

//     }
// }
ll kai4(int n){
    vector<int>f(n+1);
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]*ksm(i+1,mod-2)%mod*(4*i-2)%mod;
    }
    return f[n];
}
void solve(){
     for(int i=1;i<maxn;i++){
        cout<<kai1(i)<<endl;
     }
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
  // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}