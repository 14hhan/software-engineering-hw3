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
  void addUser(int userType, std::string id, std::string password,
               std::string name, int number);
};

class WithdrawUser {
 public:
  void deleteUser(std::string id);
};

class Login {
 public:
  void login(std::string id, std::string password);
};

class Logout {
 public:
  void logout(std::string id);
};

class SearchHireInfo {
 public:
  SearchHireInfoUI* getUI(std::ifstream& inputFile, std::ofstream& outputFile);
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
  bool sendCreateNewApplication(std::string userId, int chosenIndex);

 private:
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

// 송양기
class ShowApplianceInfo {
 public:
  void showApplianceInfo(std::string);
  bool compareByCompanyName(HireInfoSummary, HireInfoSummary);
};

class CancelApplianceInfo {
 public:
  std::string deleteApplicationInfo(std::string, int);
};

class ShowApplicationStatInfo {
 public:
  void showApplicationStatInfo(std::string);
  void sortByMonth();
  void sortByWorkType();
};

class ShowHireStatInfo {
 public:
  void showHireStatInfo(std::string);
  void sortByWorkType();
};

class ShowHireInfo {
 public:
  std::string* sendHireInfoData();
};

class RegisterHireInfo {
 public:
  void RegisterHireInfo::sendHireInfoData(std::string workType,
                                          std::string dueDate, int quota);
};

#endif