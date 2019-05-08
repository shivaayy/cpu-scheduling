#include<stdio.h>
#include<stdlib.h>
struct table
{  int pro,at,bt,p,bbt;
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
 printf("\n\nEnter arriving time , Burst time ,      Priority        for ( %d ) process-------------\n",n);
 int ia=0;
 for(ia=0;ia<n;ia++)
 {
 	(a+ia)->pro=ia+1;
 	int x,y,z;
 	scanf("%d%d%d",&x,&y,&z);
 	(a+ia)->at=x;
 	(a+ia)->bt=y;
 	(a+ia)->p=z;
 		(a+ia)->bbt=y;
 }
int i,j,flag=0;
for(i=1;i<n;i++)
 {     int key=(a+i)->at;
             int l=(a+i)->bt;
             int m=(a+i)->pro;
             int o=(a+i)->p;
             int q=(a+i)->bbt;
             
     for(j=i-1;j>=0;j--)
 	{  
 		if(key<(a+j)->at)
 		{
            (a+j+1)->at=(a+j)->at;
            (a+j+1)->bt=(a+j)->bt;
            (a+j+1)->pro=(a+j)->pro;
            (a+j+1)->p=(a+j)->p;
             (a+j+1)->bbt=(a+j)->bbt;

            (a+j)->at=key;
            (a+j)->bt=l;
            (a+j)->pro=m;
            (a+j)->p=o;
             (a+j)->bbt=q;

 		}
       else
       {   (a+j+1)->at=key;
       	(a+j+1)->pro=m;
       	(a+j+1)->bt=l;
       	(a+j+1)->bbt=q;
       		(a+j+1)->p=o;
       	
       	break;


       }

 	}


 }
 
int ic;
//for(ic=0;ic<n;ic++)
 //printf("  P%d           %d              %d       %d\n",(a+ic)->pro,(a+ic)->at,(a+ic)->bt,(a+ic)->p);


// int visit[n];
 //for(i=0;i<n;i++)
 //visit[i]=0;
struct node *b=(struct node*)(malloc(sizeof(struct node)*n));
   int time=(a+0)->at;
  int max_P=999999;
   float avg_wt=0.0,avg_tat=0.0;
   int ib=0;
   int r;
   flag=0;
 while(1)
 {int flag_1=0;
     max_P=999999;
     
   for(i=0;i<n;i++)
   {
       if((a+i)->at<=time&&(a+i)->bt!=0)
       {
           if(max_P>(a+i)->p)
           {
               max_P=(a+i)->p;
               r=i;
               flag_1++;
           }

       }

   }
   
   if(flag_1==0)
   {
      int ly=0;
      for(ly=0;ly<n;ly++)
       {
           if((a+ly)->at>time)
           {   time=(a+ly)->at;
               r=ly;
               break;
           }
       }
       
   }
   time=time+1;
   (a+r)->bt=(a+r)->bt-1;
   if((a+r)->bt==0)
   {    flag++;
       (b+r)->tat=time-(a+r)->at;
       (b+r)->wt=(b+r)->tat-(a+r)->bbt;
       (b+r)->pr=(a+r)->pro;
       avg_tat=avg_tat+(b+r)->tat;
       avg_wt=avg_wt+(b+r)->wt;
   }
   
   if(flag==n)
   break;
   
   
   

	
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


