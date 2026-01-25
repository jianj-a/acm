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
vector<int>man(string ss){
     int n=2*ss.size()+1;
    vector<char>s(n);
    for(int i=0,j=0;i<n;i++){
        s[i]=(i&1)==0?'#':ss[j++];
    }
    vector<int>p(n);
    int len,r=0,c=0;
    int max1=0;
    for(int i=0;i<n;i++){
        len=r>i?min(p[2*c-i],r-i):1;
        while(i+len<n&&i-len>=0&&s[i+len]==s[i-len]){
          len++;  
        }
        if(i+len>r){
            r=i+len;
            c=i;
        }
        p[i]=len-1;
    }
    return p;
}
void solve(){
    string s1;
    cin>>s1;
    int n=2*s1.size()+1;
    auto p=man(s1);
    int max1=0;
    for(int i=0;i<n;i++){
        max1=max(max1,p[i]);
    }
    cout<<max1<<endl;
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