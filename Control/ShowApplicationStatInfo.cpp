using namespace std;

#include "Control.h"
#include <map>

// 일반회원의 ID를 받아서 지원통계정보를 생성한다. 이후 그 정보를 ShowApplicationStatInfoUI 클래스의 startInterface함수에 인자로 넘긴다.
void ShowApplicationStatInfo::showApplicationStatInfo(string userId) {
    // 일반회원 : 업무별 지원횟수 출력
    vector<HireInfoSummary> normarUsersApplications = Application::getNormalUsersApplications(userId);

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
