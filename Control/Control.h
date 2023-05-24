#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Entity/Entity.h"

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

 protected:
  std::vector<HireInfo*> hireInfoGroup;
  vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo : public SearchHireInfo {
 public:
  bool sendCreateNewApplication(int chosenIndex);
};

#endif