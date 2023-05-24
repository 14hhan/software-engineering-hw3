#include "Control.h"

bool ApplyHireInfo::sendCreateNewApplication(int registrationNumber,
                                             int chosenIndex) {
  HireInfo* appliedCompany = hireInfoGroup[chosenIndex];
  Application* newApp = new Application(appliedCompany, registrationNumber);
  return true;
}