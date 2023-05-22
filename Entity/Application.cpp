#include "Entity.h"

Application::Application(HireInfo* hireInfo) : appliedHireInfo(hireInfo) {
  hireInfo->increaseApplicantNum();
}