#include<bits/stdc++.h>
using namespace std;
 
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define mod               998244353
#define endl             "\n"
#define inf               1e15
#define ninf              1e-15
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif
 
 
 
template<typename T>
struct Fenwick {
    vector<T> tree;
    void  resz(int n)
    {
        tree.resize(n + 1);
    }
 
    T query(int i) {
        int sum = 0;
        while (i) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
    void update(int i, int n, T val) {
        while (i <= n) {
            // cout << i << " * " << val << endl;
            tree[i] += val;
            i += i & (-i);
        }
    }
};

bool check(vector<int> v,int n,int m, int k)
{
    
    for(int i=0;i<k;i++)
        v[i]/=n;
    int temp=0;
    bool bl = false;
    for(int i=0;i<k;i++)
    {
        if(v[i]&1 )
            {   if(temp+v[i]<m)
                temp+=v[i],v[i]=0;
                else
                    temp=m,v[i]=0,bl=true;
        }
    }
    // debug(v,temp);
    if(temp && (m-temp)&1)
        temp--;
    // debug(v,temp);
    if((m-temp)%2 == 0)
    { for(int i=0;i<k;i++)
    {
        if(v[i]%2 ==0)
                temp+=v[i];
    }}
    if(temp>=m)
        bl = true;
    return bl;
}
 

int fun(vector<int> &a)
{
    int count=0;
    for(int i=0;i<26;i++)
        if(a[i])
            count++;
    return count;
}
 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test;
    cin >> test;

     while(test--)
     {
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];

        Fenwick<int> fn;
        fn.resz(n);
        while(q--)
        {
            int t;
            cin >> t;
            if(t==1)
            {
                int l,r;
                cin >> l >> r;
                fn.update(l,n,1);
                fn.update(r+1,n,-1);

            }
            else
            {
                int x;
                cin >> x;
                int c = fn.query(x);
                fn.update(x,n,-c);
                if(x+1<=n)
                fn.update(x+1,n,c);

                while(c-- && v[x-1]>=10) 
                {
                    int temp = v[x-1];
                    int a = 0;
                    while(v[x-1])
                    {
                        a+=(v[x-1]%10);
                        v[x-1]/=10;
                    }
                    v[x-1] = a;

                }
                cout << v[x-1] << endl;

            }
        }

      }
    return 0;
 
  }