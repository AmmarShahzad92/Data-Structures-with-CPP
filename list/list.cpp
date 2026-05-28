#include <iostream>
#include <list>
#include <String>
using namespace std;

int main(){
	list<string> car= {"BMW","Mercidies"};
	car.push_front("Honda"); //adding a item in the start
	cout<< car.front()<< "\n"; // check the first element
	cout<< car.back()<< "\n";  //see that last element of the list
	
	for (string j: car){   //use for each loop instead of for or index number to see all
		cout<< j << "\n" ; //the values in the list;
		
	}
	return 0;           // can't use [] like we used to do in vector as will give error 
	
}
