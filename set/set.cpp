#include<iostream>
#include<set>
#include<String>

using namespace std;
class str{
	public: 
	void strings(){
		set<string> strs = {"David","jones","Micheal","Rajput","Taha"};
		for(string k: strs){
			cout << k << "\n";
		}
	}
};

int main(){
	/* set<int, greater<int>> numb = {1,2,3,4,5,7,8,90,12};
	   it print from greater to smaller number */
	set<int> numb = {1,2,3,4,5,7,8,90,12}; // for int it from less to greater
	numb.insert(405);                      // to add number
	numb.erase(90);                        // to erase just use erase and enter the name
	for (int k : numb){
		cout<< k << "\n";
	}
	
	//calling function
	str st;
	st.	strings();
	return 0;
}
