#include <fstream>
#include <iostream>
using namespace std;

#include "Boundary/Boundary.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void program_exit(ofstream& outFile);

int loginNum = 0;
string userId;

int main() {
  doTask();
  return 0;
}

void doTask() {
  ifstream inputFile(INPUT_FILE_NAME);
  ofstream outputFile(OUTPUT_FILE_NAME);

  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;

  while (!is_program_exit) {
    inputFile >> menu_level_1 >> menu_level_2;

    switch (menu_level_1) {
      // menu_level_1: 1 -> 회원 가입 및 탈퇴
      case 1: {
        switch (menu_level_2) {
          // 1.1. 회원가입
          case 1: {
            RegisterUserUI* registerUserUI = new RegisterUserUI();
            registerUserUI->startInterface(outputFile);
            loginNum = registerUserUI->createUser(inputFile, outputFile);
            break;
          }
          // 1.2. 회원탈퇴
          case 2: {
            WithdrawUserUI* withdrawUserUI = new WithdrawUserUI();
            withdrawUserUI->startInterface(outputFile);
            withdrawUserUI->startWithdraw(userId, outputFile);
            break;
          }
        }
      }
      // menu_level_1: 2 -> 로그인 및 로그아웃
      case 2: {
        switch (menu_level_2) {
          case 1: {
            LoginUI* loginUI = new LoginUI();
            loginUI->startInterface(outputFile);
            userId = loginUI->startLogin(inputFile, outputFile);
            break;
          }
          case 2: {
            LogoutUI* logoutUI = new LogoutUI();
            logoutUI->startInterface(outputFile);
            userId = logoutUI->startLogout(userId, outputFile);
            loginNum = 0;
            break;
          }
        }
      }
      // menu_level_1: 3 -> 채용 정보 등록 및 조회
      case 3: {
        switch (menu_level_2) {
          case 1:
            break;
          case 2:
            break;
        }
      }
      // menu_level_1: 4 -> 채용 정보 검색, 지원, 지원 정보 조회, 지원 취소
      case 4: {
        switch (menu_level_2) {
          case 1:
            break;
          case 2:
            break;
          case 3: {
            ShowApplianceInfo* showApplianceInfo = new ShowApplianceInfo();
            showApplianceInfo->showApplianceInfo(userId);
            break;
          }
          case 4:
            // CancelApplianceInfoUI* cancelApplianceInfoUI =
            //     new CancelApplianceInfoUI();
            // cancelApplianceInfoUI->startInterface(
            //     userId, businessNum);  // businessNum을 startInterface 안에서
            // 하는 방법도 있음.
            break;
        }
      }
      //  menu_level_1: 5 -> 지원 정보 통계
      case 5: {
        switch (menu_level_2) {
          case 1: {
            ShowApplicationStatInfo* showApplicationStatInfo =
                new ShowApplicationStatInfo();
            showApplicationStatInfo->showApplicationStatInfo(userId);
            break;
          }
          case 2: {
            ShowHireStatInfo* showHireStatInfo = new ShowHireStatInfo();
            showHireStatInfo->showHireStatInfo(userId);
            break;
          }
        }
      }
      // menu_level_1: 6 -> 종료
      case 6: {
        switch (menu_level_2) {
          case 1: {
            program_exit(outputFile);
            is_program_exit = 1;
            break;
          }
        }
      }
    }
  }
  return;
}

void program_exit(ofstream& outFile) { outFile << "6.1. 종료"; }
