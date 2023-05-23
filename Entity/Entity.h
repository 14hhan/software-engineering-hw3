#ifndef Entity_h
#define Entity_h

#include <string>
#include <vector>

class User {
 private:
  std::string id;
  int password;

 public:
  User(std::string id, int password);
  void getUserInfo();     // NEEDED: 반환형 지정 필요
  void getUserDetails();  // NEEDED: 반환형 지정 필요
};

class NormalUser : public User {
 private:
  std::string userName;
  int registrationNumber;

 public:
  NormalUser(std::string id, int password, std::string userName,
             int registrationNumber);
};

class CompanyUser : public User {
 private:
  std::string companyName;
  int companyNumber;

 public:
  CompanyUser(std::string id, int password, std::string companyName,
              int companyNumber);
};

struct HireInfoSummary {
  std::string companyName;
  std::string workType;
  std::string applicantNum;
  std::string dueDate;
};
class HireInfo {
 private:
  std::string companyName;
  std::string workType;
  int applicantNum;
  int dueDate;
  static std::vector<HireInfo*> allHireInfo;

 public:
  HireInfo(std::string companyName, std::string workType, int dueDate);
  HireInfoSummary getHireInfo();
  void increaseApplicantNum();
  static std::vector<HireInfo*> getAllHireInfo();
};

class Application {
 private:
  HireInfo* appliedHireInfo;

 public:
  Application(HireInfo* hireInfo);
};

#endif