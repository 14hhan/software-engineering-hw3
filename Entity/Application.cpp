using namespace std;

#include "./Entity.h"

Application::Application(HireInfo* hireInfo, int registrationNumber) {
  hireInfo->increaseApplicantNum();
  this->appliedHireInfo = hireInfo;
  this->applicantNumber = registrationNumber;
  allApplication.push_back(this);
}

vector<Application*> Application::getAllApplication() { return allApplication; };

