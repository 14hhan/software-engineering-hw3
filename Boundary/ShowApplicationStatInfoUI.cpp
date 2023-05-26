using namespace std;

#include <map>
#include "Boundary.h"

// 기능: 지원통계정보를 받아서 출력한다.
void ShowApplicationStatInfoUI::startInterface(map<string, int> workTypeCount, ofstream& outputFile) const
{
    for(int i=0; i<workTypeCount.size(); i++) {
		outputFile << workTypeCount[i].key << workTypeCount[i].item << endl;
	}
}