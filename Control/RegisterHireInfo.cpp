#include <stdio.h>

#include <string>

#include "Control.h"

// 입력받은 채용 정보들을 멤버 클래스에게 전달하는 함수
void RegisterHireInfo::sendHireInfoData(string workType, string dueDate,
                                        int quota) {
  // 현재 로그인 한 회사 회원이 새 채용 정보를 등록하는 함수 호출
  companyUser->HireInfo(workType, dueDate, quota);

  RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;

  // 출력 형식
  fprintf(out_fp, "3.1. 채용 정보 등록\n");
  fprintf(out_fp, "%s %s %u", workType, dueDate, quota);
};