#include "bits/stdc++.h"
using namespace std;

#define NUMMAX 1000002
int CalNum(int num);
vector <int> arrNum;

int CalNum(int num)
{
	int a = NUMMAX;
	int b = NUMMAX;
	int c = NUMMAX;

	if ((arrNum[num] != NUMMAX) || (num == 1))
	{
		return arrNum[num];
	}

	if (num & 1)//(홀수 & 1) == 1
	{
		if ((num % 3) == 0)
		{
			//3으로 나누어 떨어짐
			//a = CalNum(num / 2); //2로 나눠떨어지지 않는 수는 할 필요없음
			b = CalNum(num / 3);
			c = CalNum(num - 1);
		}
		else
		{
			//11이나 7 같은 소수....
      //a = CalNum(num / 2); //2로 나눠떨어지지 않는 수는 할 필요없음
			//b = CalNum(num / 3); //3으로 나눠떨어지지 않는 수는 할 필요없음
			c = CalNum(num - 1);
		}
	}
	else//(짝수 & 1) == 0
	{
		if ((num % 3) == 0)
		{
			//6배수
			a = CalNum(num / 2);
			b = CalNum(num / 3);
			c = CalNum(num - 1);
		}
		else
		{
			//걍 2배수
			a = CalNum(num / 2);
      //b = CalNum(num / 3); //3으로 나눠떨어지지 않는 수는 할 필요없음
			c = CalNum(num - 1);
		}
	}

	int tmp = min(a, min(b, c));
	arrNum[num] = tmp + 1;//a,b,c는 연산을 한번 해준 숫자들이니까!

	return arrNum[num];
}

int main()
{
  arrNum.resize(NUMMAX, NUMMAX);
	int num;
	scanf("%d", &num);

	arrNum[1] = 0;
	arrNum[2] = 1;
	arrNum[3] = 1;
	arrNum[4] = 2;
	arrNum[5] = 3;
	arrNum[6] = 2;
	arrNum[7] = 3;
	arrNum[8] = 3;
	arrNum[9] = 2;
  
//num 을 입력받으면 1부터 num 까지 캐싱해서 찾는게 젤 빠름,,,,
	int answer = CalNum(num);
	printf("%d", answer);
}
