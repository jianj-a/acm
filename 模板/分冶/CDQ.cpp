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
const int maxn=200005;
struct node
{
  int a,b,c,i;
  /* data */
}a[maxn];
int n,k;
node tmp[maxn];
int tree[maxn];
int low(int i){return i&(-i);}
void add(int i,int x){
     while(i<=k){
      tree[i]+=x;
      i+=low(i);
     }
}
int sum(int i){
  int ans=0;
  while(i>0){
    ans+=tree[i];
    i-=low(i);
  }
  return ans;
}
int ans[maxn]={};
void merge(int l,int mid,int r){
    int cnt=l;
    int i,j;
    for(i=l,j=mid+1;j<=r;j++){
        while(i<=mid&&a[i].b<=a[j].b){
          add(a[i].c,1);
          tmp[cnt++]=a[i];
          i++;
        }
        tmp[cnt++]=a[j];
        ans[a[j].i]+=sum(a[j].c);
    }
    for(int k=i-1;k>=l;k--){
        add(a[k].c,-1);
    }
    while(i<=mid){
      tmp[cnt++]=a[i];
      i++;
    }
    for(int k=l;k<=r;k++){
      a[k]=tmp[k];
    }
}
void f(int l,int r){
  if(l==r){
    return ;
  }
  int mid=l+r>>1;
  f(l,mid);
  f(mid+1,r);
  merge(l,mid,r);
}
void solve(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
    cin>>a[i].a>>a[i].b>>a[i].c;
    a[i].i=i;
   }
   auto cmp=[&](node a,node b){
     if(a.a!=b.a){
      return a.a<b.a;
     }
     if(a.b!=b.b){
      return a.b<b.b;
     }
     return a.c<b.c;
   };
   sort(a+1,a+n+1,cmp);
   for(int i=1,j=1;i<=n;i=++j){
      while(j<n&&a[j+1].a==a[i].a&&a[j+1].b==a[i].b&&a[j+1].c==a[i].c){
        j++;
      }
      for(int k=i;k<=j;k++){
        ans[a[k].i]+=j-k;
      }
   }
  //    for(int i=1;i<=n;i++){
  //   cerr<<ans[i]<<" 5"<<endl;
  //  }
   f(1,n);
   vector<int>cnt(n+1);
  //  cerr<<n<<endl;
  //  int c=0;
   for(int i=1;i<=n;i++){
    cnt[ans[i]]++;
    // cerr<<ans[i]<<" 5"<<endl;
   }  
   for(int i=0;i<=n-1;i++){
    // c+=cnt[i];
    cout<<cnt[i]<<endl;
   }
  //  cout<<c<<endl;
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
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}