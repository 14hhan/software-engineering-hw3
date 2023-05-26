using namespace std;

#include "Control.h"
#include<algorithm>


void ShowApplianceInfo::showApplianceInfo(string userId) const
{
    vector<HireInfoSummary> ApplicationOfNormalUser = Application::getNormalUsersApplications(userId);

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