#include<stdio.h>
#include<conio.h>
#define maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[maxlength];
	Position Last;
}List;
void makenull_list(List *L){
	L->Last=0;
	}
int empty_list(List L){
	return L.Last==0;
	}
int full_list(List L){
	return L.Last==maxlength;
	}
Position first_list(List L){
	return 1;
	}
Position end_list(List L){
	return L.Last+1;
	}
Position Next(Position p, List L){
	return p+1;
	}
Position Previous(Position p, List L){
	return p-1;
	}
ElementType retrieve(Position p, List L){
	return L.Elements[p-1];
	}
void insertList(ElementType x, Position p, List *L){
	if(L->Last==maxlength){
		printf("Danh sach day");
		}
	else if(p<1||p>L->Last+1){
		printf("Vi tri khong hop le");
		}
		else{
			Position i;
			for(i=L->Last;i>=p;i--){
				L->Elements[i]=L->Elements[i-1];
				}
			L->Elements[p-1]=x;
			L->Last++;
		}
}
void DeleteList(Position p, List *L){
	if(L->Last==0){
		printf("Danh sach rong");
		}
	else if(p<1||p>L->Last){
		printf("Vi tri khong hop le");
		}
		else{
			Position i;
			for(i=p-1;i<L->Last-1;i++){
				L->Elements[i]=L->Elements[i+1];
				}
			L->Last--;
		}
}
Position Locate(ElementType x, List L){
	Position p=1;
	int found=0;
	while(p!=L.Last+1 && found==0){
		if(L.Elements[p-1]==x) found=1;
		else{
			p++;
		}
	}
	return p;
}
void read_list(List *L){
	int i,n;
	makenull_list(L);
	ElementType x;
	printf("Nhap so phan tu cua n = "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap vao phan tu thu %d: ",i);
		scanf("%d",&x);
		insertList(x,end_list(*L),L);
		}
	}
void print_list(List L){
	Position p=1;
	while(p!=L.Last+1){
		printf("%d ",L.Elements[p-1]);
		p++;
		}
    printf("\n");
}
int member(ElementType x, List L){
	Position p=1;
	int found=1;
	while(p!=L.Last+1 && found==0){
		if(L.Elements[p-1]==x) found =1;
		else{
			p++;
		}
	}
	return found;
}
// ham xoa phan tu tim thay dau tien
void earse(ElementType x, List *L){
	Position p=Locate(x,*L);
	if(p!=L->Last+1){
		DeleteList(p,L);
		}
	}
//ham xoa tat ca cac phan tu trong danh sach
void removeAll(ElementType x, List *L){
	Position p=Locate(x,*L);
	while(p!=L->Last+1){
		DeleteList(x,L);
		p=Locate(x,*L);
		}
	}
//ham xoa phan tu trung trong danh sach, chi giu lai mot phan tu
void normalize(List *L){
	Position p,q;
	p=1;
	while(p!=L->Last+1){
		q=p+1;
		while(q!=L->Last+1){
			if(L->Elements[p-1]==L->Elements[q-1]){
				DeleteList(q,L);
				}
			else{
			    q++;
			}
		}
	p++;
	}
}
//ham chen cuoi 
void insertSet(ElementType x, List *L){
	if(L->Last==maxlength){
		printf("Danh sach day");
		}
	else{
		L->Elements[L->Last]=x;
		L->Last=L->Last+1;
	}
}
//in ra trung binh cong
float getAvg(List L){
	Position p=1;
	int S=0,dem=0;
	while(p!=L.Last+1){
		S=S+L.Elements[p-1];
		dem++;
		p++;
		}
	return (float)S/dem;
}
//in ra so le
void in_ra_so_le(ElementType x, List L){
	Position p=1;
	while(p!=L.Last+1){
		if(L.Elements[p-1]%2!=0){
			printf("%d ",L.Elements[p-1]);
			}
		p++;
	}
}
//chep so chan vao danh sach L2
void copy_so_chan(List L1, List *L2){
	Position p=1;
	makenull_list(L2);
	while(p!=L1.Last+1){
		if(L1.Elements[p-1]%2==0){
			insertList(L1.Elements[p-1],end_list(*L2),L2);
			}
		p++;
	}
}
//ham sap xep
void sort(List *L){
	Position p,q;
	ElementType tam;
	for(p=1;p<L->Last;p++){
		for(q=p+1;q<L->Last;q++){
			if(L->Elements[p-1]>L->Elements[q-1]){
				tam=L->Elements[p-1];
				L->Elements[p-1]=L->Elements[q-1];
				L->Elements[q-1]=tam;
				}
			}
		}
	}
//ham tim tap hop cua hai danh sach
void unionSet(List L1, List L2, List *L3){
	Position p=1;
	makenull_list(L3);
	while(p!=L1.Last+1){
		insertList(L1.Elements[p-1],end_list(*L3),L3);
		p++;
		}
	p=1;
	while(p!=L2.Last+1){
		if(!member(L2.Elements[p-1],*L3)){
			insertList(L2.Elements[p-1],end_list(*L3),L3);
			}
		p++;
		}
	}
//ham giao cua hai tap hop
void intersection(List L1, List L2, List *L3){
	Position p=1;
	makenull_list(L3);
	while(p!=L1.Last+1){
		if(member(L1.Elements[p-1],L2)){
			insertList(L1.Elements[p-1],end_list(*L3),L3);
			}
		p++;
	}
}
//ham hieu cua hai tap hop 
void difference(List L1, List L2, List *L3){
	Position p=1;
	makenull_list(L3);
	while(p!=L1.Last+1){
		if(!member(L1.Elements[p-1],L2)){
			insertList(L1.Elements[p-1],end_list(*L3),L3);
			}
		p++;
	}
}
int main(){
	List L;
	Position p;
	ElementType x;
	read_list(&L);
	printf("Danh sach ban vua nhap la: ");
	print_list(L);
	
	printf("\nNhap phan tu muon chen: ");
	scanf("%d",&x);
	printf("\nNhap vi tri can chen: ");
	scanf("%d",&p);
	insertList(x,p,&L);
	printf("\nDanh sach sau khi chen:  ");
	print_list(L);
	
	printf("\nNhap phan tu muon xoa: "); 
	scanf("%d",&x);
	p=Locate(x,L);
	DeleteList(p,&L);
	printf("\nDanh sach sau khi xoa:  ");
	print_list(L);
	
	
	return 0;
	}




			
	
	
		
