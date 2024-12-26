#define _CRT_SECURE_NO_WARNINGS

#include "bits/stdc++.h"
using namespace std;

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);//상근이가 설정한 알람 시간

	int minutes = (60 * A) + B;
	int hours = 0;
  
	if (minutes < 45){
		hours = 23;
		minutes += 15;
	}
	else{
		minutes -= 45;
		hours = minutes / 60;
		minutes -= (60 * hours);

		if (hours > 23)
			hours = hours % 24;
		
	}

	printf("%d %d", hours, minutes);
}
