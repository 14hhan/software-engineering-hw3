#include <string>

#include "Control.h"

// 채용정보 등록 바운더리 클래스
class RegisterHireInfoUI {
 public:
  RegisterHireInfoUI(RegisterHireInfo* control);
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
};

// 채용정보 조회 바운더리 클래스
class ShowHireInfoUI {
 public:
  ShowHireInfoUI(ShowHireInfo* control);
  void StartInterface();

 private:
  ShowHireInfo* control;
};
// showHireInfo 컨트롤 클래스의 생성자 함수
void ShowHireInfoUI::showHireInfo(ShowHireInfo* showHireInfo) {
  // 로그인 상태에서 회사 회원 자신이 등록한 채용 정보 조회 가능
  this->control = control;

  if (loginState) {
    ShowHireInfoUI* ShowHireInfoUI = new ShowHireInfoUI;
  }
};
