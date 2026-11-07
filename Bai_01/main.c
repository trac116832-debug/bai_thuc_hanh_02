
#include<stdio.h>
void nhap(float *p, int n){
	for(int i=0; i<n; i++){
		scanf("%f", p+i);
	}
	
}
void xuat(float *p, int n){
	for(int i=0; i<n; i++){
		printf("%.2f ", *(p+i));
	}
}
int main(){
	int n;
	scanf("%d", &n);
	float a[n];
	nhap(a,n);
	xuat(a,n);
	return 0;
}
