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
  string id;
  int password;

 public:
  NormalUser(std::string id, int password, std::string userName,
             int registrationNumber);
  string getId();
};

class CompanyUser : public User {
 private:
  std::string companyName;
  int companyNumber;
  string id;
  int password;

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
  int businessNum;
  int applicantNum;
  int dueDate;
  string userId;
  static std::vector<HireInfo*> allHireInfo;

 public:
  HireInfo(std::string companyName, std::string workType, int dueDate, int businessNum, string userId);
  HireInfoSummary getHireInfo();
  void increaseApplicantNum();
  void decreaseApplicantNum();
  static std::vector<HireInfo*> getAllHireInfo();
  static std::vector<HireInfoSummary> getCompanyUsersHireInfos(string);
  int getBusinessNum();
  std::string getCompanyName();
  std::string getWorkType();
  std::string getUserId();
};

class Application {
 private:
  HireInfo* appliedHireInfo;
  static std::vector<Application*> allApplication;
  
  std::string userId;

 public:
  Application(HireInfo* , string);
  static std::string deleteApplication(string , int );
  static std::vector<HireInfoSummary> getNormarUsersApplications(string);
  ~Application();
  HireInfo* getAppliedHireInfo();
  std::string getUserId();
};

#endif