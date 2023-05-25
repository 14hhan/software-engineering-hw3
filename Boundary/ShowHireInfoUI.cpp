#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include "Boundary.h"

ShowHireInfoUI::ShowHireInfoUI(ShowHireInfo* control) {
  this->control;
  startInterface();
}

// showHireInfo UI를 보여주는 함수
void ShowHireInfoUI::startInterface() {
  cout << "3.2. 등록된 채용 정보 조회" << endl;
};

void ShowHireInfoUI::showHireInfo() {
  // ????
  vector<HireInfo*> hireInfos = control->sendSearchHireInfo();

  // 출력
  // for 문 내에 어떻게 작성해야할지?
  for () {
    cout << hireInfo->GetWorkType() << hireInfo->GetQuota()
         << hireInfo->GetdueDate() << "endl";
  }
}