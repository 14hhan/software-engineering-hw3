#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "./Control.h"

ApplyHireInfoUI* ApplyHireInfo::getUI(ifstream& inputFile,
                                      ofstream& outputFile) {
  // 사용자에게 Boundary 객체를 넘겨준다
  ApplyHireInfoUI* ui = new ApplyHireInfoUI(this, inputFile, outputFile);
  return ui;
}

vector<string> ApplyHireInfo::sendSearchHireInfo(string input) {
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

bool compareItem2(HireListItem item1, HireListItem item2) {
  // sort용 함수
  string name1 = item1.summary.companyName;
  string name2 = item2.summary.companyName;
  return name1 > name2;
}

void ApplyHireInfo::sortByCompanyName() {
  // 해당하는 정보의 배열을 회사 이름순으로 정렬한다
  sort(hireList.begin(), hireList.end(), compareItem2);
}

bool ApplyHireInfo::sendCreateNewApplication(string userId, int chosenIndex) {
  // 입력받은 고유식별번호와 검색결과에서 선택한 채용 정보 번호를 입력해
  // 원하는 채용 정보에 지원한다
  HireInfo* appliedCompany = hireInfoGroup[chosenIndex];
  cout << hireInfoGroup.size() << endl;
  Application* newApp = new Application(appliedCompany, userId);
  return true;
}