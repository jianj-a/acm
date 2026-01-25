#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
using ull = unsigned long long;
const int mod=1e9+7;
struct node{
    ll data,add=0,mul=1,num=1;
}t[400001];
int n,m,q;
ll a[100001];
void build(int fa,int l,int r){
    if(l==r){
        t[fa].data=a[l]%q;
        t[fa].num=1;
        return ;
    }
    int mid=(r+l)>>1;
    build(fa<<1,l,mid);
    build(fa<<1|1,mid+1,r);
    t[fa].data=(t[fa<<1].data+t[fa<<1|1].data)%q;
    t[fa].num=t[fa<<1].num+t[fa<<1|1].num;
};
int f,l,r;
ll k;
void push_down(int fa){
  t[fa<<1].data=(t[fa<<1].data*t[fa].mul)%q;
  t[fa<<1|1].data=(t[fa<<1|1].data*t[fa].mul)%q;
  t[fa<<1].data=(t[fa<<1].data+t[fa<<1].num*t[fa].add)%q;
  t[fa<<1|1].data=(t[fa<<1|1].data+t[fa<<1|1].num*t[fa].add)%q;
  t[fa<<1].add=(t[fa<<1].add*t[fa].mul+t[fa].add)%q;
  t[fa<<1|1].add=(t[fa<<1|1].add*t[fa].mul+t[fa].add)%q;
  t[fa<<1].mul=(t[fa<<1].mul*t[fa].mul)%q;
  t[fa<<1|1].mul=(t[fa<<1|1].mul*t[fa].mul)%q;
  t[fa].mul=1;
  t[fa].add=0;
}
ll query(int l,int r,int left,int right,int fa){
    ll ans=0;
    if(l<=left&&r>=right){
        return t[fa].data;
    }
    int mid=(left+right)>>1;
    push_down(fa);
    if(l<=mid)ans=(ans+query(l,r,left,mid,fa<<1))%q;
    if(r>mid)ans=(ans+query(l,r,mid+1,right,fa<<1|1))%q;
    return ans%q;
}
void update(int l,int r,int left,int right,int fa,ll k){
   if(l<=left&&r>=right){
     if(f==2){
        t[fa].data=(t[fa].data+k*t[fa].num)%q;
        t[fa].add=(t[fa].add+k)%q;
     }
     else{
        t[fa].data=(t[fa].data*k)%q;
        t[fa].mul=t[fa].mul*k%q;
        t[fa].add=(t[fa].add*k)%q;
     }
     return ;
    }
     int mid=(left+right)>>1;
     push_down(fa);
   if(l<=mid)update(l,r,left,mid,fa<<1,k);
   if(r>mid)update(l,r,mid+1,right,fa<<1|1,k);
   t[fa].data=(t[fa<<1].data+t[fa<<1|1].data)%q;
}
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   cin>>n>>m>>q;
   for(int i=1;i<=n;i++)cin>>a[i];
   build(1,1,n);
   for(int i=1;i<=m;i++){
    cin>>f>>l>>r;
    if(f==3){
       cout<<query(l,r,1,n,1)<<endl;
    }
    else{
        cin>>k;
        update(l,r,1,n,1,k);
    }
   }
}