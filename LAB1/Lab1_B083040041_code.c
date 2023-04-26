#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(){
	
	bool A0,A1,A2,A3,n1,n2,n3,y;
	int jumeper=0;
	int out[16];
	int flagger[16]={0};
	int outA3sa1[16],outA3sa0[16],outA2sa1[16],outA2sa0[16],outA1sa1[16],outA1sa0[16],outA0sa1[16],outA0sa0[16],outn1sa1[16],outn1sa0[16];
	int stk[16]={0};
	
	
	
	
	
	
	int num, m, c, i = 0;
    int n = 2;
    int a[4]={0};

    for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;

    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];

    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	out[aa]=y;
}

	
	for(int t=0;t<6;t++){
	int stk[16]={0};
	//A3
	printf("\n");
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=1;
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA3sa1[aa]=y;
}
	
	
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;

    A3=0;
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA3sa0[aa]=y;
}
	
	for(int x=0;x<16;x++)
		printf("%4d",x);
	printf("\n");
	for(int x=0;x<16;x++){
		if(outA3sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA3sa1[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA3sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA3sa1[x]=1;
			printf("%4d",1);
		}
		else{
			outA3sa1[x]=0;
			printf("%4d",0);
			
	}
	}
	printf("\n");
	for(int x=0;x<16;x++){
		if(outA3sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA3sa0[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA3sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA3sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outA3sa0[x]=0;
			printf("%4d",0);
	}
	}
	
	
	
	//A2
	
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=1;
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA2sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outA2sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA2sa1[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA2sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA2sa1[x]=1;
			printf("%4d",1);
		
		}
		else{
			outA2sa1[x]=0;
			printf("%4d",0);
}
	}


	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=0;
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA2sa0[aa]=y;
}
	
	for(int x=0;x<16;x++){
		if(outA2sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA2sa0[x]=0;
		jumeper=0;
	}
	else{
	printf("\n");
	for(int x=0;x<16;x++)
		if(outA2sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA2sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outA2sa0[x]=0;
			printf("%4d",0);
	
}
	}
	//A1
	
	
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=1;
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA1sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outA1sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA1sa1[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA1sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA1sa1[x]=1;
			printf("%4d",1);
	}
		else{
			outA1sa1[x]=0;
			printf("%4d",0);
	}
	}
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=0;
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA1sa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outA1sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA1sa0[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA1sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA1sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outA1sa0[x]=0;
			printf("%4d",0);
	}
	//A0
	}
	
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=1;
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA0sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outA0sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA0sa1[x]=0;
		jumeper=0;
	}
	else{
	for(int x=0;x<16;x++)
		if(outA0sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA0sa1[x]=1;
			printf("%4d",1);
	}
		else{
			outA0sa1[x]=0;
			printf("%4d",0);
	}
	}
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=0;
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outA0sa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outA0sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outA0sa0[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outA0sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outA0sa0[x]=1;
			printf("%4d",1);
	}
		else{
		
			outA0sa0[x]=0;
			printf("%4d",0);
}
	}
	//n1
	
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=1;//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outn1sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn1sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn1sa1[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outn1sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn1sa1[x]=1;
			printf("%4d",1);
	}
		else{
			outn1sa1[x]=0;
			printf("%4d",0);
	}
	}


	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=0;//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outn1sa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn1sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn1sa0[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outn1sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn1sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outn1sa0[x]=0;
			printf("%4d",0);
	}
	}
	//n2
	int outn2sa1[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=1;//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outn2sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn2sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn2sa1[x]=0;
		jumeper=0;
	}
	else{	

	for(int x=0;x<16;x++)
		if(outn2sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn2sa1[x]=1;
			printf("%4d",1);
	}
		else{
			outn2sa1[x]=0;
			printf("%4d",0);
	}
	}
	int outn2sa0[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=0;//invert A1
	n3=!(n2||A0);//invert or
	y=!(n3&&n1);
	outn2sa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn2sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn2sa0[x]=0;
		jumeper=0;
	}
	else{


	for(int x=0;x<16;x++)
		if(outn2sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn2sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outn2sa0[x]=0;
			printf("%4d",0);
	}
	}
	//n3
	
	int outn3sa1[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=1;//invert or
	y=!(n3&&n1);
	outn3sa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn3sa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn3sa1[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outn3sa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn3sa1[x]=1;
			printf("%4d",1);
	}
		else{
			outn3sa1[x]=0;
			printf("%4d",0);
}
	}
	int outn3sa0[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=0;//invert or
	y=!(n3&&n1);
	outn3sa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outn3sa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outn3sa0[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outn3sa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outn3sa0[x]=1;
			printf("%4d",1);
	}
		else{
			outn3sa0[x]=0;
			printf("%4d",0);
}
	}
	//y
	int outysa1[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=1;
	outysa1[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outysa1[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outysa1[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outysa1[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outysa1[x]=1;
			printf("%4d",1);
	}
		else{
			outysa1[x]=0;
			printf("%4d",0);
	}
	}
	
	
	
	
	
	
	int outysa0[16];
	for(int aa=0;aa<16;aa++){
	int a[4]={0};
    num = aa;
    i=0;
    while (num > 0)
    { 
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
	i=4;
	//for(i--; i >= 0; i--)
		//printf("%d",a[i]);
    A3=a[3];
    A2=a[2];
    A1=a[1];
    A0=a[0];
    //printf("\n?%d%d%d%d\n\n",A3,A2,A1,A0);
    n1=!(A2&&A3);//NAND A3 A2
	n2=!(A1);//invert A1
	n3=!(n2||A0);//invert or
	y=0;
	outysa0[aa]=y;
}
	

	printf("\n");
	for(int x=0;x<16;x++){
		if(outysa0[x]!=out[x]&&flagger[x]==1){
			jumeper=1;
		}
	}
	if(jumeper==1){
		for(int x=0;x<16;x++)
			outysa0[x]=0;
		jumeper=0;
	}
	else{

	for(int x=0;x<16;x++)
		if(outysa0[x]!=out[x]&&flagger[x]==0){
			stk[x]++;
			outysa0[x]=1;
			printf("%4d",1);
	}
		else{
			outysa0[x]=0;
			printf("%4d",0);
	}
	}
	//output
	
	printf("\ninput: ");
	for(int x=0;x<16;x++){
		
		printf("%4d",stk[x]);
	}
	int maxx=0;
	int flag;
	for(int x=0;x<16;x++){
		if(stk[x]>maxx){
			maxx=stk[x];
			flag=x;
		}
	}
	printf("\nsol: %d\n",flag);
	flagger[flag]=1;
	}
}
