#include <stdio.h>

#include <string>

#include "Control.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언

// 변수 선언
FILE *in_fp, *out_fp;
FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

// 등록한 채용정보 리스트를 보여주는 함수
void ShowHireInfo::startInterface() {
  this->hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();

  hireList = new HireListItem[size];
  for (int i = 0; i < size; i++) {
    // 각 채용정보 주소의 포인터들을 받아왔으니 반복문을 통해 상세정보 출력
    ShowHireInfoUI* ShowHireInfoUI = new ShowHireInfoUI;
    fprintf(out_fp, "%s %s %u\n", workType, dueDate, quota);
  }
}