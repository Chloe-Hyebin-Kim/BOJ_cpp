#include<bits/stdc++.h>
using namespace std;
char valN[1001][301];
char* GetVal(int inputVal);
void TotalSum(int inputVal);

void TotalSum(int inputVal)
{
	int temp = inputVal - 1;
	strcpy(valN[temp], GetVal(temp));
	if (valN[temp][0] != '\0')
	{
		string str_tmp = valN[temp];
		int str_size = str_tmp.size() - 1;

		string a = str_tmp;
		string b = str_tmp;
		for (int i = str_size; i >= 0; i--)
		{
			a[i] += (b[i] - '0');
			if (a[i] > '9' && i > 0)
			{
				int d = a[i] - '0';
				a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
				a[i] = (d % 10) + '0';
			}
			if (i == str_size)
			{
				if (inputVal % 2 == 0)
					a[i] = ((a[i] - '0') + 1) + '0';
				else
					a[i] = ((a[i] - '0') - 1) + '0';
			}
		}
		if (a[0] > '9')
		{
			string k;
			k += a[0];
			a[0] = ((a[0] - '0') % 10) + '0';
			k[0] = ((k[0] - '0') / 10) + '0';
			a = k + a;
		}
		strcpy(valN[inputVal], a.c_str());
	}
}

char* GetVal(int inputVal)
{
	if (inputVal > 10 && valN[inputVal][0] == '\0')
	{
		TotalSum(inputVal);
	}
	return valN[inputVal];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	valN[0][0] = '0';
	valN[1][0] = '0';
	valN[2][0] = '1';
	valN[3][0] = '1';
	valN[4][0] = '3';
	valN[5][0] = '5';
	valN[6][0] = '1';
	valN[6][1] = '1';
	valN[7][0] = '2';
	valN[7][1] = '1';
	valN[8][0] = '4';
	valN[8][1] = '3';
	valN[9][0] = '8';
	valN[9][1] = '5';
	valN[10][0] = '1';
	valN[10][1] = '7';
	valN[10][2] = '1';

	string str;
	while (getline(cin, str))
	{
		int n = stoi(str);
		if (cin.eof()) break;

		if (valN[n][0] != '\0') { cout << valN[n] << "\n"; }
		else if (valN[n][0] == '\0') { cout << GetVal(n) << "\n"; }
		else if (n <= 0 || n > 1000)  return 0;
	}
}