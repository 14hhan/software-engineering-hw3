#ifndef Boundary_h
#define Boundary_h

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
  void startInterface(vector<HireInfoSummary>);
};

class CancelApplianceInfoUI {
 public:
  void startInterface(string, int) const;
};

class ShowApplicationStatInfoUI {
 public:
  void startInterface(void) const;
};

class ShowHireStatInfoUI {
 public:
  void startInterface(vector<HireInfoSummary>) const;
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
  void startInterface(ofstream& outputFile);
  void sendHireInfoData(ShowHireInfo* showHireInfo);

 private:
  RegisterHireInfo* control;
};

// 채용정보 조회 바운더리 클래스
class ShowHireInfoUI {
 public:
  ShowHireInfoUI(ShowHireInfo* control);
  void startInterface();

 private:
  ShowHireInfo* control;
};

#endif
