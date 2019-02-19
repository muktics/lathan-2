#include <stdio.h>
#include <conio.h>

struct Node{
	int data;
	Node *kiri;
	Node *kanan;
};

void tambah(Node **root, int databaru){
	if((*root)==NULL){
		Node *baru;
		baru = new Node;
		baru->data=databaru;
		baru->kiri=NULL;
		baru->kanan=NULL;
		(*root)=baru;
		(*root)->kiri=NULL;
		(*root)->kanan=NULL;
		printf("data ditambah!");
	}
	else if(databaru<(*root)->data)
	tambah(&(*root)->kiri, databaru);
	else if(databaru>(*root)->data)
	tambah(&(*root)->kanan, databaru);
	else if(databaru==(*root)->data)
	printf("data sudah ada!");
}

void preOrder(Node *root){
	if(root !=NULL){
		printf("%d", root->data);
		preOrder(root->kiri);
		preOrder(root->kanan);
	}
}

void inOrder(Node *root){
	if(root !=NULL){
		inOrder(root->kiri);
		printf("%d", root->data);
		inOrder(root->kanan);
	}
}

void postOrder(Node *root){
	if(root !=NULL){
		postOrder(root->kiri);
		postOrder(root->kanan);
		printf("%d", root->data);
	}
}

main(){
	int pil, c;
	Node *pohon, *t;
	pohon=NULL;
	do{
		int data;
		printf("menu\n");
		printf("1. tambah data\n");
		printf("2. lihat preorder\n");
		printf("3. lihat inorder\n");
		printf("4. lihat postorder\n");
		printf("5. exit\n");
		printf("pilihan : "); scanf("%d", &pil);
		switch(pil){
			case 1 :
				printf("data baru : ");
				scanf("%d", &data);
				tambah(&pohon, data);
				break;
			case 2 :
				if(pohon!=NULL)
				preOrder(pohon);
				else
				printf("masih kosong!");
				break;
			case 3 :
				if(pohon!=NULL)
				inOrder(pohon);
				else
				printf("masih kosong!");
				break;
			case 4 :
				if(pohon!=NULL)
				postOrder(pohon);
				else
				printf("masih kosong!");
				break;
		}
		getch();
		printf("\n");
	}
	while(pil!=5);
}
