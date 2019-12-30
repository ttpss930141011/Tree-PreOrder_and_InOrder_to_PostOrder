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
	postorder(node->right);  //��� 
	printf("%c", node->data);
	fprintf(outfile , "%c", node->data);
	
	}
}
//tppre�O���o�@�����j�s�W��node�O�bpre_input���ĴX��
//tpin�O�o�����j ���ǰ}�C�N�n�Q�B�z��in_input 
//num�O�ӧP�_�٦��X�Ӹ`�I�ݷs�W 
Node* build_tree(int tppre, int tpin, int num)  
{
	int i = 0; // i �k�s 
	
	if(num == 0){
	//�p�G�b��34�汽�y���Ĥ@�ӴN�O�L�ۤv���ܡA�N�N��L�u���k�l��A�o�ӱ��p�i�ӴN�|�QNULL���M���c�l�𪺻��j 	
		return NULL;
	}
	Node *tree = new Node; //new�@��node�Ŷ� 
	
	tree->data = pre_input[tppre]; //�`�Idata���O�e�Ǫ��Ĥ@��
	 
	while(pre_input[tppre] != in_input[tpin + i]) i ++; //�bin_input�̭��M��pre�Ĥ@�Ӧr���M��O���_�� >=1�N�N�����l�� 
	//        012  3 
	//�Ҧppre:ABC  D 
	//     in:BCA  D 
	//�Ĥ@�����j(0,0,3) ��:(1,0,2) �k: (2,1,1)
	tree->left = build_tree(tppre + 1, tpin, i);
	//tree->right = build_tree(tppre + 1, tpin + 1, num - i - 1);
	tree->right = build_tree(tppre + i + 1, tpin + i + 1, num - i - 1);
	//�s�W�k�l��ɤ��ҥH�n�[i�O�]���n���T��m 
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
