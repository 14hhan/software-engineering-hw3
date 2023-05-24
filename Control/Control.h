#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Entity/Entity.h"
#include "../Boundary/Boundary.h"

struct HireListItem {
  int groupIndex;
  HireInfoSummary summary;  // 의존성을 줄여야하나? string으로 쪼개야하나
                            // 궁금하지만 귀찮다... 대충 살자
};

class SearchHireInfo {
 public:
  SearchHireInfo();
  std::vector<std::string>
  sendSearchHireInfo();  // TODO: UI에 대한 반환형 논의 필요

 private:
  std::vector<HireInfo*> hireInfoGroup;
  vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo {
 public:
  std::vector<std::string> sendSearchHireInfo();
  bool sendCreateNewApplication();
};




// 송양기
class ShowApplianceInfo
{
public:
	void sortByCompanyName() const;
  void showApplianceInfo() const;
};

class CancelApplianceInfo
{
public:
	std::string deleteApplicationInfo(int) const;
	void sortByCompanyName() const;
};

class ShowApplicationStatInfo
{
public:
	void sortByMonth() const;
	void sortByWorkType() const;
};

class ShowHireStatInfo
{
public:
	void getApplicationInfoCnt() const;
	void sortByWorkType() const;
};

#endif