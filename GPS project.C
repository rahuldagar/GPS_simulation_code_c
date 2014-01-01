#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<string.h>

/*struct col2
{  int  xc;
   int colour;
   struct col2 * next;
}*head_col2=NULL,*temp_col2,*temp2_col2;
struct col
{ int yc;
  struct col2 *next2;
  struct col * next1;
} */
struct map4
{  int id;
   int distance2;
   int type;
   struct map4* next1;
}*head_map4=NULL,*temp_map4,*temp2_map4;
struct map3
{  int id;
   float time1;
   int tp;
   int dp;
   float distance1;
   struct map4* next2;
   struct map3* next1;
}*head_map3=NULL,*temp_map3,*temp2_map3;

struct map2
{  char name[80];
   int id;
   int link[10];
   int dis3[10];
   int xp;
   int yp;
   int type[10];
}head_map2,*head2_map2;
struct link
{  int id;
   int dis;
   int type;
   struct link *next;
}*temp_link,*temp2_link,*head_link;
struct map
{  int id;
   int xp;
   int yp;
   char name[80];
   struct map *next;
   struct link *next2;
}*temp_map,*temp2_map,*head_map;
struct stack
{   int id;
	int check;
	int d;
	int type;
	struct stack *next;
	struct stack *pre;
}*temp_stack,*temp2_stack,*head_stack;
void pstack();
void mapfile();
int path(int ch1,int ch2,struct map *pointer);
struct map* rollback();
void put_stack(int id1,int dis1,int type1);
int check(int id1,int ch1,int ch2);
int traf,thick=5;
void check1()
{ temp_map3=head_map3;
  while(temp_map3!=NULL)
  {  temp_map4=temp_map3->next2;
  //   while(temp_map4!=NULL)
 //   { // printf("\nid %d\ndis %d\ntype %d\n",temp_map4->id,temp_map4->distance2,temp_map4->type);
 //      temp_map4=temp_map4->next1;
  //  }
    printf("\ndp- %d tp- %d",temp_map3->dp,temp_map3->tp);
 //   getch();

    temp_map3=temp_map3->next1;
  }
}
int zoomlevel;
void zoom(int xp1,int yp1)
{    int i=0,j=0,k=0,maxx,maxy,xp2,yp2,temp;
     maxx=getmaxx();
     maxy=getmaxy();

     xp2=maxx-zoomlevel*50;
     yp2=maxy-zoomlevel*50;

     for(i=xp1-25;i<xp1+25;i++)
     {    yp2=maxy-zoomlevel*50;
	  for(j=yp1-25;j<yp1+25;j++)
	  {
	    setcolor(getpixel(i,j));
	    for(k=0;k<zoomlevel;k++)
	    {
	    rectangle(xp2,yp2,xp2+k,yp2+k);
	    }
	 //   floodfill(xp2+1,yp2+1, getpixel(i,j));
	    yp2=yp2+zoomlevel;

	  }
	  xp2=xp2+zoomlevel;


     }

}
void pixelmove();
void userchoice()
{    int no=1,ch7,i,j,k;
     temp_map3=head_map3;
     temp_map=head_map;
     while(temp_map->id!=temp_map3->id)
     {   temp_map=temp_map->next;
     }

  while(temp_map3!=NULL)
  {
     printf("\n\t\t\t%d %s  ",no,temp_map->name);
     temp_map4=temp_map3->next2;
     while(temp_map4!=NULL)
     {
	temp2_map=head_map;
     while(temp2_map->id!=temp_map4->id)
     { temp2_map=temp2_map->next;
     }
	printf("= %s   ",temp2_map->name);

	temp_map4=temp_map4->next1;
     }
     temp_map3=temp_map3->next1;
     no++;
     printf("\n");
  }
  getch();


   printf("\n\t\t\tenter path  ");
    scanf("%d",&ch7);
    temp_map3=head_map3;
       while(ch7>1)
    {   temp_map3=temp_map3->next1;
	ch7--;
    }
//	temp_map3=NULL;
//	drawgraph2();

     pixelmove();





}



