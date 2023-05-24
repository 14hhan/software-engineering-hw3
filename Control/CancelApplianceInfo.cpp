using namespace std;

#include "Control.h"



string CancelApplianceInfo::deleteApplicationInfo(int registrationNumber, int businessNum) const
{
    // Application에 객체 삭제 요청.(지원자정보 + 회사번호를 기반으로)
    // 그 과정에서 HireInfo 정보 필요.
    // 삭제한 후 HireInfo 데이터 string형태로 반환

    std::string outputInfo = Application::deleteApplication(registrationNumber, businessNum);
}