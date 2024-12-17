#include <bits/stdc++.h>
using namespace std;
long long int segtree[4500];
vector<int> start_p[2001];
int leafNode_startIndex;

long long int init_segtree(int start, int end, int node)
{
	if (start == end)
		return segtree[node] = 0;
	int mid = (start + end) / 2;
	return segtree[node] = init_segtree(start, mid, node * 2) + init_segtree(mid + 1, end, node * 2 + 1);
}

long long int query(int l, int r)
{
	long ret = 0;
	int left = leafNode_startIndex + l;
	int right = leafNode_startIndex + r;

	while (left < right)
	{
		if (left % 2 == 1) {
			ret += segtree[left++];
		}
		if (right % 2 == 0) {
			ret += segtree[right--];
		}

		left /= 2;
		right /= 2;
	}

	if (left == right) {
		ret += segtree[left];
	}
	return ret;
}

void update(int idx)
{
	int pos = leafNode_startIndex + idx;
	segtree[pos]++;

	while (pos > 1) {
		pos /= 2;
		segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n, m;
	long long int result = 0;

	cin >> n >> m;
	//N과 간선의 개수 M이 주어진다.
	//그 다음 줄부터 M + 1번째 줄까지 두 개의 수(i, j)가 주어지는데
	//이는 왼쪽 그룹의 i번 정점과 오른쪽 그룹의 j번 정점을 연결하는 간선이 있다는 의미이다.
	//중복되는 간선이 입력으로 주어지지 않는다.

	int tree_height = ceil(log2(n) + 1);
	leafNode_startIndex = 1 << (tree_height - 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		start_p[a].push_back(b);
	}
	init_segtree(1, n, 1);

	for (int i = 1; i < n + 1; i++)
	{
		for (int v : start_p[i])
			result += query(v + 1, n);
		for (int v : start_p[i])
			update(v);
	}
	cout << result;
}