#define _CRT_SECURE_NO_WARNINGS //gcc 제출시엔 지울 것!

#include "bits/stdc++.h"
using namespace std;

int main()
{
	int A, B, C;
	scanf("%d %d", &A, &B);
	scanf("%d", &C);

	int minutes = C + B;
	int hours = minutes / 60;
	minutes -= (60 * hours);
	hours += A;
	if (hours > 23)
		hours = hours % 24;

	printf("%d %d", hours, minutes);
}