void pixelmove()
{ float i=0,vx=0,d4,vy=0,px5,py5,j=0,k=0,time2,type1,l=0,d3=0,px1,py1,px2,py2;
  int ch,z=0;
  int gdriver = DETECT, gmode, errorcode;
  clock_t start, end,time4;
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

//  i=userchoice();
//  start = clock();
//  temp_map3=head_map3;
//  while(temp_map3->dp!=1)
//  { temp_map3=temp_map3->next1;
//  }
  temp_map=head_map;
  while(temp_map->id != temp_map3->id)
  {   temp_map=temp_map->next;
  }
  px1=temp_map->xp;
  py1=temp_map->yp;

  temp_map4=temp_map3->next2;
  while(temp_map4!=NULL)
  { 	temp2_map=head_map;
	while(temp2_map->id != temp_map4->id)
	{   temp2_map=temp2_map->next;
	}
	px2=temp2_map->xp;
	py2=temp2_map->yp;
	type1=temp_map4->type;
//	d3=(px2-px1)*(px1-px2);
//	d3+=(py2-py1)*(py2-py1);
//	d3=sqrt(d3);
	d4=temp_map4->distance2;

       //	if(type1==1)
       //	{
	if(traf==1)
	{   if(temp_map4->type==1)
	    time2=d4/80;

	    if(temp_map4->type==2)
	    time2=d4/60;

	    if(temp_map4->type==3)
	    time2=d4/40;

	    if(temp_map4->type==4)
	    time2=d4/30;
	}
	if(traf==2)
	{   if(temp_map4->type==1)
	    time2=d4/75;

	    if(temp_map4->type==2)
	    time2=d4/55;

	    if(temp_map4->type==3)
	    time2=d4/35;

	    if(temp_map4->type==4)
	    time2=d4/25;
	}
	if(traf==3)
	{   if(temp_map4->type==1)
	    time2=d4/70;

	    if(temp_map4->type==2)
	    time2=d4/50;

	    if(temp_map4->type==3)
	    time2=d4/30;

	    if(temp_map4->type==4)
	    time2=d4/20;
	}

      //	time2=d4/40;
	 //  vx=80*((px2-px1)/d3);
	 //  vy=80*((py2-py1)/d3);
	 //  for(i=0;i<10;i++)
	 //  {  // circle()
	   time4=0;
	   time2=time2*60*60;
	   vx=(px2-px1)/time2;
	   vy=(py2-py1)/time2;
	   z=0;
	   i=0;

	   start = clock();
	   while(z==0)
	 {//  delay(2000);
	 //  time4=time4+30;

	   end=clock();
	   time4=(end-start)/CLK_TCK;
       //	   end=clock();
     //	   time4=(end-start)/CLK_TCK;
	   gotoxy(30,30);
	   printf("Time elapsed %f",(end-start)/CLK_TCK);
	   setcolor(8);
	   for(k=0;k<5;k++)
	   {
	   circle(px1+ (vx)*time4 , py1+ (vy)*time4,k);
	   }
	   px5=px1+ (vx)*time4;
	   py5= py1+ (vy)*time4;
//	   zoom(px5,py5);
	 //  delay(200);
	   setcolor(11);
	   for(k=0;k<5;k++)
	   {
	   circle(px1+ (vx)*time4 , py1+ (vy)*time4,k);
	   }
	   i++;
	   ch= px1+ (vx)*time4;
	   if(px2>px1 && ch>px2)
	   z=1;

	   if(px2<px1 && ch<px2)
	   z=1;
	 //  getch();
	 }





//delay(2000);

//end = clock();
//printf("The time was: %f\n", (end - start) / CLK_TCK);
       px1=px2;
       py1=py2;
       temp_map4=temp_map4->next1;

      }

     closegraph();
}



void drawgraph()
{  int x1,y1,x2,y2,i,j,k;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   temp_map=head_map;
   while(temp_map!=NULL )
   {   //	  k=0;
       //	  j=0;
       //	  temp_map=head_map;
       //	  while(temp_map->id!=temp_map3->id)
      //	  {    temp_map=temp_map->next;
      //	  }
	  x1=temp_map->xp;
	  y1=temp_map->yp;
	 // temp2_map=temp2_map->next;
	 // n=temp->salary;
	    temp_link=temp_map->next2;
	  while(temp_link!=NULL)
	  {     temp2_map=head_map;
		while(temp2_map->id!=temp_link->id)
		{    temp2_map=temp2_map->next;
		}
		x2=temp2_map->xp;
		y2=temp2_map->yp;
		if(y2>y1)
		{
		for(i=x1-thick;i<x1+thick;i++)
		{    j=y2+x1-i;
		     setcolor(getmaxcolor());
		     line(i,y1,x2,j);
		}
		}

		if(y2<y1)
		{
		for(i=x1+thick;i>x1-thick;i--)
		{    j=y2+x1-i;
		     setcolor(getmaxcolor());
		     line(i,y1,x2,j);
		}
		}
		if(y2==y1)
		{
		  for(i=0;i<thick;i++)
		  {  line(x1,y1+i,x2,y2+i);
		  }

		}
		if(x1==x2)
		{ for(i=0;i>thick;i++)
		  {  line(x1+i,y1,x2+1,y2);
		  }
		}
	    /*	for(i=y1-10;i<y1+10;i++)
		{    j=y2+y1-i;
		     setcolor(getmaxcolor());
		     line(x1,i,x2,j);
		}  */

	       //	line(x1,y1,x2,y2);
	  //	getch();
		temp_link=temp_link->next;
	  }
       //	  temp_map3->dp=k+1;
       //	  temp_map3->tp=j+1;
	  temp_map=temp_map->next;

	//  getch();
  }

 temp_map=head_map;
 setcolor(3);
 while(temp_map!=NULL)
 { setcolor(9);
 for(i=0;i<20;i++)
   {     rectangle(temp_map->xp-i,temp_map->yp-i,temp_map->xp+i,temp_map->yp+i);
   }
   setcolor(3);
   outtextxy(temp_map->xp,temp_map->yp,temp_map->name);

   temp_map=temp_map->next;
 }
  getch();

  pixelmove();

  closegraph();

}
void sort1()
{ int k=0,j=0;
  temp_map3=head_map3;
   while(temp_map3!=NULL )
   {  	  k=0;
	  j=0;
	  temp2_map3=head_map3;
	 // n=temp->salary;
	  while(temp2_map3!=NULL)
	  {  if(temp2_map3->distance1 < temp_map3->distance1)
		{ k++;

		}

	     if(temp2_map3->time1 < temp_map3->time1)
		{ j++;

		}
		temp2_map3=temp2_map3->next1;
	  }
	  temp_map3->dp=k+1;
	  temp_map3->tp=j+1;
	  temp_map3=temp_map3->next1;
  }
// check1();

 userchoice();


}


