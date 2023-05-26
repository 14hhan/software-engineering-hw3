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
  SearchHireInfoUI(SearchHireInfo* control, std::ifstream& inputFile,
                   std::ofstream& outputFile);
  void startInterface();
  void searchHireInfo();

 private:
  SearchHireInfo* control;
  std::ifstream* inputFile;
  std::ofstream* outputFile;
};

class ApplyHireInfoUI {
 public:
  ApplyHireInfoUI(ApplyHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);
  void applyHireInfo(std::string userId, int chosenIndex);

 private:
  ApplyHireInfo* control;
};

class ShowApplianceInfoUI {
 public:
  // 인자 필요
  void startInterface(std::vector<HireInfoSummary>);
};

class CancelApplianceInfoUI {
 public:
  void startInterface(std::string, int);
};

class ShowApplicationStatInfoUI {
 public:
  void startInterface(void);
};

class ShowHireStatInfoUI {
 public:
  void startInterface(std::vector<HireInfoSummary>);
};

class RegisterUserUI {
 public:
  void startInterface(std::ofstream& outputFile);
  int createUser(std::ifstream& inputFile, std::ofstream& outputFile);
};

class WithdrawUserUI {
 public:
  void startInterface(std::ofstream& outputFile);
  void startWithdraw(std::string userId, std::ofstream& outputFile);
};

class LoginUI {
 public:
  void startInterface(std::ofstream& outputFile);
  std::string startLogin(std::ifstream& inputFile, std::ofstream& outputFile);
};

class LogoutUI {
 public:
  void startInterface(std::ofstream& outputFile);
  std::string startLogout(std::string userId, std::ofstream& outputFile);
};

// 채용정보 등록 바운더리 클래스
class RegisterHireInfoUI {
 public:
  RegisterHireInfoUI(RegisterHireInfo* control);
  void startInterface(std::ofstream& outputFile);
  void InputHireInfoData(std::ifstream& inputFile, std::ofstream& outputFile);

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
