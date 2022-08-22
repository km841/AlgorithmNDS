#include <iostream>
#include <string>
#include <forward_list>
#include <vector>
using namespace std;

int main()
{
	std::vector<std::string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};

	auto it = vec.begin();
	std::cout << "가장 최근 우승자: " << *it << endl;

	it += 8; // random access iterator의 경우 덧셈 연산이 가능하다
	cout << "8년 전 우승자: " << *it << endl;

	advance(it, -3);
	cout << "그후 3년 뒤 우승자: " << *it << endl;

	std::forward_list<std::string> fwd(vec.begin(), vec.end());
	
	auto it1 = fwd.begin();
	std::cout << "가장 최근 우승자: " << *it1 << std::endl;

	advance(it1, 5); // forward iterator의 경우 advance를 활용
	std::cout << "5년 전 우승자: " << *it1 << std::endl;

}
