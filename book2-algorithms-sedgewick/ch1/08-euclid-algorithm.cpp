#include <iostream>
#include <cmath>
using namespace std;

int gcd(int p, int q) {
	if (q == 0) {
		return p;
	}
	const auto r = p % q;
	return gcd(q, r);
}

int main() {
	cout << "gcd(5, 10) = " << gcd(5, 10) << endl;
	cout << "gcd(2, 10) = " << gcd(2, 10) << endl;
	return 0;
}
