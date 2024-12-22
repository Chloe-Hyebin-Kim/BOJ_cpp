#include<bits/stdc++.h>
using namespace std;

int n, m, arr1[1000001], arr2[1000001], arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr1[i];
	for (int i = 1; i <= m; i++)
		cin >> arr2[i];

	int arr1_idx = 1, arr2_idx = 1;
	for (int i = 1; i <= n + m; i++)
	{
		if (arr1_idx > n) // 이미 arr1 배열의 모든 원소를 arr로 옮긴 상태면
			arr[i] = arr2[arr2_idx++]; // arr2의 원소를 arr에 옮김
		else if (arr2_idx > m) // 이미 arr2 배열의 모든 원소를 arr로 옮긴 상태면
			arr[i] = arr1[arr1_idx++]; // arr1의 원소를 arr로 옮김
		// arr1과 arr2 중 더 작은 값을 갖는 원소를 arr로 옮기고 포인터 증가
		else if (arr1[arr1_idx] < arr2[arr2_idx])
			arr[i] = arr1[arr1_idx++];
		else if (arr1[arr1_idx] >= arr2[arr2_idx])
			arr[i] = arr2[arr2_idx++];
	}

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';

	return 0;
}
