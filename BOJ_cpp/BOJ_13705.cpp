#include <bits/stdc++.h>
using namespace std;
#define E_TOL 0.000000000000000000001L
const __float128 PI = 3.1415926535897932384626433832795028841971693993751058209749445923L;
__float128 a, b, c;

__float128 __sin(__float128 x)
{
	while (x > PI) { x -= 2 * PI; }
	while (x < -PI) { x += 2 * PI; }
	if (x > PI / 2) { x = PI - x; }
	if (x < -PI / 2) { x = -PI - x; }
	__float128 ans = x;
	__float128 term = x, n = 1, sign = 1;
	for (int iter = 0; iter <= 30; ++iter)
	{
		n += 2;
		term *= x / (n - 1) * x / n;
		sign *= -1;
		ans += term * sign;
	}
	return ans;
}
__float128 func(__float128 num)
{
	return (a * num) + (b * __sin(num)) - c;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long double p, q, r;
	cin >> p >> q >> r;
	a = p, b = q, c = r;

	__float128 left = (c - b) / a;
	__float128 right = (b + c) / a;

	long long n = (int)(ceil(log((double)(right - left) / E_TOL) / log(2)));
	long long i;
	__float128 mid, fmid, fright;

	for (i = 0; i < n; i++)
	{
		mid = (right + left) / 2;
		fmid = func(mid);
		fright = func(right);
		if (fmid * fright > 0) right = mid;
		else left = mid;
	}

	__float128 ans = (right + left) / 2;
	__float128 tmp = (long long)(ans * (__float128)1e7) / (__float128)1e7;

	long x = tmp * 1e7;
	printf("%.6lf", (x - x % 10 + (x % 10 >= 5) * 10) / 1e7);

	return 0;
}