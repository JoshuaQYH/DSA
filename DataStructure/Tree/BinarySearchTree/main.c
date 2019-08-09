#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;

/*�Զ���������Ϊ����ѧϰ�������ĸ��ֲ���*/

struct TreeNode{
    int data;
    BinTree left;
    BinTree right;
};


/*
��������������-����-�ҽ��
*/
void preOrder(BinTree BT){
    if(BT){
        printf("%d ", BT->data);
        preOrder(BT->left);
        preOrder(BT->right);
    }
}

/*
�������������-�����-�ҽ��
*/
void inOrder(BinTree BT){
    if(BT){
        inOrder(BT->left);
        printf("%d ", BT->data);
        inOrder(BT->right);
    }
}

/*
�������������-�ҽ��-�����
*/
void postOrder(BinTree BT){
    if(BT){
        postOrder(BT->left);
        postOrder(BT->right);
        printf("%d ", BT->data);
    }
}

/*
���Ҷ�ӽ��
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
��������ĸ߶�
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

/*���Ҷ�Ӧ��data�������ָ��*/
BinTree find(int data, BinTree BT){
    if(!BT) return NULL;
    if(data > BT->data){
        return find(data, BT->right);
    }
    else if(data < BT->data){
        return find(data, BT->left);  // β�ݹ�
    }
    return BT;
}

/*β�ݹ��תΪѭ�������*/
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

/*����������ָ��*/
BinTree findMax(BinTree BT){
    if(BT == NULL) return NULL;
    while(BT->right){
        BT = BT->right;
    }
    return BT;
}

/*������С����ָ��*/
BinTree findMin(BinTree BT){
    if(BT == NULL) return NULL;
    while(BT->left){
        BT = BT->left;
    }
    return BT;
}

/*�����������ĵݹ����*/
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

/*������������ɾ��:
1. ɾ��Ҷ��㣬ֱ��ɾ������ΪNULL
2. ɾ��ֻ��һ�����ӵĽ�㣬��������ָ��ָ��ɾ�����ĺ��ӽ��
3. ɾ�������Һ��ӵĽ�㣬�ҵ�Ŀ���������������Ԫ�ػ�����������СԪ�أ�
��Ԫ�ؿ�����ɾ������ֵ��Ȼ��ת��Ϊ�����ӽ���ɾ�������ɾ����/���������/СԪ�صĽ��
*/
BinTree delete(Bintree BT, int data){
    if(BT == NULL) printf("�����ڴ�ɾ���Ľ��");
    else if(data < BT->data){
        BT->left = delete(BT->left, data); // �������ݹ�ɾ��
    }
    else if(data > BT->data){
        BT->right = delete(BT->right , data);
    }
    else{
        if(BT->right && BT->left){ // �������ҽ��
            BinTree leftMax = findMax(BT->left);  // �ҵ������������Ԫ�ؽ��
            BT->data = leftMax->data;  // �����Ԫ�����Ϊ��ǰ���
            BT->left = delete(BT->left, BT->data); // ɾ���������е������
        }
        else if (BT->right==BT->left==NULL){ // ΪҶ�ڵ�
            free(BT);
            BT=NULL;
        }
        else{ // ֻ��һ�����ӽ��
            // ������/�ҽ���ֵ����ǰ��㣬Ȼ��ɾ������ҽ�㡣
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
�ж����ö����������Ƿ���ͬ,(���������Ƚϣ�
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
