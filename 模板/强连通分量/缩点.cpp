#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ull = unsigned long long;       
using i128 = __int128;    
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=INT_MAX;
const int maxn=10001;
int n,m;
vector<int>a[maxn];
int w[maxn];
int dfn[maxn];
int low[maxn];
int cnt=0;
vector<int>to[maxn];
int bcnt=0;
int bsum[maxn];
int st[maxn];
int tot=0;
bool inst[maxn];
int belong[maxn];
int dp[maxn];

void targan(int u){
    dfn[u]=low[u]=++cnt;
    st[++tot]=u;
    inst[u]=true;
    for(auto v:a[u]){
        if(!dfn[v]){
            targan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++bcnt;
        int p;
        do{
            p=st[tot--];
            inst[p]=false;
            belong[p]=bcnt;
            bsum[bcnt]+=w[p];
        }
        while(p!=u);
    }
}
int dfs(int u){
    if(~dp[u])return dp[u];
    dp[u]=bsum[u];
    for(auto v:to[u]){
        dp[u]=max(dp[u],bsum[u]+dfs(v));
    }
    return dp[u];
}
void solve(){
  cin>>n>>m;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
    cin>>w[i];
  }
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    a[u].push_back(v);
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
        targan(i);
    }
  }
  for(int i=1;i<=n;i++){
    int bu=belong[i];
    for(auto v:a[i]){
        if(bu!=belong[v]){
            to[bu].push_back(belong[v]);
        }
    }
  }
  int ans=0;
  for(int i=1;i<=bcnt;i++){
    ans=max(ans,dfs(i));
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