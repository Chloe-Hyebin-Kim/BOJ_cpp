#include<bits/stdc++.h>
using namespace std;

const long long MAX = 3000;
long long M, K;
long long cycle1 = 0;
vector<long long> arr;
bitset<MAX + 1> setValue;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> K;
	arr.resize(K);
	for (long long i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	for (long long i = 1; i <= MAX; i++)
	{
		for (long long j = 0; j < K; j++)
		{
			if (i - arr[j] >= 0 && !setValue[i - arr[j]])
				setValue[i] = 1;
		}
	}
	for (long long i = MAX / 5; i >= 0; i--)
	{
		bool isLoop = true;
		for (long long j = 0; j < i; j++)
		{
			if (setValue[MAX - j] != setValue[MAX - i - j])
				isLoop = 0;
		}
		if (isLoop)
		{
			cycle1 = i;
			break;
		}
	}
	long long ans = 0;
	if (M < 1000)
	{
		for (long long i = 1; i <= M; i++)
		{
			if (!setValue[i])
				ans++;
		}
		cout << ans;
	}
	else
	{
		long long cycle2 = 0;

		for (long long i = 1; i <= 1000; i++)
		{
			if (!setValue[i])ans++;
		}
		for (long long i = 0; i < cycle1; i++)
		{
			if (!setValue[MAX - i])
				cycle2++;
		}
		long long times = (M - 1000) / cycle1;
		ans += cycle2 * times;
		for (long long i = 1001; i < 1001 + (M - 1000) % cycle1; i++)
		{
			if (!setValue[i])
				ans++;
		}
		cout << ans;
	}
	return 0;
}