#include <bits/stdc++.h>
using namespace std;

struct Point
{
	long long x = 0, y = 0;
};

long long int CCW(Point A, Point B, Point C)
{
	long long int a = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
	if (a > 0) return 1;
	if (a == 0) return 0;
	return -1;
}

bool ComparePoint(Point left, Point right)
{
	bool result;
	if (left.x == right.x) {
		result = (left.y <= right.y);
	}
	else {
		result = (left.x <= right.x);
	}

	return result;// right가 left 보다 크면 true를 반환
}

int IsIntersect(pair< Point, Point > line1, pair<Point, Point > line2)
{
	Point l1_p1 = line1.first;
	Point l1_p2 = line1.second;
	Point l2_p1 = line2.first;
	Point l2_p2 = line2.second;

	int l1 = CCW(l1_p1, l1_p2, l2_p1) * CCW(l1_p1, l1_p2, l2_p2);
	int l2 = CCW(l2_p1, l2_p2, l1_p1) * CCW(l2_p1, l2_p2, l1_p2);
	if (l1 == 0 && l2 == 0)
	{
		if (ComparePoint(l1_p1, l1_p2))
			swap(l1_p1, l1_p2);
		if (ComparePoint(l2_p1, l2_p2))
			swap(l2_p1, l2_p2);

		return (ComparePoint(l2_p1, l1_p2) && ComparePoint(l1_p1, l2_p2));
	}

	return(l1 <= 0) && (l2 <= 0);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Point arrPoint[5];
	long long int answer = 0;

	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arrPoint[i].x = a;
		arrPoint[i].y = b;
		++i;
		arrPoint[i].x = c;
		arrPoint[i].y = d;
	}

	long long line1 = CCW(arrPoint[0], arrPoint[1], arrPoint[2]) * CCW(arrPoint[0], arrPoint[1], arrPoint[3]);// l1 기준
	long long line2 = CCW(arrPoint[2], arrPoint[3], arrPoint[0]) * CCW(arrPoint[2], arrPoint[3], arrPoint[1]);// l2 기준

	if ((line1 < 0) && (line2 < 0))
		answer = 1;


	if ((line1 == 0) && (line2 == 0))// 두 직선이 일직선 상에 존재
	{
		// Set the order of the points on Line1 in the order p1 < p2.
		if (ComparePoint(arrPoint[1], arrPoint[0]))
			swap(arrPoint[0], arrPoint[1]);

		// Set the order of the points on Line2 in the order p1 < p2.
		if (ComparePoint(arrPoint[3], arrPoint[2]))
			swap(arrPoint[2], arrPoint[3]);

		// See if the above conditions are met.	// 두 선분이 포개어져 있는지 확인
		answer = (ComparePoint(arrPoint[2], arrPoint[1])) && (ComparePoint(arrPoint[0], arrPoint[3]));
	}
	else// l1과 l2가 일직선 상에 있지 않는 경우
	{
		answer = (line1 <= 0) && (line2 <= 0);// l1 and l2 are not in same line.

	}

	cout << answer << "\n";
}