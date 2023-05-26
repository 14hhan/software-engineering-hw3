using namespace std;

#include "Boundary.h"
#include "Control/Control.h"

void RegisterUserUI::startInterface(ofstream& outputFile) {
  outputFile << "1.1. 회원가입\n";
}

int RegisterUserUI::createUser(ifstream& inputFile, ofstream& outputFile) {
  int userType, number;
  string id, name, password;

  inputFile >> userType >> name >> number >> id >> password;

  RegisterUser* registerUser = new RegisterUser();
  registerUser->addUser(userType, id, password, name, number);

  outputFile << "> " << userType << " " << name << " " << number << " " << id
             << " " << password << "\n\n";

  return userType;
}

void WithdrawUserUI::startInterface(ofstream& outputFile) {
  outputFile << "1.1. 회원탈퇴\n";
}

void WithdrawUserUI::startWithdraw(string userId, ofstream& outputFile) {
  WithdrawUser* withdrawUser = new WithdrawUser();
  withdrawUser->deleteUser(userId);
  outputFile << "> " << userId << "\n\n";
}

void LoginUI::startInterface(ofstream& outputFile) {
  outputFile << "2.1. 로그인\n";
}

string LoginUI::startLogin(ifstream& inputFile, ofstream& outputFile) {
  string id, password;
  inputFile >> id >> password;
  Login* login = new Login();
  login->login(id, password);
  outputFile << "> " << id << " " << password << "\n\n";
  return id;
}

void LogoutUI::startInterface(ofstream& outputFile) {
  outputFile << "2.2. 로그아웃\n";
}

string LogoutUI::startLogout(string userId, ofstream& outputFile) {
  Logout* logout = new Logout();
  logout->logout(userId);
  outputFile << "> " << userId << "\n\n";

  return "";
}
