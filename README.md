# C++ 자동 formatting 설정법(Visual Studio 사용시)

### 1.Visual Studio 좌측의 Extensions에서 C/C++을 검색해 설치합니다
![1](https://github.com/14hhan/software-engineering-hw3/assets/53640976/3186904e-0e64-4030-a514-277216c3df3b)

해당 항목이 제대로 설치되었다면 편집창에 C++ 파일(.cpp)을 띄운 상태에서  
`Shift`+`alt`+`F`를 입력하면 vscode가 둘 중 하나의 반응을 합니다.
- 해당 Extension을 포멧터로 지정 여부에 대한 대화창을 출력합니다. 
- 자동으로 해당 Extension을 이용해 코드를 포멧합니다. 

### 2.명령 팔레트에서 user preference JSON 파일을 검색해 수정합니다. 

![2](https://github.com/14hhan/software-engineering-hw3/assets/53640976/117c7e1d-873a-41ca-b342-6a8abefb9ecf)

명령 팔레트를 클릭해 `>preferences: open user settings (JSON)` 를 검색한 후  
해당 파일의 cpp 항목에서 설정을 다음과 같이 바꿔줍니다

![3](https://github.com/14hhan/software-engineering-hw3/assets/53640976/0c33bec2-eb0a-41bd-9251-a5e53ffe32b5)

```
    "[cpp]": {
        "editor.defaultFormatter": "ms-vscode.cpptools",
        "editor.formatOnSave": true
    },
    "C_Cpp.clang_format_fallbackStyle": "Google"
```
