#ifndef Boundary_h
#define Boundary_h

#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include"../Control/Control.h"

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

class ShowApplianceInfoUI
{
public:
    // 인자 필요
	void startInterface(vector<HireInfoSummary>);
};

class CancelApplianceInfoUI
{
public:
	void startInterface(string, int) const;

};

class ShowApplicationStatInfoUI
{
public:
	void startInterface(void) const;
};

class ShowHireStatInfoUI
{
public:
	void startInterface(vector<HireInfoSummary>) const;
};

#endif