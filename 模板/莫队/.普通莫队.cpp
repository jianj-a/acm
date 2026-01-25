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
const int maxn=30001;
const int maxm=200001;
struct node
{
    int l,r;
    int id;
}b[maxm];

int a[maxn];
int n,q;    
int bi[maxm];
int an[maxm];
void prepare(){
    int len=sqrt(q);
    for(int i=1;i<=q;i++){
        bi[i]=(i-1)/len+1;
    }
    auto cmp=[&](node a,node b){
        if(bi[a.l]!=bi[b.l]){
            return bi[a.l]<bi[b.l];
        }
        if((bi[a.l]&1)==1){
            return a.r<b.r;
        }
        else{
            return a.r>b.r;
        }
    };
    sort(b+1,b+q+1,cmp);
}
int cnt[1000001]={};
int ans=0;
void add(int x){
    // cerr<<cnt[x]<<" "<<x<<endl;
    cnt[x]++;
    if(cnt[x]==1){
        ans++;
    }
}
void del(int x){
    cnt[x]--;
    if(cnt[x]==0){
        ans--;
    }
}
void solve(){
      cin>>n;
      for(int i=1;i<=n;i++){
        cin>>a[i];
      }
      cin>>q;
      for(int i=1;i<=q;i++){
            cin>>b[i].l>>b[i].r;
            b[i].id=i;
      }
      prepare();
      int l=1,r=0;
      for(int i=1;i<=q;i++){
          while(l>b[i].l){
            add(a[--l]);
          }
          while(r<b[i].r){
            add(a[++r]);
          }
          while(l<b[i].l){
            del(a[l++]);
          }
          while(r>b[i].r){
            del(a[r--]);
          }
          an[b[i].id]=ans;
      }
      for(int i=1;i<=q;i++){
        cout<<an[i]<<endl;
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