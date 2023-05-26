using namespace std;

#include "Boundary.h"
#include "Control/Control.h"

void RegisterUserUI::startInterface(ofstream& outputFile) {
  outputFile << "1.1. 회원가입\n";
}

int RegisterUserUI::createUser(ifstream& inputFile,
                               ofstream& outputFile) {  // 회원 가입
  int userType, number;
  string id, name, password;

  inputFile >> userType >> name >> number >> id >>
      password;  // inputFile에서 가입 정보 받음

  RegisterUser* registerUser = new RegisterUser();
  registerUser->addUser(userType, id, password, name,
                        number);  // Control 통해서 새 회원 생성

  outputFile << "> " << userType << " " << name << " " << number << " " << id
             << " " << password << "\n\n";  // 가입된 회원 정보 출력

  return userType;
}

void WithdrawUserUI::startInterface(ofstream& outputFile) {
  outputFile << "1.1. 회원탈퇴\n";
}

void WithdrawUserUI::startWithdraw(string userId,
                                   ofstream& outputFile) {  // 회원 탈퇴
  WithdrawUser* withdrawUser = new WithdrawUser();
  withdrawUser->deleteUser(userId);  // userId 받아서 회원 탈퇴(삭제)
  outputFile << "> " << userId << "\n\n";  // 삭제된 회원 id 출력
}

void LoginUI::startInterface(ofstream& outputFile) {
  outputFile << "2.1. 로그인\n";
}

string LoginUI::startLogin(ifstream& inputFile,
                           ofstream& outputFile) {  // 로그인
  string id, password;
  inputFile >> id >> password;  // inputFile에서 id, pw 받음
  Login* login = new Login();
  login->login(id, password);  // id, pw로 로그인
  outputFile << "> " << id << " " << password << "\n\n";
  return id;
}

void LogoutUI::startInterface(ofstream& outputFile) {
  outputFile << "2.2. 로그아웃\n";
}

string LogoutUI::startLogout(string userId, ofstream& outputFile) {  // 로그아웃
  Logout* logout = new Logout();
  logout->logout(userId);                  // userId로 logout
  outputFile << "> " << userId << "\n\n";  // logout 된 회원의 id 출력

  return "";
}
