using namespace std;

#include "Control.h"


void ShowApplianceInfo::sortByCompanyName(void) const
{

}

void ShowApplianceInfo::showApplianceInfo(void) const
{
    vector<Application*> allApplication = Application::getAllApplication();

    // vector 가공
    // 그 과정에서 HireInfo 정보도 가져와야됨

    // 오름차순 정렬 필요

    ShowApplianceInfoUI::startInterface();
}