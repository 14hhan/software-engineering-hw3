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
    if (summary.companyName.compare(input) == 0) {
      HireListItem item;
      item.groupIndex = to_string(i);
      item.summary = summary;
      hireList.push_back(item);
    }
  }

  // sortByCompanyName();

  vector<string> response;

  for (const HireListItem item : hireList) {
    HireInfoSummary summary = item.summary;

    string info = "";
    info.append("Index: ").append(item.groupIndex).append("\n");
    info.append("Company: ").append(summary.companyName).append("\n");
    info.append("Work: ").append(summary.workType).append("\n");
    info.append("Applicant: ").append(summary.applicantNum).append("\n");
    info.append("Due Date: ").append(summary.dueDate).append("\n");

    response.push_back(info);
  }

  return response;
}

bool compareItem1(HireListItem item1, HireListItem item2) {
  string name1 = item1.summary.companyName;
  string name2 = item2.summary.companyName;
  return name1 > name2;
}

void SearchHireInfo::sortByCompanyName() {
  sort(hireList.begin(), hireList.end(), compareItem1);
}
