#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long x[4], y[4];
	long long iResult = 0;

	for (int i = 0; i < 4; ++i)
	{
		cin >> x[i] >> y[i];
	}

	long long oneNtwo3 = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);
	long long oneNtwo4 = (x[1] - x[0]) * (y[3] - y[0]) - (x[3] - x[0]) * (y[1] - y[0]);
	long long threeNfour1 = (x[3] - x[2]) * (y[0] - y[2]) - (x[0] - x[2]) * (y[3] - y[2]);
	long long threeNfour2 = (x[3] - x[2]) * (y[1] - y[2]) - (x[1] - x[2]) * (y[3] - y[2]);

	if (oneNtwo3 * oneNtwo4 < 0 && threeNfour1 * threeNfour2 < 0)
		iResult = 1;

	cout << iResult << "\n";
}
