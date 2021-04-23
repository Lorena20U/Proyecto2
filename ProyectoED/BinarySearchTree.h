#include <Adafruit_NeoPixel.h>
#define PIN 13
#define N_LEDS 64
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
struct node
{
int data;
struct node *left;
struct node *right;
};
int i = 0;
int y = 0;
struct node *treeA;
struct node *treeB;
String pagina = "";
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
struct node *deleteElement(struct node *, int);

int totalNodes(struct node *);
struct node *ptr;
void preorderTraversal(struct node *, String player, bool mostrar, bool pixeles);
struct node *findSmallestElement(struct node *tree);
struct node* search(struct node *ptr, int data);
void create_tree(struct node *tree)
{
tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = val;
ptr->left = NULL;
ptr->right = NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=tree;
while(nodeptr!=NULL)
 {
parentptr=nodeptr;
if(val<nodeptr->data){
nodeptr=nodeptr->left;}
else{
nodeptr = nodeptr->right;}
 }
if(val<parentptr->data){
parentptr->left = ptr;}
else{
parentptr->right = ptr;}
}
return tree;
}
struct node *deleteElement(struct node *tree, int val)
{
if(tree==NULL)
{
Serial.print("\n The tree is empty ");
return(tree);
}
if (val < tree->data){tree->left = deleteElement(tree->left, val);}
else if (val > tree->data){tree->right = deleteElement(tree->right, val);}
else {
        if (tree->left == NULL) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = findSmallestElement(tree->right);
 
        // Copy the inorder
        // successor's content to this node
        tree->data = temp->data;
 
        // Delete the inorder successor
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}
int totalNodes(struct node *tree)
{
if(tree==NULL){
return 0;}
else{
  i++;
return(totalNodes(tree->left) + totalNodes(tree->right) + 1);}
}
void preorderTraversal(struct node *tree, String player, bool mostrar, bool pixeles)
{
  if(tree != NULL)
{
if(mostrar == true){
  pagina += String(tree->data) + "->";
}
if(pixeles == true){
  if(player == "A"){
    strip.setPixelColor((tree->data),255,0,0);
  }
  else{
    strip.setPixelColor((tree->data),0,0,255);
  }
}
preorderTraversal(tree->left, player, mostrar, pixeles);
preorderTraversal(tree->right, player, mostrar, pixeles);
}
strip.show();
}
struct node* search(struct node *tree, int x)
{
    if(tree==NULL){
      y = -1;
      return tree;
    }
    if(tree->data==x){ //if root->data is x then the element is found
      y = tree->data;
        return tree;}
    else if(x>tree->data){ // x is greater, so we will search the right subtree
        return search(tree->right, x);}
    else{ //x is smaller than the data, so we will search the left subtree
        return search(tree->left,x);}
}
struct node *findSmallestElement(struct node *tree)
{
if( (tree == NULL) || (tree->left == NULL)){
return tree;}
else{
return findSmallestElement(tree ->left);}
}
