#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

// int main()
// {
//  fast_cin();
//  ll t;
//  cin >> t;
//  for(int it=1;it<=t;it++) {
//      int n;
//      cin>>n;
//      string a,b="2020";
//      int i,j=0;
//      bool flag=false;
//      cin>>a;
//      for(i=0;i<n;i++)
//      {
//          if(j==4)
//          break;
//          else if(flag==false && a[i]==b[j])
//          j++;
//          else if(flag==false && a[i]!=b[j])
//          {
//              flag=true;
//              break;
//          }
//      }
//      if(j==4)
//      cout<<"YES"<<"\n";
//      else if(flag==true)
//      {
//          int k=n-1,m=3;
//          while(j<4)
//          {
//              if(a[k]==b[m])
//              {
//                  m--;
//                  k--;
//                  j++;
//              }
//              else
//              break;
//          }
//          if(j==4)
//          cout<<"YES"<<"\n";
//          else
//          cout<<"NO"<<"\n";
//      }
//      else
//      cout<<"NO"<<"\n";
//  }
//  return 0;
// }
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     int n;
     cin>>n;
     string a;
     bool flag=false;
     cin>>a;
     for(int i=0;i<=4;i++)
     {
         if(a.substr(0,i)+a.substr(n-4+i,4-i)=="2020")
         {
             flag=true;
             cout<<"YES"<<"\n";
             break;
         }
     }
     if(flag==false)
     cout<<"NO"<<"\n";
 }
 return 0;
}