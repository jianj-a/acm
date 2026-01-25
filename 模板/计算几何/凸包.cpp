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
const int maxn=100001;
struct node
{
    double x,y;
    /* data */
}st[maxn];
double D(node a,node b){
    return sqrt((a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x));
}
void solve(){
    int n;
    cin>>n;
    vector<node>a(n+1);
    double max1=inf;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if(a[i].y<a[1].y){
            swap(a[i],a[1]);
        }
        else if(a[i].y==a[1].y&&a[i].x<a[1].x){
            swap(a[i],a[1]);
        }
    }
    auto check=[&](node b,node c,node d,node e){
        return (c.x-b.x)*(e.y-d.y)-(c.y-b.y)*(e.x-d.x);
    };
    auto cmp=[&](node c,node d){
        double tmp=check(a[1],c,a[1],d);
        if(tmp>0){
            return 1;
        }
        if(tmp==0&&(D(a[1],c)<D(a[1],d))){
            return 1;
        }
        return 0;
    };
    sort(a.begin()+2,a.end(),cmp);
    int r=1;
    st[1]=a[1];
    for(int i=2;i<=n;i++){
        while(r>1&&check(st[r-1],st[r],st[r],a[i])<=0){
            r--;

        }
        r++;
        st[r]=a[i]; 
    }
    st[r+1]=a[1];
    double ans=0;
    for(int i=1;i<=r;i++){
        ans+=D(st[i],st[i+1]);
    }
    printf("%.2lf",ans);
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
 //  cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}