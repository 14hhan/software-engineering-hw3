using namespace std;

#include "Entity.h"

User::User(string id, string password) {
  this->id = id;
  this->password = password;
}

NormalUser::NormalUser(string id, string password, string userName,
                       int registrationNumber)
    : User::User(id, password) {
  this->userName = userName;
  this->registrationNumber = registrationNumber;
}

CompanyUser::CompanyUser(string id, string password, string companyName,
                         int companyNumber)
    : User::User(id, password) {
  this->companyName = companyName;
  this->companyNumber = companyNumber;
}

string User::getUserInfo() {
  string summary = "";
  summary.append("ID:").append(id).append("\n");
  return summary;
}

string NormalUser::getUserInfo() {
  string summary = User::getUserInfo();
  summary.append("User Name:").append(userName).append("\n");
  return summary;
}

string CompanyUser::getUserInfo() {
  string summary = User::getUserInfo();
  summary.append("Company Name:").append(companyName).append("\n");
  return summary;
}
