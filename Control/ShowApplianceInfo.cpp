using namespace std;

#include "Control.h"
#include<algorithm>

// 기능:  일반사용자의 모든 Application객체를 가져와서 회사이름의 오름차순으로 정렬한 후 ShowApplianceInfoUI의 startInterface함수를 호출한다.
void ShowApplianceInfo::showApplianceInfo(string userId) const
{
    vector<HireInfoSummary> ApplicationOfNormalUser = Application::getNormalUsersApplications(userId);

    sort(ApplicationOfNormalUser.begin(), ApplicationOfNormalUser.end(), compareByCompanyName);

    ShowApplianceInfoUI* showApplianceInfoUI = new ShowApplianceInfoUI();
    showApplianceInfoUI->startInterface(ApplicationOfNormalUser);
}

// 기능: 회사이름의 오름차순으로 정렬시 필요한 비교함수
bool compareByCompanyName(HireInfoSummary a, HireInfoSummary b)
{
	return a.companyName < b.companyName;
}