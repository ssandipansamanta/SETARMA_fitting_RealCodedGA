#include "stdafx.h"
#include<math.h>
#include<conio.h>
#define ss 50
#define rvalue 48
#define sandipan_SETAR
void main()
{
	int			d=2,ar1=2,ar2=1,ma1=1,ma2=1;
	float		ar_1[5]={12.421,0.258,-0.112},
		        ar_2[5]={33.345,0.389},
		        ma_1[5]={0.351},
				ma_2[5]={0.431},
				r=22.350;


	int   		i,t,j,p1=0,p2=0,k,l=0,k1=0,k2=0,n1,n2,check;
	float 		pasum1,pasum2,resid1=0,resid2=0,aic1,aic2,y1[ss],y2[ss],
				naic,pasum11,pasum22,s1[ss],s2[ss],error[ss],e_2[ss],e_1[ss],
				error1[ss],error2[ss],e1[ss],e2[ss],y[ss],ynew[ss];
	
	FILE *in,*out;
	in=fopen("input.txt","r");
	for(k=0;k<rvalue;k++)
	fscanf(in,"%f",&y[k]);
    fclose(in);

#ifdef sandipan_SETARMA

for(t=0;t<rvalue;t++)
{
	if(t>=d)
	{
		if((y[t-d]<=r)&&(t>=ar1))
		{
			pasum1=0;
			for(k=1;k<=ar1;k++)
				pasum1=pasum1 + ar_1[k]*y[t-k];
			s1[p1]=y[t]-ar_1[0]-pasum1;			
			y1[p1]=y[t];
		}
		if((y[t-d]>r)&&(t>=ar2))
		{
			pasum2=0;
			for(k=1;k<=ar2;k++)
				pasum2=pasum2 + ar_2[k]*y[t-k];
			s2[p2]=y[t]-ar_2[0]-pasum2;
			y2[p2]=y[t];
		}
		if (t<ar1)e1[t]=0;
		if (t<ar2)e2[t]=0;
			pasum11=0;
			for(k=0;k<ma1;k++)
			{
				if(t>=k+d)
				{
					if(y[t-k-d]<=r)
						pasum11=pasum11+ma_1[k]*e1[t-k-1];
					if(y[t-k-d]>r)
						pasum11=pasum11+ma_1[k]*e2[t-k-1];
				}
			}
				
			pasum22=0;
			for(k=0;k<ma2;k++)
			{
				if(t>=k+d)
				{
					if(y[t-k-d]<=r)
						pasum22=pasum22+ma_2[k]*e1[t-k-1];
					if(y[t-k-d]>r)
						pasum22=pasum22+ma_2[k]*e2[t-k-1];
				}
			}
		
		if((t>=ar1)&&(y[t-d]<=r))
		{
			e1[t]= s1[p1]-pasum11;e_1[p1]=e1[t];
			error1[p1] = pow(e1[t],2);
			p1= p1+1;
			if (t==rvalue-1)
				check =1;
			else 
				check=2;
		}
		if (y[t-d]>r) 
			e1[t]=0;
		if((t>=ar2)&&(y[t-d]>r))
		{
			e2[t]= s2[p2]-pasum22;e_2[p2]=e2[t];
			error2[p2] = pow(e2[t],2);
			p2=p2+1;
		}
		if (y[t-d]<r) 
			e2[t]=0;
	}
	else
	{
		e1[t] = 0;
		e2[t] = 0;
	}
}/*<-----------------------------------------------------------------run complete for N observation*/
   for (i=d;i<rvalue;i++)
	   {
		   for (j=0;j<rvalue;j++)
		   {
			   if (y[i]==y1[j])
			   {
					   error[l]=e_1[k1];
					   ynew[l]=y[i];
					   k1=k1+1;l=l+1;
			   }
			   if (y[i]==y2[j])
			   {
				   error[l]=e_2[k2];
				   ynew[l]=y[i];
				   k2=k2+1;l=l+1;
			   }
		   }
	   }
	for (i=0;i<l;i++)
	printf("\n%d\t%f\t%f\t%f",/*y[i],*/i+d+1,ynew[i],ynew[i]-error[i],error[i]);
/*--------------------------------------------------------------------*/

for(i=0;i<p1;i++)
	resid1 = resid1 + error1[i];

for(i=0;i<p2;i++)
	resid2 = resid2 + error2[i];

aic1 = p1*log(resid1/p1)+ 2*(ar1+ma1+1);/*<-------------------------evaluate the aic values for I regim*/
aic2 = p2*log(resid2/p2)+ 2*(ar2+ma2+1);/*<-------------------------evaluate the aic values for II regim*/
naic = (aic1+aic2)/(rvalue-d);

printf("\n\nvar(e1)=%f\tvar(e2)=%f\n",resid1/(p1),resid2/(p2));

printf("\n\nNAIC= %f",naic);

	/*out=fopen("Fit_Residual.xls","w+");
	for (i=0;i<l;i++)
		fprintf(out,"\n%f\t%f\t%f",ynew[i],ynew[i]-error[i],error[i]);
	fprintf(out,"\n\nNAIC =\t%f\n%d\t%d",naic,p1,p2);
    fclose(out);*/
#endif

#ifdef sandipan_SETAR

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
	printf("\n\nNAIC= %f\n\np1= %d\n\np2= %d\n\nlast obsevation= %f",naic,p1,p2,y[rvalue-1]);
	
	out=fopen("Fit_Residual.xls","w+");
	for (i=0;i<l;i++)
		fprintf(out,"\n%f\t%f\t%f",ynew[i],ynew[i]-error[i],error[i]);
		fprintf(out,"\n\n%f",naic);
    fclose(out);

#endif

getch();
}
