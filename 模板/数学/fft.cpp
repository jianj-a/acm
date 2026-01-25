#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
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
const int maxn=200001*2;
const double pi=acos(-1);
complex<double>a[maxn];
complex<double>b[maxn];
void fft(complex<double> a[],int n,int op){
            if(n==1)return ;
            complex<double>a1[n/2],a2[n/2];
            for(int i=0;i<n/2;i++){
                a1[i]=a[i*2];
                a2[i]=a[i*2+1];
            }
            fft(a1,n/2,op);
            fft(a2,n/2,op);
            complex<double>w1({cos(2*pi/n),sin(2*pi/n)*op});
            complex<double>wk({1,0});
            for(int i=0;i<n/2;i++){
                a[i]=a1[i]+a2[i]*wk;
                a[i+n/2]=a1[i]-a2[i]*wk;
                wk=wk*w1;
         }
}
void fft1(complex<double> a[], int n, int op) {
    vector<int>r(n);
    for(int i=0;i<n;i++){
        r[i]=r[i/2]/2+((i&1)?n/2:0);
    }
    for(int i=0;i<n;i++){
        if(i<r[i]){
            swap(a[i],a[r[i]]);
        }    
    }
    for(int m=2;m<=n;m<<=1){
        complex<double>w1(cos(2*pi/m),sin(2*pi/m)*op);
        for(int i=0;i<n;i+=m){
            complex<double>wk(1,0);
            for(int j=0;j<m/2;j++){
                auto x=a[i+j],y=a[i+j+m/2]*wk;
                a[i+j]=x+y;
                a[i+j+m/2]=x-y;
                wk=w1*wk;
            }
        }
    }
}
void solve(){
    string s1;
    string s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    for(int i=0;i<n;i++){
        int y=s1[n-i-1]-'0';
        double x=y;
        a[i]={x,0};
    }
     for(int i=0;i<m;i++){
        int y=s2[m-i-1]-'0';
        double x=y;
        b[i]={x,0};
    }
    for(m=n+m-2,n=1;n<=m;n=n*2);
    fft(a,n,1);
    fft(b,n,1);
    for(int i=0;i<n;i++){
        a[i]=a[i]*b[i];
    }
    fft(a,n,-1);
    vector<int>ans(n+40,0);
    for(int i=0;i<n;i++){
        auto x=(int)(a[i].real()/n+0.5);
        ans[i]=x;
        a[i]={0,0};
        b[i]={0,0};
    }
    array<int,2>p({0,0});
    for(int i=0;i<n+40;i++){
        int v=ans[i]+p[i%2];
        if(v%2){
            ans[i]=1;
            v--;
        }
        else{
            ans[i]=0;
        }
        p[i%2]=v/(-2);
    }
    int f=n+39;
    while(f>0&&ans[f]==0)f--;
    for(int i=f;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
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