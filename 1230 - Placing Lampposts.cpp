/* 
    author : Shahriar Newaz Shuvo
    cf : thedragonslayer

*/



// #pragma comment(linker, "/stack:247474112")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
//typedef tree<
//        pair<int, int>, // change type
//        null_type,
//        less<pair<int, int> >, // change type
//        rb_tree_tag,
//        tree_order_statistics_node_update>
//        ordered_set;

#define     pii             pair<int ,int>
#define     ff              first
#define     ss              second
#define     pb(x)           push_back(x ) 
#define     mp              make_pair
#define     sz(x)           x.size()
#define     clr(x)          x.clear()
#define     mem(x ,y)       memset(x , y , sizeof x )
#define     all(a )         a.begin() , a.end()
#define     endl            "\n"
#define     si(x )          scanf("%d", &x)
#define     sl(x )          scanf("%I64d", &x)
#define     sd(x )          scanf("%lf", &x)
#define     sii(x,y )       scanf("%d%d", &x,&y)
#define     siii(x,y ,z)    scanf("%d%d%d ", &x,&y , &z)
#define     rep(i ,n )      for(int i = 0 ; i < n ; i++ )
#define     repi(i ,n )     for(int i = 1 ; i <= n ; i++ )
#define     forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define     repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#define     dbg(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
  
typedef long long ll  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;

const ll  mod =  1e9+7;
const int  inf = 1e4  ;
const long long  infL = 1e18 ;

int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int  n,int pos ) { return (bool ) (n&(1<<pos))  ; }

template < typename T > T mul(T x, T y   ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template < typename T > T add(T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
template < typename T > T modPow(T x, T k ,T mod ) { if(k == 0 ) return 1; if(k&1  ) { return ( (x%mod)*modPow(x,k-1, mod )%mod )%mod ; } else { T ret = modPow(x,k/2 , mod ) ; ret %= mod ; return (ret*ret )%mod; } }
template < typename T > T ext_gcd(T num1 , T num2, T &X , T &Y ) { T r2,r1, q2, q1 , x2, x1, y2 ,y1 , x,  y, r   ; x2 = 1; y2 = 0;  x1 = 0; y1 = 1; for( r2 =num1 ,r1 = num2 ;r1 != 0 ; y2 = y1, y1 = y,x2 = x1 ,x1 = x ,r2 = r1, r1 = r) {q1 = r2/r1; x = x2 - q1*x1; y = y2 - q1*y1; r = r2%r1 ; } X = x2 ; Y = y2 ; return r2 ;  }
template < typename T > T modInv( T x , T m ) {  return modPow(x,m-2 , m) ; }  // long long ret, t ;// ext_gcd( x, m ,ret ,t  ) ;// ret %= m ;// if(ret<0) ret += m  ; // return ret;}
template < typename T > void print(const T& v) {    cerr << v << ' ' ;}
template < typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
// debuging ... 
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "[ "; rep(i , sz( v)  )  os << v[i] << ' ' ; return os << " ]" ; 
}

//int dx[] = {0 , 0 ,+1, -1 } ;
//int dy[] = {-1, +1,0 , 0 };
  
const int M = (int )1000;  
const int mx = (int)700; 
const int nx  = 1000+ 7 ;
////  code from here ... 

int dp[nx+2][2] ,cnt[nx+2][ 2] ,vis[nx+2]; 
vector<int>g[nx+2] ; 

void merge(int u, int v ) {
    dp[u][0] += dp[v][1] ; 
    cnt[u][0 ] += cnt[v][1] ;

    if(dp[v][0]<dp[v][1] ){
        dp[u][1] += dp[v][0 ] ;
        cnt[u][1] += cnt[v][0 ] ;


    } else if(dp[v][0]>dp[v][1] ){
        dp[u][1] += dp[v][1 ] ;
        cnt[u][1] += cnt[v][1] +1;

    } else {
        dp[u][1] += dp[v][1] ; 
        cnt[u][1] += max(cnt[v][0], cnt[v][1]+1); 

    } 
}

void dfs(int u) {
    //   dbg(u) ; 
    vis[u]=1 ;
    dp[u][1]=1;
    rep( i ,sz(g[u]) )  {
        int v = g[u][i] ; 
        if(vis[v]== 0 )  {
            dfs(v  ) ; 
            merge(u, v) ; 

        }


    }

}

void solve() {
    int  n , k, r ,b, x,y ,ans1 = 0,ans2 = 0; 
    mem(dp,0) ; 
    mem(cnt, 0) ;  
    rep(i ,nx+1)g[i].clear( ) ;
    mem(vis, 0) ;     
    
    sii(n,  k) ; 

    rep(i ,k ) {
        sii(x,y ) ; g[x].pb(y) ;  g[y].pb(x)  ;
    }
    rep(i, n )  {
        if(vis[i]==0) {
           dfs(i) ;    

            if(dp[i][0]<dp[i][1])  {
                ans1+= dp[i][0] ; 
                ans2 +=cnt[i ][0] ;

            } else if(dp[i][0]>dp[i][1])  {
                ans1+= dp[i][1] ; 
                ans2 +=cnt[i ][1] ;

            } else  {
                ans1+= dp[i][0] ; 
                ans2 += max(cnt[i ][0] ,cnt[i][1] );

            } 



        }
    }
    printf("%d %d %d\n",ans1, ans2,k-ans2)  ; 



} 
    
int main() {
    
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
     //   freopen("out.txt", "w", stdout);
    #endif
   // ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    
    int t=1 , c= 0 ;  si( t) ; 
    while(t--) {
        printf("Case %d: ",++c)  ;
        solve() ;
    }

   
}






