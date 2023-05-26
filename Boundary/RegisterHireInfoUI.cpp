#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control/Control.h"

RegisterHireInfoUI::RegisterHireInfoUI(RegisterHireInfo* control) {
  this->control = control;
  startInterface();
}

// RegisterHireInfo UI를 보여주는 함수
void RegisterHireInfoUI::startInterface(ofstream& outputFile) {
  outputFile << "3.1. 채용 정보 등록";
};

// 입력받은 채용 정보들을 컨트롤 클래스에게 전달하는 함수
// 값을 전달할 컨트롤 클래스:  RegisterHireInfo* registerHireInfo
void RegisterHireInfoUI::InputHireInfoData(ifstream& inputFile,
                                           ofstream& outputFile) {
  string workType, dueDate;
  int quota;

  // 업무, 인원수, 신청 마감일을 파일로 부터 입력받음
  inputFile >> workType >> dueDate >> quota;

  // 입력받은 정보를 컨트롤 클래스로 전달
  control->sendHireInfoData(workType, dueDate, quota);

  // 출력
  outputFile << "> " << workType << " " << dueDate << " " << quota << "\n\n";
};
