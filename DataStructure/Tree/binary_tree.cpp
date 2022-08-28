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

    node* successor(node* start)
    {
        auto current = start->right;
        while (current && current->left)
            current = current->left;
        return current;
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

        if (value < start->data)
            start->left = delete_impl(start->left, value);

        else if (value > start->data)
            start->right = delete_impl(start->right, value);

        else
        {
            if (!start->left)
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            if (!start->right)
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            auto succNode = successor(start);
            start->data = succNode->data;

            start->right = delete_impl(start->right, succNode->data);
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

