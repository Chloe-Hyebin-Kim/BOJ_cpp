#include <bits/stdc++.h>
using namespace std;

#define FOR(x,y) for(int i=x; i<y; i++)

int Char2Int(int uniNum)
{
	int iChar = 2;
	switch (uniNum)
	{
	case 17:
	case 18:
	case 19:
	{
		iChar = 3;
	}
	break;

	case 20:
	case 21:
	case 22:
	{
		iChar = 4;
	}
	break;

	case 23:
	case 24:
	case 25:
	{
		iChar = 5;
	}
	break;

	case 26:
	case 27:
	case 28:
	{
		iChar = 6;
	}
	break;

	case 29:
	case 30:
	case 31:

	{
		iChar = 7;
	}
	break;

	case 32:
	case 33:
	case 34:
	case 35:
	{
		iChar = 8;
	}
	break;

	case 36:
	case 37:
	case 38:

	{
		iChar = 9;
	}
	break;

	case 39:
	case 40:
	case 41:
	case 42:
	{
		iChar = 10;
	}
	break;

	default:
		break;
	}

	return iChar;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int answer = 0;
	string str;
	cin >> str;

	int len = str.length();

	const char* chars = str.c_str();
	auto aa = chars[0];
	auto aaa = chars[0] - '0';//A=65. '0'=48

	for (int i = 0; i < len; i++)
	{
		int uniNum = chars[i] - '0';//A=65. '0'=48
		answer += Char2Int(uniNum);
	}

	cout << answer;
}