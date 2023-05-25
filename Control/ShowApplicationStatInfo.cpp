using namespace std;

#include "Control.h"
#include <map>

void ShowApplicationStatInfo::showApplicationStatInfo(string userId) {
    // 일반회원 : 업무별 지원횟수 출력
    // 일반회원이 작성한 Application을 우선 다 불러온 후
        // 회사별이 아니라 업무별로 카운트 해야 함!!
    vector<HireInfoSummary> normarUsersApplications = Application::getNormarUsersApplications(userId);

    // 새로운 자료구조가 필요
    map<string, int> workTypeCount;
    workTypeCount["h"] = 10;

    for(int i=0; i<normarUsersApplications.size(); i++) {
        if (workTypeCount.find(normarUsersApplications[i].workType) == workTypeCount.end()) { // 없는 경우
            workTypeCount[normarUsersApplications[i].workType] = 1;
        }
        else {
            workTypeCount[normarUsersApplications[i].workType] +=1;
        }
    }

    ShowApplicationStatInfoUI* showApplicationStatInfoUI = new ShowApplicationStatInfoUI();
    showApplicationStatInfoUI->startInterface(workTypeCount);
}
