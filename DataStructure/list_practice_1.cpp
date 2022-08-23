#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void Print(const T& container)
{
	for (auto i : container)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	std::list<int> list1 = { 1, 2, 3, 4, 5 };

	list1.push_back(6);

	list1.insert(next(list1.begin()), 0);

	list1.insert(list1.end(), 7);

	Print(list1);

	list1.pop_back();

	cout << "삭제 후 리스트 :";
	Print(list1);

}
