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
const int maxn=100001;
int dfn[maxn];
int low[maxn];
vector<int>a[maxn];
int root;
int cnt=0;
bool iscut[maxn];
void tarjan(int i){
    dfn[i]=low[i]=++cnt;
    int son=0;
    for(auto v:a[i]){
        if(!dfn[v]){
            son++;
            tarjan(v);
            low[i]=min(low[i],low[v]);
            if(low[v]>=dfn[i]&&i!=root)iscut[i]=true;
        }
        else{
            low[i]=min(low[i],dfn[v]);
        }
    }
    if(i==root&&son>=2){
        iscut[i]=true;
    }
}
void solve(){
  int n,m;
  cin>>n>>m;
  while(m--){
    int x,y;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
   for(int i=1;i<=n;i++){
    root=i; 
    tarjan(i);
   }
   vector<int>ans;
   for(int i=1;i<=n;i++){
    if(iscut[i]){
        ans.push_back(i);
    }
   }
   cout<<ans.size()<<endl;
   for(auto v:ans){
    cout<<v<<" ";
   }
   cout<<endl;
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