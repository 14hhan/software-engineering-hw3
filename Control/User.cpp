using namespace std;

#include "Control.h"
#include "Entity.h"

void RegisterUser::addUser(int userType, string id,
                           string password,  // 새 회원 등록 함수
                           string name, int number) {
  if (userType == 1) {
    NormalUser* newUser = new NormalUser(id, password, name, number);
  } else if (userType == 2) {
    CompanyUser* newUser = new CompanyUser(id, password, name, number);
  }
}

void WithdrawUser::deleteUser(string id) {}  // 회원 탈퇴 함수

void Login::login(string id, string password) {}  // 로그인 함수

void Logout::logout(string id) {}  // 로그아웃 함수
