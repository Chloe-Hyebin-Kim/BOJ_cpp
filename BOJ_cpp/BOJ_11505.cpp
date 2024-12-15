#include "bits/stdc++.h"
using namespace std;
#define lli unsigned long long int
int n, m, k;
int leafStart;
vector<int> arrInput;
vector<lli> arrSegmentTree;
vector<lli> answer;

lli MakeSegmentTree(int start, int end, int node)
{
	if (start == end)
	{
		arrSegmentTree[node] = arrInput[start] % 1000000007;
	}
	else
	{
		int mid = (start + end) / 2;
		arrSegmentTree[node] = (MakeSegmentTree(start, mid, 2 * node) % 1000000007) * (MakeSegmentTree(mid + 1, end, 2 * node + 1) % 1000000007);
	}

	return arrSegmentTree[node];
}

lli ChangeSegmentTree(int node, int start, int end, int idx, int newValue)
{
	if (start == end)
	{
		arrSegmentTree[node] = newValue % 1000000007;
	}
	else
	{
		int mid = (start + end) / 2;

		if (idx <= mid)
			ChangeSegmentTree(2 * node, start, mid, idx, newValue);
		else
			ChangeSegmentTree(2 * node + 1, mid + 1, end, idx, newValue);

		arrSegmentTree[node] = (arrSegmentTree[2 * node] % 1000000007) * (arrSegmentTree[2 * node + 1] % 1000000007);
	}

	return arrSegmentTree[node];
}

lli MultipleSegmentTree(int start, int end, int node, int left, int right)
{
	if (right < start || end < left)
	{
		//���� ��
		return 1;//�׵�����!!!
	}

	if (left <= start && end <= right)
	{
		//�Ϻ��ϰ� ���� ���� ����
		return arrSegmentTree[node] % 1000000007;
	}

	int mid = (start + end) / 2;
	return	((MultipleSegmentTree(start, mid, 2 * node, left, right) * MultipleSegmentTree(mid + 1, end, 2 * node + 1, left, right)) % 1000000007);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;//���� ����: N(1 �� N �� 1,000,000)�� .  ���� ������ �Ͼ�� Ƚ��: M(1 �� M �� 10,000), ������ ���� ���ϴ� Ƚ��: K(1 �� K �� 10,000)

	int h = ceil(log2(n));
	leafStart = 1 << h;//������� ���� �ε���
	int segSize = 2 * leafStart;//���׸�Ʈ Ʈ�� �迭 ũ��

	arrSegmentTree.resize(segSize);
	arrInput.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arrInput[i];

	MakeSegmentTree(0, n - 1, 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c; //a�� 1�� ��� b��° ���� c�� �ٲٰ� a�� 2�� ��쿡�� b���� c������ ���� ���Ͽ� ���
		cin >> a >> b >> c;

		if (a == 1)//b��° ���� c�� �ٲٰ�
		{
			ChangeSegmentTree(1, 0, n - 1, b - 1, c);
		}
		else if (a == 2)//b���� c������ ���� ���Ͽ� ���
		{
			lli ans = MultipleSegmentTree(0, n - 1, 1, b - 1, c - 1);

			answer.push_back(ans);
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}