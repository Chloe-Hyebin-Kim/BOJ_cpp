#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x = 0, y = 0;
};

int CCW(Point A, Point B, Point C)
{
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Point arrPoint[4];
	int answer = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> arrPoint[i].x >> arrPoint[i].y;
	}

	int i32Result = CCW(arrPoint[0], arrPoint[1], arrPoint[2]);

	if (i32Result > 0)//D>0이면 반시계방향
		answer = 1;
	else if (i32Result == 0)//D=0인 경우는 평행
		answer = 0;
	else//D<0이면 시계방향
		answer = -1;
	

	cout << answer << "\n";
}
