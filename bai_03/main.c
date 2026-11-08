#include<stdio.h>
typedef struct {
	char ten[100];
	int masv;
	float d1, d2, d3;
}SinhVien;


void nhap(SinhVien *p, int n){
	for(int i=0; i<n; i++){
		scanf(" %[^\n]", p -> ten);
		scanf("%d", &p -> masv);
		scanf("%f %f %f", &p ->d1, &p -> d2, &p -> d3);
		p++;
	} 
}

void xuat(SinhVien *p, int n){
	for(int i=0; i<n; i++){
		printf("Ho ten: %s\n", p->ten);
		printf("Ma sinh vien: %d\n", p->masv);
		printf("Diem mon 1: %.2f\n", p->d1);
		printf("Diem mon 2: %.2f\n", p->d2);
		printf("Diem mon 3: %.2f\n", p->d3);
		p++;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	SinhVien sv[100];
	nhap(sv, n);
	printf("Danh sach sinh vien:\n");
	xuat(sv,n);
	return 0;
}
