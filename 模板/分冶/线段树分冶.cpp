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
int n,m;
struct node
{
    int u,v,nx;
    /* data */
}eg[maxn*20];
int head[maxn*20]={};
int cnt=0;
void add(int u,int v,int x){
     eg[++cnt]={u,v,head[x]};
     head[x]=cnt;
}
int ls[5001][5001];
int op[maxn];
void add(int ql,int qr,int u,int v,int l,int r,int i){
     if(ql<=l&&qr>=r){
        add(u,v,i);
        return ;
     }
     int mid=(l+r)>>1;
     if(ql<=mid){
        add(ql,qr,u,v,l,mid,i<<1);
     }
     if(qr>mid){
        add(ql,qr,u,v,mid+1,r,i<<1|1);
     }
}
int u[maxn];
int v[maxn];
int fa[maxn];
int siz[maxn];
int st[maxn][2];
int cntd=0;
int find(int x){
    while(x!=fa[x]){
        x=fa[x];
    }
    return x;
}
void un(int a,int b){
     int pa=find(a);
     int pb=find(b);
     if(siz[pa]<siz[pb]){
        swap(pa,pb);
     }
     siz[pa]+=siz[pb];
      fa[pb]=pa;
      st[++cntd][0]=pa;
      st[cntd][1]=pb;
}
void undo(){
    int pa=st[cntd][0];
    int pb=st[cntd][1];
    cntd--;
    siz[pa]-=siz[pb];
    fa[pb]=pb;
}
char ans[maxn];
void dfs(int l,int r,int i){
        int tmp=0;
     for(int j=head[i];j>0;j=eg[j].nx){
         int x=eg[j].u;
         int y=eg[j].v;
         int pa=find(x);
         int pb=find(y);
         if(pa!=pb){
            un(pa,pb);
            tmp++;
         }
     }
     if(l==r){
        if(op[l]==2){
            int pa=find(u[l]);
            int pb=find(v[l]);
           if(pa==pb){
            ans[l]='Y';
           }
           else{
            ans[l]='N';
           }
        }
     }
     else{
        int mid=(l+r)/2;
        dfs(l,mid,i<<1);
        dfs(mid+1,r,i<<1|1);
     }
     for(int j=1;j<=tmp;j++){
        undo();
     }
}
void solve(){
    cin>>n>>m;
    iota(fa+1,fa+n+1,1);
    fill(siz+1,siz+n+1,1);
    for(int i=1;i<=m;i++){
        cin>>op[i];
        int a,b;
        cin>>a>>b;
        u[i]=min(a,b);
        v[i]=max(a,b);
        if(op[i]==0){
            ls[u[i]][v[i]]=i;
        }
        if(op[i]==1){
            add(ls[u[i]][v[i]],i-1,u[i],v[i],1,m,1);
            ls[u[i]][v[i]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        if(op[i]!=0)continue;
        if(ls[u[i]][v[i]]!=0){
            add(ls[u[i]][v[i]],m,u[i],v[i],1,m,1);
            ls[u[i]][v[i]]=0;
        }
    }
    dfs(1,m,1);
    for(int i=1;i<=m;i++){
        if(op[i]==2){
            cout<<ans[i]<<endl;
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