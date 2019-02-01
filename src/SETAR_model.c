#include "stdafx.h"
#include<math.h>
#include<conio.h>
#define ss 50
#define value 46
#define rvalue value-1

void main()
{
	int		d=2,ar1=3,ar2=1;
	int   	p1=0,p2=0,i,j,k,k1=0,k2=0,l=0;
	float 	ar_1[5]={10.696,0.224,0.102,-0.073},
            ar_2[5]={34.738,0.488},r=22.298,
			y[ss],resid1,resid2,aic1,aic2,pasum2,pasum1,
			naic,y1[ss],y2[ss],ynew[ss],error[ss],
	        s1[ss],s2[ss],e1[ss],e2[ss];
	
	FILE *in,*out;
	in=fopen("input.txt","r");
	for(k=0;k<rvalue;k++)
	fscanf(in,"%f",&y[k]);
    fclose(in);

   for(i=0;i<rvalue;i++)
   {  
		if(i>=d)
		{
     		if((y[i-d]<=r)&&(i>=ar1))
		    {
				pasum1=0;
				for(k=1;k<=ar1;k++)
					pasum1=pasum1 + ar_1[k]*y[i-k];
				e1[p1]=y[i]-ar_1[0]-pasum1;
				s1[p1]=pow(e1[p1],2);
				y1[p1]=y[i];
				p1=p1+1;/*<---------------p1: number of AR models in Ist regim*/
			}/*<-------------------------run complete once forI regim -0.207510*y[i-2]*/
			if((y[i-d]>r)&&(i>=ar2))
			{
				pasum2=0;
				for(k=1;k<=ar2;k++)
					pasum2=pasum2 + ar_2[k]*y[i-k];
				e2[p2]=y[i]-ar_2[0]-pasum2;
				s2[p2]=pow(e2[p2],2);
				y2[p2]=y[i];
			    p2=p2+1;/*<-----------------p2: number of AR models in IIrd regim*/
			}/*<----------------------------run complete once for III regim */
		}
	}/*<------------------------------------run complete for N observation*/
    for (i=d;i<rvalue;i++)
	   {
		   for (j=0;j<rvalue;j++)
		   {
			   if (y[i]==y1[j])
			   {
					   error[l]=e1[k1];
					   ynew[l]=y1[j];
					   k1=k1+1;l=l+1;
			   }
			   if (y[i]==y2[j]) 
			   {
				   error[l]=e2[k2];
				   ynew[l]=y2[j];
				   k2=k2+1;l=l+1;
			   }
		   }
	   }
  
   
	for (i=0;i<l;i++)
		printf("\n%d\t%f\t%f\t%f",i+d+1,ynew[i],ynew[i]-error[i],error[i]);

	resid1=0;
	for(i=0;i<p1;i++)
		resid1=resid1+s1[i];
	
	aic1=p1*log(resid1/p1)+2*(ar1+1);/*<----evaluate the aic values for I regim*/

	resid2=0;
	for(i=0;i<p2;i++)
		resid2=resid2+s2[i];

	aic2=p2*log(resid2/p2)+2*(ar2+1);
	
	naic=(aic1+aic2)/(rvalue-d);
	printf("\n\nvar(e1)=%f\tvar(e2)=%f\n",resid1/p1,resid2/p2);
	printf("\n\nnaic= %f\n\np1= %d\n\np2= %d\n\nlast obsevation= %f",naic,p1,p2,y[rvalue-1]);
	
	/*out=fopen("Fit_Residual.xls","w+");
	for (i=0;i<l;i++)
		fprintf(out,"\n%f\t%f\t%f",ynew[i],ynew[i]-error[i],error[i]);
		fprintf(out,"\n\n%f",naic);
    fclose(out);*/

	getch();
}