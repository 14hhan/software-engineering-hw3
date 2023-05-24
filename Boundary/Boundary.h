#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include"../Control/Control.h"

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
	void startInterface(void) const;
};