void traffic()
{  float i=0,z=0,l=0,y=0;
   printf("\nenter traffic conditions");
   scanf("%d",&traf);
   temp_map3=head_map3;
  while(temp_map3!=NULL)
  {  temp_map4=temp_map3->next2;
     i=0;
     y=0;
     l=0;
     z=0;
     while(temp_map4!=NULL)
    { // printf("\nid %d\ndis %d\ntype %d\n",temp_map4->id,temp_map4->distance2,temp_map4->type);

       if(traf==1)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/80;
	       z+=y;
	    }
	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);

	       y=y/60;
	       z+=y;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/40;
	       z+=y;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/30;
	       z+=y;
	    }

	   l+=5;
       }
       if(traf==3)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/64;
	       z+=y;
	    }

	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/48;
	       z+=y;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/32;
	       z+=y;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       y+=(temp_map4->distance2);
	       y=y/24;
	       z+=y;
	    }
	    l+=8;
       }
       if(traf==2)
       {    if(temp_map4->type == 1)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/72;
	       z+=y;
	    }
	    if(temp_map4->type == 2)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/54;
	       z+=y;
	    }
	    if(temp_map4->type == 3)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/36;
	       z+=y;
	    }
	    if(temp_map4->type == 4)
	    {  i+=temp_map4->distance2;
	       y=(temp_map4->distance2);
	       y=y/27;
	       z+=y;
	    }

	  l+=12;
       }
       temp_map4=temp_map4->next1;
    }
    z=z+l;
    temp_map3->time1=z;
    temp_map3->distance1=i;
//    getch();
    temp_map3=temp_map3->next1;
  }
  sort1();
}

void gpspath()
{  int i=0,j=0,k=0,ch1,ch2,ch3,z;
   mapfile();

  head_stack=NULL;
  printf("\nenter places between which path is to be found");
  scanf("%d%d",&ch1,&ch2);
  temp2_stack=(struct stack *)malloc(sizeof(struct stack));
  temp2_stack->next=NULL;
  temp2_stack->pre=NULL;
  temp2_stack->id=ch1;
  temp2_stack->check=0;
  temp2_stack->d=0;
  head_stack=temp2_stack;
  temp_stack=head_stack;
  temp_map=head_map;
  while(temp_map->id!=ch1)
  {  temp_map=temp_map->next;
  }
  i=path(ch1,ch2,temp_map);
  printf("enter zoom level");
  scanf("%d",&zoomlevel);


//  check1();
  traffic();
// drawgraph();


}

