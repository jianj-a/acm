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
const int inf=INT_MAX;
const int maxn=100001;
int siz[maxn];
int key[maxn];
int rs[maxn];
int ls[maxn];
int he[maxn];
int keycnt[maxn];
int head=0;
int cnt=0;
void up(int i){
  siz[i]=siz[rs[i]]+siz[ls[i]]+keycnt[i];
  he[i]=max(he[rs[i]],he[ls[i]])+1;
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
int maintain(int i){
  int lh=he[ls[i]];
  int rh=he[rs[i]];
  if(lh-rh>1){
    if(he[ls[ls[i]]]>=he[rs[ls[i]]]){
      i=ri(i);
    }
    else{
      ls[i]=li(ls[i]);
      i=ri(i);
    }
  }
  else if(rh-lh>1){
     if(he[rs[rs[i]]]>=he[ls[rs[i]]]){
      i=li(i);
    }
    else{
      rs[i]=ri(rs[i]);
      i=li(i);
    }
  }
  return i;
}
int add(int i,int x){
    if(i==0){
      i=++cnt;
      key[cnt]=x;
      keycnt[cnt]=siz[cnt]=he[cnt]=1;
      return cnt;
    }                                
    if(key[i]==x){
      keycnt[i]++;
    }             
    else if(key[i]>x){
       ls[i]= add(ls[i],x);
    }               
    else{
      rs[i]=add(rs[i],x);
    }
    up(i); 
    return maintain(i);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}
int getrank(int i,int x){
   if(i==0){
    return 0;
  }
  if(key[i]>=x){
    return getrank(ls[i],x);
  }
  else{
    return siz[ls[i]]+keycnt[i]+getrank(rs[i],x);
  }
}
int getrank(int x){
  return getrank(head,x)+1;
}
int moveleft(int i,int mlf){
  if(i==mlf){
    return rs[i];
  }
  else{
     ls[i]=moveleft(ls[i],mlf);
     up(i);
     return maintain(i);
  }
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
      if(rs[i]==0&&ls[i]==0){
        return 0;
      }
      else if(ls[i]==0&&rs[i]!=0){
       i=rs[i];
     }
     else if(rs[i]==0&&ls[i]!=0){
       i=ls[i];
     }
     else{
      int mlf=rs[i];
      while(ls[mlf]!=0){
        mlf=ls[mlf];
      }
      rs[i]=moveleft(rs[i],mlf);
       ls[mlf]=ls[i];
       rs[mlf]=rs[i];
       i=mlf;
      }
      }
    }
    up(i);
    return maintain(i);
}
void remove1(int x){
  if(getrank(x)!=getrank(x+1)){
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
    return INT_MIN;
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
    return INT_MAX;
  }
  if(key[i]<=x){
    return suf(rs[i],x);
  }
  else{
    return min(key[i],suf(ls[i],x));
  }
}
void solve(){
  int n;
  cin>>n;
  int op,x;
  for(int i=1;i<=n;i++){
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
    else if(op==6){
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