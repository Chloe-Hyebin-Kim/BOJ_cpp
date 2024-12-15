#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int maxVal;  // 구간 최대값
	int minVal;  // 구간 최소값
};

vector<Node> arrSegmentTree;    // 구간 최대/최소값 세그먼트 트리
vector<int> arrInput;     // 입력 배열
vector<pair<int, int> > arrRange;
vector<pair<int, int> > answer;
int i32InputSize;   // 배열의 크기
int k;
int leafStart;

// 세그먼트 트리 빌드 함수
Node BuildMinMaxSegmentTree(int node, int start, int end)
{
	Node result;

	if (start == end) // 리프 노드: 배열의 값을 트리에 저장
	{
		arrSegmentTree[node+1].maxVal = arrInput[end-1];
		arrSegmentTree[node+1].minVal = arrInput[end-1];	//if (node > leafStart)
		//{
		//arrSegmentTree[node].maxVal = arrInput[node - leafStart];
		//arrSegmentTree[node].minVal = arrInput[node - leafStart];
		//}

		result = arrSegmentTree[node];
		return result;
	}

	int mid = (start + end) / 2;
	Node leftResult = BuildMinMaxSegmentTree(2 * node, start, mid);      // 왼쪽
	Node rightResult = BuildMinMaxSegmentTree(2 * node + 1, mid + 1, end);   // 오른쪽

	arrSegmentTree[node].minVal = min(leftResult.minVal, rightResult.minVal);
	arrSegmentTree[node].maxVal = max(leftResult.maxVal, rightResult.maxVal);

	result = arrSegmentTree[node];
	return result;
}

// 구간 최대/최소값 쿼리 함수
Node QueryUpdate(int node, int s, int e, int l, int r)
{
	vector<Node> arrCopySegmentTree = arrSegmentTree;    // 구간 최대/최소값 세그먼트 트리
	Node result;

	if (l > e || r < s)
	{
		result.maxVal = max(arrCopySegmentTree[l].maxVal, arrCopySegmentTree[r].maxVal);
		result.minVal = min(arrCopySegmentTree[l].minVal, arrCopySegmentTree[r].minVal);

		return result;
	}

	if ((l <= s) && (e <= r))
	{
		result.maxVal = arrCopySegmentTree[node].maxVal;
		result.minVal = arrCopySegmentTree[node].minVal;

		return result;
	}

	int m = (s + e) / 2;
	result.maxVal = max(QueryUpdate(node * 2, s, m, l, r).maxVal, QueryUpdate(node * 2 + 1, m + 1, e, l, r).maxVal);
	result.minVal = min(QueryUpdate(node * 2, s, m, l, r).minVal, QueryUpdate(node * 2 + 1, m + 1, e, l, r).minVal);

	return result;
}

Node QueryMaxMin(int node, int start, int end, int left, int right)
{
	Node result;
	/* 구간이 겹치지 않음 */
	if ((right < start) || (end < left))
	{
		result.maxVal = max(arrSegmentTree[right].maxVal, arrSegmentTree[left].maxVal);
		result.minVal = min(arrSegmentTree[right].minVal, arrSegmentTree[left].minVal);

		return result;
	}

	/* 구간이 완전히 포함됨 */
	if ((left <= start) && (end <= right))
	{
		result.maxVal = arrSegmentTree[node].maxVal;
		result.minVal = arrSegmentTree[node].minVal;
		return result;
	}

	/* 구간이 일부만 겹침 */
	int mid = (start + end) / 2;
	result.maxVal = max(QueryUpdate(node * 2, start, mid, left, right).maxVal, QueryUpdate(node * 2 + 1, mid + 1, end, left, right).maxVal);
	result.minVal = min(QueryUpdate(node * 2, start, mid, left, right).minVal, QueryUpdate(node * 2 + 1, mid + 1, end, left, right).minVal);

	//int l = 2 * node;  //node의 왼쪽 자식
	//int r = 2 * node + 1; //node의 오른쪽 자식
	//Node leftResult = QueryMaxMin(l, start, mid, left, right);
	//Node rightResult = QueryMaxMin(r, mid + 1, end, left, right);

	////result.maxVal = max(QueryMaxMin(l, start, mid, left, right).maxVal, QueryMaxMin(r, mid + 1, end, left, right).maxVal);
	////result.minVal = min(QueryMaxMin(l, start, mid, left, right).minVal, QueryMaxMin(r, mid + 1, end, left, right).minVal);
	//result.maxVal = max(leftResult.maxVal, rightResult.maxVal);
	//result.minVal = min(leftResult.minVal, rightResult.minVal);

	return result;
}

// 구간 최대/최소값 쿼리 호출 함수
pair<int, int> Query(int left, int right)
{
	Node result = QueryMaxMin(1, 1, i32InputSize, left, right);
	return { result.minVal,result.maxVal };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int  N, M;
	cin >> N >> M;

	i32InputSize = N;
	k = ceil(log2(N) + 1);//세그먼트 트리 높이
	leafStart = 1 << k - 1;
	int segSize = 2 * leafStart;  // 세그먼트 트리 크기
	arrSegmentTree.resize(segSize, { INT_MIN, INT_MAX }); // 초기화

	for (int i = 0; i < N; ++i)
	{
		int i32Num;
		cin >> i32Num;
		arrInput.push_back(i32Num);//arrInput

		arrSegmentTree[leafStart + i].maxVal = i32Num;
		arrSegmentTree[leafStart + i].minVal = i32Num;
	}

	BuildMinMaxSegmentTree(1, 1, N);  // 세그먼트 트리 빌드

	for (int i = 0; i < arrSegmentTree.size(); ++i)
	{
		cout << "[ Index " << i << " ]" << " Min : " << arrSegmentTree[i].minVal << " , " << " Max : " << arrSegmentTree[i].maxVal << "\n";
	}
	//for (int i = 0; i < M; ++i)
	//{
	//	int a, b;
	//	cin >> a >> b;
	//	arrRange.push_back({ a,b });

	//	Node tmpNode = QueryUpdate(1, 0, N-1 , a, b);//(1,  0, N-1, a, b);
	//	pair<int, int> tmp = { tmpNode.minVal, tmpNode.maxVal };
	//	answer.push_back(tmp);
	//}

	///*for (int i = 0; i < M; ++i)
	// {
	//     Node tmpNode = QueryMaxMin(1, 1, N, arrRange[i].first, arrRange[i].second);
	//     pair<int, int> tmp = { tmpNode.minVal, tmpNode.maxVal };
	//     answer.push_back(tmp);
	// }*/

	//for (int i = 0; i < M; ++i)
	//{
	//	cout << answer[i].first << " " << answer[i].second << "\n";
	//}
	return 0;
}