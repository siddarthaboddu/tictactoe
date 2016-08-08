#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<ctype.h>

char f,p[20],e,q[20]="computer",a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},ni,in,no,h=3;
int result=0;
void user1input();
void layout();
void user2input();
void win();
void loading();
void computer();
void user1_user2();
void user1_comp();

void main()
{int i,j,k=2;
clrscr();
textcolor(1);
gotoxy(30,5);
cprintf("TIC TAC TOE");
gotoxy(30,6);
loading();
gotoxy(30,15);
printf(" E N T E R ");
textcolor(15);
getch();
gotoxy(30,18);
printf("1)start game");
gotoxy(30,19);
printf("2)exit");
gotoxy(30,20);
e=getch();
clrscr();
if(e=='1')
{

printf("1)player vs computer\n");
printf("2)player vs player\n");
f=getch();
if(f=='1')
 user1_comp();
if(f=='2')
 user1_user2();
if(f!='1' && f!='2')
 printf("enter 1 or 2 only");


scanf("%c",&in);
if(in!='x' && in!='0')
{ while(in!='x' &&  in!='o')
 {printf("choose only x or 0\n");
  printf("what %s want to take x or 0:",p);
  in=getch();putch(in);
  printf("\n");
} }
if(in=='x')
ni='0';
if(in=='0')
ni='x';
i=1;
layout();
if(f=='1')
{
while(i<20)
{
user1input();
layout();
win();
if(result=='w')
{printf("%s won\n",p);
printf("%s better luck next time",q);
break;}
if(result=='d')
{printf("draw");
break;}
i=i+1;
computer();
layout();
win();
if(result=='w')
{printf("%s won\n",q);
printf("%s better luck next time",p);
break;}


if(result=='d')
{printf("draw");
break;}
else
i=i+1;
}
getch();
}


else
{
while(i<20)
{
user1input();
layout();
win();
if(result=='w')
{printf("%s won\n",p);
printf("%s better luck next time",q);
break;}
if(result=='d')
{printf("draw");
break;}
i=i+1;
user2input();
layout();
win();
if(result=='w')
{printf("%s won\n",q);
printf("%s better luck next time",p);
break;}

if(result=='d')
{printf("draw");
break;}
else
i=i+1;
}
getch();}
}}


void layout()
{int i,j;
i=0;
clrscr();
printf("%s : symbol : %c\n",p,in);
printf("%s : symbol : %c\n",q,ni);
while(i<3)
{j=0;
while(j<3)
{
printf("%c ",a[i][j]);
j=j+1;
printf("| ");
printf("%c ",a[i][j]);
j=j+1;
printf("| ");
printf("%c ",a[i][j]);
j=j+1;
printf("\n");
if(i<2)
printf("..|...|..\n");
}
i=i+1;}
}

void user1input()
{ int i,j;
printf("%s where u desire to enter %c\n",p,in);
printf("position : ");
no=getche();getch();
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
{if(a[i][j]==no)
a[i][j]=in;
}}
}

void user2input()
{ int i,j;
printf("%s where u desire to enter %c\n",q,ni);
printf("position : ");
no=getche();
getch();
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
{if(a[i][j]==no)
a[i][j]=ni;
}}
}

void win()
{int i,j,k=0;
if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) || (a[0][2]==a[1][1] && a[1][1]==a[2][0]) || (a[0][0]==a[0][1] && a[0][1]==a[0][2]) || (a[1][0]==a[1][1] && a[1][1]==a[1][2]) || (a[2][0]==a[2][1] && a[2][1]==a[2][2]) || (a[0][0]==a[1][0] && a[1][0]==a[2][0]) || (a[0][1]==a[1][1] && a[1][1]==a[2][1]) || (a[0][2]==a[1][2] && a[1][2]==a[2][2]) )
{ result='w'; }
else
{for(i=0;i<3;i++)
{for(j=0;j<3;j++)
{if(a[i][j]=='0' || a[i][j]=='x')
k=k+1; }}}
if(k==9)
result='d';}

void loading()
{ int i;
for(i=0;i<11;i++)
{delay(200);
printf("." );}}


void user1_user2()
{printf("user1 name:");
gets(p);
printf("user2 name:");
gets(q);
printf("enter 0 or x in boxes\n");
printf("what %s want to take x or 0:",p); }

void user1_comp()
{printf("user1 name:");
gets(p);
printf("enter 0 or x in boxes\n");
printf("what %s want to take x or 0:",p);   }

