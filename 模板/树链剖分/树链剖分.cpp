#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ull = unsigned long long;
using i128 = __int128;    
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator<<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1e18;
const int inf=1e9+1;
const int maxn=100001*4;
int n,m,root,mod;
int p[maxn];
vector<int>a[maxn];
int son[maxn];
int siz[maxn];
int dfn[maxn];
int deep[maxn];
int top[maxn];
int seg[maxn];
int fa[maxn];
int sum[maxn];
int tag[maxn];
void dfs1(int r,int pr){
    deep[r]=deep[pr]+1;
    fa[r]=pr;
    siz[r]=1;
    for(auto v:a[r]){
      if(v==pr){
        continue ;
      }
      dfs1(v,r);
    }
    for(auto v:a[r]){
      if(v==pr){
        continue ;
      }
      siz[r]+=siz[v];
      if(son[r]==0||siz[son[r]]<siz[v]){
        son[r]=v;
      }
    }
}
int cnt=0;
void dfs2(int u,int t){
  top[u]=t;
  dfn[u]=++cnt;
  seg[cnt]=u;
  if(son[u]==0){
    return ;
  }
  dfs2(son[u],t);
  for(auto v:a[u]){
    if(v!=fa[u]&&v!=son[u]){
      dfs2(v,v);
    }
   
  }
}
void up(int i){
  sum[i]=(sum[i*2]+sum[i*2+1])%mod;
}
void lazy(int i,ll v,int n){
    sum[i]=(sum[i]+v*n)%mod;
    tag[i]=(tag[i]+v)%mod;
}
void down(int i,int in,int rn){
  if(tag[i]!=0){
    int l=i*2;
    int r=i*2+1;
    lazy(l,tag[i],in);
    lazy(r,tag[i],rn);
    tag[i]=0;
  }
}
void build(int l,int r,int i){
    tag[i]=0;
  if(l==r){
    sum[i]=p[seg[l]]%mod;
    return ;
  }
  int mid=l+r>>1;
  build(l,mid,i*2);
  build(mid+1,r,i*2+1);
  up(i);
}
void add(int ql,int qr,int l,int r,int i,int v){
  if(ql<=l&&qr>=r){
    lazy(i,v,r-l+1);
  }else{
    int mid=l+r>>1;
    down(i,mid-l+1,r-mid);
    if(ql<=mid){
      add(ql,qr,l,mid,i*2,v);
    }
    if(qr>mid){
      add(ql,qr,mid+1,r,i*2+1,v);
    }
    up(i);
  }
}
ll query(int ql,int qr,int l,int r,int i){
  if(ql<=l&&qr>=r){
    return sum[i];
  }
  else{
    int mid=l+r>>1;
    down(i,mid-l+1,r-mid);
    ll ans=0;
    if(ql<=mid){
      ans+=query(ql,qr,l,mid,i*2);
      ans%=mod;
    }
    if(qr>mid){
      ans+=query(ql,qr,mid+1,r,i*2+1);
      ans%=mod;
    }
    return ans;
  }
}
void pathadd(int x,int y,int v){
   while(top[x]!=top[y]){
    if(deep[top[x]]<=deep[top[y]]){
        add(dfn[top[y]],dfn[y],1,n,1,v);
        y=fa[top[y]];
    }
    else{
        add(dfn[top[x]],dfn[x],1,n,1,v);
        x=fa[top[x]];
    }
   }
   add(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,1,v);
}
ll pathquery(int x,int y){
  ll ans=0;
  while(top[x]!=top[y]){
    if(deep[top[x]]<=deep[top[y]]){
        ans+=query(dfn[top[y]],dfn[y],1,n,1);
        ans%=mod;
        y=fa[top[y]];
    }
    else{
        ans+=query(dfn[top[x]],dfn[x],1,n,1);
        ans%=mod;
        x=fa[top[x]];
    }
   }
   ans+=query(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,1);
   return ans%mod;
}
void solve(){
  cin>>n>>m>>root>>mod;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs1(root,0);
  dfs2(root,root);
  build(1,n,1);
  int op,x,y,z;
  while(m--){
    cin>>op;
    if(op==1){
      cin>>x>>y>>z;
      pathadd(x,y,z); 
    }
    else if(op==2){
      cin>>x>>y;
      cout<<pathquery(x,y)<<endl;
    }
    else if(op==3){
       cin>>x>>z;
       add(dfn[x],dfn[x]+siz[x]-1,1,n,1,z);
    }
    else{
      cin>>x;
      cout<<query(dfn[x],dfn[x]+siz[x]-1,1,n,1)<<endl;
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
  // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}