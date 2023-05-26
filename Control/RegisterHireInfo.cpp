#include <stdio.h>

#include <string>

#include "Boundary/Boundary.h"
#include "Control.h"

User* companyUser;  // 현재 로그인중인 회사 회원의 정보를 전역으로 설정

// RegisterHireInfo 객체를 생성하는 생성자 함수
RegisterHireInfo::RegisterHireInfo(RegisterHireInfo* control) {
  // 로그인 중, 회사 회원 상태 일 때만 채용 정보를 등록 할 수 있음
  this->control = control;

  if (loginState) {
    RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
  }
};
// 입력받은 채용 정보들을 전달하는 함수
void RegisterHireInfo::sendHireInfoData(string workType, string dueDate,
                                        int quota) {
  // 현재 로그인 한 회사 회원이 새 채용 정보를 등록하는 함수 호출
  companyUser->HireInfo(workType, dueDate, quota);

  RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
};