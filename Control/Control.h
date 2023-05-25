#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "Boundary.h"
#include "Entity.h"

struct HireListItem {
  std::string groupIndex;
  HireInfoSummary summary;
};

class SearchHireInfo {
 public:
  SearchHireInfo();
  SearchHireInfoUI* getUI();
  std::vector<std::string> sendSearchHireInfo(std::string input);

 private:
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

class ApplyHireInfo {
 public:
  ApplyHireInfo();
  ApplyHireInfoUI* getUI();
  std::vector<std::string> sendSearchHireInfo(std::string input);
  bool sendCreateNewApplication(int registrationNumber, int chosenIndex);

 private:
  std::string InputWord;
  std::vector<HireInfo*> hireInfoGroup;
  std::vector<HireListItem> hireList;
  void sortByCompanyName();
};

#endif