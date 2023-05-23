#include <vector>

using namespace std;

#include "./Control.h"

SearchHireInfo::SearchHireInfo() {
  this->hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();

  hireList = new HireListItem[size];
  for (int i = 0; i < size; i++) {
    HireInfoSummary summary = hireInfoGroup[i]->getHireInfo();
    HireListItem item;
    item.groupIndex = i;
    item.summary = summary;
  }
}

vector<string> SearchHireInfo::sendSearchHireInfo() {}

void SearchHireInfo::sortByCompanyName() {}