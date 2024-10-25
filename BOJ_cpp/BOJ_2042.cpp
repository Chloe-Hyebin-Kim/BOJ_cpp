#include <bits/stdc++.h>
using namespace std;

#define lli long long int

long long int arrNum[1000002] = { 0, };
long long int arrSum[1000002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// N : ���� ���� (1 �� N �� 1000000)
	// M : ���� ������ �Ͼ�� Ƚ�� (1 �� M �� 10000)
	// K : ������ ���� ���ϴ� Ƚ��

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

		if (a == 1)	// a�� 1�� ��� b��° ���� c�� �ٲ�
		{
			lli i32b = arrSum[b] - arrSum[b - 1];
			arrNum[b] = c - i32b;
		}
		else	// a�� 2�� ��쿡�� b��° ������ c��° �������� ��
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