#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	vector <string> answer;
	for (int i = 0; i < T; i++)
	{
		int  H, W, N;
		cin >> H >> W >> N;

		int iX = (N / H) + 1;//호수
		int iY = (N % H);//층수

		if (iY == 0)
		{
			iX -= 1;//딱나눠 떨어짐 (꼭대기층)
			iY = H;
		}
		string X = to_string(iX);
		string Y = to_string(iY);

		string strRoom = "";
		//int i32Room = 0;

		if (iX < 10)
		{
			strRoom = (Y + "0" + X);
			//i32Room = atoi((strRoom).c_str());
		}
		else
		{
			strRoom = (Y + X);
			//i32Room = atoi(strRoom.c_str());
		}
		//cout << strRoom << "\n";
		answer.push_back(strRoom);
		//answer.push_back(i32Room);
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << "\n";
}
