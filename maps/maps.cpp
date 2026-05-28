//map
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main (){
	map<string, int> name_age = {{"Taha",19},{"Nazir", 49},{"Ali",68}};
	name_age.insert({"Umer",55});
	cout << name_age["Taha"]<<"\n";
	cout << name_age.size()<< "\n";
	name_age.erase("Ali");
	cout << name_age.size()<< "\n";

	return 0;
	
}
