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
    if(n>1){
        ans=ans/n*(n-1);
    }
    return ans;
}
int p[maxn];
int v[maxn]={};
int phi[maxn];
int cnt=0;
void init(){
    phi[1]=1;
    for(int i=2;i<maxn;i++){
        if(!v[i]){
            phi[i]=i-1;
            p[++cnt]=i;
        }
        for(int j=1;p[j]*i<maxn&&j<=cnt;j++){
            int m=i*p[j];
            v[m]=1;
            if(i%p[j]==0){
                phi[m]=phi[i]*p[j];
                break;
            }
            else{
                phi[m]=phi[i]*(p[j]-1);
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
    init();
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}