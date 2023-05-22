using namespace std;

#include "Entity.h"

HireInfo::HireInfo(string companyName, string workType, int dueDate) {
  this->companyName = companyName;
  this->workType = workType;
  this->dueDate = dueDate;
  this->applicantNum = 0;
}

string HireInfo::getHireInfo() {
  string summary = "";
  summary.append("Company:").append(companyName).append("\n");
  summary.append("Work Type:").append(workType).append("\n");
  summary.append("Due Date:").append(to_string(dueDate)).append("\n");
  summary.append("Applicant Num:").append(to_string(applicantNum)).append("\n");
  return summary;
}

void HireInfo::increaseApplicantNum() { applicantNum++; }