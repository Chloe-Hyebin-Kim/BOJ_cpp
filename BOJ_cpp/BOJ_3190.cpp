#include <bits/stdc++.h>
using namespace std;

int N; //������ ũ��
int K; //����� ����
int L; //���� ���� ��ȯ Ƚ��

int Board[102][102];//N x N
deque< pair<int, int> > Snake;
vector<int> SnakeDir;
int answer;

int dir[4][2] = { {0,+1},{+1,0},{0,-1},{-1,0} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N; //������ ũ��
	cin >> K; //����� ����

	for (int i = 0; i < N + 2; ++i)
	{
		Board[0][i] = 1; //��
		Board[i][0] = 1; //��
		Board[i][N + 1] = 1; //��
		Board[N + 1][i] = 1; //��
	}

	for (int i = 0; i < K; ++i)
	{
		int a, b; //ù ��° ������ ��, �� ��° ������ �� ��ġ
		cin >> a >> b;
		Board[a][b] = 2; //���
	}

	cin >> L; //���� ���� ��ȯ Ƚ��

	SnakeDir.push_back(0);
	int dirN = 0;

	for (int i = 0; i < L; ++i)
	{
		int a; //���� ���� �ð����κ��� X��
		char c; // ����(C�� 'L') �Ǵ� ������(C�� 'D')
		cin >> a >> c;

		vector<int>::iterator it = SnakeDir.end();
		it = SnakeDir.insert(it, a - SnakeDir.size(), dirN); // ���������� dirN�� 	a - SnakeDir.size() �� ����

		if (c == 'D') //������
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

		if (Board[x][y] == 2)//����� ������
		{
			//Board[x][y]=0;//����� ������

			pair<int, int> tmpBack = Snake.back();
			Board[tmpBack.first][tmpBack.second] = 1;//��
			Board[x][y] = 1;//��
		}
		else if (Board[x][y] == 1)//���̳� ����
		{
			answer = i + 1;//��!
			result = false;

			break;
		}
		else//(Board[x][y] == 0)//��ĭ
		{
			pair<int, int> tmpBack = Snake.back();
			Board[tmpBack.first][tmpBack.second] = 0;//��
			Snake.pop_back(); // ��������

			Board[x][y] = 1;//��
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

			if (Board[x][y] == 2)//����� ������
			{
				//Board[x][y]=0;//����� ������

				pair<int, int> tmpBack = Snake.back();
				Board[tmpBack.first][tmpBack.second] = 1;//��
				Board[x][y] = 1;//��
			}
			else if (Board[x][y] == 1)//���̳� ����
			{
				answer = i + 1;//��!
				result = false;
				break;
			}
			else//(Board[x][y] == 0)//��ĭ
			{
				Board[x][y] = 1;//��

				pair<int, int> tmpBack = Snake.back();
				Board[tmpBack.first][tmpBack.second] = 0;//��
				Snake.pop_back(); // ��������
			}

			i++;
		}
	}

	cout << answer;
}