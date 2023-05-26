using namespace std;

#include <string.h>

#include "Entity.h"

std::vector<HireInfo*> HireInfo::allHireInfo;

HireInfo::HireInfo(string companyName, string workType, int dueDate,
                   int businessNum, string userId) {
  // 회사이름, 업무, 마감일, 회사번호, 유저 번호를 받아서 저장한다
  // Q: 유저 번호는 어디에 쓰는 건가요?
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
  this->businessNum = businessNum;
  this->userId = userId;
  allHireInfo.push_back(this);
};

vector<HireInfo*> HireInfo::getAllHireInfo() { return allHireInfo; };
// STATIC: Control에게 모든 채용 정보의 포인터가 담긴 배열을 반환한다

vector<HireInfoSummary> HireInfo::getCompanyUsersHireInfos(string userId) {
  // STATIC: userId와 일치하는 userId를 가진 HireInfo의 목록을 반환한다
  vector<HireInfoSummary> companyUsersHireInfos;

  for (int i = 0; i < allHireInfo.size(); i++) {
    if (allHireInfo[i]->getUserId() == userId) {
      companyUsersHireInfos.push_back(allHireInfo[i]->getHireInfo());
    }
  }
  return companyUsersHireInfos;
};

HireInfoSummary HireInfo::getHireInfo() {
  // HireInfo의 요약정보를 구조체 형태로 반환한다.
  HireInfoSummary summary;
  summary.companyName = companyName;
  summary.workType = workType;
  summary.applicantNum = to_string(applicantNum);
  summary.dueDate = to_string(dueDate);
  return summary;
};

void HireInfo::increaseApplicantNum() { applicantNum++; };
// 지원 정보 생성시 해당 HireInfo의 지원자수를 1 늘린다

void HireInfo::decreaseApplicantNum() { applicantNum--; };
// 지원 정보 소멸시 해당 HireInfo의 지원자수를 1줄인다

int HireInfo::getBusinessNum() { return this->businessNum; }

string HireInfo::getCompanyName() { return this->companyName; }

string HireInfo::getWorkType() { return this->workType; }

string HireInfo::getUserId() { return this->userId; }