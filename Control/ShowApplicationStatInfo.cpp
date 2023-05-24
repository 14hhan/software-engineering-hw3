using namespace std;

#include "Control.h"

void ShowApplicationStatInfo::showApplicationStatInfo(string userId) {
    // 일반회원 : 업무별 지원횟수 출력
    // 일반회원이 작성한 Application을 우선 다 불러온 후
        // 회사별이 아니라 업무별로 카운트 해야 함!!

}

// void ShowApplianceInfo::showApplianceInfo(string userId) const
// {
//     vector<HireInfoSummary> ApplicationOfNormalUser = Application::getNormarUsersApplications(userId);

//     // sort by company name. 오름차순인지 검사 다시 해야함
//     sort(ApplicationOfNormalUser.begin(), ApplicationOfNormalUser.end(), compareByCompanyName);

//     // ApplicationOfNormalUser 에서 가공해야함


//     ShowApplianceInfoUI* showApplianceInfoUI = new ShowApplianceInfoUI();
//     showApplianceInfoUI->startInterface(ApplicationOfNormalUser);
// }

// bool compareByCompanyName(HireInfoSummary a, HireInfoSummary b)
// {
// 	return a.companyName < b.companyName;
// }