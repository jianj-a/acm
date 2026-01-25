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
const int maxt=100001*33;
ll a[maxn]={};
int root[maxn]={};
int ls[maxt]={};
int rs[maxt]={};
ll sum[maxt]={};
ll tag[maxt]={};
int cnt=0;
int n,m;
int t=0;
int build(int l,int r){
    int rt=++cnt;
    tag[rt]=0;
    if(l==r){
        sum[rt]=a[l];
    }
    else{
        int mid=(l+r)>>1;
        ls[rt]=build(l,mid);
        rs[rt]=build(mid+1,r);
        sum[rt]=sum[ls[rt]]+sum[rs[rt]];
    }
    return rt;
}
int add(ll ql,ll qr,ll l,ll r,int i,ll k){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    ll a=max(ql,l);
    ll b=min(qr,r);
    sum[rt]=sum[i]+(b-a+1)*k;
    tag[rt]=tag[i];
    if(ql<=l&&qr>=r){
        tag[rt]+=k;
    }
    else{
        int mid=(l+r)>>1;
        if(ql<=mid){
            ls[rt]=add(ql,qr,l,mid,ls[rt],k);
        }
        if(qr>mid){
            rs[rt]=add(ql,qr,mid+1,r,rs[rt],k);
        }
    }
    return rt;
}
ll query(ll ql,ll qr,ll l,ll r,ll h,ll i){
    if(ql<=l&&qr>=r){
        return sum[i]+h*(r-l+1);
    }
    ll ans=0;
    int mid=(r+l)>>1;
    if(ql<=mid){
        ans+=query(ql,qr,l,mid,h+tag[i],ls[i]);
    }
    if(qr>mid){
        ans+=query(ql,qr,mid+1,r,h+tag[i],rs[i]);
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    root[0]=build(1,n);
    string op;
    ll l,r,x;
    for(int i=0;i<m;i++){
       cin>>op;
       if(op=="C"){
        cin>>l>>r>>x;
        root[t+1]=add(l,r,1,n,root[t],x);
        t++;
       }
       else if(op=="Q"){
        cin>>l>>r;
        cout<<query(l,r,1,n,0,root[t])<<endl;
       }
       else if(op=="H"){
        cin>>l>>r>>x;
         cout<<query(l,r,1,n,0,root[x])<<endl;
       }
       else{
        cin>>x;
        t=x;
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
    //cin>>T;
    while(T--)
    {
      solve();
    }
    //====================