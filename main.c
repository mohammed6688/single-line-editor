#include <stdio.h>
#include <stdlib.h>
#include "E:\iti\lec\C\MyLibrary.h"

#define Highlighted 0X60
#define Normal 0X07

#define ENTER 13
#define ESC 27
#define HOME 71
#define UP 72
#define PAGE_UP 73
#define LEFT 75
#define RIGHT 77
#define END 79
#define DOWN 80
#define PAGE_DOWN 81
#define TAB 9
#define size 30
#define DELETE 83
#define BACK 8
#define margen 12

void printArrayContent();

int i=0, cur = 0,end=0, ExitFlag = 0;
int *pcur,*pfir,*plas;
char arr[size]={'\0'};
char ch={'\0'};
int curr_temp=0,end_temp=0;
int main()
{
    gotoxy(margen,margen);
    do
    {
        textattr(Highlighted);
        for(int i;i<size;i++){
            printf(" ");
            if(i==size-1){
                gotoxy(margen,margen);
            }
        }

        textattr(Normal);

        ch = getch();
        switch(ch)
        {
        case -32:  ///case Extended key
            ch = getch();  ///read 1 byte from buffer
            switch(ch)
            {
            case HOME:
                gotoxy(margen,margen);
                break;
            case END:
                gotoxy(margen+cur,margen);
                break;
            case RIGHT:
                if(cur<end){
                    gotoxy(margen+cur+1,margen);
                    cur ++;
                }
                break;
            case LEFT:
                if(cur>0){
                    gotoxy(margen+cur-1,margen);
                    cur --;
                }
                break;
            case DELETE:
                if(cur<end){

                    curr_temp=cur;

                    while(curr_temp<=end){
                        arr[curr_temp-1]=arr[curr_temp];
                        curr_temp++;
                    }

                    end--;

                    gotoxy(margen+cur,margen);
                    curr_temp=cur;
                    while(curr_temp<end){
                        printf("%c",arr[curr_temp]);
                        curr_temp++;
                    }
                    printf(" ");
                    gotoxy(margen+cur,margen);



                    /*gotoxy(margen+cur+1,margen);
                    printf(" ");
                    arr[cur+1]=' ';
                    cur ++;*/
                }
                break;

            }
            break;  ///break of case extended key

        case ENTER: ///case Enter
            printArrayContent();
            break;
        case ESC: ///case ESC
            ExitFlag = 1;
            break;
        case BACK:
            if(cur>0){
                //gotoxy(margen+cur-1,margen);
                curr_temp=cur;

                while(curr_temp<=end){
                    arr[curr_temp-1]=arr[curr_temp];
                    curr_temp++;
                }
                cur --;
                end--;

                gotoxy(margen+cur,margen);
                curr_temp=cur;
                while(curr_temp<end){
                    printf("%c",arr[curr_temp]);
                    curr_temp++;
                }
                printf(" ");
                gotoxy(margen+cur-1,margen);
                //arr[cur-1]=' ';
            }
            break;


        default:
            if(cur<size){
                if(cur!=end){
                    end++;
                    curr_temp=cur;
                    end_temp=end;

                    while(curr_temp<=end_temp){
                        arr[end_temp]=arr[end_temp-1];
                        end_temp--;
                        if(curr_temp==end_temp-1){
                            arr[curr_temp]=ch;
                        }
                    }

                    curr_temp=cur;
                    end_temp=end;

                    while(curr_temp<=end_temp){
                        printf("%c",arr[curr_temp]);
                        curr_temp++;

                    }

                    gotoxy(margen+cur,margen);
                }else{
                    printf("%c",ch);
                    arr[cur]=ch;
                    if(cur==end){
                        end++;
                    }
                    cur++;
                }
            }
        }


    }while(ExitFlag == 0);
}

void printArrayContent(){
    printf("\n\n\n");
    printf("%s",arr);
}
