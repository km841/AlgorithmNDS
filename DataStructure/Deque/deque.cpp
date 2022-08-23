#include <iostream>
#include <vector>
#include <deque>
#include <list>

/*
deque는 배열 기반과 연결 리스트 기반이 섞여 있는 형태로 각각의 장점을 가지고 있음

<C++ 표준이 정하는 덱이 만족해야 하는 조건>
1. push_front, pop_front(), push_back(), pop_back() 동작이 O(1) 시간복잡도로 동작해야 함
2. 모든 원소에 대해 임의 접근 동작이 O(1) 시간 복잡도로 동작해야 함
3. 덱 중간 원소 삽입 및 삭제는 O(n) 시간 복잡도로 동작해야 하며, 실제로는 최대 n/2 단계로 동작함 (n은 덱의 크기)

덱은 단일 메모리 청크를 사용하지 않는다.
대신 크기가 같은 여러 개의 여러 개의 메모리 청크를 사용하여 데이터를 저장한다.
청크의 인덱스 및 크기(또는 하나의 청크에 저장된 원소 개수)를 이용하여 특정 위치의 원소가 어느 청크에 저장되어 있는지 알 수 있다.
모든 메모리 청크 주소를 연속적인 메모리 구조에 저장해놓고 사용하면 O(1)의 시간 복잡도로 원소의 임의 접근이 가능하다.
따라서 덱의 구조는 배열 또는 벡터와 유사하다고 볼 수 있다.

덱의 맨 앞에 새로운 원소를 추가할 경우, 첫 번째 청크에 여유 공간이 없다면?
새로운 청크를 할당하고 이 메모리 청크 주소를 첫 번째 메모리 청크 주소로 설정함.
이렇게 하면 실제 원소 데이터는 전혀 이동시키지 않아도 무방함.
메모리 재할당을 피하기 위해서 중간 위치의 청크를 이용할 수 있으며 이 경우
일정 횟수의 push_front() 함수에 대한 메모리 재할당을 피할 수 있다.

*/

using std::cout;
using std::endl;

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
	std::deque<int> deq = { 1, 2, 3, 4, 5 };

	deq.push_front(0); // { 0, 1, 2, 3, 4, 5 }

	deq.insert(deq.begin() + 2, 10); // { 0, 1, 10, 2, 3, 4, 5 }

	deq.pop_back(); // { 0, 1, 10, 2, 3, 4 }

	deq.pop_front(); // { 1, 10, 2, 3, 4 }

	deq.erase(deq.begin() + 1); // { 1, 2, 3, 4 }

	deq.erase(deq.begin() + 3, deq.end()); // { 1, 2, 3 }
}

