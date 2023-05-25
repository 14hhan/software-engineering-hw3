#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Entity/Entity.h"
#include "../Boundary/Boundary.h"

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


// 송양기
class ShowApplianceInfo
{
public:
  void showApplianceInfo(string) const;
  bool compareByCompanyName(HireInfoSummary, HireInfoSummary);
};

class CancelApplianceInfo
{
public:
	std::string deleteApplicationInfo(string, int) const;
};

class ShowApplicationStatInfo
{
public:
  void showApplicationStatInfo(string);
	void sortByMonth() const;
	void sortByWorkType() const;
};

class ShowHireStatInfo
{
public:
	void showHireStatInfo(string) const;
	void sortByWorkType() const;
};

#endif