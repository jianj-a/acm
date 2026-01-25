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
#define int ll
const int maxn=100001;
const int maxm=701;
struct node
{
    int v,i;
    /* data */
}sv[maxn];

int n,m;
int a[maxn];
int bi[maxn];
int bl[maxm];
int br[maxm];
int cnt[maxm][maxn];
int dp[maxm][maxm];
int tree[maxn*2];
int num;
int len;
int lower(int i){
    return i&(-i);
}
void add(int i,int v){
    while(i<=n){
        tree[i]+=v;
        i+=lower(i);
    }
}
inline void read(ll &x){
	ll w=1; x=0; 
	char c=getchar(); 
	while(!isdigit(c)){ w|=(c=='-'); c=getchar();}  
	while(isdigit(c)){ x=(x<<1)+(x<<3)+(c^48); c=getchar();} 
	x=x*w;
}

    
int sum(int i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lower(i);    
    }
    return ans;
}
int pre[maxn];
int suf[maxn];
int f(int x,int xl,int xr,int y,int yl,int yr){
    int ans=0;
    for(int p1=bl[x],p2=bl[y]-1,cnt=0;p1<=br[x];p1++){
        if(xl<=sv[p1].i&&sv[p1].i<=xr){
            while(p2+1<=br[y]&&sv[p1].v>sv[p2+1].v){
                p2++;
                 if(yl<=sv[p2].i&&sv[p2].i<=yr){
                    cnt++;
                 }
            }
            ans+=cnt;
        }
    }
    return ans;
}
void build(){
    len=sqrt(n/4);
    num=(n+len-1)/len;
    for(int i=1;i<=n;i++){
        bi[i]=(i-1)/len+1;
    }
    for(int i=1;i<=num;i++){
        bl[i]=(i-1)*len+1;
        br[i]=min(i*len,n);
    }
    for(int i=1;i<=n;i++){
        sv[i].v=a[i];
        sv[i].i=i;
    }
    auto cmp=[&](node a,node b){
        return a.v<b.v;
    };
    for(int i=1;i<=num;i++){
        sort(sv+bl[i],sv+br[i]+1,cmp);
    }
    for(int i=1;i<=num;i++){
        for(int j=bl[i];j<=br[i];j++){
            cnt[i][a[j]]++;
            if(j!=bl[i]){
                pre[j]=pre[j-1]+sum(n)-sum(a[j]);
            }
            add(a[j],1);
        }
         for(int j=bl[i];j<=br[i];j++){
            add(a[j],-1);
        }
        for(int j=br[i];j>=bl[i];j--){
            if(j!=br[i]){
                suf[j]=suf[j+1]+sum(a[j]);
            }
            add(a[j],1);
        }
         for(int j=bl[i];j<=br[i];j++){
            add(a[j],-1);
        }
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=cnt[i][j];
            cnt[i][j]=cnt[i-1][j]+tmp;
        }  
    }
    for(int i=num;i>=1;i--){
        dp[i][i]=pre[br[i]];
        for(int j=i+1;j<=num;j++){
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+f(i,bl[i],br[i],j,bl[j],br[j]);
        }
    }
}
int query(int l,int r){
    int lb=bi[l];
    int rb=bi[r];
    int ans=0;
    if(lb==rb){
        if(l==bl[rb]){
            return pre[r];
        }
        else{
            ans=pre[r]-pre[l-1]-f(lb,bl[lb],l-1,lb,l,r);
        }
        return ans;
    }
    ans=f(lb,l,br[lb],rb,bl[rb],r)+suf[l]+pre[r];
    for(int i=l;i<=br[lb];i++){
        ans+=cnt[rb-1][a[i]]-cnt[lb][a[i]];
    }
    for(int i=r;i>=bl[rb];i--){
        ans+=br[rb-1]-bl[lb+1]+1-(cnt[rb-1][a[i]]-cnt[lb][a[i]]);
    }
    ans+=dp[lb+1][rb-1];
    return ans;
}
void solve(){
       read(n);
       read(m);
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        build();
        int ans=0;
        for(int i=1;i<=m;i++){
            int l,r;
            read(l);
            read(r);
            l=l^ans;
            r=r^ans;
            ans=query(l,r);
            cout<<ans<<endl;
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