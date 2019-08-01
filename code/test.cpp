#include<iostream>
#include<fstream>

using namespace std;


void writer(ofstream* file ){
	int data=12;
	(*file) << data << endl;
}
void writer(){
	ofstream file("Customer.file", ios::app);
				file << "hello" << endl;
				file << "he" << endl;
				file << "jskdlf" << endl;
				file << "jskfj" << endl;
			file.close();
		}


int main(){
	ofstream file("test.txt", ios::out);
	file << "Hello1111" << endl;
	file.close();

	writer();
	
	ofstream file3("test.txt", ios::out);	
	file3 << "man"  <<endl;
	file3.close();
	
	ifstream file2("test.txt", ios::in);
	string first, last;
	int second;
	
	file2 >> first;
	file2 >> second;
	file2 >> last;
	
	cout << first << endl;
	cout << second << endl;
	cout << last <<endl;
	
	file2.close();
	
}

		void save_to(ofstream* file=){
			(*file) >> _name << endl;
			(*file) >> _employee_number << endl;
		}

