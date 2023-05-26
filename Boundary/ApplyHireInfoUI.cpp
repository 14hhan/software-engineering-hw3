#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

ApplyHireInfoUI::ApplyHireInfoUI(ApplyHireInfo* control, ifstream& inputFile,
                                 ofstream& outputFile) {
  // control 변수에 ApplyHireInfo를 저장한다
  // startInterface로 초기출력을 출력한다.
  this->control = control;
  this->inputFile = &inputFile;
  this->outputFile = &outputFile;
  startInterface();
};

void ApplyHireInfoUI::startInterface() {
  if (outputFile->is_open()) {
    *outputFile << "==Apply_HIRE_INFO==\n";
  } else {
    cout << "File not accessed" << endl;
  }
};
// 초기출력 TODO: 파일에 출력하는 방식으로 변경

void ApplyHireInfoUI::searchHireInfo() {
  // Actor가 호출하는 회사명에 따른 검색 함수
  string input;
  if (inputFile->is_open()) {
    getline(*inputFile, input);
  }
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    *outputFile << summary;
  }
}

void ApplyHireInfoUI::applyHireInfo() {
  // Actor가 호출하는 Application 생성 함수
  string message = "testing";
  string input;
  if (inputFile->is_open()) {
    getline(*inputFile, input);
  }
  bool response = control->sendCreateNewApplication(input);
  message = response ? "APPLYED" : "REJECTED";
  cout << message << endl;
}