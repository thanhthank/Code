#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		long long tu, mau;
		cin >> tu >> mau;

		while (true) {
			if (mau % tu == 0) {
				cout << "1/" << mau / tu << "\n";
				break;
			} else {
				long long res = mau / tu + 1;
				cout << "1/" << res << " + ";

				tu = tu * res - mau;
				mau = mau * res;

				long long g = gcd(tu, mau);
				tu /= g;
				mau /= g;
			}
		}
	}

	return 0;
}
