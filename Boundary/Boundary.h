#ifndef Boundary_h
#define Boundary_h

#include <Control.h>

#include <string>

class RegisterHireInfo {
 public:
  void StartInterface();
  void sendHireInfoData(ShowHireInfo* showHireInfo);
};

#endif

// startInterface()
// InputHireInfoData()