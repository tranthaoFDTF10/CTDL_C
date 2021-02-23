#include<stdio.h>
#include<conio.h>
#include<string.h>
#define maxlength 100
typedef int Position;
struct SinhVien{
	char MSSV[10];
	char Hoten[50];
	float DiemLT, DTH1, DTH2;
};
typedef struct{
	struct SinhVien A[maxlength];
	int n;
}DanhSach;
DanhSach dsRong(){
	DanhSach L;
	L.n=0;
	return L;
	}
void chencuoi(struct SinhVien sv, DanhSach *L){
	if(L->n==maxlength){
		printf("Danh Sach day");
		}
	else{
		L->A[L->n]=sv;
		L->n++;
	}
}
void xoatai(int p, DanhSach *L){
	if(p<1||p>L->n){
		printf("Vi tri khong hop le");
		}
	else if(L->n==0){
		printf("Danh sach rong");
		}
		else{
			int i;
			for(i=p-1;i<L->n-1;i++){
				L->A[i]=L->A[i+1];
				}
			L->n--;
		}
	}
int tim(char mssv[], DanhSach L){
	Position p=1;
	int found=0;
	while(p!=L.n+1 && found ==0){
		if(strcmp(L.A[p-1].MSSV,mssv)==0) found=1;
		else{
			p++;
		}
	}
	return p;
}
void xoasinhvien(char mssv[], DanhSach *L){
	Position p=tim(mssv,*L);
	if(p!=L->n+1){
		xoatai(p,L);
		}
	}
DanhSach nhap(){
	DanhSach L;
	int i,n;
	L=dsRong();
	struct SinhVien sv;
	char ms[10];
	char ht[50];
	printf("Nhap so luong sinh vien n = "); scanf("%d", &n); fflush(stdin);
	for(i=1;i<=n;i++){
		printf("Nhap thong tin sinh vien thu %d: ",i);
		fflush(stdin);
		printf("\nMSSV: ");
		fgets(ms,10,stdin);
		if(ms[strlen(ms)-1]=='\n') ms[strlen(ms)-1]='\0';
		strcpy(sv.MSSV,ms);
		
		printf("Ho ten: ");
		fgets(ht,50,stdin);
		if(ht[strlen(ht)-1]=='\n') ht[strlen(ht)-1]='\0';
		strcpy(sv.Hoten,ht);
		
		printf("Diem LT: "); scanf("%f",&sv.DiemLT);
		printf("Diem TH1: "); scanf("%f",&sv.DTH1);
		printf("Diem TH2: "); scanf("%f",&sv.DTH2);
		if(tim(ms,L)==L.n+1){
			chencuoi(sv,&L);
			}
		else{
			printf("MSSV da ton tai");
		}
	}
	return L;
}
void hienthi(DanhSach L){
	int p=1;
	int stt=1;
	struct SinhVien sv;
	while(p!=L.n+1){
		sv=L.A[p-1];
		printf("%d. MSSV: %s",stt,sv.MSSV);
		printf("\n-Ho va ten: %s",sv.Hoten);
		printf("\n-Diem LT: %.2f",sv.DiemLT);
		printf("\n-Diem TH1: %.2f",sv.DTH1);
		printf("\n-Diem TH2: %.2f",sv.DTH2);
		stt++;
		p++;
		printf("\n");
		}
	}
DanhSach chepkhongdat(DanhSach L){
	DanhSach L1;
	struct SinhVien sv;
	L1=dsRong();
	int p=1;
	float dtb=0;
	while(p!=L.n+1){
		sv=L.A[p-1];
		dtb=(sv.DiemLT+sv.DTH1+sv.DTH2)/3;
		if(dtb<4){
			chencuoi(L.A[p-1],&L1);
			}
		p++;
	}
	return L1;
	}
void hienthidat(DanhSach L){
	int p=1,stt=1;
	float dtb=0;
	struct SinhVien sv;
	while(p!=L.n+1){
		sv=L.A[p-1];
		dtb=(sv.DiemLT+sv.DTH1+sv.DTH2)/3;
		if(dtb>=4){
			printf("%d. MSSV: %s",stt,sv.MSSV);
			printf("\n-Ho va ten: %s",sv.Hoten);
			printf("\n-Diem LT: %.2f",sv.DiemLT);
			printf("\n-Diem TH1: %.2f",sv.DTH1);
			printf("\n-Diem TH2: %.2f",sv.DTH2);
			stt++;
			printf("\n");
		}
		p++;
	}
}
int main(){
	DanhSach L;
	L=nhap();
	hienthi(L);
	printf("\n\nDanh Sach sinh vien thi dat: \n\n");
	hienthidat(L);
	return 0;
	}
	
     
