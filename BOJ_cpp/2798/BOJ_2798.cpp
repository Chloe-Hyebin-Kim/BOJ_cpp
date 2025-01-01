#include <bits/stdc++.h>
using namespace std;

vector<int> arrCard;
int N, M;// N장의 카드 중에서 3장의 카드를 골라 합이 M을 넘지 않으면서 M과 최대한 가깝게

int Sum()
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int tmp = arrCard[i] + arrCard[j] + arrCard[k];

				if (M == tmp)
				{
					answer = tmp;
					return answer;
				}
				else if (M > tmp)
				{
					answer = max(tmp, answer);
				}
			}
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int answer = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		arrCard.push_back(K);
	}
	answer = Sum();

	cout << answer;
}