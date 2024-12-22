#include <bits/stdc++.h>
using namespace std;
long double f(long double x);
void Secant_Method(long double x0, long double x1, long double error, int Max);

int A, B, C;

void Secant_Method(long double x0, long double x1, long double error, int Max)
{
	long double c, y0, y1;
	y0 = f(x0);
	y1 = f(x1);
	for (int n = 2; n <= Max; n++)
	{
		c = (long double)(x1 - y1 * (x1 - x0) / (y1 - y0));
		//cout << c ;
		if (fabs(f(c)) < error)
		{
			cout << fixed;
			cout.precision(11);
			cout << c;
			break;
		}
		x0 = x1;
		x1 = c;
		y0 = y1;
		y1 = f(c);
	}
}
long double f(long double x)
{
	long double y;
	y = (long double)(A * x + B * sin(x) - C);
	return y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> C;
	long double x0 = 0.1;
	long double x1 = 2.0;
	long double error = (long double)0.0000000001;
	int Max = 256;
	Secant_Method(x0, x1, error, Max);
	return 0;
}
