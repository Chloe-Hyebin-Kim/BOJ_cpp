#include "bits/stdc++.h"
using namespace std;

int K, N;//이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N
vector<long long int> arrLine;// 이미 가지고 있는 랜선의 길이

int FindLength(long long int startLength, long long int endLength)
{
	if (startLength > endLength)
	{
		return endLength;
	}

	long long int minNum = 0;
	long long int midLength = (startLength + endLength) / 2;

	for (int i = 0; i < K; i++)
	{
		minNum += arrLine[i] / midLength;
	}

	if (minNum < N)//너무 크게 잘라서 개수가 모자름
	{
		return FindLength(startLength, midLength - 1);
	}
	else
	{
		return FindLength(midLength + 1, endLength);
	}
}

int main()
{
	scanf("%d %d", &K, &N);
	long long int answer = 0;
	long long int minLine = 2147483648;
	long long int maxLine = 0;

	arrLine.resize(K, 0);

	for (int i = 0; i < K; i++)
	{
		long long int a;
		scanf("%lld", &a);
		arrLine[i] = a;

		if (arrLine[i] > maxLine)
			maxLine = arrLine[i];
		//maxLine = max(maxLine, a);

		if (arrLine[i] < minLine)
			minLine = arrLine[i];
		//minLine = min(minLine, a);
	}

	//sort(arrLine.begin(), arrLine.end());

	if ((N == K) && (maxLine == minLine))
	{
		answer = minLine;
		printf("%lld", answer);
	}
	else
	{
		if ((N > K) && (maxLine == 1))
		{
			printf("%lld", answer);//0
		}
		else
		{
			answer = FindLength(1, maxLine);
			printf("%lld", answer);
		}
	}
}
