#ifndef Entity_h
#define Entity_h

#include <string>

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

struct HireSummary {
  std::string companyName;
  std::string workType;
  int applicantNum;
  int dueDate;
};

class HireInfo {
 private:
  std::string companyName;
  std::string workType;
  int applicantNum;
  int dueDate;

 public:
  HireInfo(std::string companyName, std::string workType, int dueDate);
  HireSummary getHireInfo();
  void increaseApplicantNum();
};

class Application {
 private:
  HireInfo* appliedHireInfo;

 public:
  Application(HireInfo* hireInfo);
};

#endif