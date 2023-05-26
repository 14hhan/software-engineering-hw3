#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Boundary/Boundary.h"
#include "../Entity/Entity.h"

struct HireListItem {
  std::string groupIndex;
  HireInfoSummary summary;
};

class RegisterUser {
 public:
  void addUser(int userType, string id, string password, string name,
               int number);
};

class WithdrawUser {
 public:
  void deleteUser(string id);
};

class Login {
 public:
  void login(string id, string password);
};

class Logout {
 public:
  void logout(string id);
};

class SearchHireInfo {
 public:
  SearchHireInfoUI* getUI();
  std::vector<std::string> sendSearchHireInfo(std::string input);

 private:
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo {
 public:
  ApplyHireInfoUI* getUI();
  std::vector<std::string> sendSearchHireInfo(std::string input);
  bool sendCreateNewApplication(string userId, int chosenIndex);

 private:
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

// 송양기
class ShowApplianceInfo {
 public:
  void showApplianceInfo(string) const;
  bool compareByCompanyName(HireInfoSummary, HireInfoSummary);
};

class CancelApplianceInfo {
 public:
  std::string deleteApplicationInfo(string, int) const;
};

class ShowApplicationStatInfo {
 public:
  void showApplicationStatInfo(string);
  void sortByMonth() const;
  void sortByWorkType() const;
};

class ShowHireStatInfo {
 public:
  void showHireStatInfo(string) const;
  void sortByWorkType() const;
};

#endif