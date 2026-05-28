//queue
#include<iostream>
#include<queue>
#include<String>
using namespace std;

int main (){
	queue<string> names;
	names.push("Jones");
	names.push("Daniyal");
	names.push("Taha");
	
	while(!names.empty()){
		cout << names.front() << "\n";
		names.pop();
		
	}
	return 0;
}
