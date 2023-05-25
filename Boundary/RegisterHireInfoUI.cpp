#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"

// RegisterHireInfo UI를 보여주는 함수
void RegisterHireInfoUI::StartInterface() { cout << "3.1. 채용 정보 등록"; };

// 입력받은 채용 정보들을 컨트롤 클래스에게 전달하는 함수
// 값을 전달할 컨트롤 클래스:  RegisterHireInfo* registerHireInfo
void RegisterHireInfoUI::InputHireInfoData(string workType, string dueDate,
                                           int quota) {
  // 업무, 인원수, 신청 마감일을 파일로 부터 입력받음
  // 구현 필요

  // 입력받은 정보를 컨트롤 클래스로 전달
  control->sendHireInfoData(workType, dueDate, quota);

  // 출력
  cout << workType, dueDate, quota << endl;
};
