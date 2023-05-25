#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Boundary/Boundary.h"
#include "../Entity/Entity.h"

struct HireListItem {
  int groupIndex;
  HireInfoSummary summary;  // 의존성을 줄여야하나? string으로 쪼개야하나
                            // 궁금하지만 귀찮다... 대충 살자
};

class SearchHireInfo {
 public:
  SearchHireInfo();
  SearchHireInfoUI* getUI();
  std::vector<std::string> sendSearchHireInfo(std::string input);

 protected:
  static bool compareItem(HireListItem item1, HireListItem item2);
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo : public SearchHireInfo {
 public:
  bool sendCreateNewApplication(int registrationNumber, int chosenIndex);
};

#endif