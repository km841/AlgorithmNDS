#include <iostream>
#include <string>
#include <forward_list>
#include <vector>
using namespace std;


//vector에 대한 reverse 구현
template<typename T>
void self_reverse(T& container)
{
	const size_t size = container.size();

	for (int i = 0; i < size / 2; i++)
	{
		auto temp = container[i];
		container[i] = std::move(container[size - 1 - i]);
		container[size - 1 - i] = std::move(temp);

	}
}


int main()
{
	std::forward_list<int> list1 = { 2, 53, 1, 0, 4, 10 };
	list1.reverse();

	list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list1.unique(); // unique는 인접한 두 항의 중복여부를 확인하고 중복 시 뒤의 원소는 제거

	for (auto i : list1) cout << i << " ";
	cout << endl;

	list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list1.sort(); // 따라서 정렬 후 unique를 사용해야 함
	list1.unique();

	for (auto i : list1) cout << i << " ";
	cout << endl;
	
	list1.unique([](int a, int b) { return (b - a) < 2; });
	for (auto i : list1) cout << i << " ";
	cout << endl;
}
