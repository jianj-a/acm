#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ul = unsigned long long;
using i128 = __int128;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator<<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+1;
const int maxn=100001;
int w[501];
int dis[501];
int v[501];
int book[501];
vector<int>a[501];
int n,m;
int dfs(int x){
    for(auto u:a[x]){
        if(!v[u]){
            v[u]=1;
            if(!book[u]||dfs(book[u])){
                book[u]=x;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    int min2=1e9;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        book[i]=0;
        min2=min(min2,w[i]);
    }
    for(int i=1;i<=n;i++){
        a[i].clear();
        cin>>dis[i];
    }
    if(dis[1]!=0){
        cout<<"NO"<<endl;
        return ;
    }
    map<int,int>mp;
    int mx=1e9;
    sort(dis+2,dis+n+1);
    mp[0]=1;
    for(int i=2;i<=n;mp[dis[i]]=1,i++){
        for(int j=1;j<=m;j++){
           if(mp.count(dis[i]-w[j])){
             a[i].emplace_back(j);
             mx=min(mx,w[j]);
           }
        }
     }
    if(mx!=min2){cout<<"NO"<<endl;return;}
    int ans=0;
     for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++)v[j]=0;
        ans+=dfs(i);
     }
     if(ans==n-1){
        cout<<"YES"<<endl;
        return ;
     }
     cout<<"NO"<<endl;
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
    cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}