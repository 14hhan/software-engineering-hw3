#ifndef Boundary_h
#define Boundary_h

#include <string>

#include "Control.h"

// 채용정보 등록 바운더리 클래스
class RegisterHireInfoUI {
 public:
  void StartInterface();
  void sendHireInfoData(ShowHireInfo* showHireInfo);
};

// 채용정보 조회 바운더리 클래스
class ShowHireInfoUI {
 public:
  void StartInterface();
};

#endif

// startInterface()
// InputHireInfoData()