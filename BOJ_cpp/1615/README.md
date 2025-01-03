#  **[ 1615 : 교차 개수 세기 ]**


🔗[문제링크](https://www.acmicpc.net/problem/1615)

###  **[통과 시의 스펙]**
![image](https://github.com/user-attachments/assets/0e5db9a8-c0aa-47e1-bd87-73daf1b91fa3)

_오예!!!! 31등!!!_




### **[해결 과정]**

- 문제단순화
1. 이분그래프로 생각하여 한쪽 Set 에서 다른 Set 으로 선을 그을때, 두 엣지들 사이의 값이 역전되는 갯수를 센다.
2. 교차의 조건은 둘 중 하나 만족하면 충분
    2-1 ) A1 < A2, B1 > B2
    2-2 ) A1 > A2, B1 < B2
3. 간선의 두 점 중 A를 Index, B를 Value라고 한다면 Inversion Counting에 해당된다는 것을 알 수 있다.
4. 세그먼크 트리로 교차선의 개수를 셀 수 있다.
     - (i,j)간선을 오름차순으로 정렬하고
     - 순서대로 간선을 배치하면서 (트리노드j번째에 1을 더해 줌)
     - [j+1,n]사이 구간 합니 교차한 선의 개수이다.

- 풀이 
1. 두 엣지들 사이의 값이 역전되는 갯수를 센다.(2-1,2-2 조건 중 하나만 만족하면 됨.)
2. 단 모든 엣지들간의 관계를 검사하려면 0(N^2)이 되어 시간초과.
3. 그렇다면 둘중에 한 지점을 정렬하여, 나머지 하나의 관계만 비교를 하도록 만든다.
   즉,이중 리스트 정렬이 느리기에 두개의 수를 묶어서 정렬하지말고 하나의 수로 만들어서 정렬!! (정렬된 순서로 순차로 처리하게 되면, A의 좌표간의 관계는 고려하지 않아도 됨)
4. A를 내립차순으로 정렬하였다면, B들간의 관계는 이미 나왔던 수 중, 자신보다 작은 숫자의 갯수를 세면 됨. ->또 O(N2)이 발생 
5. 세그먼트 트리나 펜워트리를 사용하여 현재 값보다 작은 수의 부분합을 조회하고, 현재 값을 1 중가하도록 업데이트.
7. 현재보다 작은 값을 조회하기 때문에, B가 1인 경우, 인텍스가 0을 조회하게 되어 펜워트리를 사용 할 수 없어 값 보정해야하는 것에 주의!!!!!!!


###  **[리마인드]** 
1. 이중 리스트 정렬이 느리기에 두개의 수를 묶어서 정렬하지말고 하나의 수로 만들어서 정렬!!
2. pair의 리스트가 아니라 이중 리스트로 저장하면 한쪽 끝값만 저장하므로 용량이 절반으로 줄어듦!! _ㄹㅇ 꿀팁!!_
3. 비슷한 문제인 [7578번](https://www.acmicpc.net/problem/1615) 도 풀어보자!
4. 질문게시판에 [Bentley-Ottmann](https://velog.io/@frog_slayer/Bentley-Ottmann) 이런게 있던데....~~이건 뭐지~~  


<details>
<summary> 참고 </summary>

<!-- summary 아래 한칸 공백 두어야함 -->
_~~이거 뭔데 이렇게...깔끔....하지....ㄷㄷ~~_
[개쩌는 고수 인 듯...](https://lastknight00.tistory.com/42)
![image](https://github.com/user-attachments/assets/d4911dd8-b70e-4039-b1c2-a209a2e9ea43)
</details>
