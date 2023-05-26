#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "./Control.h"

SearchHireInfoUI* SearchHireInfo::getUI(ifstream& inputFile,
                                        ofstream& outputFile) {
  // 사용자에게 Boundary 객체를 넘겨준다
  SearchHireInfoUI* ui = new SearchHireInfoUI(this, inputFile, outputFile);
  return ui;
}

vector<string> SearchHireInfo::sendSearchHireInfo(string input) {
  // 검색어를 입력받아 채용 정보를 추려내어 Boundary에게 해당 목록을 반환한다
  hireInfoGroup = HireInfo::getAllHireInfo();
  int size = hireInfoGroup.size();
  // 검색어와 일치하는 회사명을 가진 채용 정보를 추린다
  for (int i = 0; i < size; i++) {
    HireInfoSummary summary = hireInfoGroup[i]->getHireInfo();
    if (summary.companyName.compare(input) == 0) {
      HireListItem item;
      item.groupIndex = to_string(i);
      item.summary = summary;
      hireList.push_back(item);
    }
  }

  // 해당하는 정보의 배열을 회사 이름순으로 정렬한다
  sortByCompanyName();

  vector<string> response;

  // 해당하는 정보의 배열을 string 배열로 가공한다
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

  // 가공된 string 배열을 반환한다
  return response;
}

bool compareItem1(HireListItem item1, HireListItem item2) {
  // sort용 함수
  string name1 = item1.summary.companyName;
  string name2 = item2.summary.companyName;
  return name1 > name2;
}

void SearchHireInfo::sortByCompanyName() {
  // 해당하는 정보의 배열을 회사 이름순으로 정렬한다
  sort(hireList.begin(), hireList.end(), compareItem1);
}
