#include <iostream>
#include <stdio.h>
#include <map>

class Info {

public:
	Info() {
		printf("%p|%s\n", this, "default constructor");
		m_name = "";
		m_age = 0;
	}
	Info(const std::string& name, int age) {
		printf("%p|%s\n", this, "params constructor");
		m_name = name;
		m_age = age;
	}
	Info(const Info& other) {
		printf("%p|%s\n", this, "copy constructor");
		this->m_name = other.m_name;
		this->m_age = other.m_age;
	}
	void Dump() {
		printf("name:%s|age:%d\n", m_name.c_str(), m_age);
	}

	//string 对象由其他对象赋值 本身的成员内存会释放 比如指针对象占用的内存
	//字符串 存储在哪里？
	Info& operator=(const Info& other) {
		printf("%p|%s\n", this, "assignment operator overload");
		if (this != &other) {
			this->m_name = other.m_name;
			this->m_age = other.m_age;
		}
		return *this;
	}
	
	~Info() {
		printf("%p|%s\n", this, "disconstructor");
	}

	std::string Name() {
		return m_name;
	}

	int Age() {
		return m_age;
	}
	
	//Debug(const char* format, )

private:
	std::string m_name;
	int m_age;

};

void GetInfo(Info& info) {
	Info* i = new Info("test", 50);
	info = *i;
	delete i;
}

int main(int argc, char *argv[]) {

//	Info* info = new Info("york", 100);
//	info->Dump();

	/*
	//很有可能对象没有立刻回收
	Info* again = new Info("jack", 20); //很有可能占据原来info的内存空间
	Info copy = *info;
	copy.Dump();
	Info assign;
	assign = *info;
	assign.Dump();
	delete again;

	Info get;
	GetInfo(get);
	get.Dump();
*/
	
	std::map<std::string, Info> info_map;
//	info_map[info->Name()] = *info;
//	info_map[info->Name()] = *info;
    Info aInfo;
	aInfo = info_map["haha"];
	info_map["haha"] = aInfo;


	return 0;
}
