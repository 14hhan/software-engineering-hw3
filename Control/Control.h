#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Boundary/Boundary.h"
#include "../Entity/Entity.h"

struct HireListItem {
  int groupIndex;
  HireInfoSummary summary;  // 의존성을 줄여야하나? string으로 쪼개야하나
                            // 궁금하지만 귀찮다... 대충 살자
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
  SearchHireInfo();
  std::vector<std::string>
  sendSearchHireInfo();  // TODO: UI에 대한 반환형 논의 필요

 private:
  std::vector<HireInfo*> hireInfoGroup;
  vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo {
 public:
  std::vector<std::string> sendSearchHireInfo();
  bool sendCreateNewApplication();
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