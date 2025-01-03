#include "bits/stdc++.h"
using namespace std;

stack <int> stkNum;
vector <char> arrOutput;

int main()
{
	int num;
	scanf("%d", &num);

	int ptr = 0;
	for (int i = 0; i < num; i++)
	{
		int a;
		scanf("%d", &a);

		while (ptr < a)
		{
			++ptr;
			stkNum.push(ptr);
			arrOutput.push_back('+');
		}

		if (!stkNum.empty())
		{
			int len = stkNum.size();
			for (int j = 0; j < len; j++)
			{
				if (stkNum.top() == a)
				{
					stkNum.pop();
					arrOutput.push_back('-');
					break;
				}
				else
				{
					stkNum.pop();
					arrOutput.push_back('-');
				}
			}
		}
		else
		{
			if (ptr <= num)
			{
				arrOutput.clear();
				break;
			}
		}
	}

	if (arrOutput.empty())
	{
		printf("%s", "NO");
	}
	else
	{
		for (int i = 0; i < arrOutput.size(); i++)
		{
			printf("%c", arrOutput[i]);
			printf("\n");
		}
	}
}
