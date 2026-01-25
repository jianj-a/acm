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
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9+7;
const int maxn=100005;
vector<int> build(string s,int len){
      // int len=s.size()-1;
   vector<int>kmp(len+2);
    int pos=0;
    for(int i=2;i<=len;i++){
      while(pos&&s[pos+1]!=s[i])pos=kmp[pos];
      if(s[pos+1]==s[i]){
        pos++;
      }
      kmp[i]=pos;
    }
    return kmp;
}
void solve(){
 string s1,s2;
    cin>>s1>>s2;
    s1='0'+s1;
    s2='0'+s2;
       int len=s2.size()-1;
    int pos=0;
    auto kmp=build(s2,len);
    for(int i=1;i<=s1.size()-1;i++){
        while(pos&&s2[pos+1]!=s1[i])pos=kmp[pos];
        if(s2[pos+1]==s1[i])pos++;
        if(pos==len){
            cout<<i-len+1<<endl;
        }
    }
    for(int i=1;i<=len;i++){
        cout<<kmp[i]<<" ";
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
   // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}