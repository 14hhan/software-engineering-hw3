#include <string.h>

#include <fstream>
#include <iostream>
using namespace std;

#include "Boundary/Boundary.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void join();
void program_exit();

int loginNum = 0;
string userId;

ifstream inputFile(INPUT_FILE_NAME);
ofstream outputFile(OUTPUT_FILE_NAME);

int main() {
  doTask();
  return 0;
}

void doTask() {
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;

  while (!is_program_exit) {
    fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
    switch (menu_level_1) {
      case 1: {
        switch (menu_level_2) {
          case 1:
            join();
            break;
          case 2:
            break;
        }
      }
      case 2: {
        switch (menu_level_2) {
          case 1:
            break;
          case 2:
            break;
        }
      }
      case 3: {
        switch (menu_level_2) {
          case 1:
            break;
          case 2:
            break;
        }
      }
      case 4: {
        switch (menu_level_2) {
          case 1:
            break;
          case 2:
            break;
          case 3:
            ShowApplianceInfo* showApplianceInfo = new ShowApplianceInfo();
            showApplianceInfo->showApplianceInfo(userId);
            break;
          case 4:
            CancelApplianceInfoUI* cancelApplianceInfoUI = new CancelApplianceInfoUI();
            cancelApplianceInfoUI->startInterface(userId, businessNum); // businessNum을 startInterface 안에서 하는 방법도 있음.
        }
      }
      case 5: {
        switch (menu_level_2) {
          case 1:
            ShowApplicationStatInfo* showApplicationStatInfo = new ShowApplicationStatInfo();
            showApplicationStatInfo->showApplicationStatInfo(userId);
            break;
          case 2:
            ShowHireStatInfo* showHireStatInfo = new ShowHireStatInfo();
            showHireStatInfo->showHireStatInfo(userId);
            break;
        }
      }
      case 6: {
        switch (menu_level_2) {
          case 1:
            program_exit();
            is_program_exit = 1;
            break;
          case 2:
            break;
        }
      }
    }
  }
  return;
}

void join() {
  char user_type[MAX_STRING], ID[MAX_STRING], password[MAX_STRING],
      name[MAX_STRING], SSN[MAX_STRING];
  fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

  fprintf(out_fp, "1.1. 회원가입\n");
  fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}

void program_exit() {}
