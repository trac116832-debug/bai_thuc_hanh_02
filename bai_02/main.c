#include<stdio.h>
void nhap(float *p, int h, int c){
	for(int i=0; i<h; i++){
		for(int j=0; j<c; j++){
			scanf("%f", p);
			p++;
		}
	}
} 

void xuat(float *p, int h, int c){
	for(int i=0; i<h; i++){
		for(int j=0; j<c; j++){
			printf("%.2f ", *p);
			p++;
		}
		printf("\n"); 
	}
}

int main(){
	int h, c;
	scanf("%d %d", &h, &c);
	float a[h][c];
	nhap(&a[0][0], h, c);
	printf("Mang 2 chieu la:\n"); 
	xuat(&a[0][0], h, c);
}
 
