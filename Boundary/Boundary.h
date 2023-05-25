#ifndef Boundary_h
#define Boundary_h

#include <fstream>
#include <string>
#include <vector>

#include "../Control/Control.h"
#include "../Entity/Entity.h"

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

#endif