int path(int ch1,int ch2,struct map *pointer)
{   int flag=0;
	if(pointer->id==ch2)
	{  while(pointer->id==ch2 && pointer!=NULL)
	   { printf("\npath found");
		 pstack();
		 getch();
		 pointer=rollback();
	   }
	}
	if(pointer==NULL)
	{  printf("\nall path found");
	   getch();
	   return 1;
	}
	temp_link=pointer->next2;
	while(temp_link!=NULL)
	{ flag=check(temp_link->id,ch1,ch2);
	  if(flag==0)
	  {  put_stack(temp_link->id,temp_link->dis,temp_link->type);
	  }
	  temp_link=temp_link->next;
	}
	  pointer=rollback();
	  path(ch1,ch2,pointer);
}
struct map * rollback()
{    temp2_stack=temp_stack;
	 while(temp2_stack->check!=1 && temp2_stack!=NULL)
	 {  temp2_stack=temp2_stack->pre;
	 }
	 if(temp2_stack==NULL)
	 { return NULL;
	 }
	 temp2_stack->check=0;
	 temp_stack=temp2_stack;
	 temp_stack->next=NULL;
	 temp_map=head_map;
	 while(temp_map->id!=temp2_stack->id && temp_map!=NULL)
	 {  temp_map=temp_map->next;
	 }
	 return temp_map;
}
int check(int id1,int ch1,int ch2)
{   if(id1==ch1)
	{  return 1;
	}
	temp2_stack=head_stack;
	while(temp2_stack!=NULL)
	{     if(temp2_stack->id==id1 && temp2_stack->check==0)
		  {return 1;
		  }
	   temp2_stack=temp2_stack->next;
	}
   return 0;
}
void put_stack(int id1, int dis1,int type1)
{ temp2_stack=(struct stack *)malloc(sizeof(struct stack));
  temp2_stack->next=NULL;
  temp2_stack->pre=temp_stack;
  temp_stack->next=temp2_stack;
  temp2_stack->id=id1;
  temp2_stack->check=1;
  temp2_stack->type=type1;
  temp2_stack->d=dis1;
  temp_stack=temp2_stack;
}
void pstack()
{  int dist=0,k=0;
   temp2_stack=head_stack;
   printf("\npath found\n");
   while(temp2_stack!=NULL)
   {   if(temp2_stack->check==0)
	   {  printf("-%d--%d",temp2_stack->id,temp2_stack->d);
		  dist+=temp2_stack->d;
		  if(k==0)
		  { temp2_map3=(struct map3*)malloc(sizeof(struct map3));
			temp2_map3->id=temp2_stack->id;
	   //		temp2_map3->type=temp2_stack->type;
	   //		temp2_map3->distance2=temp2_stack->d;
			temp2_map3->next2=NULL;
			temp2_map3->next1=NULL;
			if(head_map3==NULL)
			{  head_map3=temp_map3=temp2_map3;
			}
			else
			{  temp_map3->next1=temp2_map3;
			   temp_map3=temp2_map3;
			}

		  }
		  else
		  {	temp2_map4=(struct map4*)malloc(sizeof(struct map4));
			temp2_map4->id=temp2_stack->id;
			temp2_map4->type=temp2_stack->type;
			temp2_map4->distance2=temp2_stack->d;
	   //		temp2_map4->next2=NULL;
			temp2_map4->next1=NULL;
			if(temp2_map3->next2==NULL)
			{ temp2_map3->next2=temp2_map4;
			  temp_map4=temp2_map4;
			}
			else
			{  temp_map4->next1=temp2_map4;
			   temp_map4=temp2_map4;
			}
		  }

	   }
	   temp2_stack=temp2_stack->next;
	   k++;
 }
  printf("   total distance-  %d",dist);
}


void mapfile()
{   FILE *fp;
    int i=0,j=0,ch2;
    fp=fopen("c:\\project\\new.dat","rb");
    while( (fread(&head_map2,sizeof(struct map2),1,fp)) !=NULL)
   {  temp2_map=(struct map *)malloc(sizeof(struct map));
	 // printf("\nenter id  ");
	  temp2_map->id=head_map2.id;
	 // printf("\nenter no of links");
	  strcpy(temp2_map->name,head_map2.name);
	  temp2_map->xp=head_map2.xp;
	  temp2_map->yp=head_map2.yp;
	  ch2=0;
	  while(head_map2.link[ch2]!=-1)
	  {  ch2++;
	  }
	  head_link=NULL;
	  temp2_map->next=NULL;
	  temp2_map->next2=NULL;
	  for(j=0;j<ch2;j++)
	  {     temp2_link=(struct link *)malloc(sizeof(struct link));
	      //	printf("\nenter link id  ");
		temp2_link->id=head_map2.link[j];
	      //	printf("\nenter distance");
		temp2_link->dis=head_map2.dis3[j];
		temp2_link->type=head_map2.type[j];
		if(head_link==NULL)
		{ head_link=temp_link=temp2_link;
		 temp2_map->next2=temp2_link;
		}
		else
		{ temp_link->next=temp2_link;
		  temp_link=temp2_link;
		}
		temp2_link->next=NULL;
	  }
	 if(head_map==NULL)
	 {   head_map=temp_map=temp2_map;
	 }
	 else
	 {   temp_map->next=temp2_map;
	     temp_map=temp2_map;
	 }

	}
	fclose(fp);
 }