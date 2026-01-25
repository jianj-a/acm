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
const int maxn=500005;
int n,m,k;
int eg[maxn][2];
struct node
{
  int u,tu,v,tv;
  /* data */
}a[2*maxn];
int cnt=0;
int fa[2*maxn];
int siz[2*maxn];
int find(int x){
  while(x!=fa[x]){
    x=fa[x];
  }
  return x;
}
int st[2*maxn][2];
int cntd=0;
void un(int a,int b){
    int pa=find(a);
    int pb=find(b);
    if(siz[pa]<siz[pb]){
      swap(pa,pb);
    }
    fa[pb]=pa;
    siz[pa]+=siz[pb];
    st[++cntd][0]=pa;
    st[cntd][1]=pb;
}
void undo(){
   int pa=st[cntd][0];
   int pb=st[cntd][1];
   cntd--;
   fa[pb]=pb;
   siz[pa]-=siz[pb];
}
void solve(){
    cin>>n>>m>>k;
    vector<int>c(n+1);
    for(int i=1;i<=n;i++){
      cin>>c[i];
    }
    for(int i=1;i<=m;i++){
      cin>>eg[i][0]>>eg[i][1];
    }
    iota(fa+1,fa+2*n+1,1);
    fill(siz+1,siz+2*n+1,1);
    vector<int>f(k+1);
    for(int i=1;i<=m;i++){
       int u=eg[i][0];
       int v=eg[i][1];
       if(c[u]>c[v]){
           a[++cnt]={v,c[v],u,c[u]};
       }
       else if(c[v]>c[u]){
           a[++cnt]={u,c[u],v,c[v]};
       }
       else{
          if(f[c[v]]){
            continue;
          }
          if(find(u)==find(v)){
             k--;
             f[c[v]]=1;
          }
          else{
             un(u,v+n);
             un(v,u+n);
          }
       }
    }
    ll ans=1ll*k*(k-1)/2;
    auto cmp=[&](node a,node b){
      if(a.tu==b.tu){
        return a.tv<b.tv;
      }
      return a.tu<b.tu;
    };
    sort(a+1,a+cnt+1,cmp);
    for(int l=1,r=1;r<=cnt;l=++r){
       auto [u,tu,v,tv]=a[l];
        while(r+1<=cnt&&a[r+1].tu==tu&&a[r+1].tv==tv){
          r++;
        }
        if(f[tu]||f[tv]){
          continue;
        }
        int tmp=0;
        for(int i=l;i<=r;i++){
             u=a[i].u;
             v=a[i].v;
             if(find(u)==find(v)){
               ans--;
               break;
             }
             else{
               un(u,v+n);
               un(v,u+n);
               tmp+=2;
             }
        }
        for(int i=1;i<=tmp;i++){
          undo();
        }
    }
    cout<<ans<<endl;
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
   // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}