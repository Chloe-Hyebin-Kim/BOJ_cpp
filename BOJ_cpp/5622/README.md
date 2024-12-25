#  [ 5662 : 다이얼 ]

🔗[문제링크](https://www.acmicpc.net/problem/5662)



###  **[통과 시의 스펙]**
![image](https://github.com/user-attachments/assets/de7c28c9-be35-41e5-bf10-9e24c9017ed6)


### **[해결 과정]**

- 문제단순화
  1. 입력이 '알파벳 대문자로 이루어진 단어' 이므로 0이나 1에 대해 신경 쓸 필요 없음
  2. 알파벳마다 숫자 +1 매칭해서 누적합 구해주면 끄-읏!

 


- 풀이
  1. string strMsg 으로 입력받고 ```const char* chars = strMsg.c_str();``` 으로 변형.
  2. ```strMsg.length();``` 개수 만큼 for 문 돌려서 ```chars[i]``` 낱개 문자 읽음
  3. ```strMsg = "HelloWorld"``` 일 때,  chars[0] 은 char 타입의 'H' 이다. (유니코드 72 ='H')  ```char H = chars[0]```
  4. ```chars[0] - '0' = 24``` 이렇게 '0' 을 빼주면 char가 아니라 int(유니코드 숫자!로 나온다. 'H'=72. '0'=48. 따라서 결과는 24.
  5. 유니코드를 이용하여 switch case 문으로 해결함



###  **[리마인드]** 
1. 외워두자!
   ```'A' == 65;``` 
   ```'a' == 97;``` 
   ```'0' == 48;``` 
2. string to char 
```
std::string str = "string";
const char *cstr = str.c_str();
```

```
std::string str = "string";
char *cstr = str.data(); // non - const char!!
```

```
std::string str = "string";
char *cstr = new char[str.size() + 1]; //반드시 +1 !!! 맨뒤에 '\0' 널문자 필요!! 
std::strcpy(cstr, str.c_str());

delete [] cstr; // do stuff
```

```
std::string str = "string";
char* cPtr = new char[str.size()+1];
std::copy(str.begin(), str.end(), cPtr);
cPtr[str.size()] = '\0';
```
