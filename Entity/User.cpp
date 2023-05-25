using namespace std;

#include "Entity.h"

User::User(string id, int password) {
  // id와 비밀번호를 입력받아 저장한다
  this->id = id;
  this->password = password;
}

NormalUser::NormalUser(string id, int password, string userName,
                       int registrationNumber)
    : User::User(id, password) {
  // User의 상속자로 사용자 이름과 고유식별번호를 저장한다
  this->userName = userName;
  this->registrationNumber = registrationNumber;
}

CompanyUser::CompanyUser(string id, int password, string companyName,
                         int companyNumber)
    : User::User(id, password) {
  // User의 상속자로 회사명과 사업자 번호를 저장한다
  this->companyName = companyName;
  this->companyNumber = companyNumber;
}

string User::getUserInfo() {
  // User 정보 요약이 담긴 문자열을 반환한다
  string summary = "";
  summary.append("ID:").append(id).append("\n");
  return summary;
}

string NormalUser::getUserInfo() {
  // 위에 더해 일반 유저의 이름을 덧붙여 반환한다
  string summary = User::getUserInfo();
  summary.append("User Name:").append(userName).append("\n");
  return summary;
}

string CompanyUser::getUserInfo() {
  // 위에 더해 회사 회원의 회사명을 덧붙여 반환한다
  string summary = User::getUserInfo();
  summary.append("Company Name:").append(companyName).append("\n");
  return summary;
}
