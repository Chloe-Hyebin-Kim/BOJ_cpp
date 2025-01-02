#include "bits/stdc++.h"
using namespace std;

int BFS(int N, int K)
{
	int dist = abs(K - N);
	int answer = 0;
	queue <int> q;
	vector <int> arrTime;
	arrTime.resize(100001, -1);
	q.push(N);
	arrTime[N] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == K)
		{
			answer = arrTime[x];
			break;
		}

		int tmp1 = x - 1;
		if ((0 <= tmp1) && (tmp1 <= 100000))
		{
			if ((arrTime[tmp1] == -1) || ((arrTime[tmp1] != -1) && (arrTime[tmp1] > arrTime[x])))
			{
				arrTime[tmp1] = arrTime[x] + 1;
				q.push(tmp1);
			}
		}

		int tmp2 = x + 1;
		if ((0 <= tmp2) && (tmp2 <= 100000))
		{
			if ((arrTime[tmp2] == -1) || ((arrTime[tmp2] != -1) && (arrTime[tmp2] > arrTime[x])))
			{
				arrTime[tmp2] = arrTime[x] + 1;
				q.push(tmp2);
			}
		}

		int tmp3 = 2 * x;
		if ((0 <= tmp3) && (tmp3 <= 100000))
		{
			if ((arrTime[tmp3] == -1) || ((arrTime[tmp3] != -1) && (arrTime[tmp3] > arrTime[x])))
			{
				arrTime[tmp3] = arrTime[x] + 1;
				q.push(tmp3);
			}
		}
	}

	return answer;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int answer = BFS(N, K);
	printf("%d", answer);
}
