//写代码：定义顺序存储的二叉树（数组实现，树的结点从数组下标0开始存储）
#include <stdio.h>
#define MAX_SIZE 100

typedef struct  {
    int tree[MAX_SIZE];
    int size;
}ArrayBinaryTree;

// 初始化二叉树
void initTree(ArrayBinaryTree* t) {
    t->size = -1;
}

// 插入节点
void insertNode(ArrayBinaryTree* t, int value) {
    if (t->size + 1 >= MAX_SIZE) {
        printf("Error: Tree is full.\n");
        return;
    }
    t->size++;
    t->tree[t->size] = value;
}

//父节点
int findFather(ArrayBinaryTree *tree, int i) {
    if (i <= 1 || i > tree->size) {
        printf("节点 %d 不存在父节点\n", i);
        return -1;
    }
    
    int fatherIndex = i / 2 - 1;
    return tree->tree[fatherIndex];
}

//左孩子
int leftChild(ArrayBinaryTree *tree, int i) {
    int leftChildIndex = 2 * i + 1;
    if (leftChildIndex > tree->size) {
        printf("节点 %d 不存在左孩子\n", i);
        return -1;
    }

    return tree->tree[leftChildIndex];
}
//右孩子
int rightChild(ArrayBinaryTree *tree, int i) {
    int rightChildIndex = 2 * i + 2;
    if (rightChildIndex > tree->size) {
        printf("节点 %d 不存在右孩子\n", i);
        return -1;
    }

    return tree->tree[rightChildIndex];
}
//先中后序遍历
void preorderTraversal(ArrayBinaryTree *tree, int index) {
    if (index > tree->size) {
        return;
    }

    printf("%d ", tree->tree[index]);  // 输出当前节点
    preorderTraversal(tree, leftChild(tree, index));  // 遍历左子树
    preorderTraversal(tree, rightChild(tree, index));  // 遍历右子树
}

void inorderTraversal(ArrayBinaryTree *tree, int index) {
    if (index > tree->size) {
        return;
    }

    inorderTraversal(tree, leftChild(tree, index));  // 遍历左子树
    printf("%d ", tree->tree[index]);  // 输出当前节点
    inorderTraversal(tree, rightChild(tree, index));  // 遍历右子树
}

void postorderTraversal(ArrayBinaryTree *tree, int index) {
    if (index > tree->size) {
        return;
    }

    postorderTraversal(tree, leftChild(tree, index));  // 遍历左子树
    postorderTraversal(tree, rightChild(tree, index));  // 遍历右子树
    printf("%d ", tree->tree[index]);  // 输出当前节点
}

int main() {
    ArrayBinaryTree tree;
    initTree(&tree);
    insertNode(&tree, 1);
    insertNode(&tree, 1);
    insertNode(&tree, 2);
    insertNode(&tree, 3);
    insertNode(&tree, 4);
    insertNode(&tree, 5);
    insertNode(&tree, 2);
    insertNode(&tree, 2);
    insertNode(&tree, 2);

    printf("先序遍历结果：");
    preorderTraversal(&tree, 0);  // 输出：1 2 4 5 3
    printf("\n");

    printf("中序遍历结果：");
    inorderTraversal(&tree, 0);  // 输出：4 2 5 1 3
    printf("\n");

    printf("后序遍历结果：");
    postorderTraversal(&tree, 0);  // 输出：4 5 2 3 1
    printf("\n");

    return 0;
}