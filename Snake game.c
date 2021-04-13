#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int height=20, width=20,gameOver,flag;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int countTail=0;

void action()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 'd':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 's':
            flag=4;
            break;
        case 'x':
            gameOver=1;
            break;

        }
    }
}

void makeConcept()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prevX2;
    int prevY2;
    tailX[0]=x;
    tailY[0]=y;

    for(i=1;i<countTail;i++)
    {
        prevX2=tailX[i];
        prevY2=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prevX2;
        prevY=prevY2;
    }




    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;

    default:
        break;
    }

    if(x<0||x>width||y<0||y>height)
        gameOver=1;

        for(i=0;i<countTail;i++)
        {
            if(x==tailX[i]&&y==tailY[i])
                gameOver=1;
        }

        if(x==fruitX && y==fruitY)
        {
           label3:
        fruitX=rand()%20;
        if(fruitX==0)
        goto label3;

    label4:
        fruitY=rand()%20;
        if(fruitY==0)
        goto label4;

        score+=10;
        countTail++;
        }
}

void setup()
{
  x=width/2;
  y=height/2;


  label1:
        fruitX=rand()%20;
        if(fruitX==0)
        goto label1;

    label2:
        fruitY=rand()%20;
        if(fruitY==0)
        goto label2;

        score=0;
}

void boundary()
{
    int i,j,k;
    system("cls"); //for clear screen
    for(i=0;i<width;i++)
    {
       for(j=0;j<height;j++)
       if(i==0||i==height-1||j==0||j==width-1)
        {
          printf("*");
        }
       else
       {
           if(i==x&&j==y)
           {
             printf("O");
           }

           else if(i==fruitX&& j==fruitY)
           {
              printf("F");
           }

           else
            {
                int ch=0;
                for(k=0;k<countTail;k++)
                {
                    if(i==tailX[k]&& j==tailY[k])
                    {
                        printf("o");
                        ch++;
                    }
                }
                if(ch==0)
                printf(" ");
            }


       }
       printf("\n");
    }
    printf("SCORE=%d",score);

}


int main()
{
   int m,n;
    setup();

     while(!gameOver)
     {
        boundary();
        action();
        makeConcept();

        for(m=0;m<1000;m++)
            {
            for(n=0;n<10000;n++)
            {

            }
            }

            for(m=0;m<100;m++){
                for(n=0;n<1000;n++){}
            }


     }

    return 0;
}

