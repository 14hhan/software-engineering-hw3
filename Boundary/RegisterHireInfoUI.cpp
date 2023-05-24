#include <stdio.h>

#include <string>

#include "Boundary.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언

// 변수 선언
FILE *in_fp, *out_fp;
FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

// RegisterHireInfo 객체를 생성하는 생성자 함수
RegisterHireInfo::RegisterHireInfo() {
  // 로그인 중, 회사 회원 상태 일 때만 채용 정보를 등록 할 수 있음
  if (loginState) {
    RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
    registerHireInfoUI->InputHireInfotData(this);
  }
}

// RegisterHireInfo UI를 보여주는 함수
void RegisterHireInfoUI::StartInterface() {
  RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
};

// 입력받은 채용 정보들을 컨트롤 클래스에게 전달하는 함수
// 값을 전달할 컨트롤 클래스:  RegisterHireInfo* registerHireInfo
void RegisterHireInfoUI::InputHireInfoData(RegisterHireInfo* registerHireInfo) {
  std::string workType, dueDate;
  std::int quota;  // 인원 수는 지원자 수와 다른 값이므로 quota로

  // 업무, 인원수, 신청 마감일을 파일로 부터 입력받음
  fscanf(in_fp, "%s %s %u", workType, dueDate, quota);

  // 입력받은 정보를 컨트롤 클래스로 전달
  registerHireInfo->sendHireInfoData(workType, dueDate, quota);
};
