#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char pre_input[50], in_input[50];
FILE *infile,*outfile;

struct Node{
	char data;
	struct Node *left;
	struct Node *right;
};
void postorder(Node *node)
{
	if(node != NULL){
	
	postorder(node->left);
	postorder(node->right);  //後序 
	printf("%c", node->data);
	fprintf(outfile , "%c", node->data);
	
	}
}
//tppre是指這一次遞迴新增的node是在pre_input的第幾個
//tpin是這次遞迴 中序陣列將要被處理的in_input 
//num是來判斷還有幾個節點待新增 
Node* build_tree(int tppre, int tpin, int num)  
{
	int i = 0; // i 歸零 
	
	if(num == 0){
	//如果在第34行掃描的第一個就是他自己的話，就代表他只有右子樹，這個情況進來就會被NULL掉然後到柚子樹的遞迴 	
		return NULL;
	}
	Node *tree = new Node; //new一個node空間 
	
	tree->data = pre_input[tppre]; //節點data都是前序的第一位
	 
	while(pre_input[tppre] != in_input[tpin + i]) i ++; //在in_input裡面尋找pre第一個字元然後記錄起來 >=1就代表有左子樹 
	//        012  3 
	//例如pre:ABC  D 
	//     in:BCA  D 
	//第一次遞迴(0,0,3) 左:(1,0,2) 右: (2,1,1)
	tree->left = build_tree(tppre + 1, tpin, i);
	//tree->right = build_tree(tppre + 1, tpin + 1, num - i - 1);
	tree->right = build_tree(tppre + i + 1, tpin + i + 1, num - i - 1);
	//新增右子樹時之所以要加i是因為要正確位置 
	return tree;
}
int main(){
	
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "a");
    int num = 0;
    
    if(infile == NULL && outfile == NULL){
       printf("error!\n");
    }
    else{
         while(feof(infile) == 0)
         {
         	fscanf(infile, "%d %s %s", &num, &pre_input, &in_input); 

		Node *print_tree = build_tree(0, 0, num);
		
		postorder(print_tree);
		printf("\n");
		fprintf(outfile,"\n");
		
		}
	system("pause");
	return 0;
	}
}
