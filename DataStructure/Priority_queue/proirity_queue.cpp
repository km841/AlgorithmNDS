#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*

priority_queue는 힙이라고 부르는 매우 유용한 구조를 제공함
힙은 컨테이너에서 가장 작은(또는 가장 큰) 원소에 빠르게 접근할 수 있는 자료 구조이다.
최소/최대 원소에 접근하는 동작은 O(1)의 시간 복잡도를 가진다.

원소 삽입은 O(log n) 시간 복잡도로 동작하며, 원소 제거는 최소/최대 원소에 대해서만 가능하다.

유의할 점은 최소/최대 둘 중 하나에만 적용 가능하며 둘 다는 안됨
최소와 최대 둘 중 어느 것에 빠르게 접근할 것인지는 컨테이너 비교자에 의해 결정 (std::less, std::greater 등)

std::priority_queue는 std::vector를 기본 컨테이너로 사용하며 변경이 가능하다.
컨테이너 비교자는 기본적으로 std::less이며, 따라서 기본적으로 최대 힙(max heap)으로 생성, 최대 원소가 맨 위에 나타남

*/

int main()
{

	std::priority_queue<int> pq;
	pq.push(100);
	pq.push(50);
	pq.push(200);
	pq.push(1);

	while (pq.size())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

}
