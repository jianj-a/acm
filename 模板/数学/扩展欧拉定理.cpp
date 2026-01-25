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
//a的b次方模m
#define int ll
int get(int n){
  int ans=n;
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      ans=ans/i*(i-1);
      while(n%i==0){
        n/=i;
      }
    }
  }
  if(n!=1){
    ans=ans/n*(n-1);
  }
  return ans;
}
int ksm(int a,int n,int m){
   int ans=1;
  while(n){
    if(n&1)ans=ans*a%m;
    n/=2;
    a=a*a%m;
  }
  return ans;
}
int depow(int p,string s){
   int ans=0;
   int v=0;
   for(int i=0;i<s.size();i++){
    ans=ans*10+(s[i]-'0');
    if(ans>=p){
      ans%=p;
      v=1;
    }
   }
   if(v){
     ans+=p;
   }
   return ans;
}

void solve(){
   int a,m;
   string s;
   cin>>a>>m>>s;
   int phi=get(m);
  int b=depow(phi,s);
  cout<<ksm(a,b,m)<<endl;
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
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}