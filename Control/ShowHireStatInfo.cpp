using namespace std;

#include "Control.h"

void ShowHireStatInfo::showHireStatInfo(string userId) const {
  // 회사외원의 ID를 인자로 받아서 그 HIreInfo()들을 불러온 후 그 정보를 UI에 전달

  vector<HireInfoSummary> companyUsersHireInfos = HireInfo::getCompanyUsersHireInfos(userId);

  // 위 벡터 적절히 가공해서 UI에 넘겨줌

  ShowHireStatInfoUI* showHireStatInfoUI = new ShowHireStatInfoUI();
  showHireStatInfoUI->startInterface(companyUsersHireInfos);
}