#ifndef Control_h
#define Control_h

#include <string>

class SearchHireInfo {
 public:
  std::string* sendSearchHireInfos();
};

class ApplyHireInfo {
 public:
  std::string* sendSearchHireInfos();
  bool sendCreateNewApplication();
};


class ShowHireInfo {
  public: 
    std::string* sendHireInfoData();
};

#endif