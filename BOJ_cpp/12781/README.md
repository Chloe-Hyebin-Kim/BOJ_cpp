#  **[ 12781 : PIZZA ALVOLOC ]**


🔗[문제링크](https://www.acmicpc.net/problem/12781)


###  **[통과 시의 스펙]**
![Image](https://github.com/user-attachments/assets/0ce183c9-1a35-4396-9b7e-59e786f1e0b5)
단번에 성공!! ㅋㅎ... _이건 수학러에게 식은 죽 먹기지 ㅎ.ㅎ_

### **[해결 과정]**

- 문제단순화
1. 다각형 중요X -> 원이라고 생각해도 지장 없음 ! 
2. 가정한 원(범위) 안에서 교차 해야함! (교차하더라도 원 밖이면 노소용) 즉 둘다 검사!
3. 상대적 위치 비교 노필요 ( 괴랄한 경우..일직선....)   ex. A-C-B-D


- 풀이 
1.  x1y2 + x2y3 + x3y1 - (x2y1 + x3y2 + x1y3) ==>신발끈 공식!!!
2. CCW (p1, p2, p3) * CCW (p1, p2, p4) < 0  _AND_  CCW (p3, p4, p1) * CCW (p3, p4, p2) < 0
3. CCW(C,D,A)*CCW(C,D,B)==0 _AND_ CCW(A,B,C)*CCW(A,B,D)==0  (이 문제에서 애초에 존재 X!! 고려할 필요 X )
4. CCW (Counter ClockWise)는 벡터의 외적을 이용하여 평면 위에 놓여진 세 점의 방향관계를 알 수 있게 해주는 알고리즘이다.  선분(벡터) 교차 판정 알고리즘에도 쓰이고, convex hull 알고리즘에서도 쓰인다.
   _~~이미지 프로세싱 알고리즘 개발할때 이분 블로그 자주 애용함...ㅋㅋㅋ~~ [참고](https://gaussian37.github.io/math-algorithm-line_intersection/) _ 


![Image](https://github.com/user-attachments/assets/021ac4d9-dafd-4235-b34a-44a9b789105e)
 CCW는 점 A,B,C를 순서대로 봤을 때 반시계방향으로 놓여 있으면 양수를, 시계방향이면 음수를, 평행하게 놓여있으면 0을 반환. 


###  **[리마인드]** 
1. 벡터 외적 연산을 이용하여 한 선분의 벡터를 기준으로, 다른 선분의 두 점들이 같은 회전뱡향에 있는지, 다른 회전방향에 있는지 검사하는 CCW (Counter ClockWise)을 사용 .
   평면 위에 놓여진 세 점의 방향관계를 알 수 있게 해주는 알고리즘으로 창 소프트에서 근무할 때 3D 객체를 그리는 방향, 순서를 계산할 때 처음 사용함.
   그땐 그냥 본능적으로 신발끈 공식 써서 겹치는지 봐야겠다생각했는데, 그래픽스 쪽에서 일하면서 그냥 사칙연산 마냥 자주 만남ㅋㅋㅋ
3. endl 는 느리다!!  "**\n**" 이것을 쓰자!
4. long long 64비트 정수사용!! 젭알 데이터의 크기를 잘 보자....ㅜㅡㅜ 처음 아무생각 없이 int 로 해서 틀림;;;
