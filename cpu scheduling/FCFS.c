#include<stdio.h>
#include<stdlib.h>
struct table
{  int pro,at,bt;
};
struct node
{
	int pr,wt,tat;
};

int main(){
int n;
printf("Enter no of process ::");
scanf("%d",&n);
 
 struct table *a=(struct table*)malloc(sizeof(struct table)*n);
 printf("\n\nEnter arriving time , Burst time for ( %d ) process-------------\n",n);
 int ia=0;
 for(ia=0;ia<n;ia++)
 {      
 	(a+ia)->pro=ia+1;
 	int x,y;
 	scanf("%d%d",&x,&y);
 	(a+ia)->at=x;
 	(a+ia)->bt=y;
 }
int i,j;
 for(i=1;i<n;i++)
 {     int key=(a+i)->at;
             int l=(a+i)->bt;
             int m=(a+i)->pro;
             
     for(j=i-1;j>=0;j--)
 	{  
 		if(key<(a+j)->at)
 		{
            (a+j+1)->at=(a+j)->at;
            (a+j+1)->bt=(a+j)->bt;
            (a+j+1)->pro=(a+j)->pro;

            (a+j)->at=key;
            (a+j)->bt=l;
            (a+j)->pro=m;

 		}
       else
       {   (a+j+1)->at=key;
       	(a+j+1)->pro=m;
       	(a+j+1)->bt=l;
       	break;


       }

 	}


 }
 

 
struct node *b=(struct node*)(malloc(sizeof(struct node)*n));
   int time=0;//(a+0)->at;
   //int r=time;
   float avg_wt=0.0,avg_tat=0.0;
   int ib=0;
 for(ib=0;ib<n;ib++)
 {
    (b+ib)->pr=(a+ib)->pro;
    if(time<(a+ib)->at)
    time=(a+ib)->at;
    
    time=time+(a+ib)->bt;
    (b+ib)->tat=time-(a+ib)->at;
    avg_tat=avg_tat+(b+ib)->tat;
    (b+ib)->wt=(b+ib)->tat-(a+ib)->bt;
    avg_wt=avg_wt+(b+ib)->wt;

 }
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
printf("\n\n  Processor    Wating_time     Turn_around_time\n\n");
int ic=0;
for(ic=0;ic<n;ic++)
 printf("  P%d           %d              %d\n",(b+ic)->pr,(b+ic)->wt,(b+ic)->tat);

printf("\n\nAverage_waiting_time :: %f\t\tAverage_Turn_Around_Time :: %f\n\n ",avg_wt,avg_tat);



return 0;

}



