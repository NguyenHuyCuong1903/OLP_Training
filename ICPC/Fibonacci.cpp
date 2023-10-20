#include <map>
#include <iostream>
using namespace std;
const long long M = 1000000007; // modulo
map<long long, long long> F;

long long f(long long n) {
	if (F.count(n)==1) return F[n];
	long long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main(){
	long long n;
	F[0]=F[1]=1;
	cin >> n;
    cout << f(n) << endl;
    for (auto i : F){
        cout << i.first << " " << i.second << endl;
    }
}