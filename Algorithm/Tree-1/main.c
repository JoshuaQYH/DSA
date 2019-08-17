#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree{
    int val;
    BiTree* left;
    BiTree* right;
} BiTree;


/*练习1--使用非递归算法实现二叉树的后序遍历*/
// 先访问左子树，然后访问右子树，再访问根节点
// 使用堆栈来存储结点指针,需要分清返回根结点时是左子树或者右子树
// 我们使用一个辅助指针r来指向最近访问的结点。
void postOrder(BiTree* root){
    // 初始化一个栈 S
    initStack(S);
    // 声明一个遍历指针 p
    BiTree* p = root;
    // 声明一个空的辅助指针
    BiTree* r = NULL;
    while(p ||! S.empty()){
        if(p){ // 非空结点，压栈
            push(S, p); // 压栈，走左子树
            p = p->left;
        }
        else{ // 空结点
            getTop(S, p);    // 取出栈顶结点赋值给p
            if(p->right && p->right != r){  // 存在右子树，并且未访问过
                p = p->right;   // 取右子树根结点，入栈
                push(S,  p);
                p = p->left;
            }
            else{  // 不存在右子树或者 已经访问完右子树
                pop(S, p);      // 弹出栈顶指针并赋值给p
                visit(p->val);  // 访问结点值
                r = p;          // 记录最近访问的结点
                p = NULL;       // 将p置为空
            }
        }
    }
}

/*练习2--判断一棵树为完全二叉树*/
// 思路：采用层次遍历算法，将每一个非空结点的左孩子和右孩子都加入到队列中
// 若遇到一个空结点，那么如果后续存在非空结点，那么不是完全二叉树
int isComplete(BiTree* root){
    InitQueue(Q);
    if(!root) return 1;
    EnQueue(Q);
    while(!Q.empty()){
        DeQueue(Q, q);
        if(q){
            EnQueue(Q, q->left);
            EnQueue(Q, q->right);
        }
        else{
            // 若队列中的空结点之后还存在非空结点，则非完全二叉树
            while(!Q.empty()){
                DeQueue(Q, q);
                if(q) return 0;
            }
        }
    }
    return 1;
}

/*练习3--对二叉树左右结点进行翻转*/
void swap(BiTree* root){
    if(root){
        swap(root->left);
        swap(root->right);
        BiTree* p = root->right;
        root->right = root->left;
        root->left = p;
    }
}

/*练习4--通过递归释放整棵树*/
void deleteTree(BiTree* root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

/*练习5--寻找最近的共同祖先*/
// 思路：采用非递归后续遍历算法，
int searchNode(BiTree* root, BiTree* target){
    int result = 0;
    if(root){
        if(root == target) return 1;
        result = searchNode(root->left, target);
        if(result==1) return result;
        result = searchNode(root->right, target);
    }
    return result;
}

BiTree* ancestor(BiTree* root, BiTree* a, BiTree* b){
    InitStack(S);
    Push(S, root);
    BiTree* p = root;
    BiTree* r = NULL;
    while(p || !S.empty()){
        while(p){
            Push(S, p);
            p = p->left;
        }
        getTop(S, p);
        if(p->right && p->right != r){
            p = p->right;
            Push(S, p);
            p = p->left;
        }
        else{
            Pop(S, p);
            BiTree* target = NULL;
            if(p == a) target = b;
            if(p == b) target = a;
            while(!S.empty()){
                Pop(S, p);
                int result = searchNode(p, target);
                if(result == 1) return p;
            }
        }
    }
    return NULL;
}


int main()
{
    // 无特定的执行语句，仅仅在实现一些二叉树相关的算法函数（伪代码）
    return 0;
}
