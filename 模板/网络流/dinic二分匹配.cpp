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
const int maxn=1010;
const int maxm=50001*5;
int n,m,e;
int s,t;
struct node 
{
    int v,w,nx;
    /* data */
}eg[maxm];
int cnt=1;
int head[maxn]={};
void add(int u,int v,int w){
    eg[++cnt]={v,w,head[u]};
    head[u]=cnt;
}
int d[maxn];
int cur[maxn];
bool bfs(){
    memset(d,0,sizeof(d));
    queue<int>q;
    d[s]=1;
    cur[s]=head[s];
    q.push(s);
    while(!q.empty()){
        auto id=q.front();
        q.pop();
        for(int i=head[id];i;i=eg[i].nx){
             int v=eg[i].v;
             if(d[v]==0&&eg[i].w>0){
                d[v]=d[id]+1;
                cur[v]=head[v];
                if(v==t)return 1;
                q.push(v);
             }
        }
    }
    return 0;
}
int dfs(int u,int mf){
    if(u==t)return mf;
    int sum=0;
    for(int i=cur[u];i&&mf;i=eg[i].nx){
        cur[u]=i;
        int v=eg[i].v;
        if(d[v]==d[u]+1&&eg[i].w){
            int k=dfs(v,min(mf,eg[i].w));
            eg[i].w-=k;
            eg[i^1].w+=k;
            sum+=k;
            mf-=k;
        }
    }
    if(sum==0)d[u]=0;
    return sum;
}
void solve(){
    cin>>n>>m>>e;
    while(e--){
        int u,v;
        cin>>u>>v;
        add(u,v+n,1);
        add(v+n,u,0);
    }
     s=0,t=n+m+1;
    for(int i=1;i<=n;i++){
        add(s,i,1);
        add(i,s,0);
    }
    for(int i=1;i<=m;i++){
        add(i+n,t,1);
        add(t,i+n,0);
    }
    int ans=0;
    while(bfs()){
        ans+=dfs(s,inf);
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
    while(T--)
    {
      solve();
    }
    //======================
}