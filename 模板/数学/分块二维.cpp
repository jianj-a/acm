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
const int maxn=100009;
void solve(){
   int n;
   cin>>n;
   int v=1;
   vector<int>a(n+1);
   for(int i=1;i<=n;i++){
    cin>>a[i];
    v=max(v,a[i]);
   }
   vector<ll>ans(v+1);
   for(int i=0;i<n;i++){
    for(int l=1,r;;l=r+1){
        r=min(l<a[i]?(a[i]-1)/((a[i]-1)/l):v,l<a[i+1]?(a[i+1]-1)/((a[i+1]-1)/l):v);
        if(r==v){
          break;
        }
        int x=(a[i+1]-1)/l-max(a[i]-1,0)/l;
        if(x>0){
        ans[l]+=x;
        ans[r+1]-=x;
        }
    }
   }
  ++ans[0];
   for(int i=1;i<=v;i++){
     ans[i]+=ans[i-1];
     cout<<ans[i]<<" \n"[i==v];
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
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}