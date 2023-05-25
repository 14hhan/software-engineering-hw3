#include <iostream>
#include <vector>

using namespace std;

#include "../Boundary/Boundary.h"
#include "../Control/Control.h"

SearchHireInfoUI::SearchHireInfoUI(SearchHireInfo* control) {
  this->control = control;
  startInterface();
}

void SearchHireInfoUI::startInterface() {
  cout << "2-1.회사 검색 입력창 출력...\n";
}

void SearchHireInfoUI::searchHireInfo(string input) {
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    cout << summary << "endl";
  }
}