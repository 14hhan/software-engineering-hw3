#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

ApplyHireInfoUI::ApplyHireInfoUI(ApplyHireInfo* control) {
  // control 변수에 ApplyHireInfo를 저장한다
  // startInterface로 초기출력을 출력한다.
  this->control = control;
  startInterface();
};

void ApplyHireInfoUI::startInterface() { cout << "2-2 Apply Started...\n"; };
// 초기출력 TODO: 파일에 출력하는 방식으로 변경

void ApplyHireInfoUI::searchHireInfo(string input) {
  // Actor가 호출하는 회사명에 따른 검색 함수
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    cout << summary << endl;
  }
}

void ApplyHireInfoUI::applyHireInfo(string userId, int chosenIndex) {
  // Actor가 호출하는 Application 생성 함수
  string message = "testing";
  bool response = control->sendCreateNewApplication(userId, chosenIndex);
  message = response ? "APPLYED" : "REJECTED";
  cout << message << endl;
}