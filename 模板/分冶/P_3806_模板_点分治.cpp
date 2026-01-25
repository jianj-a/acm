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
const int maxn=10005;
const int maxv=10000005;
int n,m;
struct node
{
  int v,w;
  /* data */
};
int ans[101]={};
vector<node>a[maxn];
int k[101];
int maxk=0;
int siz[maxn];
int vis[maxn];
void getsiz(int r,int pr){
  siz[r]=1; 
  for(auto [v,w]:a[r]){
    if(v==pr||vis[v])continue;
    getsiz(v,r);
    siz[r]+=siz[v];
  }
}
int getroot(int r,int pr){
  getsiz(r,pr);
  int h=siz[r]>>1;
  int find=0;
  while(!find){
    find=1;
    for(auto [v,w]:a[r]){
      if(v==pr||vis[v])continue;
      if(siz[v]>h){
        find=0;
        pr=r;
        r=v;
        break;
      }
    }
  }
  return r;
}
int cnta=0;
int ex[maxv]; 
int cnt[maxn];
int cntc;
void dfs(int r,int pr,int d){
  if(d>maxk){
    return ;
  }
  cnt[++cntc]=d;
  for(auto[v,w]:a[r]){
    if(vis[v]||v==pr)continue;
    dfs(v,r,d+w); 
  }
}
int all[maxv];
void cal(int r){
    cnta=0;
    ex[0]=1;
      for(auto [v,w]:a[r]){
        if(vis[v])continue;
        cntc=0;
        dfs(v,r,w);
        for(int i=1;i<=m;i++){
          for(int j=1;!ans[i]&&j<=cntc;j++){
              if(k[i]-cnt[j]>=0){
                // cerr<<cnt[j]<<endl;
                ans[i]|=ex[k[i]-cnt[j]];
              }
          }
        }
         for (int i = 1; i <= cntc; i++) {
                all[++cnta] = cnt[i];
               ex[cnt[i]] =1;
          }
      }
      for(int i=1;i<=cnta;i++){
        ex[all[i]]=0;
      }
}
void so(int r){
    vis[r]=1;
    cal(r); 
    for(auto [v,w]:a[r]){
      if(!vis[v]){
        so(v);  
      }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
      int u,v,w;
      cin>>u>>v>>w;
      a[u].push_back({v,w});
      a[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++){
      cin>>k[i];
      maxk=max(maxk,k[i]);
    }
    so(getroot(1,0));
    for(int i=1;i<=m;i++){
      if(ans[i]){
        cout<<"AYE"<<endl;
      }
      else{
        cout<<"NAY"<<endl;
      }
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