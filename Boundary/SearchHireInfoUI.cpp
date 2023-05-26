#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

SearchHireInfoUI::SearchHireInfoUI(SearchHireInfo* control) {
  // control 변수에 SearchHireInfo를 저장한다
  // startInterface로 초기출력을 출력한다.
  this->control = control;
  startInterface();
}

void SearchHireInfoUI::startInterface() { cout << "2-1 SearchStarted...\n"; }
// 초기출력 TODO: 파일에 쓰는 형식으로 바꾸기

void SearchHireInfoUI::searchHireInfo(string input) {
  // Actor가 호출하는 회사 검색 함수
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    cout << summary << endl;
  }
}