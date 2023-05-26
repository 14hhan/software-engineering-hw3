#ifndef Boundary_h
#define Boundary_h

#include <string>
#include <fstream>
#include <string>
#include <vector>

#include "../Control/Control.h"
#include "../Entity/Entity.h"

class SearchHireInfo;
class ApplyHireInfo;

class SearchHireInfoUI {
 public:
  SearchHireInfoUI(SearchHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);

 protected:
  SearchHireInfo* control;
};

class ApplyHireInfoUI {
 public:
  ApplyHireInfoUI(ApplyHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);
  void applyHireInfo(string userId, int chosenIndex);

 private:
  ApplyHireInfo* control;
};

class ShowApplianceInfoUI {
 public:
  // 인자 필요
  void startInterface(vector<HireInfoSummary>, ofstream&);
};

class CancelApplianceInfoUI {
 public:
  void startInterface(string, int, ofstream&) const;
};

class ShowApplicationStatInfoUI {
 public:
  void startInterface(ofstream&) const;
};

class ShowHireStatInfoUI {
 public:
  void startInterface(vector<HireInfoSummary>, ofstream&) const;
};

class RegisterUserUI {
 public:
  void startInterface(ofstream& outputFile);
  int createUser(ifstream& inputFile, ofstream& outputFile);
};

class WithdrawUserUI {
 public:
  void startInterface(ofstream& outputFile);
  void startWithdraw(string userId, ofstream& outputFile);
};

class LoginUI {
 public:
  void startInterface(ofstream& outputFile);
  string startLogin(ifstream& inputFile, ofstream& outputFile);
};

class LogoutUI {
 public:
  void startInterface(ofstream& outputFile);
  string startLogout(string userId, ofstream& outputFile);
};

// 채용정보 등록 바운더리 클래스
class RegisterHireInfoUI {
 public:
  RegisterHireInfoUI(RegisterHireInfo* control);
  void StartInterface();
  void sendHireInfoData(ShowHireInfo* showHireInfo);

 private:
  RegisterHireInfo* control;
};

// RegisterHireInfo 객체를 생성하는 생성자 함수
RegisterHireInfo::RegisterHireInfo(RegisterHireInfo* control) {
  // 로그인 중, 회사 회원 상태 일 때만 채용 정보를 등록 할 수 있음
  this->control = control;

  if (loginState) {
    RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
  }
};

// 채용정보 조회 바운더리 클래스
class ShowHireInfoUI {
 public:
  ShowHireInfoUI(ShowHireInfo* control);
  void StartInterface();

 private:
  ShowHireInfo* control;
};
// showHireInfo 컨트롤 클래스의 생성자 함수
void ShowHireInfoUI::showHireInfo(ShowHireInfo* showHireInfo) {
  // 로그인 상태에서 회사 회원 자신이 등록한 채용 정보 조회 가능
  this->control = control;

  if (loginState) {
    ShowHireInfoUI* ShowHireInfoUI = new ShowHireInfoUI;
  }
};

#endif
