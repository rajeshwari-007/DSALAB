#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ;
    struct node *left , *right ;
} *NODE ;

NODE inordersuccessor(NODE root) ;

NODE createbst(NODE root , int key){
    NODE cur , prev , temp = (NODE)malloc(sizeof(struct node)) ;
    temp -> data = key ;
    temp -> left = temp -> right = NULL ;
    if(root == NULL)
        return temp ;
    cur = root ;
    prev = NULL ;
    while(cur != NULL){
        prev = cur ;
        if(key < cur -> data)
            cur = cur -> left ;
        else
            cur = cur -> right ;
    }
    if(key < prev->data )
        prev ->left = temp ;
    else
        prev -> right = temp ;
    return root ;
}

void preorder(NODE root){
    if (root!=NULL){
        printf("%d\t" , root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d\t" , root->data);
        inorder(root->right);
    }
}

void postorder(NODE root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t" , root->data);
    }
}




int main() {
    NODE root = NULL ;
    int ch , item ;
    for(;;){
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\nEnter your choice: ");
        scanf("%d" , &ch) ;
        switch(ch){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d" , &item) ;
                root = createbst(root , item) ;
                break ;
            case 2:
                printf("Preorder Traversal: \n");
                preorder(root) ;
                break ;
            case 3:
                printf("Inorder Traversal: \n");
                inorder(root) ;
                break ;
            case 4:
                printf("Postorder Traversal: \n");
                postorder(root) ;
                break ;
            default:
                printf("Exiting...\n") ;
                exit(0) ;
                break ;
        }
    }
    return 0 ;
}
