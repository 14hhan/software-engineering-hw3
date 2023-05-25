#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "./Control.h"

SearchHireInfo::SearchHireInfo() {}

SearchHireInfoUI* SearchHireInfo::getUI() {
  SearchHireInfoUI* ui = new SearchHireInfoUI(this);
  return ui;
}

vector<string> SearchHireInfo::sendSearchHireInfo(string input) {
  hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();

  for (int i = 0; i < size; i++) {
    HireInfoSummary summary = hireInfoGroup[i]->getHireInfo();
    HireListItem item;
    item.groupIndex = i;
    item.summary = summary;
    hireList.push_back(item);
  }

  sortByCompanyName();

  for (const HireListItem item : hireList) {
    HireInfoSummary summary = item.summary;
    cout << "Index: " << item.groupIndex;
    cout << "Company: " << summary.companyName;
    cout << "Work: " << summary.workType;
    cout << "Number of Applicant: " << summary.applicantNum;
    cout << "Due Date: " << summary.dueDate;
  }
}

void SearchHireInfo::sortByCompanyName() {
  sort(hireList.begin(), hireList.end(), compareItem);
}

bool compareItem(HireListItem item1, HireListItem item2) {
  string name1 = item1.summary.companyName;
  string name2 = item2.summary.companyName;
  return name1 > name2;
}