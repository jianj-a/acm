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
int n,m;
int rootfa[maxn];
int rootsiz[maxn];
int val[maxn*40];
int ls[maxn*40];
int rs[maxn*40];
int cnt=0;
int buildfa(int l,int r){
    int rt=++cnt;
    if(l==r){
        val[rt]=l;
        return rt;
    }
    int mid=l+r>>1;
    ls[rt]=buildfa(l,mid);
    rs[rt]=buildfa(mid+1,r);
    return rt;
}
int buildsiz(int l,int r){
    int rt=++cnt;
    if(l==r){
        val[rt]=1;
        return rt;
    }
    int mid=l+r>>1;
    ls[rt]=buildsiz(l,mid);
    rs[rt]=buildsiz(mid+1,r);
    return rt;
}
int query(int x,int l,int r,int i){
    if(l==r){
        return val[i];
    }
    int mid=l+r>>1;
    if(x<=mid){
        return query(x,l,mid,ls[i]);
    }
    else{
        return query(x,mid+1,r,rs[i]);
    }
}
int find(int x,int v){
    int fa=query(x,1,n,rootfa[v]);
    while(x!=fa){
        x=fa;
        fa=query(x,1,n,rootfa[v]);
    }
    return x;
}
int add(int x,int v,int l,int r,int i){
    int rt=++cnt;
    ls[rt]=ls[i];
    rs[rt]=rs[i];
    if(l==r){
        val[rt]=v;
        return rt;
    }
    int mid=l+r>>1;
    if(x<=mid){
        ls[rt]=add(x,v,l,mid,ls[rt]);
    }
    else{
        rs[rt]=add(x,v,mid+1,r,rs[rt]);
    }
    return rt;
}
void un(int a,int b,int v){
    int pa=find(a,v);
    int pb=find(b,v);
    if(pa!=pb){
        int asiz=query(pa,1,n,rootsiz[v]);
        int bsiz=query(pb,1,n,rootsiz[v]);
        if(asiz>=bsiz){
            rootfa[v]=add(pb,pa,1,n,rootfa[v]);
            rootsiz[v]=add(pa,asiz+bsiz,1,n,rootsiz[v]);
        }
        else{
             rootfa[v]=add(pa,pb,1,n,rootfa[v]);
            rootsiz[v]=add(pb,asiz+bsiz,1,n,rootsiz[v]);
        }
    }
}
void solve(){
    cin>>n>>m;
    rootfa[0]=buildfa(1,n);
    rootsiz[0]=buildsiz(1,n);
    int op;
    int a,b,k;
    for(int i=1;i<=m;i++){
        cin>>op;
        rootfa[i]=rootfa[i-1];
        rootsiz[i]=rootsiz[i-1];
        if(op==1){
            cin>>a>>b;
            un(a,b,i);
        }
        else if(op==2){
            cin>>k;
            rootfa[i]=rootfa[k];
            rootsiz[i]=rootsiz[k];
        }
        else{
            cin>>a>>b;
            int pa=find(a,i);
            int pb=find(b,i);
            if(pa==pb){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
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
 // cin>>T;
    while(T--)
    {
      solve();
    }
    //======================
}