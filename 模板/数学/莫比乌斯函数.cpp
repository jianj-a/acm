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
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=100005;
int mu[maxn];
int vis[maxn]={};
int p[maxn];
int cnt=0;
void init(){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt;j++){
            int m=p[j]*i;
            vis[m]=1;
            if(i%p[j]==0){
                mu[m]=0;
                break;
            }
            else{
                mu[m]=-mu[i];
            }
        }
    }
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
    //  cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}