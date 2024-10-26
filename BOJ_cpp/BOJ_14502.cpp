#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > Data;//0: 빈 칸, 1: 벽, 2: 바이러스
vector <vector<int> > Data_copy;//0: 빈 칸, 1: 벽, 2: 바이러스
vector<int>I0;
vector<int>I2;
vector<int>J0;
vector<int>J2;

int N, M, answer, cnt0, cnt2;
int X[4] = { 0,0,-1,1 };
int Y[4] = { -1,1,0,0 };

void DFS(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	Data.resize(N, vector<int>(M, 0));
	Data_copy.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int tmp = 0;
			cin >> tmp;
			Data[i][j] = tmp;
			Data_copy[i][j] = Data[i][j];
			if (tmp == 0)
			{
				cnt0++;//카운트 증가
				I0.push_back(i);//위치 저장
				J0.push_back(j);//위치 저장
			}
			else if (tmp == 2)
			{
				cnt2++;//카운트 증가
				I2.push_back(i);//위치 저장
				J2.push_back(j);//위치 저장
			}
		}
	}

	int wall_X1, wall_Y1, wall_X2, wall_Y2, wall_X3, wall_Y3;// 벽 3개좌표
	//벽세우기 시뮬레이션 (0 ~ n*m-1까지 반복)
	for (int i = 0; i < cnt0; ++i)
	{
		wall_X1 = I0[i];//  == i/M
		wall_Y1 = J0[i];//  == i%M

		for (int j = i + 1; j < cnt0; ++j)
		{
			wall_X2 = I0[j];//  == j/M
			wall_Y2 = J0[j];//  == j%M

			for (int k = j + 1; k < cnt0; ++k)
			{
				wall_X3 = I0[k];//  == j/M
				wall_Y3 = J0[k];//  == j%M

				//벽세우기
				Data_copy[wall_X1][wall_Y1] = 1;
				Data_copy[wall_X2][wall_Y2] = 1;
				Data_copy[wall_X3][wall_Y3] = 1;

				//바이러스 퍼트리는 시뮬레이션
				for (int p = 0; p < cnt2; ++p)
					DFS(I2[p], J2[p]);

				int cnt = 0;

				//해당 시뮬레이션의 안전지대 개수
				for (int p = 0; p < N; ++p)
					for (int q = 0; q < M; ++q)
						if (0 == Data_copy[p][q]) cnt++;

				if (answer < cnt)
					answer = cnt;

				for (int p = 0; p < N; ++p)
					for (int q = 0; q < M; ++q)
						Data_copy[p][q] = Data[p][q];
			}
		}
	}

	cout << answer;
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int x_ = x + X[i];
		int y_ = y + Y[i];

		if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M)
		{
			if (0 == Data_copy[x_][y_])
			{
				Data_copy[x_][y_] = 2;//바이러스 퍼트리기
				DFS(x_, y_);
			}
		}
	}
}