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
int x,y;  
int exgcd(int a,int b){
    if(b==0){
      x=1;
      y=0;
      return a;
    }
    int g=exgcd(b,a%b);
    int px=x;
    int py=y;
    x=py;
    y=px-(a/b)*py;
    return g;
}
int exgcdk(vector<int>a,vector<int>b,int n){
   int lcm=1;
   int t=0;
    for(int i=1;i<=n;i++){
        int a1=lcm;
        int b1=a[i];
        int c1=(b[i]-t);
        int g=exgcd(a1,b1);
        if(c1%g!=0){
          return -1;
        }
        x=((i128)x*(c1/g)%(b1/g)+b1/g)%(b1/g);
        int tmp=lcm*(b1/g);
        t=(t+(i128)(x*lcm)%tmp)%tmp;
        lcm=tmp;
    }
    return t;
}
void solve(){
   int n;
   cin>>n;
   vector<int>a(n+1);
   vector<int>b(n+1);
   for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
   }
   cout<<exgcdk(a,b,n)<<endl;
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