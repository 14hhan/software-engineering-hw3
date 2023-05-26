using namespace std;

#include "Boundary.h"

//기능: 채용통계정보를 받아서 출력한다.
void ShowHireStatInfoUI::startInterface(vector<HireInfoSummary> companyUsersHireInfos) const
{
    for(int i=0; i<companyUsersHireInfos.size(); i++) {
		outputFile << companyUsersHireInfos[i].companyName << companyUsersHireInfos[i].applicantNum << endl;
	}
}