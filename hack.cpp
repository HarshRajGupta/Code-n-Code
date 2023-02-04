#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> pbds;
typedef long long ll;
#define pb push_back
#define F first
#define S second
#define OM_NAMAH_SHIVAY ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define minusone cout<<"-1"<<endl 

void build(int i,int l,int r,ll a[],vector<ll> &t){
    if(l==r){
        t[i]=a[l];
    }
    else{
        int mid=(l+r)/2;
        build(2*i+1,l,mid,a,t);
        build(2*i+2,mid+1,r,a,t);
        t[i]=t[2*i+1]+t[2*i+2];
    }
}
void propagate(int i,int l,int r,vector<ll> &t,vector<ll> &p){
    t[i]+=(ll)(r-l+1)*p[i];
    if(l!=r){
        p[2*i+1]+=p[i];
        p[2*i+2]+=p[i];
    }
    p[i]=0;
}
void update(int i,int tl,int tr,int l,int r,ll val,vector<ll> &t,vector<ll> &p){
    propagate(i,tl,tr,t,p);
    if(tl>=l&&tr<=r){
        p[i]+=val;
    }
    else{
        int mid=(tl+tr)/2;
        if(mid>=l){
            update(2*i+1,tl,mid,l,r,val,t,p);
        }
        if(mid+1<=r){
            update(2*i+2,mid+1,tr,l,r,val,t,p);
        }
        propagate(2*i+1,tl,mid,t,p);
        propagate(2*i+2,mid+1,tr,t,p);
        t[i]=t[2*i+1]+t[2*i+2];
    }
}
ll query(int i,int tl,int tr,int l,int r,vector<ll> &t,vector<ll> &p){
    propagate(i,tl,tr,t,p);
    if(tl>=l&&tr<=r){
        return t[i];
    }
    else{
        int mid=(tl+tr)/2;
        ll k=0;
        if(mid>=l){
            k+=query(2*i+1,tl,mid,l,r,t,p);
        }
        if(mid+1<=r){
            k+=query(2*i+2,mid+1,tr,l,r,t,p);
        }
        return k;
    }
}
int main()
{
// #ifndef ONLINE_JUDGE
//     // For getting input from input.txt file
//     freopen("input.txt", "r", stdin);
//     // Printing the Output to output.txt file
//     freopen("output.txt", "w", stdout);
// #endif
    OM_NAMAH_SHIVAY;
    int cs;
    cin>>cs;
    while(cs--)
    {
        int n,q;
        cin>>n>>q;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vector<ll> t(4*n),p(4*n);
        while(q--){
            int y;
            cin>>y;
            if(y==1)
            {
                int l,r;
                cin>>l>>r;
                update(0,0,n-1,l-1,r-1,1,t,p);
            }
            else
            {
                int x;
                cin>>x;
                int k=query(0,0,n-1,x-1,x-1,t,p);
                if(k>5)k=5;
                int f=a[x];
                while(k--)
                {
                    int g=0;
                    while(f){
                        g+=f%10;
                        f/=10;
                    }
                    f=g;
                }
                cout<<f<<endl;
            }
        }
    }
    return 0;
}