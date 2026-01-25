#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int>pi;
using ull = unsigned long long;       
using i128 = __int128;    
istream &operator>>(istream &cin, i128 &x) { 
    bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
const ll INF = 1e18;
const int inf=1e9;
const int maxn=100001;
int n;
int key[maxn];
ll pri[maxn];
int cnt=0;
int head=0;
int keycnt[maxn];
int ls[maxn];
int rs[maxn];
int siz[maxn];
void up(int i){
  siz[i]=siz[rs[i]]+siz[ls[i]]+keycnt[i];
}
int ri(int i){
  int l=ls[i];
  ls[i]=rs[l];
  rs[l]=i;
  up(i);
  up(l);
  return l;
}
int li(int i){
  int r=rs[i];
  rs[i]=ls[r];
  ls[r]=i;
  up(i);
  up(r);
  return r;
}
int add(int i,int x){
  if(i==0){
    key[++cnt]=x;
    keycnt[cnt]=siz[cnt]=1;
    pri[cnt]=rng();
    return cnt;
  }
  if(key[i]==x){
    keycnt[i]++;
  }
  else if(x<key[i]){
    ls[i]=add(ls[i],x);
  }
  else{
    rs[i]=add(rs[i],x);
  }
  up(i);
  if(ls[i]!=0&&pri[ls[i]]>pri[i]){
     return ri(i);
  }
  if(rs[i]!=0&&pri[rs[i]]>pri[i]){
    return li(i);
  }
  return i;
}
int getrank(int i,int x){
  if(i==0){
    return 0;
  }
  if(x<=key[i]){
    return getrank(ls[i],x);
  }
  else{
    return siz[ls[i]]+keycnt[i]+getrank(rs[i],x);
  }
}
int getrank(int x){
  return getrank(head,x)+1;
}
int remove(int i,int x){
  if(key[i]<x){
    rs[i]=remove(rs[i],x);
  }
  else if(key[i]>x){
    ls[i]=remove(ls[i],x);
  }
  else{
    if(keycnt[i]>1){
      keycnt[i]--;
    }
    else{
        if(ls[i]==0&&rs[i]==0){
          return 0;
        }
        else if(ls[i]!=0&&rs[i]==0){
          i=ls[i];
        }
        else if(rs[i]!=0&&ls[i]==0){
          i=rs[i];
        }
        else{
           if(pri[ls[i]]>=pri[rs[i]]){
            i=ri(i);
            rs[i]=remove(rs[i],x);
           }
           else{
            i=li(i);
            ls[i]=remove(ls[i],x);
           }
        }
    }
  }
  up(i);
  return i;
}
void remove1(int x){
  if(getrank(x+1)!=getrank(x)){
    head=remove(head,x);
  }
}
int index(int i,int x){
   if(siz[ls[i]]>=x){
    return index(ls[i],x);
   }
   else if(siz[ls[i]]+keycnt[i]<x){
    return index(rs[i],x-siz[ls[i]]-keycnt[i]);
   }
   return key[i];
}
int pre(int i,int x){
  if(i==0){
    return -inf;
  }
  if(key[i]>=x){
    return pre(ls[i],x);
  }
  else{
    return max(key[i],pre(rs[i],x));
  }
}
int suf(int i,int x){
  if(i==0){
    return inf;
  }
  if(key[i]<=x){
    return suf(rs[i],x);
  }
  else{
    return min(key[i],suf(ls[i],x));
  }
}
void solve(){
    cin>>n;
    int op,x;
    while(n--){
      cin>>op>>x;
      if(op==1){
        head=add(head,x);
      }
      else if(op==2){
        remove1(x);
      }
      else if(op==3){
        cout<<getrank(x)<<endl;
      }
      else if(op==4){
        cout<<index(head,x)<<endl;
      }
      else if(op==5){
        cout<<pre(head,x)<<endl;
      }
      else{
        cout<<suf(head,x)<<endl;
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