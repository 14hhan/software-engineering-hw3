#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

ApplyHireInfoUI::ApplyHireInfoUI(ApplyHireInfo* control) {
  this->control = control;
  startInterface();
};

void ApplyHireInfoUI::startInterface() { cout << "2-2 Apply Started...\n"; };

void ApplyHireInfoUI::searchHireInfo(string input) {
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    cout << summary << endl;
  }
}

void ApplyHireInfoUI::applyHireInfo(string userId, int chosenIndex) {
  string message = "testing";
  bool response = control->sendCreateNewApplication(userId, chosenIndex);
  message = response ? "APPLYED" : "REJECTED";
  cout << message << endl;
}