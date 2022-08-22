#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

struct citizen
{
	std::string name;
	int age;
};

std::ostream& operator<<(ostream& os, const citizen& c)
{
	os << "[" << c.name << ", " << c.age << "]";
	return os;
}

int main()
{
	std::forward_list<citizen> citizens = {
		{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
	};

	auto citizens_copy = citizens;

	std::cout << "전체 시민들: ";
	for (const auto& c : citizens)
	{
		std::cout << c << " ";
	}
	cout << endl;
	
	citizens.remove_if([](const citizen& c) {return (c.age < 19); });

	cout << "투표권이 있는 시민들: ";

	for (const auto& c : citizens)
	{
		std::cout << c << " ";
	}
	cout << endl;

	// 참인 것은 삭제, 거짓은 것은 냅둠
	citizens_copy.remove_if([](const citizen& c) { return (c.age != 18); });
	cout << "내년에 투표권이 생기는 시민들: ";

	for (const auto& c : citizens_copy)
	{
		std::cout << c << " ";
	}
	cout << endl;

}
