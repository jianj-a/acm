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
const int maxn=500005;
int low(int i){
    return i&(-i);
}
int n,m;
int tree[maxn];
void add(int i,int x){
    while(i<=n){
        tree[i]+=x;
        i+=low(i);
    }
}
int query(int i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=low(i);
    }
    return ans;
}
void solve(){
      cin>>n>>m;
      for(int i=1;i<=n;i++){
        tree[i]=0;
      }
      for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(i,x);
        add(i+1,-x);
      }
      int op,x,k,y;
      while(m--){
            cin>>op;
            if(op==1){
                cin>>x>>y>>k;
                add(x,k);
                add(y+1,-k);
            }
            else{
                cin>>x;
                cout<<query(x)<<endl;
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