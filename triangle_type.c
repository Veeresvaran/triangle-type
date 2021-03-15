#include<stdio.h>
#include<string.h>
#define size 1000

struct Triangle{
	int sides[4];
	char type[30];
}triangle[size];

	
int main(){
	int side1,side2,side3,i=0;
	char op;
	
	void input_sides(int *,int *,int *,int *);
	void get_type(int *);
	void get_output(int *);
	
	do{
		input_sides(&side1,&side2,&side3,&i);
		printf("\nInput another?(Y/N):");
		scanf(" %c",&op);
		switch(op){
			case 'Y':
				i++;
				break; 
			
			case 'N':
				break;
				
			default :
					printf("\nInvalid");
				break;
		}
	}while(op != 'N');
	get_type(&i);
	get_output(&i);
	
	return 0;
	
}
void input_sides(int *side1,int *side2,int *side3,int *i){
	printf("\nEnter the length of the sides for a triangle\n");
	printf("Side 1 = ");
	scanf("%d",side1);
	printf("Side 2 = ");
	scanf("%d",side2);
	printf("Side 3 = ");
	scanf("%d",side3);
	
	triangle[*i].sides[0]=*side1;
	triangle[*i].sides[1]=*side2;
	triangle[*i].sides[2]=*side3;
	
}
void get_type(int *i){
	int a,p,q,r,t1,t2,t3;
	for(a=0;a<=*i;a++){
		p=triangle[a].sides[0];
		q=triangle[a].sides[1];
		r=triangle[a].sides[2]; 
		
		t1=p*p;
		t2=q*q;
		t3=r*r;
		
		if((p < q+r) && (q < p+r) && (r < p+q) ){
			if((t1==t2+t3) || (t2==t1+t3) || (t3==t1+t2)){
				strcpy(triangle[a].type,"Right triangle ");
			}else if(p==q || p==r || q==r){
				if(p==q && q==r && p==r){
					strcpy(triangle[a].type,"Equilateral triangle");
				}else if((t1==t2+t3) || (t2==t1+t3) || (t3==t1+t2)){
					strcpy(triangle[a].type,"A right & isosceles triangle");
				}else{
					strcpy(triangle[a].type,"Isosceles triangle");
				}	
			}else{
				strcpy(triangle[a].type,"Scalene triangle");
			}
		}else{
			strcpy(triangle[a].type,"Not a triangle");
		}
	}
}
void get_output(int *i){
	int j,b;
	printf("\nThe details of the triangles are:");
	for(b=0;b<=*i;b++){
		printf("\nTriangle number %d:\n",b+1);
		for(j=0;j<3;j++){
			printf("Side %d = %d\n",j+1,triangle[b].sides[j]);
		}
		printf("Type = %s\n",triangle[b].type);
	}
}
