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
		if (arr1_idx > n) // �̹� arr1 �迭�� ��� ���Ҹ� arr�� �ű� ���¸�
			arr[i] = arr2[arr2_idx++]; // arr2�� ���Ҹ� arr�� �ű�
		else if (arr2_idx > m) // �̹� arr2 �迭�� ��� ���Ҹ� arr�� �ű� ���¸�
			arr[i] = arr1[arr1_idx++]; // arr1�� ���Ҹ� arr�� �ű�
		// arr1�� arr2 �� �� ���� ���� ���� ���Ҹ� arr�� �ű�� ������ ����
		else if (arr1[arr1_idx] < arr2[arr2_idx])
			arr[i] = arr1[arr1_idx++];
		else if (arr1[arr1_idx] >= arr2[arr2_idx])
			arr[i] = arr2[arr2_idx++];
	}

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';

	return 0;
}