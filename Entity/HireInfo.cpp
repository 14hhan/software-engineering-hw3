using namespace std;

#include "./Entity.h"

std::vector<HireInfo*> HireInfo::allHireInfo;

HireInfo::HireInfo(string companyName, string workType, int dueDate) {
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
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

vector<HireInfo*> HireInfo::getAllHireInfo() { return allHireInfo; };