#include <stdio.h>

#include <string>

#include "Boundary/Boundary.h"
#include "Control.h"

User* companyUser;  // 현재 로그인중인 회사 회원의 정보를 전역으로 설정
// 입력받은 채용 정보들을 전달하는 함수
void RegisterHireInfo::sendHireInfoData(string workType, string dueDate,
                                        int quota) {
  // 현재 로그인 한 회사 회원이 새 채용 정보를 등록하는 함수 호출
  companyUser->HireInfo(workType, dueDate, quota);

  RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
};