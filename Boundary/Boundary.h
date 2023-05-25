

#include <string>

#include "Control.h"

// 채용정보 등록 바운더리 클래스
class RegisterHireInfoUI {
 public:
  void StartInterface();
  void sendHireInfoData(ShowHireInfo* showHireInfo);

 private:
  RegisterHireInfo* control;
};

// RegisterHireInfo 객체를 생성하는 생성자 함수
RegisterHireInfo::RegisterHireInfo(RegisterHireInfo* control) {
  // 로그인 중, 회사 회원 상태 일 때만 채용 정보를 등록 할 수 있음
  this->control = control;
  if (loginState) {
    RegisterHireInfoUI* registerHireInfoUI = new RegisterHireInfoUI;
  }
}

// 채용정보 조회 바운더리 클래스
class ShowHireInfoUI {
 public:
  void StartInterface();
};

// startInterface()
// InputHireInfoData()