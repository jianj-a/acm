#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
#define il inline
using ull = unsigned long long;       
using i128 = __int128;    
using db=long double;
#define int ll
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=998244353;
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=100005;
//   f=前n项(a*i+b)/c
//   h是平方
//   g是前面✖i
// int f(int a,int b,int c,int n){
//   int n2=n*(n+1)/2; 
//   if(a>=c||b>=c){
//       return (a/c)*n2+(b/c)*(n+1)+f(a%c,b%c,c,n);
//   }
//    if(a==0){
//     return (b/c)*(n+1);
//   }
//   int m=(a*n+b)/c;
//   if(m==0)return 0;
//   return m*n-f(c,c-b-1,a,m-1);
// }
struct node
{
  int f,h,g;
  /* data */
};
const int inv2=(mod+1)/2;
const int inv6=(mod+1)/6;
node f(int a,int b,int c,int n){
    int n2=n*(n+1)%mod*inv2%mod;
    int n3=n*(n+1)%mod*inv6%mod*(2*n+1)%mod;
       node res={0,0,0};
    if(a>=c||b>=c){
          auto tmp=f(a%c,b%c,c,n);
          int aa=a/c;
          int bb=b/c;
          res.f=(tmp.f+aa*n2%mod+bb*(n+1)%mod)%mod;
          res.h=(tmp.h+2*bb*tmp.f%mod+2*aa*tmp.g%mod+aa*aa%mod*n3%mod+bb*bb%mod*(n+1)%mod+2*aa*bb%mod*n2%mod)%mod;   
          res.g=(tmp.g+aa*n3%mod+bb*n2)%mod;
          return res;
    }
    int m=(a*n+b)/c;
    if(!m)return res;
    auto tmp=f(c,c-b-1,a,m-1);
    res.f=(n*m%mod+mod-tmp.f)%mod;
    res.g=(m*n2%mod+mod-tmp.f*inv2%mod+mod-tmp.h*inv2%mod)%mod;
    res.h=(n*m%mod*m%mod+3*mod-2*tmp.g-tmp.f)%mod;
    return res;
}
void solve(){
   int n,c,a,b;
   cin>>n>>a>>b>>c;
   auto ans=f(a,b,c,n);
   cout<<ans.f<<" "<<ans.h<<" "<<ans.g<<endl;
  // cout<<f(a,b,c,n)%mod<<" "<<h(a,b,c,n)%mod<<" "<<g(a,b,c,n)%mod<<endl;
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