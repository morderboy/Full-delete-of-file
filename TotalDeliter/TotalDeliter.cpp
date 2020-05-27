#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int deletfile(int *lenghtFile, string *str){
	int* i = new int(0);
	if(i == nullptr){
		cout << "Error 1" << endl;
		return 1;
	}
	if(!lenghtFile){
		cout << "Error 2" << endl;
		return 2;
	}
	if(!str){
		cout << "Error 3" << endl;
		return 3;
	}
	for (; *i < 10; (*i)++) {
		ofstream* f = new ofstream;
		(*f).open(*str, ios::trunc);
		if (!(*f)) { cout << "Error 4" << endl; return 4; }
		for (int k = 0; k < *lenghtFile; k++) {
			(*f).write("", 1);
		}
		(*f).close();
		if((*f).fail()){
		cout << "Error 5" << endl;
		return 5;
		}
		(*f).clear();
		if((*f).fail()){
		cout << "Error 6" << endl;
		return 6;
		}
		delete f;
		f = nullptr;
	}
	delete i;
	return 0;
}

int main()
{
	fstream *file = new fstream;
	if(!file){
		cout << "Error 1" << endl;
		return 1;
	}
	string *str = new string;
	if(!str){
		cout << "Error 2" << endl;
		return 2;
	}

	cout << "Enter path to file" << endl;
	if(cout.fail()){
		cout.clear();
		cout << "Error 3" << endl;
		return 3;
	}
	if(!getline(cin, *str, '\n')){
		cout << "Error 4" << endl;
		return 4;
	}
	(*file).open(*str, ios::in | ios::binary);
	if (!(*file)) { cout << "Error 5" << endl; return 5; }


	(*file).seekg(0, ios::end);
	if((*file).fail()){
		cout << "Error 6" << endl;
		return 6;
	}
	int* lenghtFile = new int(0);
	*lenghtFile = (*file).tellg();
	if((*file).fail()){
		cout << "Error 7" << endl;
		return 7;
	}


	

	(*file).close();
	if((*file).fail()){
		cout << "Error 8" << endl;
		return 8;
	}
	(*file).clear();
	if((*file).fail()){
		cout << "Error 9" << endl;
		return 9;
	}
	delete file;
	file = nullptr;
	if(deletfile(lenghtFile, str)){
		cout << "Error 10" << endl;
		return 10;
	}

	if (!remove(str->c_str())) {
		cout << "Error 11" << endl;
		return 11;
	}

	delete lenghtFile;
	delete str;
	return 0;
}


