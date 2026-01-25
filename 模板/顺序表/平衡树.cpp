    #include<bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    typedef long long ll;
    typedef pair<int,int>pi;
    #define il inline
    using ull = unsigned long long;       
    using i128 = __int128;    
    using db=long double;
    // istream &operator>>(istream &cin, i128 &x) { 
    //     bool flg = 0; x = 0; static string s; cin >> s; if (s[0] == '-') flg = 1, s = s.substr(1); for (char c : s) x = x * 10 + (c - '0'); if (flg) x = -x; return cin; }
    // ostream &operator <<(ostream &cout, i128 x) { static char s[60];
    //     if (x < 0) cout << '-', x = -x; int tp = 1; s[0] = '0' + (x % 10); while (x /= 10) s[tp++] = '0' + (x % 10); while (tp--) cout << s[tp]; return cout; }
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int mod=1e9+7;
    const ll INF = 1e18;
    const int inf=1e9+7;
    const int maxn=100005;
    int rs[maxn];
    int ls[maxn];
    int siz[maxn];
    int key[maxn];
    int fa[maxn];
    int head=0;
    int cnt=0;
    int tag[maxn]={};
    int lr(int i){
        return rs[fa[i]]==i?1:0;
    }
    void up(int i){
        siz[i]=siz[rs[i]]+siz[ls[i]]+1;
    }
    void xuan(int i){
        int f=fa[i],g=fa[f],soni=lr(i),sonf=lr(f);
        if(soni==1){
            rs[f]=ls[i];
            if(rs[f]!=0){
                fa[rs[f]]=f;
            }
            ls[i]=f;
        }
        else{
            ls[f]=rs[i];
            if(ls[f]!=0){
                fa[ls[f]]=f;
            }
            rs[i]=f;
        }
        if(g!=0){
            if(sonf==1){
                rs[g]=i;
            }
            else{
                ls[g]=i;
            }
        }
        fa[i]=g;
        fa[f]=i;
        up(f);
        up(i);
    }
    void splay(int i,int x){
        int f=fa[i],g=fa[f];
        while(f!=x){
            if(g!=x){
                if(lr(f)==lr(i)){
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
        fa[cnt]=head;
        rs[head]=cnt;
        splay(cnt,0);
    }
    void down(int i){
        if(tag[i]){
        tag[ls[i]]=tag[ls[i]]^1;
        tag[rs[i]]=tag[rs[i]]^1;
            int tmp = ls[i];
        ls[i] = rs[i];
        rs[i] = tmp;
        tag[i]=0;
        }
    }
    int find(int k){
        int i=head;
        while(i!=0){
            down(i);
            if(siz[ls[i]]+1==k){
                return i;
            }
            else if(siz[ls[i]]>=k){
                i=ls[i];
            }
            else{
                k=k-siz[ls[i]]-1;
                i=rs[i];
            }
        }
        return 0;
    }
    void re(int x,int y){
        int i=find(x-1);
        int j=find(y+1);
        splay(i,0);
        splay(j,i);
        tag[ls[rs[head]]]=tag[ls[rs[head]]]^1;
    }
    vector<int>ans;
    void inorder(int i){
        if(i!=0){
            down(i);
            inorder(ls[i]);
            ans.push_back(key[i]);
            inorder(rs[i]);
        }
    }
    void solve(){
        int n,m;
        cin>>n>>m;
        add(0);
        for(int i=1;i<=n;i++){
            add(i);
        }
        add(0);
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            re(x+1,y+1);
        }
        inorder(head);
        for(int i=1;i<ans.size()-1;i++){
            cout<<ans[i]<<" ";
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