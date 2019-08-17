#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree{
    int val;
    BiTree* left;
    BiTree* right;
} BiTree;


/*��ϰ1--ʹ�÷ǵݹ��㷨ʵ�ֶ������ĺ������*/
// �ȷ�����������Ȼ��������������ٷ��ʸ��ڵ�
// ʹ�ö�ջ���洢���ָ��,��Ҫ���巵�ظ����ʱ������������������
// ����ʹ��һ������ָ��r��ָ��������ʵĽ�㡣
void postOrder(BiTree* root){
    // ��ʼ��һ��ջ S
    initStack(S);
    // ����һ������ָ�� p
    BiTree* p = root;
    // ����һ���յĸ���ָ��
    BiTree* r = NULL;
    while(p ||! S.empty()){
        if(p){ // �ǿս�㣬ѹջ
            push(S, p); // ѹջ����������
            p = p->left;
        }
        else{ // �ս��
            getTop(S, p);    // ȡ��ջ����㸳ֵ��p
            if(p->right && p->right != r){  // ����������������δ���ʹ�
                p = p->right;   // ȡ����������㣬��ջ
                push(S,  p);
                p = p->left;
            }
            else{  // ���������������� �Ѿ�������������
                pop(S, p);      // ����ջ��ָ�벢��ֵ��p
                visit(p->val);  // ���ʽ��ֵ
                r = p;          // ��¼������ʵĽ��
                p = NULL;       // ��p��Ϊ��
            }
        }
    }
}

/*��ϰ2--�ж�һ����Ϊ��ȫ������*/
// ˼·�����ò�α����㷨����ÿһ���ǿս������Ӻ��Һ��Ӷ����뵽������
// ������һ���ս�㣬��ô����������ڷǿս�㣬��ô������ȫ������
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
            // �������еĿս��֮�󻹴��ڷǿս�㣬�����ȫ������
            while(!Q.empty()){
                DeQueue(Q, q);
                if(q) return 0;
            }
        }
    }
    return 1;
}

/*��ϰ3--�Զ��������ҽ����з�ת*/
void swap(BiTree* root){
    if(root){
        swap(root->left);
        swap(root->right);
        BiTree* p = root->right;
        root->right = root->left;
        root->left = p;
    }
}

/*��ϰ4--ͨ���ݹ��ͷ�������*/
void deleteTree(BiTree* root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

/*��ϰ5--Ѱ������Ĺ�ͬ����*/
// ˼·�����÷ǵݹ���������㷨��
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
    // ���ض���ִ����䣬������ʵ��һЩ��������ص��㷨������α���룩
    return 0;
}
