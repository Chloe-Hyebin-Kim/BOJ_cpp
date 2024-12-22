#include<bits/stdc++.h>
using namespace std;
typedef __float128 lli;

__float128 MySqrt(__float128 x)
{
	if (x == 0) return 0;

	__float128 y = 1, gy = 0;
	do
	{
		__float128 t = (y + (x / y)) / 2;
		gy = y;
		y = t;
	} while (y != gy);

	return y;
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);

		int px = 0, py = 0, pz = 0;
		lli ans = 0;

		for (int j = 0; j < 4; ++j)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);

			ans += MySqrt(lli((px - a) * (px - a) + (py - b) * (py - b) + (pz - c) * (pz - c)));
			px = a, py = b, pz = c;
		}
		if (ans <= x)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}