#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;

/*以二叉搜索树为例来学习二叉树的各种操作*/

struct TreeNode{
    int data;
    BinTree left;
    BinTree right;
};


/*
先序遍历：根结点-左结点-右结点
*/
void preOrder(BinTree BT){
    if(BT){
        printf("%d ", BT->data);
        preOrder(BT->left);
        preOrder(BT->right);
    }
}

/*
中序遍历：左结点-根结点-右结点
*/
void inOrder(BinTree BT){
    if(BT){
        inOrder(BT->left);
        printf("%d ", BT->data);
        inOrder(BT->right);
    }
}

/*
后序遍历：左结点-右结点-根结点
*/
void postOrder(BinTree BT){
    if(BT){
        postOrder(BT->left);
        postOrder(BT->right);
        printf("%d ", BT->data);
    }
}

/*
输出叶子结点
*/
void outputLeaf(BinTree BT){
    if(BT){
        if(BT->right == NULL && BT->left == NULL)
            printf("%d ", BT->data);
        outputLeaf(BT->left);
        outputLeaf(BT->right);
    }
}

/*
求二叉树的高度
*/
int treeHeight(BinTree BT){
    int leftH, rightH, maxH;
    if(BT){
        leftH = treeHeight(BT->left);
        rightH = treeHeight(BT->right);
        maxH = leftH > rightH ? leftH : rightH;
        return maxH + 1;
    }
    else return 0;
}

/*查找对应的data的树结点指针*/
BinTree find(int data, BinTree BT){
    if(!BT) return NULL;
    if(data > BT->data){
        return find(data, BT->right);
    }
    else if(data < BT->data){
        return find(data, BT->left);  // 尾递归
    }
    return BT;
}

/*尾递归可转为循环来解决*/
BinTree find_notRecursive(int data, BinTree BT){
    while(BT){
        if(BT->data < data){
            BT = BT->right;
        }
        else if(BT->data > data){
            BT = BT->left;
        }
        else return BST;
    }
    return NULL;
}

/*查找最大结点的指针*/
BinTree findMax(BinTree BT){
    if(BT == NULL) return NULL;
    while(BT->right){
        BT = BT->right;
    }
    return BT;
}

/*查找最小结点的指针*/
BinTree findMin(BinTree BT){
    if(BT == NULL) return NULL;
    while(BT->left){
        BT = BT->left;
    }
    return BT;
}

/*二叉搜索树的递归插入*/
BinTree insert(Bintree BT, int data){
    if(BT == NULL){
        BT = (BinTree) malloc(sizeof(TreeNode));
        BT->data = data;
        BT->left = BT->right = NULL;
    }
    else{
        if(BT->data > data){
            BT->left = insert(BT->left, data);
        }
        else if(BT->data < data){
            BT->right = insert(BT->right, data);
        }
    }
    return BT;
}

/*二叉搜索树的删除:
1. 删除叶结点，直接删除，置为NULL
2. 删除只有一个孩子的结点，将父结点的指针指向删除结点的孩子结点
3. 删除有左右孩子的结点，找到目标结点左子树的最大元素或右子树的最小元素，
将元素拷贝到删除结点的值，然后转化为单孩子结点的删除情况，删除左/右子树最大/小元素的结点
*/
BinTree delete(Bintree BT, int data){
    if(BT == NULL) printf("不存在待删除的结点");
    else if(data < BT->data){
        BT->left = delete(BT->left, data); // 左子树递归删除
    }
    else if(data > BT->data){
        BT->right = delete(BT->right , data);
    }
    else{
        if(BT->right && BT->left){ // 存在左右结点
            BinTree leftMax = findMax(BT->left);  // 找到左子树的最大元素结点
            BT->data = leftMax->data;  // 将最大元素替代为当前结点
            BT->left = delete(BT->left, BT->data); // 删除左子树中的最大结点
        }
        else if (BT->right==BT->left==NULL){ // 为叶节点
            free(BT);
            BT=NULL;
        }
        else{ // 只有一个孩子结点
            // 拷贝左/右结点的值到当前结点，然后删除左或右结点。
            if(BT->right){
                BT->data = BT->right->data;
                free(BT->right);
                BT->right = NULL;
            }
            else if(BT->left){
                BT->data = BT->left->data;
                free(BT->left);
                BT->left = NULL;
            }
        }
    }
    return BT;

}

/*
判断两棵二叉搜索树是否相同,(建两棵树比较）
*/
bool isSame(BinTree T1, BinTree T2){
    if(T1->data != T2->data)
        return false;
    else{
        if(T1->right && T2->right)
            return isSame(T1->right, T2->right);
        if(T1->left && T2->left){
            return isSame(T1->left, T2->left);
        }
    }
    return true;
}


int main()
{
    printf("Wait to test\n");
    return 0;
}
