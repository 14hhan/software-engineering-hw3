using namespace std;
#include <string.h>

#include "./Entity.h"

Application::Application(HireInfo* hireInfo, string userId) {
  // 지원한 채용정보의 포인터, 유저 ID를 저장한다
  hireInfo->increaseApplicantNum();
  this->appliedHireInfo = hireInfo;
  this->userId = userId;
  allApplication.push_back(this);
}

Application::~Application() {
  // 소멸시 allApplication에서 자신을 삭제한다
  appliedHireInfo->decreaseApplicantNum();  // TODO
  allApplication.erase(
      remove(allApplication.begin(), allApplication.end(), this),
      allApplication.end());
}

vector<HireInfoSummary> Application::getNormalUsersApplications(string userId) {
  // STATIC: 입력된 userId와 일치하는 userId를 가진 지원 정보 목록 반환
  vector<HireInfoSummary> ApplicationOfNormalUser;
  for (int i = 0; i < allApplication.size(); i++) {
    if (allApplication[i]->getUserId() == userId) {
      ApplicationOfNormalUser.push_back(
          allApplication[i]->getAppliedHireInfo()->getHireInfo());
    }
  }

  return ApplicationOfNormalUser;
};

string Application::deleteApplication(string userId, int businessNum) {
  // STATIC: 모든 지원 정보중 입력된 userId와 businessNum을 가진 정보를 삭제
  // 삭제 후 삭제된 지원 정보의 정보를 반환
  for (int i = 0; i < allApplication.size(); i++) {
    if ((allApplication[i]->getUserId() == userId) &&
        (allApplication[i]->getAppliedHireInfo()->getBusinessNum() ==
         businessNum)) {
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

HireInfo* Application::getAppliedHireInfo() { return appliedHireInfo; }

string Application::getUserId() { return userId; }