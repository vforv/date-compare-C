#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int getValue(char * date1,char * data2);
int getMonthNum(char * name);

int main()
{
    int which;
    which = getValue("16-Mar-2002","14-Jun-2001");
    printf(" %d",which);
    return 0;
}

struct datum{
    int * day;
    int * month;
    int * year;
};


int getValue(char * date1,char * date2){
    struct datum prvi;
    struct datum drugi;


    char * token;
    int br =1;
    char* tofree;
    char *string = strdup(date1);
    tofree = string;
    token = strtok(string, "-");
          while (token != NULL)
          {
              if(br == 1){
               prvi.day = token;
              }else if(br == 2){
              prvi.month = token;
              }else if(br == 3){
                prvi.year = token;
              }
              token = strtok(NULL,"-");
              br++;
          }


    char * token1;
    int br1 =1;
    char* tofree1;
    char *string1 = strdup(date2);
    tofree1 = string1;
    token1 = strtok(string1, "-");

          while (token1 != NULL)
          {
              if(br1 == 1){
               drugi.day = token1;
              }else if(br1 == 2){
                drugi.month = token1;
              }else if(br1 == 3){
                drugi.year = token1;
              }
              token1 = strtok(NULL,"-");
              br1++;
          }
          int monthToIntPrvi = getMonthNum(prvi.month);
          int monthToIntDrugi = getMonthNum(drugi.month);

        if(strcmp(prvi.year, drugi.year)>0){

                return 1;
        }else if(strcmp(prvi.year, drugi.year)<0){

            return 0;
        }else if(strcmp(prvi.year, drugi.year)==0){

            if(monthToIntPrvi > monthToIntDrugi){
                return 1;
            }else if(monthToIntPrvi < monthToIntDrugi){
                return 0;
            }else if(monthToIntPrvi == monthToIntDrugi){
                if(strcmp(prvi.day, drugi.day) >0){
                    return 1;

                }else if(strcmp(prvi.day, drugi.day) < 0){
                    return 0;
                }else if(strcmp(prvi.day, drugi.day) == 0){
                    return 1;
                }
            }
        }


        free(tofree1);
        free(tofree);


}


int getMonthNum(char * name){
char *months[12] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char *pointertoarray = &months;
int i;
    for(i = 1; i <= 12; i++){
        if(strcmp(months[i], name)==0){
            return i;
        }
    }
}
