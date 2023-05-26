#include <stdio.h>

#include <iostream>
#include <string>

#include "./Control.h"

using namespace std;

ShowHireInfo::ShowHireInfo() {}

ShowHireInfoUI* ShowHireInfo::getUI() {
  ShowHireInfoUI* ui = new ShowHireInfoUI(this);
  return ui;
}

// 등록한 채용정보 리스트를 보여주는 함수
void ShowHireInfo::showHireInfo() {
  hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();

  // 각 채용정보 주소의 포인터들을 받아오고 반복문을 통해 ShowHireInfoUI에 전달
  for (int i = 0; i < size; i++) {
    ShowHireInfoUI* ShowHireInfoUI = new ShowHireInfoUI;

    ShowHireInfoUI->ShowHireInfo(hireInfoGroup[i]->GetworkType(),
                                 hireInfoGroup[i]->GetdueDate(),
                                 hireInfoGroup[i]->Getquota());
  }
}

// hireList = new HireListItem[size];