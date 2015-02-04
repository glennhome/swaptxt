#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h> 
struct addressList 
{
    char ext[15];
    char firstname[15];
    char name[15];
    char tel[15];
};

char s[15];
char letter[15];
int element=0,number=0;    // for loop counter
int	ARRAY_SIZE=35; 
typedef struct addressList IDD;
IDD member[35]; // struct array for write
IDD tmp;
void DatatoStruct(void);
void Debugmessage(void);
void sort(int);
void StrcpySwapStrings(int);
void StoretoFile(void);
FILE *fp;                     // file handle
FILE *fp2=fopen("homework2.txt","w");
 int main() 
 {	  
	  	  // printf("%d ",'a');
		   //printf("%d ",'z');
		   //printf("%d ",'A');
		   //printf("%d ",'d');
	 printf("請輸入要搜尋的字母:");
	 scanf("%s",letter);
     //printf("scanf:%s",letter);
       if (!(fp = fopen("homework.txt", "r")))
                 return -1;      
	
       while(fscanf(fp,"%s",s)!=EOF)
       {                    
                 DatatoStruct();
       }

       sort(ARRAY_SIZE);         
  
       Debugmessage();
		
	   StoretoFile();

       fclose(fp);
		
	   system("pause");
       return 0;
		
	   //system("pause");
	
 }

 

void sort(int ARRAY_SIZE)
{
	int i,j;
	//char tmp[15];
	//IDD tmp[35];
	//printf("%c\n",member[0].firstname[0]);
	//sprintf("%c\n",member[1].firstname[0]);
        for (i = 0; i < ARRAY_SIZE; i++) 
	{
       		 for (j = ARRAY_SIZE - 1; j > i; j--) 
		{
           		 if (strcmp(member[j].firstname ,member[j-1].firstname)==-1)
			{	
           			 StrcpySwapStrings(j);
			}
			
        		}
        	}		 
	
}

void StrcpySwapStrings(int j)
{
	memcpy(&tmp ,&member[j-1],sizeof(member[j-1]));
 	memcpy(&member[j-1],&member[j],sizeof(member[j]));
  	memcpy(&member[j],&tmp,sizeof(tmp));
	
//	printf("%d ",sizeof(member[j-1]));
//	printf("%d ",sizeof(member[j]));
//	printf("%d \n",sizeof(tmp));



}
	
 void DatatoStruct()
 {
          switch(element)
           {
                     case 0:
                                strcpy(member[number].ext, s);
			      strcat ( member[number].ext,"\t");					
                                //printf("%s\n", member[number].ext);                     
                                break;
                     case 1:
                                strcpy(member[number].firstname, s);
                                //printf("%s\n", member[number].firstname);
                                break;
                     case 2:
				strcpy(member[number].name ,s);
				strcat ( member[number].firstname," ");	
				strcat ( member[number].firstname,member[number].name);
				strcat ( member[number].firstname,"\t");
                                //printf("%s\n", member[number].name);
                                break;
                     case 3:
                                strcpy(member[number].tel, s);
			     strcat ( member[number].tel,"\n");					
                                //printf("%s\n", member[j].tel);
                                break;
           }
           element++;
           if(element==4)
           {
                     element=0;
                     number++;
           }
 }

 

 void Debugmessage()
 {
	//printf("struct element:%d\n",letter-32);
	//printf("memer number:%d\n",member[0].firstname[0]);
           for(number = 0; number < 35; ++number) 
		   {
			   
				if(!stricmp(letter,"All"))
				{
				printf("%s ", member[number].firstname);
				printf("%s", member[number].ext);
				printf("%s", member[number].tel);
				}
				//else if(!strncmp(member[number].firstname,letter,1))
			   else if((member[number].firstname[0]==letter[0]-32)||(member[number].firstname[0]==letter[0]))
				{
				printf("%s ", member[number].firstname);
				printf("%s", member[number].ext);
				printf("%s", member[number].tel);
				}
			
				
				
           }
	
		   //if(letter[0]<)
 }

void StoretoFile()
{
		for(number = 0; number < 35; ++number) 
		{
		fputs(member[number].firstname,fp2);
		fputs(member[number].ext,fp2);
		fputs(member[number].tel,fp2);
        }
}
