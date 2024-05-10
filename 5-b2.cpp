/*2353126 ÐÅ03 ´ÞÂ¶ÎÄ*/
#include <iostream>
using namespace std;
int main()
{
	const int num_lamp = 100;
	bool lamps[num_lamp] = { false };
	const int num_people = 100;
	
	for(int people=1;people<=num_people;people++){
		for (int lamp = people; lamp <= num_lamp; lamp += people) {
			lamps[lamp - 1] = !lamps[lamp - 1];
	    }
	}
	
	int count = 0;
	for (int i = 0; i < num_lamp; i++) {
		if (lamps[i] == true) {
			count++;
			if (count == 1)
				cout << i + 1;
			else
				cout << " " << i + 1;
		}
	}
	cout << endl;
	return 0;
}
