using namespace std;
#include<string.h>
#include "./Entity.h"

Application::Application(HireInfo* hireInfo, string userId) {
  hireInfo->increaseApplicantNum();
  this->appliedHireInfo = hireInfo;
  this->userId = userId;
  allApplication.push_back(this);
}

Application::~Application() {
  this -> appliedHireInfo -> decreaseApplicantNum();
  allApplication.erase(remove(allApplication.begin(), allApplication.end(), this), allApplication.end());
}

vector<HireInfoSummary> Application::getNormarUsersApplications(string userId) { 
  // allApplication 을 가공해서 가공한 vector 반환해야.

  vector<HireInfoSummary> ApplicationOfNormalUser;
  for(int i=0; i<allApplication.size(); i++) {
    if (allApplication[i]->getUserId() == userId) {
      ApplicationOfNormalUser.push_back(allApplication[i]->getAppliedHireInfo()->getHireInfo());
    }
  }

  return ApplicationOfNormalUser;
};

string Application::deleteApplication(string userId, int businessNum) {
  
  for(int i=0; i<allApplication.size(); i++) {
    if ((allApplication[i]->getUserId() == userId) && (allApplication[i]->getAppliedHireInfo()->getBusinessNum() ==businessNum )) {
      // 백업 -> 저장 -> 리턴
      // 회사이름, 사업자번호, 업무

      Application* targetApplication = allApplication[i];
      HireInfo* targetHireInfo = allApplication[i]->appliedHireInfo;
      string applicationInfo = "";
      applicationInfo.append(targetHireInfo->getCompanyName());
      applicationInfo.append(to_string(targetHireInfo->getBusinessNum()));
      applicationInfo.append(targetHireInfo->getWorkType());

      targetApplication->~Application();
      return applicationInfo;
    }
  }
}

HireInfo* Application::getAppliedHireInfo() {
  return appliedHireInfo;
}

string Application::getUserId() {
  return userId;
  
}