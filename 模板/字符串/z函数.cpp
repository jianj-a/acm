#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ul = unsigned long long;
using i128 = __int128;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator<<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+1;
ll z[20000001]={};
ll p[20000001]={};
int len;
void z1(string s){
    int n=s.size();
    z[0]=n;
    for(ll i=1,c=1,r=1;i<n;i++){
    len=(r>i)?min(z[i-c],r-i):0;
    while(i+len<n&&s[i+len]==s[len]){
        len++;
    }
     if(i+len>r){
        r=i+len;
        c=i;
     }
     z[i]=len;
    }
}
void p1(string a,string b){
  int n=a.size();
  int m=b.size();
  for(ll i=0,c=0,r=0;i<m;i++){
    len=(r>i)?min(r-i,z[i-c]):0;
    while(len<n&&i+len<m&&a[len]==b[i+len]){
      len++;
    }
    if(i+len>r){
      r=i+len;
      c=i;
    }
    p[i]=len;
  } 
}
void solve(){
  string a,b;
  cin>>a>>b;
  z1(b);
  p1(b,a);
  ll ans1=0;
  for(ll i=0;i<b.size();i++){
    ans1=ans1^((i+1)*(z[i]+1ll*1));
  }
  cout<<ans1<<endl;
  ans1=0;
   for(ll i=0;i<a.size();i++){
    ans1^=((i+1ll*1)*(p[i]+1ll*1));
  }
  cout<<ans1<<endl;

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