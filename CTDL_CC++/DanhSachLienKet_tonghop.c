#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;
void makenull_list(List *L){
	(*L)=(struct Node*)malloc(sizeof(struct Node));
	(*L)->Next=NULL;
	}
int empty_list(List L){
	return L->Next==NULL;
	}
Position first_list(List L){
	return L;
	}
Position end_list(List L){
	Position p=first_list(L);
	while(p->Next!=NULL){
		p=p->Next;
		}
	return p;
}
Position next(Position p, List L){
	return p->Next;
	}
ElementType retrieve(Position p, List L){
	return p->Next->Element;
	}
void insertList(ElementType x, Position p, List *L){
	Position t;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=x;
	t->Next=p->Next;
	p->Next=t;
	}
void DeleteList(Position p, List *L){
	Position t;
	if(p->Next!=NULL){
		t=p->Next;
		p->Next=t->Next;
		free(t);
		}
	}

Position position_n(int n, List L){
	int i=1;
	Position p=L;
	while(p->Next!=NULL && i<n){
		p=p->Next;
		i++;
		}
	return p;
	}

Position locate(ElementType x, List L){
	Position p=L;
	int found=0;
	while(p->Next!=NULL && found==0){
		if(p->Next->Element==x) found=1;
		else{
			p=p->Next;
		}
	}
	return p;
	}
void read(List *L){
	int i,n;
	makenull_list(L);
	ElementType x;
	printf("Nhap phan tu n = "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap phan tu thu %d: ",i); scanf("%d",&x);
		insertList(x,end_list(*L),L);
		}
	}
void print(List L){
	Position p=L;
	while(p->Next!=NULL){
		printf("%d ",p->Next->Element);
		p=p->Next;
	}
	printf("\n");
}
//chen cuoi
void chencuoi(ElementType x, List *L){
	Position p=*L;
	while(p->Next!=NULL){
		p=p->Next;
	}
	insertList(x,p,L);
}
//xoa phan tu tim thay dau tien
void earse(ElementType x, List *L){
	Position p=locate(x,*L);
	if(p->Next!=NULL){
		DeleteList(p,L);
		}
	}
//xoa tat ca phan tu x duoc tim thay 
void removeAll(ElementType x, List *L){
	Position p=locate(x,*L);
	while(p->Next!=NULL){
		DeleteList(p,L);
		p=locate(x,*L);
		}
	}
//xoa tat ca chi giu lai 1 phan tu 
void normalize(List *L){
	Position p,q;
	p=*L;
	while(p->Next!=NULL){
		q=p->Next;
		while(q->Next!=NULL){
			if(p->Next->Element==q->Next->Element){
				DeleteList(q,L);
				}
			else{
				q=q->Next;
			}
		}
	p=p->Next;
	}
}
void in_so_le(List L){
	Position p=L;
	while(p->Next!=NULL){
		if(p->Next->Element%2!=0){
			printf("%d ",p->Next->Element);
			}
		else{
			p=p->Next;
		}
	}
}
void chep_so_chan(List L1, List *L2){
	Position p=L1;
	makenull_list(L2);
	while(p->Next!=NULL){
		if(p->Next->Element%2==0){
			chencuoi(p->Next->Element,L2);
			}
		else{
			p=p->Next;
		}
	}
}
float getAvg(List L){
	Position p=L;
	int S=0, dem=0;
	while(p->Next!=NULL){
		S=S+p->Next->Element;
		dem++;
		p=p->Next;
		}
	return (float)S/dem;
	}
int member(ElementType x, List L){
	Position p=L;
	int found=0;
	while(p->Next!=NULL && found==0){
		if(p->Next->Element==x) found=1;
		else{
			p=p->Next;
		}
	}
	return found;
	}
void unionSet(List L1,List L2, List *L3){
	makenull_list(L3);
	Position p=L1;
	while(p->Next!=NULL){
		chencuoi(p->Next->Element,L3);
		p=p->Next;
		}
	p=L2;
	while(p->Next!=NULL){
		if(!member(p->Next->Element,*L3)){
			chencuoi(p->Next->Element,L3);
			}
		p=p->Next;
		}
	}
void intersection(List L1, List L2, List *L3){
	makenull_list(L3);
	Position p=L1;
	while(p->Next!=NULL){
		if(member(p->Next->Element,L2)){
			chencuoi(p->Next->Element,L3);
			}
		p=p->Next;
		}
	}
void difference(List L1, List L2, List *L3){
	makenull_list(L3);
	Position p=L1;
	while(p->Next!=NULL){
		if(!member(p->Next->Element,L2)){
			chencuoi(p->Next->Element,L3);
			}
		p=p->Next;
		}
	}
		
int main(){
	List L;
	read(&L);
	printf("Danh sach vua nhap la: ");
	print(L);
	return 0;
	}	

	
