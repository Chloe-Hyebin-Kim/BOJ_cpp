#include <bits/stdc++.h>
using namespace std;

#define lli long long int
long long int arrNum[1000002];
long long int arrSum[1000002];
long long int arrChange[1000002] = { 0 };
map <long long int, long long int> mapChange;

long long int  A1(long long int  b, long long int  c)
{
	lli tmp = arrNum[b];//a�� 1�� ��� b(1 �� b �� N)��° ���� c�� �ٲ�
	arrChange[b] = ((tmp - c) * (-1));
	mapChange.emplace(b, arrChange[b]);
	return tmp;
}

long long int  A2(lli b, lli c)
{
	lli tmp = arrSum[c] - arrSum[b - 1]; //b(1 �� b �� N)��° ������ c(b �� c �� N)��° �������� ��

	for (int i = b; i <= c; ++i)
	{
		map<lli, lli>::iterator it = mapChange.find(i);
		if (it != mapChange.end())
			tmp += mapChange[i];//���� ���� �ݿ�
	}

	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<lli> answer;
	lli N, M, K;
	cin >> N >> M >> K;
	arrNum[0] = 0;
	arrSum[0] = 0;

	for (int i = 0; i < N; i++)
	{
		lli a;
		cin >> a;
		arrNum[i + 1] = a;
		arrSum[i + 1] = arrSum[i] + a;
	}

	for (int i = 0; i < M + K; i++)
	{
		lli a, b, c;
		cin >> a >> b >> c;

		//lli z = 0;

		if (a == 1)
			A1(b, c);
		else {
			answer.push_back(A2(b, c));
			//z = A2(b, c);
			//cout << z << "\n";
		}
	}
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << "\n";
}