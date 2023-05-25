#ifndef Boundary_h
#define Boundary_h

#include <string>

class SearchHireInfo;
class ApplyHireInfo;
class SearchHireInfoUI {
 public:
  SearchHireInfoUI(SearchHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);

 protected:
  SearchHireInfo* control;
};

class ApplyHireInfoUI {
 public:
  ApplyHireInfoUI(ApplyHireInfo* control);
  void startInterface();
  void searchHireInfo(std::string input);
  void applyHireInfo(int registrationNumber, int chosenIndex);

 private:
  ApplyHireInfo* control;
};

#endif