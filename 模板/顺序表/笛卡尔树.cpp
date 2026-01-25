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
#define int ll
const ll INF = 1e18;
const int inf=INT_MAX;
const int maxn=10000001;
int n;
int a[maxn];
int ls[maxn];
int rs[maxn];
int st[maxn];
void build(){
    int top=0;
    for(int i=1;i<=n;i++){
        int pos=top;
        while(pos>0&&a[st[pos]]>a[i]){
            pos--;
        }
        if(pos>0){
            rs[st[pos]]=i;
        }    
        if(pos<top){
            ls[i]=st[pos+1];
        }
        st[++pos]=i;
        top=pos;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    ll ans1=0;
    ll ans2=0;
    for(int i=1;i<=n;i++){
        ans1=ans1^(i*(ls[i]+1));
        ans2=ans2^(i*(rs[i]+1));
    }
    cout<<ans1<<" "<<ans2<<endl;
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