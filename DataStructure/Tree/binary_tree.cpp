#include <iostream>
#include <queue>

/*
    
이진 검색 트리(BST)

이진 트리의 특징은?
부모 노드의 값 >= 왼쪽 자식 노드의 값
부모 노드의 값 <= 오른쪽 자식 노드의 값

즉, 왼쪽 노드 <= 부모 노드 <= 오른쪽 노드의 관계를 가짐

따라서 부모 노드보다 작거나 같은 모든 원소는 항상 왼쪽이고,
부모 노드보다 크거나 같은 원소는 항상 오른쪽에 있다.

따라서 루트 노드부터 값을 비교하는 경우 각 단계마다 검색 범위가 반씩 줄어듦.

마지막 레벨을 제외한 모든 노드에 두 개의 자식 노드가 있을 경우,
이 트리의 높이는 log₂N이 되고, 이로 인해 BST의 삽입 동작은 O(log n) 시간 복잡도를 갖는다.


*/

struct node
{
    int data;
    node* left;
    node* right;
};

struct bst
{
    // 재귀적으로 동작하는 함수들은 private에 구현부를 옮겨두어 외부에서 사용할 수 없게 하고,
    // 사용자 편의를 위해 래퍼함수를 public에 배치

    node* root = nullptr;

    node* find(int value)
    {
        return find_impl(root, value);
    }

    void insert(int value)
    {
        if (!root)
            root = new node{ value, nullptr, nullptr };
        else
            insert_impl(root, value);
    }

    void inorder()
    {
        inorder_impl(root);
    }
    
    /*
    노드 삭제 후 빈 공간을 메우기 위한 함수

            12
          /    \
        10      18
       /  \    /  \
      8   11  15  20
      \        \
       9       16
                \
                17

    이 트리에서 12를 제거하고 나면 재정리해야 함
    1. 자식 노드가 없는 경우         : 그냥 삭제하면 된다
    2. 자식 노드가 하나만 있는 경우  : 노드 삭제 후, 부모 노드의 포인터가 해당 자식 노드를 가리키도록 조정
    3. 자식 노드가 둘 다 있는 경우   : 노드 삭제 후, 현재 노드를 후속 노드로 대체
    */
    node* successor(node* start)
    {
        auto current = start->right; // 매개변수의 노드 기준 자기보다 큰 값을 가진 노드를 가져온다.
        while (current && current->left) // 자기보다 큰 노드 중 가장 작은 노드를 찾는다
            current = current->left; 
        return current;              // 그 노드를 반환
    }

    void deleteValue(int value)
    {
        root = delete_impl(root, value);
    }

private:
    node* find_impl(node* current, int value) // find 함수 메커니즘은 기존 tree와 동일
    {
        if (!current)
        {
            std::cout << std::endl;
            return nullptr;
        }

        if (current->data == value)
        {
            std::cout << value << " 을 찾았습니다. " << std::endl;
            return current;
        }
        

        if (value < current->data) // 노드 왼쪽에 있는 경우
        {
            std::cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }

        std::cout << current->data << "에서 오른쪽으로 이동: ";
        return find_impl(current->right, value);
    }

    void insert_impl(node* current, int value) // 주어진 노드를 타고 내려가며 적합한 위치를 찾는 노드
    {
        if (value < current->data)
        {
            if (!current->left)
                current->left = new node{ value, nullptr, nullptr };
            else
                insert_impl(current->left, value);
        }

        else
        {
            if (!current->right)
                current->right = new node{ value, nullptr, nullptr };
            else
                insert_impl(current->right, value);
        }
    }

    void inorder_impl(node* start)
    {
        if (!start)
            return;

        inorder_impl(start->left);
        std::cout << start->data << " ";
        inorder_impl(start->right);
    }

    node* delete_impl(node* start, int value)
    {
        if (!start)
            return nullptr;

        if (value < start->data) // value : 12, start->data : 12
            start->left = delete_impl(start->left, value);

        else if (value > start->data)
            start->right = delete_impl(start->right, value);

        else
        {
            if (!start->left) // 찾았는데, 좌측(작은 쪽) 값이 비어 있다면
            {
                auto tmp = start->right;  
                delete start;
                return tmp;   // 삭제 후 삭제한 놈 우측에 있는 값을 반환
            }

            if (!start->right) // 찾았는데, 우측(큰 쪽) 값이 비어 있다면
            {
                auto tmp = start->left;
                delete start;
                return tmp;    // 삭제 후 삭제한 놈 좌측에 있던 값 반환
            }

            auto succNode = successor(start);                         // 삭제될 원소 다음으로 큰 값을 가져옴
            start->data = succNode->data;                             // 삭제될 노드보다 하나 큰 원소를 덮어쓰기

            start->right = delete_impl(start->right, succNode->data); // 값을 가져온 부분을 지우는 코드
        }

        return start;
    }

};


int main()
{
    bst tree;

    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    if (tree.find(12))
        std::cout << "원소 12는 트리에 있습니다." << std::endl;

    else
        std::cout << "원소 12는 트리에 없습니다." << std::endl;
}

