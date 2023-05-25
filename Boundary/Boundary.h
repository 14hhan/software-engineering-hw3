#include <string>

#include "../Control/Control.h"

class SearchHireInfoUI {
 public:
  SearchHireInfoUI(SearchHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);

 private:
  SearchHireInfo* control;
};