#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int leafNode_startIndex;
lli segtree[1000002];

vector<lli> answer; //사이즈는 K
vector<lli> SegmentTree; //사이즈는 K

lli arrNum[1000002] = { 0, };
lli arrSum[1000002] = { 0, };

lli init_segtree(int start, int end, int node)
{
	if (start == end)
	{
		segtree[node] = 0;
	}
	else
	{
		int mid = (start + end) / 2;
		lli nextSegTree = init_segtree(start, mid, (node * 2)) + init_segtree(mid + 1, end, (node * 2 + 1));
		segtree[node] = nextSegTree;
	}

	return segtree[node];
}

lli Query(int b, int c)
{
	lli ret = 0;

	//if (a == 2)	// a가 2인 경우에는 b번째 수부터 c번째 수까지의 합
	//{
	ret = arrSum[c] - arrSum[b - 1];
	for (int j = b; j < c + 1; ++j)
	{
		ret += arrNum[j];
	}

	answer.push_back(ret);
	//}
	//else if (a == 1)	// a가 1인 경우 b번째 수를 c로 바꿈
	//{
	//	//lli tmp = arrNum[b];
	//	//arrNum[b] = c;

	//	lli i32b = arrSum[b] - arrSum[b - 1];//==arrNum[b]
	//	ret = i32b + (c - i32b);
	//}

	return ret;
}

void Update_SegmentTree(int Node, int Start, int End, int Index, int Diff)
{
	if (Index< Start || Index > End)
		return;

	SegmentTree[Node] = SegmentTree[Node] + Diff;
	if (Start != End)
	{
		int Mid = (Start + End) / 2;

		Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
		Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
	}
}

///Node = 노드 번호
///Start End = 해당 노드가 포함하고 있는 범위
///Left, Right = 구하고자 하는 범위
lli Sum(int Node, int Start, int End, int Left, int Right)
{
	lli rst = 0;

	if (Left > End || Right < Start)//탐색하고 있는 범위가 구하고자 하는 범위와 완전히 일치하지 않는 경우.
		rst = 0;//따라서 더 이상의 탐색은 무의미하다.

	if (Left <= Start && End <= Right) //탐색하고 있는 범위가 구하고자 하는 범위에 완전히 속해있는 경우.
		rst = SegmentTree[Node];//재빨리 해당 노드의 값을 반환!

	//일부만 걸쳤으므로 더 깊은 탐색을 진행해봐야 하는 경우
	lli Mid = (Start + End) / 2;
	lli Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
	lli Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
	rst = Left_Result + Right_Result;

	return rst;
}

lli Make_SegmentTree(int Node, int Start, int End)
{
	lli rst = 0;

	if (Start == End)//더 이상 나눌 수 있는 범위가 없다==이는 더 이상의자식을 가질 수 없음==즉, 리프노드
		SegmentTree[Node] = arrNum[Start]; //재귀함수에서 기저조건에 해당하는 부분!(재귀의 종료)

	lli Mid = (Start + End) / 2;
	lli Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	lli Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	SegmentTree[Node] = Left_Result + Right_Result;
	rst = SegmentTree[Node];

	return rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// N : 수의 개수 (1 ≤ N ≤ 1000000)
	// M : 수의 변경이 일어나는 횟수 (1 ≤ M ≤ 10000)
	// K : 구간의 합을 구하는 횟수

	lli N, M, K;

	cin >> N >> M >> K;
	//scanf("%lld %lld %lld", &N, &M, &K);

	int tree_height = ceil(log2(N) + 1);
	leafNode_startIndex = 1 << (tree_height - 1);

	//int Tree_Height = (int)ceil(log2(N));//세그트리 높이
	//int Tree_Size = (1 << (Tree_Height + 1));//세그트리 크기
	//SegmentTree.resize(Tree_Size);//벡터배열 크기 정의
	SegmentTree.resize(N * 4);//벡터배열 크기 정의

	arrNum[0] = 0;
	//arrSum[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> arrNum[i];
		//lli a;
		//cin >> a;
		//arrSum[i] = a;
		//arrNum[i] = a;
	}

	//init_segtree(1, N, 1);
	Make_SegmentTree(1, 1, N);

	for (int i = 0; i < M + K; ++i)
	{
		lli a, b, c;
		cin >> a >> b >> c;
		//int a, b, c;
		//scanf("%d %d %d", &a, &b, &c);

		if (a == 1)	// a가 1인 경우 b번째 수를 c로 바꿈
		{
			Update_SegmentTree(b, b + 1, N, b, c - arrNum[b]);
			//lli i32b = arrSum[b] - arrSum[b - 1];
			//arrNum[b] = c - i32b;
		}
		else// a가 2인 경우에는 b번째 수부터 c번째 수까지의 합
		{
			lli i32b = Sum(1, 1, N, b, c);
			answer.push_back(i32b);

			//Query(b, c);
			/*lli i32b = arrSum[c] - arrSum[b - 1];
			for (int j = b; j < c + 1; ++j)
			{
				i32b += arrNum[j];
			}

			answer.push_back(i32b);*/
		}
	}

	for (int i = 0; i < K; ++i)
		cout << answer[i] << "\n";//printf("%lld\n", answer[i]); //
}