#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
#define il inline
using ull = unsigned long long;       
using i128 = __int128;    
using ldb=long double;
using db=double;
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=998244353;
const ll INF = 1e18;
#define int ll
const int inf=1e9+7;
const int maxn=3000005;
inline ll ksm(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n& 1) ans = (ans * a ) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans ;
}
ll a[maxn];
ll r[maxn];
ll b[maxn];
int limit=1;
int G = 3, Gi = 332748118;
int L=0;
inline void NTT(ll *A, int type) {
	for(int i = 0; i < limit; i++) 
		if(i < r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < limit; mid <<= 1) {	
		ll Wn = ksm( type == 1 ? G : Gi , (mod - 1) / (mid << 1));
		for(int j = 0; j < limit; j += (mid << 1)) {
			ll w = 1;
			for(int k = 0; k < mid; k++, w = (w * Wn) % mod) {
				 int x = A[j + k], y = w * A[j + k + mid] % mod;
				 A[j + k] = (x + y) % mod,
				 A[j + k + mid] = (x - y + mod) % mod;
			}
		}
	}
}
void solve(){
    int n,m;
    cin>>n>>m;
    while(limit <= n + m) limit <<= 1, L++;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
      for(int i=0;i<=m;i++){
        cin>>b[i];
    }
    for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));	
    NTT(a,1);
    NTT(b,1);
    for(int i=0;i<limit;i++){
        a[i]=(a[i]*b[i])%mod;
    }
    NTT(a,-1);
    int inv=ksm(limit,mod-2);
    for(int i=0;i<=n+m;i++){
        cout<<(a[i]*inv)%mod<<" ";
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
    //  cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}