#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
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
const int maxn=300001;
vector<int>a[maxn];
int p[maxn];
int deep[maxn]={};
int bit;
int stump[maxn][30]={};
int w[maxn]={};
void dfs(int r,int pr){
    deep[r]=deep[pr]+1;
    stump[r][0]=pr;
    for(int i=1;i<=bit;i++){
        stump[r][i]=stump[stump[r][i-1]][i-1];
    }
    for(auto v:a[r]){
        if(v==pr)continue;
        dfs(v,r);
    }
}
int lca(int a,int b){
    if(deep[a]<deep[b]){
        swap(a,b);
    }
    for(int i=bit;i>=0;i--){
        if(deep[stump[a][i]]>=deep[b]){
            a=stump[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=bit;i>=0;i--){
        if(stump[a][i]!=stump[b][i]){
            a=stump[a][i];
            b=stump[b][i];
        }
    }
    return stump[a][0];
}

void solve(){
      int n;
      cin>>n;
      bit=log2(n);
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