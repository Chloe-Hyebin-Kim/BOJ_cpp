#include "bits/stdc++.h"
using namespace std;

int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

int n, m;
vector<vector<int> > arrInput;
vector<vector<int> > arrVisited;

void BFS(int starti, int startj)
{
    queue<pair<int, int> > q;
	q.push({ starti,startj });
	arrVisited[starti][startj] = 1;

	while (!q.empty())
	{
		pair<int, int> ele = q.front();
		q.pop();

		int x = ele.first;
		int y = ele.second;

		for (int i = 0; i < 4; i++)
		{
			int dx = x + moveX[i];
			int dy = y + moveY[i];

			if (dx < 0 || dx >= n || dy < 0 || dy >= m) //행렬 벗어남
				continue;

			if (arrInput[dx][dy] == 0)// 갈수 없는 길
				continue;

			if (0 == arrVisited[dx][dy]) //방문 안한 곳
			{
				q.push({ dx,dy }); 
				arrVisited[dx][dy] = arrVisited[x][y] + 1; //각 칸 진행 스텝 단계
        //answer++; //이방식으로 하면 잘 못 갔던 길도 다 포함 됨
        
				if ((dx == (n - 1)) && (dy == (m - 1)))
				{
					queue<pair<int, int> > emptyQueue;
					swap(q, emptyQueue);//재귀 끝내기 위해 비어있는 큐랑 바꿔치기!!!

					break;
				}
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	arrInput.resize(n, vector<int>(m, 0));
	arrVisited.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		char row[101];
		cin >> row;

		for (int j = 0; j < m; j++)
		{
			char tmpChar = row[j];
			arrInput[i][j] = tmpChar - '0';
		}
	}
    
	BFS(0, 0);
	cout << arrVisited[n - 1][m - 1];

	return 0;
}
