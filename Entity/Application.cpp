using namespace std;

#include "./Entity.h"

Application::Application(HireInfo* hireInfo) : appliedHireInfo(hireInfo) {
  hireInfo->increaseApplicantNum();
  allApplication.push_back(this);
}

vector<Application*> Application::getAllApplication() { return allApplication; };