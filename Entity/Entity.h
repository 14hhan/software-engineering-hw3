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
  virtual std::string getUserInfo();
};

class NormalUser : public User {
 private:
  std::string userName;
  int registrationNumber;

 public:
  NormalUser(std::string id, int password, std::string userName,
             int registrationNumber);
  virtual std::string getUserInfo();  // Q: 이것도 virtual이 필요한가요?
};

class CompanyUser : public User {
 private:
  std::string companyName;
  int companyNumber;

 public:
  CompanyUser(std::string id, int password, std::string companyName,
              int companyNumber);
  virtual std::string getUserInfo();  // Q: 이것도 virtual이 필요한가요?
};

struct HireInfoSummary {
  std::string companyName;
  std::string workType;
  std::string applicantNum;
  std::string dueDate;
};

class HireInfo {
 public:
  HireInfo(std::string companyName, std::string workType, int dueDate,
           int businessNum, string userId);
  static std::vector<HireInfo*> getAllHireInfo();
  static std::vector<HireInfoSummary> getCompanyUsersHireInfos(string);
  HireInfoSummary getHireInfo();
  void increaseApplicantNum();
  void decreaseApplicantNum();
  int getBusinessNum();
  std::string getCompanyName();
  std::string getWorkType();
  std::string getUserId();

 private:
  static std::vector<HireInfo*> allHireInfo;
  std::string companyName;
  std::string workType;
  int businessNum;
  int applicantNum;
  int dueDate;
  string userId;
};

class Application {
 public:
  Application(HireInfo*, string);
  ~Application();
  static std::vector<HireInfoSummary> getNormalUsersApplications(string);
  static std::string deleteApplication(string, int);
  HireInfo* getAppliedHireInfo();
  std::string getUserId();

 private:
  HireInfo* appliedHireInfo;
  static std::vector<Application*> allApplication;
  std::string userId;
};

#endif