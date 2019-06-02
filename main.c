#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
void newScoreSheet();
void openScoreSheet();
void readScore();
FILE *fp;

int main()
{
    int choice;
    printf("\t\t\t\t\t\tHello!!\n");
    Sleep(2000);
    system("@cls");
    printf("\t\t\t\tCricket Score Sheet\n");
    printf("\t\t\t\t1.New score sheet\n");
    printf("\t\t\t\t2.View score sheet\n");
    printf("\t\t\t\t3.Exit\n");
    printf("\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);
    switch(choice){
case 1:
  newScoreSheet();
  fprintf(fp,"0");
    break;
case 2:
  openScoreSheet();
    break;
case 3 :
    exit(0);
default :
    printf("\n\t\t\t\tYour choide is invalid\n\n\t\t\t\t\tThank You");
    }
    printf("\n\t\t\t\t\t**********\n");
    getch();
    return 0;
}
char firstteam[30]="",secondteam[30]="";
void newScoreSheet(){
  char comname[30]="",venuename[30]="",tosswinner[30]="";
  int tosswin=1,choice=1,date=0,month=0,year=0,matchtype=0,i=0,decission = 0,dateCount=1,winner=0;

  printf("Enter competition name\n");
  scanf(" %[^\n]",comname);
  strcat(comname,".txt");
  fp = fopen(comname,"w");
  printf("Enter the venue name\n");
  scanf(" %[^\n]",venuename);
  fprintf(fp, "%s\n",venuename);
  printf("Enter the name of first team\n");
  scanf(" %[^\n]",firstteam);
  printf("Enter the name of second team\n");
  scanf(" %[^\n]",secondteam);
  fprintf(fp,"%s\n%s\n",firstteam,secondteam);
  do{
    printf("Enter toss winner team number\nTeam 1 : %s\nTema 2 : %s\n",firstteam,secondteam);
    scanf("%d",&tosswin);
    if(tosswin == 1)
          fprintf(fp,"%s\n",firstteam);
    else if(tosswin == 2)
          fprintf(fp, "%s\n",secondteam );
    else
    printf("Invalid choice!!\nPlease try again\n\n");
  }
  while(tosswin != 1 && tosswin != 2);{}

  do{
    printf("Elected chice of toss winner team\nChoice 1 : Bat\nChoice 2 : Bowl\n");
    scanf("%d",&choice);
    if(choice == 1)
      fprintf(fp,"Bat\n");
    else if(choice == 2)
      fprintf(fp,"Bowl\n");
    else
      printf("Invalid choice!!\nPlease try again\n\n");
  }
  while(choice != 1 && choice != 2);{}

  do{
    printf("Who is the winner of the game\nTeam 1 : %s\nTema 2 : %s\n",firstteam,secondteam);
    scanf("%d",&winner);
    if(winner == 1)
          fprintf(fp,"%s\n",firstteam);
    else if(winner == 2)
          fprintf(fp, "%s\n",secondteam );
    else
    printf("Invalid choice!!\nPlease try again\n\n");
  }
  while(winner != 1 && winner != 2);{}

  do{
    if(dateCount >1)
      printf("Sorry:(\n Please try again\n");
  printf("Enter match date in the format dd/mm/yyyy\n");
  scanf("%d/%d/%d",&date,&month,&year);
  fprintf(fp,"%d/%d/%d\n",date,month,year);
  decission = 0;
  if(year<=1 || month <= 1 || date <= 1)
    decission = 1;
  else{

  if(year%4 == 0 || year%400 == 0){
    if(month == 2){
      if(date > 29)
        decission = 1;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
      if(date > 31)
        decission = 1;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
      if(date> 30)
        decission = 1;
  }
  else{
    if(month == 2 && date>28)
      decission = 1;
  }
  if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    if(date > 31)
      decission = 1;
  }
  if(month == 4 || month == 6 || month == 9 || month == 11)
    if(date> 30)
      decission = 1;
    }
  dateCount++;

}
  while(decission);

  do{
    printf("Enter match type\nTest\t\t[1]\nOne day\t\t[2]\t\t\nT 20\t\t[3]\n");
    scanf("%d",&matchtype);
    if(matchtype == 1){
        readScore();
        readScore();}
    else if(matchtype == 2)
      readScore();
    else if (matchtype == 3)
      readScore();
    else
      printf("Invalid Choice!!\nPlease try again\n\n");
  }
  while(matchtype !=1 && matchtype != 2 && matchtype != 3);{}

}
 void readScore(){
    int i,frunsbatsman[11],frunsbowler[8],n,overs,srunsbatsman[11],srunsbowler[8],four,six,economy,maidens,noballs;
    int wickets=0;
    static int inningnum=1;
    char fnamebatsman[20][20],fnamebowler[15][20],snamebatsman[20][20],snamebowler[15][20];
    printf("\t\tInnings number %d\n",inningnum);
    printf("\t\t\t%s\n",firstteam);
    printf("Enter number of batsman scored in this inning\n");
    scanf("%d",&n);
    if(inningnum == 1)
      fprintf(fp,"1\n");
    else if(inningnum == 2)
      fprintf(fp, "2\n");
    fprintf(fp,"%d\n",n);
    for(i=1;i<=n;i++){
      printf("Enter name and follwed by score of batsman %d \n",i);
      scanf(" %[^\n]",&fnamebatsman[i-1]);
      scanf("%d",&frunsbatsman[i-1]);
      printf("Enter number of fours and sixes made by him\n");
      scanf("%d %d",&four,&six);
      if((4*four + 6*six)>frunsbatsman[i-1]){
        printf("Sorry:(\nPlease try again\n");i--;}
      else
        fprintf(fp,"%s\n%d\t%d\t%d\n",fnamebatsman[i-1],frunsbatsman[i-1],four,six);
    }
    printf("Enter number of bowlers bowled in this inning\n");
    scanf("%d",&n);
    fprintf(fp,"%d\n",n);
    for(i=1;i<=n;i++){
      printf("Enter name and number of overs and score given by the bowler %d\n",i);
      scanf(" %[^\n]",&fnamebowler[i-1]);
      scanf("%d %d",&overs,&frunsbowler[i-1]);
      printf("Enter maidens, number of no balls, economy and number of wickets taken\n");
      scanf("%d %d %d %d",&maidens,&noballs,&economy,&wickets);
      fprintf(fp,"%s\n%d\t%d\t%d\t%d\t%d\t%d\n",fnamebowler[i-1],overs,frunsbowler[i-1],maidens,noballs,economy,wickets);
    }

    printf("\t\t\t%s\n",secondteam);
    printf("Enter number of batsman scored in this inning\n");
    scanf("%d",&n);
    fprintf(fp,"%d\n",n);
    for(i=1;i<=n;i++){
      printf("Enter name and follwed by score of batsman %d \n",i);
      scanf(" %[^\n]",&snamebatsman[i-1]);
      scanf("%d",&srunsbatsman[i-1]);
      printf("Enter number of fours and sixes made by him\n");
      scanf("%d %d",&four,&six);
      if((4*four + 6*six)> srunsbatsman[i-1]){
        printf("Sorry:(\nPlease try again\n");i--;}
      else
        fprintf(fp,"%s\n%d\t%d\t%d\n",snamebatsman[i-1],srunsbatsman[i-1],four,six);
    }
    printf("Enter number of bowlers bowled in this inning\n");
    scanf("%d",&n);
    fprintf(fp,"%d\n",n);
    for(i=1;i<=n;i++){
      printf("Enter name and number of overs and score given by the bowler %d\n",i);
      scanf(" %[^\n]",&snamebowler[i-1]);
      scanf("%d %d",&overs,&srunsbowler[i-1]);
      printf("Enter maidens, number of no balls, economy and number of wickets taken\n");
      scanf("%d %d %d %d",&maidens,&noballs,&economy,&wickets);
      fprintf(fp,"%s\n%d\t%d\t%d\t%d\t%d\t%d\n",snamebowler[i-1],overs,srunsbowler[i-1],maidens,noballs,economy,wickets);
    }
    inningnum++;
}

void openScoreSheet(){
  char competition[30]="",temp[30]="",ft[30] = "",st[30] = "";
  FILE *fp1;
  int d,m,y,i,score,overs,j=0,four,six,economy,maidens,noballs,sum=0,wick=0;
  printf("Enter the name of the competition correctly\n");
  scanf(" %[^\n]",competition);
  strcat(competition,".txt");
  fp1 = fopen(competition,"r");
  if(fp1 == NULL)
    printf("Sorry!! :(\nFile dosen't exist\n");
  else{
  fscanf(fp1," %[^\n]",&temp);
  printf("Venue\t\t:\t%s\n",temp);
  fscanf(fp1," %[^\n]",&ft);
  printf("First Team\t:\t%s\n",ft);
  fscanf(fp1," %[^\n]",&st);
  printf("Second Team\t:\t%s\n",st);
  fscanf(fp1," %[^\n]",&temp);
  printf("Toss Winner\t:\t%s\n\n\n\t%s choosed to ",temp);
  fscanf(fp1," %[^\n]",temp);
  printf("%s\n\n",temp);
  fscanf(fp1," %[^\n]",temp);
  printf("%s won the match\n",temp);
  fscanf(fp1,"%d/%d/%d\n",&d,&m,&y);
  printf("\tMatch started on %d/%d/%d\n\n",d,m,y);
  fscanf(fp1,"%d\n",&y);
  printf("\t\t\t\tInning number %d\n",y);
while(y !=0){

  if(j == 2){
    printf("\t\t\t\tInning number 2\n");
    fscanf(fp1,"2\n%d",&y);
  }
  else
  fscanf(fp1,"%d\n",&y);
  if(j%2 == 0)
  printf("\t\t\t\t%s\n",ft);
  else
  printf("\t\t\t\t%s\n\n",st);
  printf("\n\t\t\t\tBatsmen\n");
  printf("----------------------------------------\n");
  printf("Name\t\t\tScore\tfours\tsixes\n");
  printf("----------------------------------------\n");
  for(i=1;i<=y;i++){
    fscanf(fp1," %[^\n]",&temp);
    fscanf(fp1,"%d\t%d\t%d",&score,&four,&six);
    printf("%s\t\t%d\t%d\t%d\n",temp,score,four,six);
    printf("----------------------------------------\n");
    sum+=score;
  }
  printf("\n\tTotal Score\t%d\n",sum);
  sum=0;
  fscanf(fp1,"%d\n",&y);
  printf("\n\t\t\t\tBowlers\n");
  printf("---------------------------------------------------------------------------------------\n");
  printf("Name\t\t\tOvers\tGiven Score\tMaidens\t\tNo balls\tEconomy\tWickets\n");
  printf("---------------------------------------------------------------------------------------\n");
  for(i=1;i<=y;i++){
    fscanf(fp1," %[^\n]",&temp);
    fscanf(fp1,"%d\t%d\t%d\t%d\t%d\t%d\n",&overs,&score,&maidens,&noballs,&economy,&wick);
    printf("%s\t\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",temp,overs,score,maidens,noballs,economy,wick);
    printf("---------------------------------------------------------------------------------------\n");
  }
  printf("\n\n===========================================================\n");
  printf("===========================================================\n\n");
  fscanf(fp1,"%d",&y);
  j++;

}

  fclose(fp1);
}
}
