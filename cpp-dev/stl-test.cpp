#include <map>
#include <iostream>

using namespace std;

class Record {
private: 
	string name;
	int age;
public:
	Record() {
		cout << this << " class constructing ..." << endl;
	}
	~Record() {
		cout << this <<  " class Record deconstructing ..." << endl;
	}
	Record(string _name, int _age) {
		cout << this << " class constructing ..." << endl;
		this->name = _name;
		this->age  = _age;
	}
	string getName() {
		return this->name;
	}
/*	
	Record& operator = (const Record &rh) {
		cout << "overload assignment operator: " << &rh << " -> " << this << endl;
		if (this == &rh) {
             return *this;
		}
		this->name = rh.name;
		this->age = rh.age;
        return *this;
    }
*/
	void myself() {
		cout << this << " " << this->getName() << endl;
	}
};

map<string, Record> gR;

void addRecord() {
	Record a("york", 12);
	a.myself();
	gR[a.getName()] = a;  //这里有一次构造函数
	Record b("john", 22);
	b.myself();
	gR[b.getName()] = b;
}
void printRecord() {
	map<string, Record>::iterator iter = gR.begin();
	for (; iter != gR.end(); iter++) {
		cout << iter->first << " -> " << &(iter->second) << " " << iter->second.getName() << endl;
	}
}

int main(int argc, char *argv[]) {

	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}
	printRecord();
	addRecord();
	printRecord();
}
