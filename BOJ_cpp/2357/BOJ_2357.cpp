#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int maxVal;  // 구간 최대값
	int minVal;  // 구간 최소값
};

int BuildMinSegTree(vector<Node>& arrSegTree, vector<int>& arr, int idx, int s, int e)
{
	if (s == e) return arrSegTree[idx].minVal = arr[s];
	else {
		return arrSegTree[idx].minVal = min(BuildMinSegTree(arrSegTree, arr, idx * 2, s, (s + e) / 2),
			BuildMinSegTree(arrSegTree, arr, idx * 2 + 1, (s + e) / 2 + 1, e));
	}
}

int BuildMaxSegTree(vector<Node>& arrSegTree, vector<int>& arr, int idx, int s, int e)
{
	if (s == e) return arrSegTree[idx].maxVal = arr[s];
	else {
		return arrSegTree[idx].maxVal = max(BuildMaxSegTree(arrSegTree, arr, idx * 2, s, (s + e) / 2),
			BuildMaxSegTree(arrSegTree, arr, idx * 2 + 1, (s + e) / 2 + 1, e));
	}
}

int QueryMin(vector<Node>& arrSegTree, int idx, int s, int e, int p, int q)
{
	if (q < s || e < p) return 2147000000;
	else if (p <= s && e <= q) return arrSegTree[idx].minVal;
	else {
		return min(QueryMin(arrSegTree, idx * 2, s, (s + e) / 2, p, q),
			QueryMin(arrSegTree, idx * 2 + 1, (s + e) / 2 + 1, e, p, q));
	}
}

int QueryMax(vector<Node>& arrSegTree, int idx, int s, int e, int p, int q)
{
	if (q < s || e < p) return 0;
	else if (p <= s && e <= q) return arrSegTree[idx].maxVal;
	else {
		return max(QueryMax(arrSegTree, idx * 2, s, (s + e) / 2, p, q),
			QueryMax(arrSegTree, idx * 2 + 1, (s + e) / 2 + 1, e, p, q));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<pair< int, int> > answer;
	int n, m;
	cin >> n >> m;

	vector<int> arrInput; //입력배열
	arrInput.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arrInput[i];

	vector<Node> arrSegmentTree;    // 구간 최대/최소값 세그먼트 트리

	int k = ceil(log2(n));//세그먼트 트리 높이
	int leafStart = 1 << k;//리프노드 시작 인덱스
	int segSize = 2 * leafStart;//세그먼트 트리 배열 크기

	arrSegmentTree.resize(segSize);
	BuildMinSegTree(arrSegmentTree, arrInput, 1, 0, n - 1);
	BuildMaxSegTree(arrSegmentTree, arrInput, 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		pair<long long int, long long int> tmp;
		tmp.first = QueryMin(arrSegmentTree, 1, 0, n - 1, a, b);
		tmp.second = QueryMax(arrSegmentTree, 1, 0, n - 1, a, b);
		answer.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
		cout << answer[i].first << " " << answer[i].second << "\n";

	return 0;
}
