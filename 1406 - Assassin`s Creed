#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define         pb              push_back
#define         mp              make_pair
#define         ff              first
#define         ss              second
#define         pii             pair<int , int>
#define         sz(x)           x.size()
#define         clr(x)          x.clear()
#define         mem(x ,y)       memset(x , y , sizeof x )
#define         all(a )         a.begin() , a.end()
#define         endl            "\n"
#define         si(x )          scanf("%d", &x);
#define         sii(x,y )       scanf("%d%d", &x,&y);
#define         fast()          ios_base :: sync_with_stdio(false ) ; cin.tie(0) ; cout.tie(0) ;
#define         rep(i ,n )      for(int i = 0 ; i < n ; i++ )
#define         repi(i ,n )     for(int i = 1 ; i <= n ; i++ )
#define         forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define         repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#define         dbg(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
 
 
const long long mod = 1e9+7 ;
const int inf = 1e9  ;
const long long  inflong = 1e18 ;
 
int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int n,int pos ) { return (bool ) (n& (1<<pos))  ; }
 
template < typename T > void print(const T& v) {    cerr << v << ' ' ;}
template < typename T > T modMul(T x, T y ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template < typename T > T modAdd(T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
template < typename T > T modPow(T x, T k ,T mod ) { if(k == 0 ) return 1; if(k&1  ) { return ( (x%mod)*modPow(x,k-1, mod )%mod )%mod ; } else { T ret = modPow(x,k/2 , mod ) ; ret %= mod ; return (ret*ret )%mod; } }
template < typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template < typename T > T ext_gcd(T num1 , T num2, T &X , T &Y ) { T r2,r1, q2, q1 , x2, x1, y2 ,y1 , x,  y, r   ; x2 = 1; y2 = 0;  x1 = 0; y1 = 1; for( r2 =num1 ,r1 = num2 ;r1 != 0 ; y2 = y1, y1 = y,x2 = x1 ,x1 = x ,r2 = r1, r1 = r) {q1 = r2/r1; x = x2 - q1*x1; y = y2 - q1*y1; r = r2%r1 ; } X = x2 ; Y = y2 ; return r2 ;  }
 
template<typename T >
T modInv( T x , T m ) {  
    return modPow(x,m-2 , m) ;
    long long ret, t ;
    ext_gcd( x, m ,ret ,t  ) ;
    ret %= m ;
    if(ret<0) ret += m  ;
    return ret;
}
   
typedef long long ll  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;
 
//int dx[] = {0 , 0 ,+1, -1 } ;
//int dy[] = {-1, +1,0 , 0 };
 
// code from here
const int M = 2000123 ;  
const int mx = M/2+2  ; 
//const ll N = 1e7+5 ;
//const int N =10;

int vis[16][(1<< 16)+2] , dp[(1<<16)+2 ] ;
int can[(1<<16)+2] ,cs = 0 ;

vector<int>g[20] ;

void dfs(int id, int mask ) {
    can[mask] = 1; 
    vis[id ][mask ] = 1; 

    rep(i , sz(g[id]  ))  {
        int v = g[id][i] ;
        if(vis[v][mask ] != -1  ) continue; 
   
        dfs(v , setbit(mask , v ) ) ;

    }
}

int  func(int  mask  ) {
    int &ans = dp[mask] ;
    if(mask == 0 ) return 0 ; 
    if(ans!=-1 ) return ans; 


    ans = 1000 ;

    for(int i = mask ; i>0;  i = mask&(i-1)) {

        if(can[i]) 
            ans = min(ans ,1+func(mask^i) ) ;


    }



    return ans ;

}    

void solve() {
    int n , q,x ,y ; 
    
    rep(i ,16) g[i].clear() ;
    sii(n ,  q) ;

    rep(i , q ) {
        sii(x,y ) ;
        x--  ;
        y--  ;
        g[x].pb(y ) ;

    }
    mem(vis, -1) ;
    mem(can , 0  ) ;
    mem(dp, -1) ;

    rep(i  ,  n) {
        dfs(i ,  (1<<i ) ) ;
    }
    x = (1<<n ) -1 ;
    int ans = func(x )  ; 
   
    printf("Case %d: %d\n" ,++cs , ans );

}



int main() {
  
     //freopen("in.txt", "r", stdin  );
    //  freopen( "out.txt", "w",stdout );    
    // fast() ;
    
    int  x , cnt = 0   , t  ;
    x= 14 ; 
    si(t) ;
    while(t--) solve() ;












    return 0 ;
 
}






