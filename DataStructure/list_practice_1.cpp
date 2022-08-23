#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void Print(const T& container)
{
	for (auto i : container)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::list<int> list1 = { 1, 2, 3, 4, 5 };

	list1.push_back(6); // 맨 마지막 위치에 값 삽입

	list1.insert(next(list1.begin()), 0); // insert : 첫번째 매개변수 앞 위치에 두번째 매개변수의 값 삽입
	list1.insert(list1.end(), 7);

	Print(list1);

	list1.pop_back(); // 맨 마지막 값 제거

	std::cout << "삭제 후 리스트 :";
	Print(list1);

}
