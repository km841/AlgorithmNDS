#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
stack은 컨테이너 어댑터의 한 종류로써 이미 존재하는 컨테이너를 기반으로 만들어짐
기존 컨테이너의 래퍼로 제공하는 이유는 해당 컨테이너가 가지고 있는 특성에 부합하는 기능만 구현하기 위해서이다

스택은 데이터 처리와 보관을 위해 LIFO(Last In First Out, 후입선출) 구조를 사용.
스택은 컨테이너 한쪽 끝에서만 데이터를 추가/삭제 할 수 있으며, 다른 위치에선 불가능

std::stack은 std::deque로 만든 간단한 래퍼로서 스택 자료구조에 꼭 필요한 인터페이스만을 제공한다.

<stack의 함수 래퍼>

<stack>         <deque>

push()	       push_back()
pop()		   pop_back()
top()          back()

stack 생성 시 두 번째 템플릿 매개변수로 다른 컨테이너명을 기입하여 deque가 아닌 vector나 list로도 stack을 생성할 수 있다.
1) std::stack<int, std::vector> stk;
2) std::stack<int, std::list> stk;

스택의 모든 연산의 시간 복잡도는 O(1)이며, 스택에서 기본 컨테이너로 함수 호출을 전달하는 과정은
컴파일러 최적화에 의해 모두 인라인 형식으로 호출될 수 있으므로 오버헤드는 발생하지 않음

begin, end가 구현되어 있지 않아서 범위기반 for문을 사용할 수 없다

*/

int main()
{
	std::stack<int> stk;
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);
	stk.push(7);
	stk.push(8);
	
	const size_t size = stk.size();
	for (int i = 0; i < size; i++)
	{
		cout << stk.top() << endl;
		stk.pop();
	}


}
