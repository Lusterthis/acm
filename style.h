#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)

typedef long long ll;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

//数论///////////////////////////////////////////////////////////////////////////////////////////////
//快速幂
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;  // 
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;  // 相当于 exp = exp / 2
    }
    return result;
}
//欧拉筛
const int N=1e5+10;;
int mpf[N];
vector<int>primes;
int EulerSieve = []{
    for(int i=2;i<N;++i){
        if(!mpf[i]){
            mpf[i]=i;
            primes.push_back(i);
        }
        for(int p:primes){
            if(p>mpf[i]||p*i>=N)break;
            mpf[p*i]=p;
        }

    }
    return 0;
}();