#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "Entity.h"

class SearchHireInfo {
 public:
  SearchHireInfo(){HireInfo.};
  std::vector<std::string> sendSearchHireInfo();

 private:
  HireInfo* hireInfoGroup;
};

class ApplyHireInfo {
 public:
  std::vector<std::string> sendSearchHireInfo();
  bool sendCreateNewApplication();
};

#endif