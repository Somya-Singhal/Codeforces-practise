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
 
/* solution->using queue
int main()
{
 fast_cin();
 int n;
 cin>>n;
 queue<int>q;
 int count=0;
 q.push(4);
 q.push(7);
 while(!q.empty())
 {
     int curr=q.front();
     q.pop();
     count++;
     if(curr==n)
     {
         cout<<count;
         break;
     }
     q.push(curr*10+4);
     q.push(curr*10+7);
 }
 return 0;
}
*/ 

// using bitmasks
int main()
{
 fast_cin();
 char arr[20];
 cin>>arr;
 int x=strlen(arr);
//  Part-1-> all no. having digit less than this original no. will be smaller
// 2^(x-1)+2^(x-2)+.....+2^1=2(2^(x-1)-1)/(2-1)
// Part-2-> to find no.s less than x digit current no.
// only 7 is to be considered and position of it->2^x
ll ans=(1<<x)-2;
for(int i=x-1,pos=0;i>=0;i--,pos++)
{
if(arr[i]=='7')
{
    ans+=(1<<pos);
}
}
cout<<(ans+1);
 return 0;
}