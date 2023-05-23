#ifndef Control_h
#define Control_h

#include <string>
#include <vector>

#include "../Entity/Entity.h"
#include "../Boundary/Boundary.h"

class SearchHireInfo {
 public:
  SearchHireInfo();
  std::vector<std::string> sendSearchHireInfo();

 private:
  HireInfo* hireInfoGroup;
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
	void deleteApplicationInfo() const;
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