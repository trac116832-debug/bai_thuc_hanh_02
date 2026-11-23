#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char hoten[30];
	int masv;
	float d1, d2, d3;
}Data;
typedef struct tagDNode{
	Data infor;
	struct tagDNode *prev;
	struct tagDNode *next;
} DNode;
typedef struct{
	DNode *pHead;
	DNode *pTail;
	int spt;
} DList;
void initList(DList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt=0;
} 

int emptyList(DList L){
	return (L.spt == 0);
}
//Them dau
void insert_Head(DList *L, Data x){
	DNode *pp;
	pp = (DNode*)malloc(sizeof(DNode));
	pp->infor = x;
	pp->prev = NULL;
	pp->next = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else{
		pp->next = L->pHead;
		L->pHead->prev =pp;
		L->pHead=pp;
	}
	L->spt++;
}

//Them cuoi
void insert_Tail(DList *L, Data x){
	DNode *pp;
	pp = (DNode*)malloc(sizeof(DNode));
	pp->infor=x;
	pp->prev=NULL;
	pp->next=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		pp->prev =L->pTail;
		L->pTail->next=pp;
		L->pTail=pp;
	}
	L->spt++;
}
void delete_Head(DList *L){
	DNode *pp;
	if(emptyList(*L)) return;
	else{
		pp =L->pHead;
		L->pHead = L->pHead->next;
		if(L->pHead != NULL){
			L->pHead->prev=NULL;
		}
		else{
			L->pTail=NULL;
		}
		free(pp);
		L->spt--;
	}
}

void delete_After(DList *L, DNode*q){
	DNode *pp;
	if(NULL == q || q->next == NULL) return;
	else{
		pp= q->next;
		q->next = pp->next;
		if(pp->next != NULL){
			pp->next->prev =q;
		}
		if(pp ==L->pTail){
			L->pTail =q;
		}
		free(pp);
		L->spt--;
	}
}
//Xoa theo ten
void delete_Ten(DList *L, char ten[]){
	DNode *pp = L->pHead;
	DNode *q = NULL;
	while(pp!= NULL && strstr(pp->infor.hoten,ten)==NULL){
		q = pp;
		pp = pp->next;
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
void delete_Ma(DList *L, int ma){
	DNode*pp=L->pHead;
	DNode*q=NULL;
	while(pp!=NULL && (pp->infor.masv!=ma)){
		q =pp;
		pp=pp->next;
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
DNode*search_Ten(DList L, char name[30]){
	DNode*pp = L.pHead;
	while(pp!=NULL && strstr(pp->infor.hoten,name)==NULL){
		pp =pp->next;
	}
	return pp;
}
//Tim kiem theo ma
DNode*search_Ma(DList L, int ma){
	DNode*pp = L.pHead;
	while(pp!=NULL && pp->infor.masv!=ma){
		pp=pp->next;
	}
	return pp;
}
//Tach danh sach
void tach(DList L, DList*L1, DList*L2){
	initList(L1);
	initList(L2);
	DNode *pp =L.pHead;
	while(pp != NULL){
		if(pp->infor.d1 < 5 || pp->infor.d2 <5 || pp->infor.d3 <5){
			insert_Head(L1, pp->infor);
		}
		else{
			insert_Head(L2, pp->infor);
		}
		pp=pp->next;
	}
}
//Ghep danh sach
void ghep(DList L1, DList L2, DList *L){
	initList(L);
	DNode *p1=L1.pHead;
	DNode *p2=L2.pHead;
	if(L1.spt<L2.spt){
		while(p1 != NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1 = p1->next;
			p2 = p2->next;
		}
		while(p2!=NULL){
			insert_Head(L,p2->infor);
			p2 = p2->next;
		}
	}
	else{
		while(p2!=NULL){
			insert_Head(L,p1->infor);
			insert_Head(L,p2->infor);
			p1 = p1->next;
			p2 = p2->next;
		}
		while(p1!=NULL){
			insert_Head(L,p1->infor);
			p1= p1->next;
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
void duyet(DList L){
	DNode*pp=L.pHead;
	if(emptyList(L)){
		return;
	}
	while(pp!=NULL){
		xuat(pp->infor);
		pp=pp->next;
	}
}
int main(){
	DList L, L1, L2;
	initList(&L);
	initList(&L1);
	initList(&L2);
	int kt=0;
	int masv;
	int chon;
	Data x;
	char ten[30];
	DNode *pp;
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
				printf("Danh sach hien tai:\n");
				duyet(L);
				break;
			case 2:
				printf("Nhap thong tin sinh vien:\n");
				nhap(&x);
				if(x.masv>0){
					insert_Tail(&L,x);
				}
				printf("Danh sach hien tai:\n");
				duyet(L);
				break;
			case 3:
				printf("Nhap ten sinh vien muon xoa:\n");
				scanf("%s", ten);
				delete_Ten(&L, ten);
				printf("Danh sach hien tai:\n");
				duyet(L);
				break;
			case 4:
				printf("Nhap ma sinh vien muon xoa:\n");
				scanf("%d", &masv);
				delete_Ma(&L, masv);
				printf("Danh sach hien tai:\n");
				duyet(L);
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
				printf("Danh sach hien tai:\n");
				duyet(L);
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
				printf("Danh sach hien tai:\n");
				duyet(L);
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
