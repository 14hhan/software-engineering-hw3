#include "./Entity.h"

Application::Application(HireInfo* hireInfo, int registrationNumber) {
  hireInfo->increaseApplicantNum();
  this->appliedHireInfo = hireInfo;
  this->applicantNumber = registrationNumber;
}