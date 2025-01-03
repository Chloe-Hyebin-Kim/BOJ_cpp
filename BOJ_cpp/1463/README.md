#  **[ 1463 : 1로 만들기 ]**


🔗[문제링크](https://www.acmicpc.net/problem/1463)

###  **[통과 시의 스펙]**
![image](https://github.com/user-attachments/assets/3a2a09b3-6e0c-445a-9d49-9122df0f579b)


### **[해결 과정]**

- 문제해석
1. 1부터  입력받은 숫자까지 캐싱해서 찾는게 젤 빠름
2. 항상 성립한다고 증명 해보지 않은 것(가보지 않은 길)은 수학적으로 장담 금지!
3. 메모이제이션 사용

- 풀이
1. ```arrNum[i]``` 에 i를 만들기 위한 최소 연산 횟수를 저장할거라 일단 가장큰 수를 집어넣음.
   '연산3'으로만 가장 큰 N 을 1로 만들었을 때, 999999이므로 이보다 큰 1000001로 채움.
2.  ```arrNum[i]``` 이 1000001로 이 아니거나(메모이제이션 됨!), i가 1 이면 ```arrNum[i]``` 그대로 사용.
3. 짝수 중 3으로도 나누어 떨어지는 수 (6의 배수) :  ```arrNum[i/3] +1``` 와```arrNum[i/2] +1```와 ```arrNum[i-1] + 1``` 모두 비교 필요. 
4. 짝수 중 2으로 나누어 떨어지는 수 : ```arrNum[i/2] +1``` 와 ```arrNum[i-1] + 1``` 비교 필요.
5. 홀수 중 3으로 나누어 떨어지는 수 :```arrNum[i/3] +1``` 와 ```arrNum[i-1] + 1``` 비교 필요.
6. 홀수 중 3으로 나누어 떨어지지 않는 수(소수) : ```arrNum[i] = arrNum[i-1] + 1``` 이거 하나.


   
### **[느낀 점]**
1. 자꾸 까먹음...
   ```(홀수 & 1) == 1```
   ```(짝수 & 1) == 0```
2. 1부터  입력받은 숫자까지 캐싱해서 찾는게 젤 빠름.
   어림짐작으로 알수 없음.
3. 가중치가 없는 bfs는 최단 경로가 보장되기 때문에, N부터 시작하는 BFS가 일반적으로 상당히 빠른 시간 내에 답을 찾을 수 도 있음. (참고, [1로 만들기 3](https://www.acmicpc.net/problem/27440) )
   그러나 BFS를 사용하면, 오로지 N에 대해서만 답을 알수 있다. 반면에 메모이제이션을 사용한 DP 풀이는 1부터 N까지의 모든 수에 대한 답을 구할 수 있다.
