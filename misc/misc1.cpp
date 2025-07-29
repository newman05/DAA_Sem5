// find perfect numbers present at prime indices of an array 

#include<bits/stdc++.h>

#define ll long long
#define nline '\n' 
#define FOR vector<int>v(n) ;for(int i = 0 ;i < n ; i++) cin>>v[i];
#define nv int n ; cin>>n ; 
#define sot sort(v.begin() , v.end()) ;
#define tos sort(v.begin() , v.end() , greater<int>()) ;
#define pfs vector<int>pf(n) ;pf[0] = v[0]; for (int i = 1; i < n; i++) pf[i] = pf[i - 1] + v[i];
#define stt set<int>st ; st.insert(v.begin() , v.end());
#define pb push_back
#define SUM  long long vsum = accumulate(v.begin(), v.end(), 0LL);
#define kcod ios_base::sync_with_stdio(false); cin.tie(NULL);
#define co cout<<
#define ed <<endl ;
#define INF 1000000000000000000LL
#define freqmap  unordered_map<int , int> mpp ; for(int i = 0 ; i < n ; i++) mpp[v[i]]++ ;
// conc // string str = string(1 , s[i]) + s[i + 1] + s[i + 2] + s[i + 3] + 
// overflow // int mid = l + (r - l) / 2;
const ll mod = 1e9 + 7;

using namespace std ;


bool isprime(int a ) {

  int y = 0 ;
  for (int i = 1; i <= a; i++)
  {
    if(a % i == 0 ) {
      y++ ; 
    }
  }

  if(y == 2 ) {
    return 1 ; 
  }
  return 0 ; 
  
}

bool isperfect(int a) {
  int ok =0; 
  for(int i = 1 ; i < a ; i++) {
    if(a % i ==0 ) {
      ok += i ;
    }
  }
  if(ok == a) {
    return true ;
  }
  return false ; 
}


int main(){ ;

kcod

int cnt = 0 ;
bool flag = true ;

nv
FOR
 vector<int>ans ; 
 for(int i =0;i < n ; i++) {
  if(isprime(i)) {
    if(isperfect(v[i])) {
      ans.pb(v[i]) ; 
    }
  }
 }

 for(auto x : ans ) {
  cout<<x<<" " ;
 }
 cout<<nline ; 
 



return 0 ;
}