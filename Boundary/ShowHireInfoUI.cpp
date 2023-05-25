#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

ShowHireInfoUI::ShowHireInfoUI(ShowHireInfo* control) {
  this->control;
  startInterface();
}

// showHireInfo UI를 보여주는 함수
void ShowHireInfoUI::startInterface() {
  outputFile << "3.2. 등록된 채용 정보 조회";
};

void ShowHireInfoUI::showHireInfo() {
  // 아래 코드 어떻게 수정해야할지?
  vector<HireInfo*> hireInfos = control->sendSearchHireInfo();

  // 출력
  // for 문 내에 어떻게 작성해야할지?
  for () {
    outputFile << "> " << hireInfo->GetWorkType() << " " << hireInfo->GetQuota()
               << " " << hireInfo->GetdueDate() << "\n\n";
  }
}