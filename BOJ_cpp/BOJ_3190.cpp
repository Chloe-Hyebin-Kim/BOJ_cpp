#include <bits/stdc++.h>
using namespace std;

int N; //보드의 크기
int K; //사과의 개수
int L; //뱀의 방향 변환 횟수

int Board[102][102];//N x N
deque< pair<int, int> > Snake;
vector<int> SnakeDir;
int answer;

int dir[4][2] = { {0,+1},{+1,0},{0,-1},{-1,0} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N; //보드의 크기
	cin >> K; //사과의 개수

	for (int i = 0; i < N + 2; ++i)
	{
		Board[0][i] = 1; //벽
		Board[i][0] = 1; //벽
		Board[i][N + 1] = 1; //벽
		Board[N + 1][i] = 1; //벽
	}

	for (int i = 0; i < K; ++i)
	{
		int a, b; //첫 번째 정수는 행, 두 번째 정수는 열 위치
		cin >> a >> b;
		Board[a][b] = 2; //사과
	}

	cin >> L; //뱀의 방향 변환 횟수

	SnakeDir.push_back(0);
	int dirN = 0;

	for (int i = 0; i < L; ++i)
	{
		int a; //게임 시작 시간으로부터 X초
		char c; // 왼쪽(C가 'L') 또는 오른쪽(C가 'D')
		cin >> a >> c;

		vector<int>::iterator it = SnakeDir.end();
		it = SnakeDir.insert(it, a - SnakeDir.size(), dirN); // 마지막부터 dirN을 	a - SnakeDir.size() 개 삽입

		if (c == 'D') //오른쪽
		{
			dirN += 1;
			if (dirN > 3)
				dirN = 0;
		}
		else
		{
			dirN -= 1;
			if (dirN < 0)
				dirN = 3;
		}
	}

	SnakeDir.push_back(dirN);

	int x = 1;
	int y = 1;

	int idxMove = 0;
	bool result = true;

	for (int i = 0; i < SnakeDir.size(); ++i)
	{
		idxMove = SnakeDir[i] % 4;

		Snake.push_front(make_pair(x, y));
		x += dir[idxMove][0];
		y += dir[idxMove][1];

		if (Board[x][y] == 2)//사과가 있으면
		{
			//Board[x][y]=0;//사과가 없어짐

			pair<int, int> tmpBack = Snake.back();
			Board[tmpBack.first][tmpBack.second] = 1;//뱀
			Board[x][y] = 1;//뱀
		}
		else if (Board[x][y] == 1)//벽이나 꼬리
		{
			answer = i + 1;//끝!
			result = false;

			break;
		}
		else//(Board[x][y] == 0)//빈칸
		{
			pair<int, int> tmpBack = Snake.back();
			Board[tmpBack.first][tmpBack.second] = 0;//뱀
			Snake.pop_back(); // 꼬리지움

			Board[x][y] = 1;//뱀
		}
	}
	if (result)
	{
		int i = SnakeDir.size();

		Snake.push_front(make_pair(x, y));

		while (result)
		{
			x += dir[idxMove][0];
			y += dir[idxMove][1];

			Snake.push_front(make_pair(x, y));

			if (Board[x][y] == 2)//사과가 있으면
			{
				//Board[x][y]=0;//사과가 없어짐

				pair<int, int> tmpBack = Snake.back();
				Board[tmpBack.first][tmpBack.second] = 1;//뱀
				Board[x][y] = 1;//뱀
			}
			else if (Board[x][y] == 1)//벽이나 꼬리
			{
				answer = i + 1;//끝!
				result = false;
				break;
			}
			else//(Board[x][y] == 0)//빈칸
			{
				Board[x][y] = 1;//뱀

				pair<int, int> tmpBack = Snake.back();
				Board[tmpBack.first][tmpBack.second] = 0;//뱀
				Snake.pop_back(); // 꼬리지움
			}

			i++;
		}
	}

	cout << answer;
}