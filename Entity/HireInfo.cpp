
#include <string>
using namespace std;

#include "Entity.h"

HireInfo::HireInfo(string companyName, string workType, int dueDate) {
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
}

HireSummary HireInfo::getHireInfo() {
  HireSummary summary;
  summary.companyName = companyName;
  summary.workType = workType;
  summary.applicantNum = applicantNum;
  summary.dueDate = dueDate;
}

void HireInfo::increaseApplicantNum() { applicantNum++; }