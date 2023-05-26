#ifndef Entity_h
#define Entity_h

#include <string>
#include <vector>

class User {
 private:
  std::string id;
  std::string password;

 public:
  User(std::string id, std::string password);
  virtual std::string getUserInfo();
};

class NormalUser : public User {
 private:
  std::string userName;
  int registrationNumber;

 public:
  NormalUser(std::string id, std::string password, std::string userName,
             int registrationNumber);
  virtual std::string getUserInfo();  // Q: 이것도 virtual이 필요한가요?
};

class CompanyUser : public User {
 private:
  std::string companyName;
  int companyNumber;

 public:
  CompanyUser(std::string id, std::string password, std::string companyName,
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
           int businessNum, string userId, int quota);
  static std::vector<HireInfo*> getAllHireInfo();
  static std::vector<HireInfoSummary> getCompanyUsersHireInfos(string);
  HireInfoSummary getHireInfo();
  void increaseApplicantNum();
  void decreaseApplicantNum();
  int getBusinessNum();
  std::string getCompanyName();
  std::string getWorkType();
  std::string getUserId();
  std::string getHireInfo();
  int GetQuota() { return quota; }           // 인원수 반환
  std::string GetdueDate() { return dueDate; }    // 신청 마감일 반환

 private:
  static std::vector<HireInfo*> allHireInfo;
  std::string companyName;
  std::string workType;
  int quota;
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