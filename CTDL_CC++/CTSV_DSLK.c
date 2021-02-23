#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef int Position;
typedef struct 
{
   char ID[10];
   char Name[50];
   float R1, R2, R3;
}Student;

struct Node
{
	Student Element;
	struct Node* Next;	
};

typedef struct Node* List;

List getList(){
	List L;
	L=(struct Node*)malloc(sizeof(struct Node));
	L->Next=NULL;
	return L;
}
struct Node *locate(char x[], List L){
	struct Node *P=L;
	int Found=0;
	while (P->Next!=NULL && !Found){
		if (strcmp(P->Next->Element.ID,x)==0)
			Found=1;
		else
			P=P->Next;
	}
	return P;	
}
int append(Student s, List *pL){
	struct Node *P, *temp;
	P=locate(s.ID,(*pL));
	if (P->Next!=NULL){
		return 0;
	}
	else{
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->Element=s;
		temp->Next=NULL;
		P->Next=temp;
		return 1;
	}	
}

List nhap(){
	List L;
	L=getList();
	int i,n;
	Student sv;
	char ms[10];
	char ht[50];
	printf("Nhap so luong sinh vien  n = "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap thong tin sinh vien thu %d: ",i);
		fflush(stdin);
		printf("\nMSSV: "); fgets(ms,10,stdin);
		if(ms[strlen(ms)-1]=='\n') ms[strlen(ms)-1]='\0';
		strcpy(sv.ID,ms);
		
		printf("Ho va ten: "); fgets(ht,50,stdin);
		if(ht[strlen(ht)-1]=='\n') ht[strlen(ht)-1]='\0';
		strcpy(sv.Name,ht);
		
		printf("Diem LT: "); scanf("%f",&sv.R1);
		printf("Diem TH1: "); scanf("%f",&sv.R2);
		printf("Diem TH2: "); scanf("%f",&sv.R3);
		append(sv,&L);
	}
	return L;
}
	

void hienthi(List L){
	struct Node *p=L;
	Student sv;
	int count=1;
	float avg;
	while(p->Next!=NULL){
		sv=p->Next->Element;
		avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
		printf("%d. MSSV: %s",count,sv.ID);
		printf("\n -Ho va ten: %s",sv.Name);
		printf("\n -Diem LT: %.2f",sv.R1);
		printf("\n -Diem TH1: %.2f",sv.R2);
		printf("\n -Diem TH2: %.2f",sv.R3);
		count++;
		p=p->Next;
//		printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",count,p->Next->Element.ID, 
//	      p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
//	      p->Next->Element.R3, avg);			
//	    count++;  
//		p=p->Next;
    }
}
void hienthidat(List L){
	struct Node *p=L;
	Student sv;
	int count=1;
	float avg;
	while(p->Next!=NULL){
		sv=p->Next->Element;
		avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
		if (avg>=4.0){
			printf("%d. MSSV: %s",count,sv.ID);
			printf("\n -Ho va ten: %s",sv.Name);
			printf("\n -Diem LT: %.2f",sv.R1);
			printf("\n -Diem TH1: %.2f",sv.R2);
			printf("\n -Diem TH2: %.2f",sv.R3);			
	    	count++;  
		}
		p=p->Next;
	}
	printf("%d students in total\n",count);
}
List chepKhongdat(){
	List L2;
	L2=getList();
	struct Node *p=L2;
	float avg;
	while(p->Next!=NULL){
		avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
		if (avg<4.0){
			append(p->Next->Element, &L2);
		}
		p=p->Next;
	}
	return L2;
}
int main(){
	List L;
	L=nhap();
	printf("Danh Sach vua nhap la: \n\n");
	hienthi(L);
	return 0;
	}
	
