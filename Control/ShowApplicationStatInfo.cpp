using namespace std;

#include "Control.h"

void ShowApplicationStatInfo::showApplicationStatInfo(int loginNum, string userId) {
    // 일반회원 : 업무별 지원횟수 출력
    if (loginNum==1) {
        // 일반회원이 작성한 Application을 우선 다 불러온 후
        // 회사별이 아니라 업무별로 카운트 해야 함!!
    }

    // 회사회원 : 업무별 지원자 출력
    else if (loginNum==2) {
        // 회사회원이 작성한 HireInfo를 우선 다 불러온 후
        // 업무별 지원자 수 바로 출력하면 됨 -> 쉬움.
    }
}

void ShowApplianceInfo::showApplianceInfo(string userId) const
{
    vector<HireInfoSummary> ApplicationOfNormalUser = Application::getAllApplication(userId);

    // sort by company name. 오름차순인지 검사 다시 해야함
    sort(ApplicationOfNormalUser.begin(), ApplicationOfNormalUser.end(), compareByCompanyName);

    // ApplicationOfNormalUser 에서 가공해야함


    ShowApplianceInfoUI* showApplianceInfoUI = new ShowApplianceInfoUI();
    showApplianceInfoUI->startInterface(ApplicationOfNormalUser);
}

bool compareByCompanyName(HireInfoSummary a, HireInfoSummary b)
{
	return a.companyName < b.companyName;
}