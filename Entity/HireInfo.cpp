using namespace std;

#include "./Entity.h"
#include<string.h>

std::vector<HireInfo*> HireInfo::allHireInfo;

HireInfo::HireInfo(string companyName, string workType, int dueDate, int businessNum, string userId) {
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
  this->businessNum = businessNum;
  this->userId = userId;
  allHireInfo.push_back(this);
};

HireInfoSummary HireInfo::getHireInfo() {
  HireInfoSummary summary;
  summary.companyName = companyName;
  summary.workType = workType;
  summary.applicantNum = to_string(applicantNum);
  summary.dueDate = to_string(dueDate);
  return summary;
};

vector<HireInfoSummary> HireInfo::getCompanyUsersHireInfos(string userId) { 
  vector<HireInfoSummary> companyUsersHireInfos;

  for(int i=0; i<allHireInfo.size(); i++) {
    if (allHireInfo[i]->getUserId() == userId) {
      companyUsersHireInfos.push_back(allHireInfo[i]->getHireInfo());
    }
  }
  return companyUsersHireInfos;
  };

void HireInfo::increaseApplicantNum() { applicantNum++; };

void HireInfo::decreaseApplicantNum() { applicantNum--; };

vector<HireInfo*> HireInfo::getAllHireInfo() { return allHireInfo; };

int HireInfo::getBusinessNum() {
  return this->businessNum;
}

string HireInfo::getCompanyName() {
  return this->companyName;
}

string HireInfo::getWorkType() {
  return this->workType;
}