void computer()
{int i=0,j=0;

if(a[0][0]==a[1][1] && a[0][0]==ni && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[1][1]==a[2][2] && i==0 && a[1][1]==ni && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][0]==a[2][2] && i==0 && a[0][0]==ni && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][2]==a[1][1] && i==0 && a[0][2]==ni && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[1][1]==a[2][0] && i==0 && a[1][1]==ni && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni;i=i++;}
else if(a[0][2]==a[2][0] && i==0 && a[0][2]==ni && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][0]==a[0][1] && i==0 && a[0][0]==ni && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni;i=i++;}
else if(a[0][1]==a[0][2] && i==0 && a[0][1]==ni && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][0]==a[0][2] && i==0 && a[0][0]==ni && a[0][1]!=in && a[0][1]!=ni)
{a[0][1]=ni;i=i++;}
else if(a[1][0]==a[1][1] && i==0 && a[1][0]==ni && a[1][2]!=in && a[1][2]!=ni)
{a[1][2]=ni;i=i++;}
else if(a[1][0]==a[1][2] && i==0 && a[1][0]==ni && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[1][1]==a[1][2] && i==0 && a[1][1]==ni && a[1][0]!=in && a[1][0]!=ni)
{a[1][0]=ni;i=i++;}
else if(a[2][0]==a[2][1] && i==0 && a[2][0]==ni && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[2][0]==a[2][2] && i==0 && a[2][0]==ni && a[2][1]!=in && a[2][1]!=ni)
{a[2][1]=ni;i=i++;}
else if(a[2][1]==a[2][2] && i==0 && a[2][1]==ni && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[0][0]==a[1][0] && i==0 && a[0][0]==ni && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[1][0]==a[2][0] && i==0 && a[1][0]==ni && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][1]==a[1][1] && i==0 && a[0][1]==ni && a[2][1]!=in && a[2][1]!=ni)
{a[2][1]=ni;i=i++;}
else if(a[0][0]==a[2][0] && i==0 && a[0][0]==ni && a[1][0]!=in && a[1][0]!=ni)
{a[1][0]=ni;i=i++;}
else if(a[1][1]==a[2][1] && i==0 && a[1][1]==ni && a[0][1]!=in && a[0][1]!=ni)
{a[0][1]=ni;i=i++;}
else if(a[0][1]==a[2][1] && i==0 && a[0][1]==ni && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][2]==a[1][2] && i==0 && a[0][1]==ni && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[0][2]==a[2][2] && i==0 && a[0][2]==ni && a[1][2]!=in && a[1][2]!=ni)
{a[1][2]=ni;i=i++;}
else if(a[1][2]==a[2][2] && i==0 && a[1][2]==ni && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni;i=i++;}
else if(a[0][0]==a[1][1] && i==0 && a[0][0]==in && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[1][1]==a[2][2] && i==0 && a[1][1]==in && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][0]==a[2][2] && i==0 && a[0][0]==in && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][2]==a[1][1] && i==0 && a[0][2]==in && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[1][1]==a[2][0] && i==0 && a[1][1]==in && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni;i=i++;}
else if(a[0][2]==a[2][0] && i==0 && a[0][2]==in && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][0]==a[0][1] && i==0 && a[0][0]==in && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni;i=i++;}
else if(a[0][1]==a[0][2] && i==0 && a[0][1]==in && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][0]==a[0][2] && i==0 && a[0][0]==in && a[0][1]!=in && a[0][1]!=ni)
{a[0][1]=ni;i=i++;}
else if(a[1][0]==a[1][1] && i==0 && a[1][0]==in && a[1][2]!=in && a[1][2]!=ni)
{a[1][2]=ni;i=i++;}
else if(a[1][0]==a[1][2] && i==0 && a[1][0]==in && a[1][0]!=in && a[1][0]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[1][1]==a[1][2] && i==0 && a[1][1]==in && a[1][0]!=in && a[1][0]!=ni)
{a[1][0]=ni;i=i++;}
else if(a[2][0]==a[2][1] && i==0 && a[2][0]==in && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[2][0]==a[2][2] && i==0 && a[2][0]==in && a[2][1]!=in && a[2][1]!=ni)
{a[2][1]=ni;i=i++;}
else if(a[2][1]==a[2][2] && i==0 && a[2][1]==in && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[0][0]==a[1][0] && i==0 && a[0][0]==in && a[2][0]!=in && a[2][0]!=ni)
{a[2][0]=ni;i=i++;}
else if(a[1][0]==a[2][0] && i==0 && a[1][0]==in && a[0][0]!=in && a[0][0]!=ni)
{a[0][0]=ni;i=i++;}
else if(a[0][1]==a[1][1] && i==0 && a[0][1]==in && a[2][1]!=in && a[2][1]!=ni)
{a[2][1]=ni;i=i++;}
else if(a[0][0]==a[2][0] && i==0 && a[0][0]==in && a[1][0]!=in && a[1][0]!=ni)
{a[1][0]=ni;i=i++;}
else if(a[1][1]==a[2][1] && i==0 && a[1][1]==in && a[0][1]!=in && a[0][1]!=ni)
{a[0][1]=ni;i=i++;}
else if(a[0][1]==a[2][1] && i==0 && a[0][1]==in && a[1][1]!=in && a[1][1]!=ni)
{a[1][1]=ni;i=i++;}
else if(a[0][2]==a[1][2] && i==0 && a[0][1]==in && a[2][2]!=in && a[2][2]!=ni)
{a[2][2]=ni;i=i++;}
else if(a[0][2]==a[2][2] && i==0 && a[0][2]==in && a[1][2]!=in && a[1][2]!=ni)
{a[1][2]=ni;i=i++;}
else if(a[1][2]==a[2][2] && i==0 && a[1][2]==in && a[0][2]!=in && a[0][2]!=ni)
{a[0][2]=ni; }

if(a[1][1]!='x' && a[1][1]!='0' && i==0 )
{a[1][1]=ni;i=i++;       }

if(a[0][0]!='x' && a[0][0]!='0' && i==0)
{a[0][0]=ni;i=i++;      }
else if(a[0][2]!='0' && a[0][2]!='x' && i==0)
{a[0][2]=ni;i=i++;     }
else if(a[2][0]!='0' && a[2][0]!='x' && i==0)
{a[2][0]=ni;i=i++;   }
else if(a[2][2]!='0' && a[2][2]!='x' && i==0)
{a[2][2]=ni;}

	   }