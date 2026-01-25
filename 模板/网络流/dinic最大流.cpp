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
const int maxn=501;
const int maxm=5005*2;
int n,m,s,t;
struct node
{
    int v,nx;
    ll c;
    /* data */
};
node eg[maxm];
int head[maxm];
int cur[maxm];
int cnt=1;
il void add(int u,int v,ll x){
    eg[++cnt].v=v;
    eg[cnt].nx=head[u];
    eg[cnt].c=x;
    head[u]=cnt;
    eg[++cnt].v=u;
    eg[cnt].nx=head[v];
    eg[cnt].c=0;
    head[v]=cnt;
}
ll ans=0;
int d[maxn];
il bool bfs(){
    memset(d,0,sizeof(d));
    queue<int>q;
    d[s]=1;
    q.push(s);
    cur[s]=head[s];
    while(!q.empty()){
        auto id=q.front();
        q.pop();
        for(int i=head[id];i;i=eg[i].nx){
            if(d[eg[i].v]==0&&eg[i].c!=0){
                d[eg[i].v]=d[id]+1;
                cur[eg[i].v]=head[eg[i].v];
                // q.push(eg[i].v);
                if(eg[i].v==t)return 1;
                 q.push(eg[i].v);
            }
        }   
    }
    return 0;
}
il ll dfs(int u,ll mf){
    if(u==t){
        return mf;
    }
    ll sum=0;
    for(int i=cur[u];i;i=eg[i].nx){
        cur[u]=i;
        int v=eg[i].v;
        if(d[v]==d[u]+1&&eg[i].c!=0){
            ll f=dfs(v,min(mf,eg[i].c));
            eg[i].c-=f;
            eg[i^1].c+=f;
            sum+=f;
            mf-=f;
            if(mf==0){
                break;
            }
        }
    }
    if(sum==0)d[u]=0;
    return sum;
}
void solve(){
  cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    ans=0;
    while(bfs()){
        ans+=dfs(s,INF);
        // cerr<<ans<<endl;
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