using namespace std;

#include "./Entity.h"
#include<string.h>

HireInfo::HireInfo(string companyName, string workType, int dueDate, int businessNum) {
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
  this->businessNum = businessNum;
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