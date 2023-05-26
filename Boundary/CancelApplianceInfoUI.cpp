using namespace std;

#include "Boundary.h"

// 기능: 취소된 지원정보를 출력한다.
void CancelApplianceInfoUI::startInterface(string userId, int businessNum) const
{
    // 입력 받고 그 값을 Control에 넘겨줌
    CancelApplianceInfo* cancelApplianceInfo = new CancelApplianceInfo();
    string deletedResult = cancelApplianceInfo->deleteApplicationInfo(userId,businessNum);
}