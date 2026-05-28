#include <stack>
#include <iostream>
#include <String>
using namespace std;

int main(){
    stack<string> names;// all the element in stack cannot be initialize
    names.push("Taha");  // the last intered valve it considered first
    names.push("Nazir");
    names.push("Robert");
    names.push("Alexander");
   	cout << names.top() <<"\n";
    
    //displaying all the element but do it on your own risk
    // this will also delete all the items store in it 
    while(!names.empty()){
	   	cout << names.top() <<"\n";
	   	names.pop();
	}
	return 0;
}
