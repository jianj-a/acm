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
const int maxn=200001;
const int maxm=501;
#define int ll
struct node
{
  int op,x,t,v,q;
  /* data */
}b[maxn];
int tim[maxn];
int tag[maxm];
int sv[maxn];
int n,m;
int a[maxn];
int bi[maxn];
int bl[maxm];
int br[maxm];
int len;
int num;
int cnt=0;
int cnt1=0;
void add(int t,int x,int k){
  b[++cnt].op=1;  
  b[cnt].x=x;  
  b[cnt].t=t;  
  b[cnt].v=k;  
}
void addquery(int t,int x,int k){
  b[++cnt].op=2;  
  b[cnt].x=x;  
  b[cnt].t=t;  
  b[cnt].v=k;
  b[cnt].q=++cnt1;  
}
void build(){
    len=sqrt(m);
    num=(m+len-1)/len;
    for(int i=1;i<=m;i++){
      bi[i]=(i-1)/len+1;
    }
    for(int i=1;i<=num;i++){
      bl[i]=(i-1)*len+1;
      br[i]=min(i*len,m);
    }
    auto cmp=[&](node a,node b){
      if(a.x==b.x){
        return a.t<b.t;
      } 
      return a.x<b.x;
    };
    sort(b+1,b+cnt+1,cmp);
}
void inadd(int l,int r,int v){
  for(int i=l;i<=r;i++){
    tim[i]+=v;
  }
  for(int i=bl[bi[l]];i<=br[bi[l]];i++){
    sv[i]=tim[i];
  }
  sort(sv+bl[bi[l]],sv+br[bi[l]]+1);
}
void add1(int l,int r,int v){
  if(bi[l]==bi[r]){
    inadd(l,r,v);
    return ;
  }
  inadd(l,br[bi[l]],v);
  inadd(bl[bi[r]],r,v);
  for(int i=bi[l]+1;i<bi[r];i++){
      tag[i]+=v;
  }
}
int inquery(int l,int r,int v){
  int ans=0;
  v-=tag[bi[l]];
  for(int i=l;i<=r;i++){
    if(tim[i]>=v){
        ans++;  
    }
  }
  return ans;
}
int getcnt(int i,int v){
   int ans=lower_bound(sv+bl[i],sv+br[i]+1,v)-sv;
    if(ans>br[i]){
      return 0;
    }
    return br[i]-ans+1;
}
int query(int l,int r,int v){
  int ans=0;
  if(bi[l]==bi[r]){
    ans+=inquery(l,r,v);
    return ans;
  }
  ans+=inquery(l,br[bi[l]],v);
  ans+=inquery(bl[bi[r]],r,v);
  for(int i=bi[l]+1;i<bi[r];i++){
    ans+=getcnt(i,v-tag[i]);  
  }
  return ans; 
}
void solve(){
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    int op,l,r,x;
    for(int i=2;i<=m;i++){
        cin>>op;
        if(op==1){
          cin>>l>>r>>x;
          add(i,l,x);
          add(i,r+1,-x);
        }
        else{
          cin>>l>>x;
          addquery(i,l,x);
        }
    }
    build();
    vector<int>ans(cnt1+1);
    for(int i=1;i<=cnt;i++){
      if(b[i].op==1){
        add1(b[i].t,m,b[i].v);  
      }
      else{
        ans[b[i].q]=query(1,b[i].t-1,b[i].v-a[b[i].x]);
      }
    }
    for(int i=1;i<=cnt1;i++){
      cout<<ans[i]<<endl; 
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