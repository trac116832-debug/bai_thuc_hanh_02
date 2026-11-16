#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char hoten[30];
	int masv;
	float d1, d2, d3;
}Data;

typedef struct tagNode{
	Data infor;
	struct tagNode*link;
} Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
} LList;

void initList(LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt=0;
} 

int emptyList(LList L){
	return (L.spt == 0);
}

//Them dau
void insert_Head(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else{
		pp->link = L->pHead;
		L->pHead=pp;
	}
	L->spt++;
}

//Them cuoi
void insert_Tail(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		L->pTail->link =pp;
		L->pTail=pp;
	}
	L->spt++;
}


void delete_Head(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp =L->pHead;
		L->pHead = L->pHead-> link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL){
			L->pTail=NULL;
		}
	}
}

void delete_After(LList *L, Node*q){
	Node *pp;
	if(NULL ==q || q->link ==NULL) return;
	else{
		pp= q->link;
		q->link=pp->link;
		if(pp == L->pTail){
			L->pTail=q;
		}
		free(pp);
		L->spt--;
	}
}

//Xoa theo ten
void delete_Ten(LList *L, char ten[]){
	Node *pp = L->pHead;
	Node *q = NULL;
	while(pp!= NULL && strstr(pp->infor.hoten,ten)==NULL){
		q = pp;
		pp = pp->link;
	}
	if(pp == NULL){
		return;
	}
	else{
		if(pp == L->pHead){
			delete_Head(L);
		}
		else{
			delete_After(L,q);
			
		}
	}	
}

//Xoa theo ma
void delete_Ma(LList *L, int ma){
	Node*pp=L->pHead;
	Node*q=NULL;
	while(pp!=NULL && (pp->infor.masv!=ma)){
		q =pp;
		pp=pp->link;
	}
	if(NULL==pp){
		return;
	}
	else{
		if(pp==L->pHead){
			delete_Head(L);
		}
		else{
			delete_After(L,q);
		}
	}
}

//Tim kiem theo ten
Node*search_Ten(LList L, char name[30]){
	Node*pp = L.pHead;
	while(pp!=NULL && strstr(pp->infor.hoten,name)==NULL){
		pp =pp->link;
	}
	return pp;
}

//Tim kiem theo ma
Node*search_Ma(LList L, int ma){
	Node*pp = L.pHead;
	while(pp!=NULL && pp->infor.masv!=ma){
		pp=pp->link;
	}
	return pp;
}

//Tach danh sach
void tach(LList L, LList*L1, LList*L2){
	initList(L1);
	initList(L2);
	Node *pp =L.pHead;
	while(pp != NULL){
		if(pp->infor.d1 < 5 || pp->infor.d2 <5 || pp->infor.d3 <5){
			insert_Head(L1, pp->infor);
		}
		else{
			insert_Head(L2, pp->infor);
		}
		pp=pp->link;
	}
}

//Ghep danh sach
void ghep(LList L1, LList L2, LList *L){
	initList(L);
	Node *p1=L1.pHead;
	Node *p2=L2.pHead;
	if(L1.spt<L2.spt){
		while(p1 != NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while(p2!=NULL){
			insert_Head(L,p2->infor);
			p2 = p2->link;
		}
	}
	else{
		while(p2!=NULL){
			insert_Head(L,p1->infor);
			insert_Head(L,p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while(p1!=NULL){
			insert_Head(L,p1->infor);
			p1= p1->link;
		}
	}
}
void nhap(Data*x){
	scanf("%d", &(x->masv));
	scanf("%s", (x->hoten));
	scanf("%f", &(x->d1));
	scanf("%f", &(x->d2));
	scanf("%f", &(x->d3));
}
void xuat(Data x){
	printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void duyet(LList L){
	Node*pp=L.pHead;
	if(emptyList(L)){
		return;
	}
	while(pp!=NULL){
		xuat(pp->infor);
		pp=pp->link;
	}
}
int main(){
	LList L, L1, L2;
	initList(&L);
	initList(&L1);
	initList(&L2);
	int kt=0;
	int masv;
	int chon;
	Data x;
	char ten[30];
	initList(&L);
	Node *pp;
	do{
		printf("===CHUONG TRINH QUAN LY SINH VIEN===\n");
		printf("1.Them vao dau danh sach\n");
		printf("2.Them vao cuoi danh sach\n");
		printf("3.Xoa theo ten\n");
		printf("4.Xoa theo ma\n");
		printf("5.Tim kiem theo ten\n");
		printf("6.Tim kiem theo ma\n");
		printf("7.Tach danh sach\n");
		printf("8.Ghep danh sach\n");
		printf("0.Thoat\n");
		printf("Xin moi lua chon ");
		scanf("%d", &chon);
		switch(chon){
			case 1:
				printf("Nhap thong tin sinh vien:\n");
				nhap(&x);
				if(x.masv>0){
					insert_Head(&L, x);
				}
				break;
			case 2:
				printf("Nhap thong tin sinh vien:\n");
				nhap(&x);
				if(x.masv>0){
					insert_Tail(&L,x);
				}
				break;
			case 3:
				printf("Nhap ten sinh vien muon xoa:\n");
				scanf("%s", ten);
				delete_Ten(&L, ten);
				break;
			case 4:
				printf("Nhap ma sinh vien muon xoa:\n");
				scanf("%d", &masv);
				delete_Ma(&L, masv);
				break;
		  	case 5:
		  		printf("Nhap ten sinh vien can tim");
		  		scanf("%s", ten);
		  		pp = search_Ten(L, ten);
				  if(pp!=NULL){
				  	xuat(pp->infor);
				  }
				  else{
				  	printf("Khong tim thay\n");
				  } 
		  		break;
			case 6:
				printf("Nhap ma sinh vien can tim\n");
				scanf("%d", &masv);
				pp = search_Ma(L, masv);
				if(pp!=NULL){
					xuat(pp->infor);
				}
				else{
					printf("Khong tim thay\n");
				}
				break;
		  	case 7:
		  		printf("Tach danh sach:\n");
		  		tach(L,&L1,&L2);
		  		printf("Danh sach 1:\n");
		  		duyet(L1);
		  		printf("Danh sach 2:\n");
		  		duyet(L2);
		  		break;
		  	case 8:
		  		printf("Ghep danh sach\n");
		  		ghep(L1,L2,&L);
		  		printf("Danh sach sau khi ghe:\n");
		  		duyet(L);
		  		break;
		  	case 0:
		  		printf("Thoat chuong trinh\n");
		  		break;	  		
		}
	}while(chon!=0);
	return 0;
}

