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
int head=0;
int key[maxn];
int cnt=0;
int fa[maxn];
int ls[maxn];
int rs[maxn];
int siz[maxn];
int lr(int i){
    return rs[fa[i]]==i?1:0;
}
void up(int i){
    siz[i]=siz[ls[i]]+siz[rs[i]]+1;
}
void xuan(int i){
    int f=fa[i],g=fa[f],soni=lr(i),sonf=lr(f);
    if(soni==1){
        rs[f]=ls[i];
        ls[i]=f;
        if(rs[f]!=0){
            fa[rs[f]]=f;
        }
    }
    else{
        ls[f]=rs[i];
        rs[i]=f;
        if(ls[f]!=0){
            fa[ls[f]]=f;
        }
    }
    if(g!=0){
        if(sonf==1){
            rs[g]=i;
        }
        else{
            ls[g]=i;
        }
    }
    fa[f]=i;
    fa[i]=g;
    up(f);
    up(i);
}
void splay(int i,int x){
     int f=fa[i],g=fa[f];
     while(f!=x){
        if(g!=x){
            if(lr(i)==lr(f)){
                xuan(f);
            }
            else{
                xuan(i);
            }
        }
        xuan(i);
        f=fa[i];
        g=fa[f];
     }
     if(x==0){
        head=i;
     }

}
void add(int x){
    key[++cnt]=x;
    siz[cnt]=1;
    if(head==0){
        head=cnt;
        return ;
    }
    int f=0,i=head,son=0;
    while(i!=0){
        f=i;
        if(key[i]<=x){
            i=rs[i];
            son=1;
        }
        else{
            son=0;
            i=ls[i];
        }
    }
    if(son==1){
        rs[f]=cnt;
    }
    else{
        ls[f]=cnt;
    }
    fa[cnt]=f;
    splay(cnt,0);
}
int getrank(int x){
    int i=head,last=head;
    int ans=0;
    while(i!=0){
        last=i;
        if(key[i]>=x){
            i=ls[i];
        }
        else{
            ans+=siz[ls[i]]+1;
            i=rs[i];
        }
    }
    splay(last,0);
    return ans+1;
}
int find(int x){
    int i=head;
    while(i!=0){
        if(siz[ls[i]]+1==x){
            return i;
        }
        else if(siz[ls[i]]>=x){
            i=ls[i];
        }
        else{
            x-=(siz[ls[i]]+1);
            i=rs[i];
        }
    }
    return 0;
}
void remove(int x){
    int k=getrank(x);
    if(k!=getrank(x+1)){
        int i=find(k);
        splay(i,0);
        if(ls[i]==0){
            head=rs[i];
        }
        else if(rs[i]==0){
            head=ls[i];
        }
        else{
            int j=find(k+1);
            splay(j,i);
            ls[j]=ls[i];
            fa[ls[j]]=j;
            up(j);
            head=j;
        }
    }
    if(head!=0){
        fa[head]=0;
    }
}
int pre(int x){
    int i=head;
    int ans=-inf;
    int last=i;
    while(i!=0){
        last=i;
        if(key[i]>=x){
            i=ls[i];
        }
        else{
            ans=max(ans,key[i]);
            i=rs[i];
        }
    }
    splay(last,0);
    return ans;
}
int pos(int x){
    int i=head;
    int ans=inf;
    int last=i;
    while(i!=0){
        last=i;
        if(key[i]<=x){
            i=rs[i];
        }
        else{
            ans=min(ans,key[i]);
            i=ls[i];
        }
    }
    splay(last,0);
    return ans;
}
void solve(){
    int n;
    cin>>n;
    int op,x;
    for(int i=1;i<=n;i++){
        cin>>op;
        cin>>x;
        if(op==1){
            add(x);
        }
        else if(op==2){
 
            remove(x);
        }
        else if(op==3){

            cout<<getrank(x)<<endl;
        }
        else if(op==4){
            cout<<key[find(x)]<<endl;
        }
        else if(op==5){
            cout<<pre(x)<<endl;
        }
        else{
            cout<<pos(x)<<endl;
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