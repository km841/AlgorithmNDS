#include <iostream>
#include <string>
#include <vector>
#include <queue>


/*
<선형 자료 구조의 문제와 비선형 자료 구조를 사용해야 하는 이유>

선형 자료 구조료 표현할 수 없는 대표적인 문제는 '계층적 문제'와 '순환 종속성' 문제이다.
따라서 비선형 자료 구조는 선형 자료 구조에서 배운 내용을 확장하여 해결하는 것이다.

<트리(tree)> - 상하 반전된 형태

트리는 노드(node)와 노드 사이를 연결하는 에지(edge)를 이용하여 계층을 구성한다.
트리는 화면에 말 그대로 나무 형태로 나타낼 수 있으며, 에지는 나뭇가지처럼 표현된다.

트리의 중심이 되는 노드를 루트 노드(root node)라고 부르고, 이 노드를 보통 가장 맨 위에 나타낸다.

따라서 트리를 그림으로 표현할 때는 실제 나무와는 반대로 뿌리가 맨 위에 나타나는 상하 반전 형태로 표현한다.
*/

using namespace std;

struct node
{
	std::string position;
	node* first;
	node* second;
};

struct org_tree
{
	node* root;

	static org_tree create_org_structure(const std::string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const std::string& value)
	{
		// 루트 노드가 존재하지 않을 경우
		if (root == NULL)
			return NULL;

		// 찾는 값이 루트 노드에 있을 경우
		if (root->position == value)
			return root;
		
		// 왼쪽 가지에 있는지 확인
		auto firstFound = org_tree::find(root->first, value);

		// 찾았다면
		if (firstFound != NULL)
			return firstFound;

		// 아니라면 다음 가지로
		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const std::string& manager, const std::string& subordinate)
	{
		// 관리 노드를 찾는다 (첫 번째 인자에 해당하는 값을 가진 노드)
		auto managerNode = org_tree::find(root, manager);

		// 관리 노드를 찾지 못했을 때
		if (!managerNode)
		{
			std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
			return false;
		}

		// 관리 노드의 아랫 라인의 자리가 꽉 찼을 때
		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
			return false;
		}

		// 둘 중 하나가 비었다면 새로운 노드로 채우기 (두 번째 인자로)
		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

		return true;

	}
};

int main()
{
	auto tree = org_tree::create_org_structure("CEO");
	
	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");
}
