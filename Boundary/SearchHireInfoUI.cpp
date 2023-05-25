#include <iostream>
#include <vector>

using namespace std;

#include "Boundary.h"
#include "Control.h"

SearchHireInfoUI::SearchHireInfoUI(SearchHireInfo* control) {
  this->control = control;
  startInterface();
}

void SearchHireInfoUI::startInterface() { cout << "2-1 SearchStarted...\n"; }

void SearchHireInfoUI::searchHireInfo(string input) {
  vector<string> response = control->sendSearchHireInfo(input);
  for (string summary : response) {
    cout << summary << endl;
  }
}