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
#define int ll
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=250001;
const int maxm=501;
struct node
{
    int m,p,r,d;
    /* data */
}a[maxn];
int x01=0, y01=0;
int ju(int x1,int y1){
    return (x1-x01)*(x1-x01)+(y1-y01)*(y1-y01);
}
int n;
int bi[maxn];
int bl[maxm];
int br[maxm];
int mam[maxm];
int p0,r0;
int len,num;
void build(){
    len=sqrt(n);
    num=(n+len-1)/len;
    for(int i=1;i<=n;i++){
        bi[i]=(i-1)/len+1;
    }
    for(int i=1;i<=num;i++){
        bl[i]=(i-1)*len+1;
        br[i]=min(i*len,n);
    }
    auto cmp1=[&](node a,node b){
        return a.m<b.m;
    };
    sort(a+1,a+n+1,cmp1);
    auto cmp2=[&](node a,node b){
        return a.d<b.d;
    };
    for(int i=1;i<=num;i++){
        mam[i]=a[br[i]].m;
        sort(a+bl[i],a+br[i]+1,cmp2);
    }

}
void solve(){
    cin>>x01>>y01>>p0>>r0>>n;
    a[0].r=r0*r0;
    a[0].p=p0;
    for(int i=1;i<=n;i++){
        int x,y,r,m,p;
    
        cin>>x>>y>>m>>p>>r;
        a[i]={m,p,r*r,ju(x,y)};
    } 
    build();
    vector<int>v(n+1);
    queue<int>q;
    q.push(0);
    int cnt=0;
    while(!q.empty()){
        auto id=q.front();
        q.pop();
        for(int i=1;i<=num;i++){
            if(mam[i]<=a[id].p){
                while(bl[i]<=br[i]&&a[id].r>=a[bl[i]].d){
                    int k=bl[i];
                    if(!v[k]){
                        v[k]=1;
                        q.push(k);
                        cnt++;
                    }
                    bl[i]++;
                }
            }
            else{
                for(int j=bl[i];j<=br[i];j++){
                    if(a[id].r>=a[j].d&&a[id].p>=a[j].m&&!v[j]){
                        v[j]=1;
                        cnt++;
                        q.push(j);
                    }
                }
                break;
            }
        }
    }
    cout<<cnt<<endl;
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