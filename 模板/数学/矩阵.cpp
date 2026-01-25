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
const int maxn=100001;
const int N=3;
#define int ll
// 矩阵快速幂可以解决合并问题，包括加减，最小和，最大和

ll ksm(int a,int n){
   ll ans=1;
   while(n){
    if(n&1)ans=ans*a%mod;
    n/=2;
    a=a*a%mod;
   }
   return ans;
}
struct mat
{
  int a[N][N]={};
  /* data */
  void build(){
    for(int i=0;i<N;i++){
      a[i][i]=1;
    }
  }
  friend mat operator*(mat a,mat b){
    mat c;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
          c.a[i][j]=(c.a[i][j]+(a.a[i][k]*b.a[k][j]%mod))%mod;//这个地方可以改
          
        }
      }
    }
    return c;
  }
};
mat ksm(mat a,int n){
  mat b;
  b.build();
  while(n){
    if(n&1)b=b*a;
    a=a*a;
    n/=2;
  }
  return b;
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
   cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}