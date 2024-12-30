#  **[ 2178 : 미로탐색 ]**


🔗[문제링크](https://www.acmicpc.net/problem/2178)

###  **[통과 시의 스펙]**
![image](https://github.com/user-attachments/assets/7d180ec7-f65d-463a-adf6-09e08792363b)





### **[해결 과정]**

- 문제해석
1. 최단경로 탐색!! 즉 BFS 너비우선탐색을 쓴다.
2. 움직이는 방법은 **돌려까기!**  _~~내가 지은 이름임~~_
   ```
   int moveX[4] = { 1,-1,0,0 };
   int moveY[4] = { 0,0,1,-1 };
   
		for (int i = 0; i < 4; i++)
		{
			int dx = x + moveX[i];
			int dy = y + moveY[i];
   }
3. 방문 체크를 위해 움직일때 마다 증감 연산자를 쓰면, 막다른 곳에 갔을 때, 그 움직임들을 모두 빼줘야하는데, 골치아파진다.
   경우의 수 길찾기 에서 아이디어를 얻어 해결!
 ![image](https://github.com/user-attachments/assets/ed115325-8fbe-40a5-b25a-2cb679f0d9dc)

  


- 풀이
1. BFS 를 위한 큐는 (x,y) 좌표를 쉽게 받아오기위해, ```queue<pair<int, int> > q; ``` 로 만든다.
2. 방문 체크는 arrVisited[0][0] = 1; 로 시작해서 각 진행 스텝이 추가 될 때 마다 ```arrVisited[dx][dy] = arrVisited[x][y] + 1;``` 해준다.
  (기본 초기화값은 0) 
3.  arrVisited[x][y]가 0 인 곳만 지나간다! (그래야 효율적)
4.  도착지점에 온다면, 반복문을 끝내기위해 큐를 비운다. 



### **[느낀 점]**
1. 큐를 비우는 방법은 따로 없어서 걍 비어있는 큐랑 스왑해줘야 한다
2. 고딩 때 경우의 수 길찾기 에서 아이디어를 얻어 해결!

