using namespace std;

#include "Boundary.h"

void CancelApplianceInfoUI::startInterface(string userId, int businessNum) const
{
    // 입력 받고 그 값을 Control에 넘겨줌
    CancelApplianceInfo* cancelApplianceInfo = new CancelApplianceInfo();
    string deletedResult = cancelApplianceInfo->deleteApplicationInfo(userId,businessNum);

    // 여기에 deletedResult를 바탕으로 output파일에 써야한다.
}