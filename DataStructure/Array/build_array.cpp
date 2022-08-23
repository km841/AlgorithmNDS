#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <type_traits>

using namespace std;

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
// std::forward<commonType>(arg1), std::forward<commonType>(arg2), std::forward<commonType>(arg3)... 이 목록들을 모아서 array를 만듦
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>(args)... };
}


int main()
{
	auto arr1 = build_array('a', 33, 0.4f); // common_type의 경우 공통의 자료형을 찾아서 변환하는 것이므로 const char* 같은 자료형은 사용 불가

	for (auto ele : arr1)
		cout << ele << endl;
}


