using namespace std;

#include "Control.h"
#include "Entity/Entity.h"

void RegisterUser::addUser(int userType, string id, string password,
                           string name, int number) {
  if (userType == 1) {
    NormalUser* newUser = new NormalUser(id, password, name, number);
  } else if (userType == 2) {
    CompanyUser* newUser = new CompanyUser(id, password, name, number);
  }
}

void WithdrawUser::deleteUser(string id) {}

void Login::login(string id, string password) {}

void Logout::logout(string id) {}
