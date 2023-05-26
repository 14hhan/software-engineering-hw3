using namespace std;

#include <iostream>
#include "Boundary.h"

// 기능: 지원정보를 받아서 출력한다.
void ShowApplianceInfoUI::startInterface(vector<HireInfoSummary> ApplicationOfNormalUser, ofstream& outputFile)
{
	// { [회사이름] [사업자번호] [업무] [인원 수] [신청마감일] }

	for(int i=0; i<ApplicationOfNormalUser.size(); i++) {
		outputFile << ApplicationOfNormalUser[i].companyName << ApplicationOfNormalUser[i].workType << ApplicationOfNormalUser[i].applicantNum << ApplicationOfNormalUser[i].dueDate << endl;
	}

	
}