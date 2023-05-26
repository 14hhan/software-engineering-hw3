#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

SearchHireInfoUI::SearchHireInfoUI(SearchHireInfo* control, ifstream& inputFile,
                                   ofstream& outputFile) {
  // control 변수에 SearchHireInfo를 저장한다
  // startInterface로 초기출력을 출력한다.
  this->control = control;
  this->inputFile = &inputFile;
  this->outputFile = &outputFile;
  startInterface();
}

void SearchHireInfoUI::startInterface() {
  if (outputFile->is_open()) {
    *outputFile << "==SEARCH_HIRE_INFO==\n";
  } else {
    cout << "File not accessed" << endl;
  }
}
// 초기출력 TODO: 파일에 쓰는 형식으로 바꾸기

void SearchHireInfoUI::searchHireInfo() {
  // Actor가 호출하는 회사 검색 함수
  string input;
  if (inputFile->is_open()) {
    getline(*inputFile, input);
  }
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    *outputFile << summary;
  }
}