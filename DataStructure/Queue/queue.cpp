#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
queue는 stack과 달리 FIFO(First In First Out, 선입선출) 구조이다.
스택과 비슷한 함수를 지원하며, 다만 LIFO가 아닌 FIFO를 지원하기 위해 같은 함수지만 의미와 동작이 다르다.
std::stack에서 pop()은 pop_back()을 의미하지만
std::queue에서 pop()은 pop_front()를 의미한다.

std::queue도 std::stack과 같은 이유로 std::deque를 기본 컨테이너로 사용하며,
스택과 마찬가지로 pop(), push(), top(), back()이 시간 복잡도 O(1)로 동작한다.

*/

int main()
{
	std::queue<int> q;

	q.push(1); // { 1 }
	q.push(2); // { 1, 2 }
	q.push(3); // { 1, 2, 3 }
	q.pop();   // { 2, 3 }
	q.push(4); // { 2, 3, 4 }

}
