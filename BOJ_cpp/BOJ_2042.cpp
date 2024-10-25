#include <bits/stdc++.h>
using namespace std;

#define lli long long int

long long int arrNum[1000002] = { 0, };
long long int arrSum[1000002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// N : 수의 개수 (1 ≤ N ≤ 1000000)
	// M : 수의 변경이 일어나는 횟수 (1 ≤ M ≤ 10000)
	// K : 구간의 합을 구하는 횟수

	lli N, M, K;

	cin >> N >> M >> K;
	//scanf("%lld %lld %lld", &N, &M, &K);

	arrNum[0] = 0;
	arrSum[0] = 0;

	for (int i = 0; i < N; i++)
	{
		lli a;
		cin >> a;
		arrSum[i + 1] = arrSum[i] + a;
	}

	vector<lli> answer;
	for (int i = 0; i < M + K; ++i)
	{
		lli a, b, c;
		cin >> a >> b >> c;
		//int a, b, c;
		//scanf("%d %d %d", &a, &b, &c);

		if (a == 1)	// a가 1인 경우 b번째 수를 c로 바꿈
		{
			lli i32b = arrSum[b] - arrSum[b - 1];
			arrNum[b] = c - i32b;
		}
		else	// a가 2인 경우에는 b번째 수부터 c번째 수까지의 합
		{
			lli i32b = arrSum[c] - arrSum[b - 1];
			for (int j = b; j < c + 1; ++j)
			{
				i32b += arrNum[j];
			}

			answer.push_back(i32b);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << "\n";//printf("%lld\n", answer[i]); //
}