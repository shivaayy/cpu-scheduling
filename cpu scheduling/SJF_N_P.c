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
 printf("\n\nEnter arriving time      ,     Burst time    for ( %d ) process-------------\n",n);
 int ia=0;
 for(ia=0;ia<n;ia++)
 {
 	(a+ia)->pro=ia+1;
 	int x,y;
 	scanf("%d%d",&x,&y);
 	(a+ia)->at=x;
 	(a+ia)->bt=y;
 	
 }
int i,j,flag=0;
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
           // (a+j)->p=o;

 		}
       else
       {   (a+j+1)->at=key;
       	(a+j+1)->pro=m;
       	(a+j+1)->bt=l;
       	//	(a+j+1)->p=o;
       	
       	break;


       }

 	}


 }
 
int ic;
//for(ic=0;ic<n;ic++)
 //printf("  P%d           %d              %d       %d\n",(a+ic)->pro,(a+ic)->at,(a+ic)->bt,(a+ic)->p);


 int visit[n];
 for(i=0;i<n;i++)
 visit[i]=0;
struct node *b=(struct node*)(malloc(sizeof(struct node)*n));
   int time=(a+0)->at;
  int max_P=999999;
   float avg_wt=0.0,avg_tat=0.0;
   int ib=0;
   int r;
 for(ib=0;ib<n;ib++)
 {
     max_P=999999;
     flag=0;
   for(i=0;i<n;i++)
   {
       if((a+i)->at<=time&&visit[i]==0)
       {
           if(max_P>(a+i)->bt)
           {
               max_P=(a+i)->bt;
               r=i;
               flag++;
           }

       }

   }

	 if(flag==0)
	 {
	 for(j=0;j<n;j++)
	 {
	 	if((a+j)->at>time)
	 	{
	 		time=(a+j)->at;
	 		r=j;
	 		break;
	 		
		 }
		 
		 }
		 
	 }
	 
	  visit[r]=1;
   time=time+(a+r)->bt;

   (b+r)->pr=(a+r)->pro;
    (b+r)->tat=time-(a+r)->at;
    avg_tat=avg_tat+(b+r)->tat;
     (b+r)->wt=(b+r)->tat-(a+r)->bt;
     avg_wt=avg_wt+(b+r)->wt;              
	 
flag=0;
 }
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
printf("\n\n  Processor    Wating_time     Turn_around_time\n\n");
//int ic=0;
for(ic=0;ic<n;ic++)
 printf("  P%d           %d              %d\n",(b+ic)->pr,(b+ic)->wt,(b+ic)->tat);

printf("\n\nAverage_waiting_time :: %f\t\tAverage_Turn_Around_Time :: %f\n\n ",avg_wt,avg_tat);



return 0;

}
