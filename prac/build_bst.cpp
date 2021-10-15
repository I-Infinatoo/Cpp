    #include<iostream>
    #include<queue>
    using namespace std;


            class node{
            
            public:
            
                int data;
                node * left;
                node *right;

                //constructor

                node(int d){

                    data=d;
                    left=NULL;
                    right=NULL;

                }
            };
    
            //insertion in binary search tree

    node * insert_bst(node * root, int data){
            //base case

            if(root==NULL){
                root=new node(data);
                return root;
            }

            //recursive case

            if(data <= root->data){

                root->left=insert_bst(root->left,data);

            }
            else{

                root->right= insert_bst(root->right,data);

            }
            return root;
    }


            //bulding Binary search Tree

    node *buld_bst(){

        node *root=NULL;
        int data;
        cin>>data;

        while(data!=-1){

            root=insert_bst(root,data);
            cin>>data;


        }
        return root;


    }
            //printing level wise

    void printlevelwise(node *root){
                //queue

                queue<node *> q;

                    q.push(root);
                    q.push(NULL);

                while(!q.empty()){

                    node*x= q.front();
                    q.pop();
                    if(x == NULL){
                        cout<<endl;

                        if(!q.empty()){
                            q.push(NULL);
                        }
                    }

                    else{


                        cout<<x->data<<" ";
                        if(x->left!=NULL){
                            q.push(x->left);

                        }

                        if(x->right!=NULL){
                            q.push(x->right);
                        }
                    }
                }
            }

    
    
    
    int main(){

            node * parent=buld_bst();
            printlevelwise(parent);

        return 0;
    }