using namespace std;
#include<string.h>
#include "./Entity.h"

Application::Application(HireInfo* hireInfo, int registrationNumber) {
  hireInfo->increaseApplicantNum();
  this->appliedHireInfo = hireInfo;
  this->applicantNumber = registrationNumber;
  allApplication.push_back(this);
}

Application::~Application() {
  this -> appliedHireInfo -> decreaseApplicantNum();
  allApplication.erase(remove(allApplication.begin(), allApplication.end(), this), allApplication.end());
}

vector<Application*> Application::getAllApplication() { return allApplication; };

string Application::deleteApplication(int registrationNumber, int businessNum) {
  // HireInfo에 회사번호 물어보는 과정 필요
  for(int i=0; i<allApplication.size(); i++) {
    if ((allApplication[i]->applicantNumber == registrationNumber) && (allApplication[i]->appliedHireInfo->getBusinessNum() ==businessNum )) {
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