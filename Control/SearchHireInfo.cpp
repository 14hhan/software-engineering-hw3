#include <algorithm>
#include <vector>


using namespace std;

#include "./Control.h"

SearchHireInfo::SearchHireInfo(string userName) {
  this->hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();

  for (int i = 0; i < size; i++) {
    HireInfoSummary summary = hireInfoGroup[i]->getHireInfo();
    HireListItem item;
    item.groupIndex = i;
    item.summary = summary;
    hireList.push_back(item);
  }
}

vector<string> SearchHireInfo::sendSearchHireInfo() {}

void SearchHireInfo::sortByCompanyName() {
  sort(hireList.begin(), hireList.end(), compareItem);
}

bool compareItem(HireListItem item1, HireListItem item2) {
  string name1 = item1.summary.companyName;
  string name2 = item2.summary.companyName;
  return name1 > name2;
}