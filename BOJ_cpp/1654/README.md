#  **[ 1654 : 랜선 자르기 ]**


🔗[문제링크](https://www.acmicpc.net/problem/1654)

###  **[통과 시의 스펙]**
![image](https://github.com/user-attachments/assets/2f7d95bd-c2fa-43be-90dd-52aef1387385)





### **[해결 과정]**

- 문제해석
1. 뻘짓버전
   1. 가장 긴줄을  N으로 나누고 그 길이를 최소 길이로 하고
   2. 그 최소 길이를 2배 3배... 해주면서 N을 넘어가는 순간을 구합니다 .
   3. N이 안넘은 길이에  최소 길이/2 를 한 것을  더하고 (아까 온전히 다 더했을때 넘었으니까)  N을  안넘으면 또  반으 나눈 것을 더하고......(반복_)
   4. 그렇게 최소길이를 반으로 반으로 반으로 나무면서 더하다가 N을 구한다.
<details>
<summary> 뻘짓버전 코드  </summary>

<!-- summary 아래 한칸 공백 두어야함 -->
```
#include "bits/stdc++.h"
using namespace std;

int K, N;//이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N
vector<long long int> arrLine;// 이미 가지고 있는 랜선의 길이

int FindLength(long long int& minLength, long long int& maxLength, long long int& tmpLength)
{
	long long int  maxLen = 0;

	while (true)
	{
		int minNum = 0;
		minLength += tmpLength;

		for (int i = 0; i < K; i++)
		{
			minNum += arrLine[i] / minLength;
		}

		if (minNum < N)
		{
			maxLen = minLength;

			maxLength = minLength;
			minLength -= tmpLength;

			tmpLength = tmpLength / 2;

			break;
		}
		else
		{
			tmpLength = tmpLength / 2;
			if (tmpLength <= 1)
			{
				break;
			}

		}
	}

	return tmpLength;
}

int main()
{
	scanf("%d %d", &K, &N);
	long long int answer = 0;

	arrLine.resize(K, 0);
	for (int i = 0; i < K; i++)
	{
		long long int a;
		scanf("%lld", &a);
		arrLine[i] = a;
	}

	sort(arrLine.begin(), arrLine.end());

	if ((N == K) && (arrLine[K - 1] == arrLine[0]))
	{
		answer = arrLine[0];
		printf("%lld", answer);
	}
	else
	{
		long long int smallLength = arrLine[K - 1] / N;
		long long int minLength = 0;
		long long int maxLength = 0;
		if (smallLength == 0)
		{
			printf("0");
		}
		else
		{
			while (true)
			{
				int minNum = 0;
				minLength += smallLength;

				for (int i = 0; i < K; i++)
				{
					minNum += arrLine[i] / minLength;
				}

				if (minNum < N)
				{
					maxLength = minLength;
					break;
				}
			}

			maxLength = minLength;
			minLength -= smallLength;

			long long int tmpLength = smallLength / 2;

			while (tmpLength >= 1)
			{
				tmpLength = FindLength(minLength, maxLength, tmpLength);
			}

			answer = minLength;
			printf("%lld", answer);
		}
	}
}
```
</details>

  
2. 정답버전
   1. 가장 긴줄의 길이를 넘을 수 없음...!!!!!
   2. 따라서 가장 긴줄을 기준으로 1부터 가장 긴줄(이하 ```maxLine``` ) 까지 하나씩 증가시키며 찾는..것이 아니라!
   3. 그 CCTV 탐색기법!(학교에서 배운) 절반 잘라서 확인 -> 유효 영역 선택 후 다시 절반 잘라서 확인->  반복
  


- 풀이
1. 뻘짓 풀이의 반례
```
5 6
5
5
5
5
6
//answer : 3

//////

5 6
4
4
4
4
5
//answer : 3
```




### **[느낀 점]**
1. 나는 멍청이다. _~~tlqkf~~_


