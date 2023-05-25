#include <iostream>
#include <vector>

using namespace std;

#include "../Boundary/Boundary.h"
#include "../Control/Control.h"

ApplyHireInfoUI::ApplyHireInfoUI(ApplyHireInfo* control)
    : SearchHireInfoUI(control) {
  this->control = control;
  startInterface();
};

void ApplyHireInfoUI::startInterface() {
  cout << "2-2.회사 검색 입력창 출력...\n";
};

void ApplyHireInfoUI::applyHireInfo(int registrationNumber, int chosenIndex) {
  bool response =
      control->sendCreateNewApplication(registrationNumber, chosenIndex);
  string message = response ? "지원이 완료됐습니다" : "지원에 실패했습니다.";
  cout << message << endl;
}