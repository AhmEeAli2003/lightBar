#include<stdio.h>
#include<windows.h>
void gotoxy (int , int );
void DrawBox(void);
void FillInBox(void);
void color(int );
void hidecursor();
COORD coord={0,0}; //Set coordinates  to 0,0
void main(void)
{
    hidecursor();
    DrawBox();
    FillInBox();
}
void FillInBox(void)
{
    int position=1;
    char ch,check;
    do
    {
    color(15);
    gotoxy(41,11); printf("1] Add a new student     ");
    gotoxy(41,12); printf("2] Update an old student ");
    gotoxy(41,13); printf("3] Delete an old student ");
    gotoxy(41,14); printf("4] Exit                  ");
    switch(position)
    {
    case 1:
        color(240);
        gotoxy(41,11); printf("1] Add a new student     ");
        break;
    case 2:
        color(240);
        gotoxy(41,12); printf("2] Update an old student ");
        break;
    case 3:
        color(240);
        gotoxy(41,13); printf("3] Delete an old student ");
        break;
    case 4:
        color(240);
        gotoxy(41,14); printf("4] Exit                  ");
        if(check=getch()==13)
        {
            color(15);
            gotoxy(47,20); printf("Success :)\n\n");
            exit(0);
        }
        break;
    }
    ch=getch();
    if(ch==-32) ch=getch();
    if(ch==72)
    {
        position--;
        if(position==0) position=4;
    }
    if(ch==80)
    {
        position++;
        if(position==5) position=1;
    }
    }while(1);
}
void DrawBox(void)
{
    int i;
    gotoxy(40,10);printf("%c",201);
    for(i=0;i<25;i++) printf("%c",205);
    printf("%c",187);
    for(i=11; i<15;i++)
    {
      gotoxy(40,i);
      printf("%c",186);
    }
    gotoxy(40,15); printf("%c",200);
    for(i=0;i<25;i++) printf("%c",205);
    for(i=11; i<15;i++)
    {
      gotoxy(66,i);
      printf("%c",186);
    }
    gotoxy(66,15); printf("%c",188);
}
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color(int Color)
{
    HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE); //Handle to console window's context
    SetConsoleTextAttribute(console,Color); //240 To Set the color #white foreground #black background #To Opposite = 15
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

