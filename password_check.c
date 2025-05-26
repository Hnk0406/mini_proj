#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

typedef struct users
{
    char user[100];
    char quest[100];
    char key[100];
}user;
typedef struct Web_dets
{
    char web_name[100];
    char username[100];
    char pass[100];
}web;
void strength(int lc,int uc,int sc,int n)
{
    if(lc>2)
    {
        if(uc>2)
        {
            if(sc>2)
            {
                if(n>2)
                {
                    printf("VERY STRONG PASSWORD\n");
                }
                else{
                    printf("STRONG PASSWORD\n");
                }
            }
            else{
                printf("MEDIUM PASSWORD\n");
            }
        }
        else{
            printf("WEAK PASSWORD\n");
        }
    }
    else
    {
        if(uc>2)
        {
            if(sc>2)
            {
                if(n>2)
                {
                    printf("STRONG PASSWORD\n");
                }
                else{
                    printf("MEDIUM PASSWORD\n");
                }
            }
            else{
                printf("WEAK PASSWORD\n");
            }
        }
        else{
            printf("VERY WEAK PASSWORD\n");
        }
    }
}
int strength_check(char *s)
{
    int lc=0,uc=0,sc=0,l,num=0;
    l= strlen(s);
    if(l<10)
    {   
        printf("PASSWORD SHOULD HAVE MINIMUM LENGTH OF 10\n");
        return 1;
    } 
    else 
    {
        for(int i=0 ;i<l;i++)
        {
            if(s[i]>='A'&& s[i]<='Z')
            {
                
                uc++;
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                
                lc++;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                num++;
            }
            else if(s[i] != '\n')
            {
                sc++;
            }
        }
        if(uc==0)
        {
            printf("PASSWORD MUST CONTAIN A UPPER CASE\n");
            return 1;
        }
        else if(lc==0)
        {
            printf("PASSWORD MUST CONTAIN A LOWER CASE\n");
            return 1;
        }
        else if(num==0)
        {
            printf("PASSWORD MUST CONTAIN A NUMBER\n");
            return 1;
        }
        else if (sc==0)
        {
            printf("PASSWORD MUST CONTAIN A SPECIAL CHARACTER\n");
            return 1;
        }


    }
    strength(lc,uc,sc,num);
    return 0;
}
void generatePassword(char *password)
{
    
    int length;
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char specialCharacters[] = "!@#$%^&*()-_=<>?/";

    int upperCount = 0, lowerCount = 0, numCount = 0, specialCount = 0;

    srand(time(NULL)); 
    length = (rand() % 20) + 10;

    password[0] = uppercase[rand() % (sizeof(uppercase) - 1)];
    password[1] = lowercase[rand() % (sizeof(lowercase) - 1)];
    password[2] = numbers[rand() % (sizeof(numbers) - 1)];
    password[3] = specialCharacters[rand() % (sizeof(specialCharacters) - 1)];

    upperCount = lowerCount = numCount = specialCount = 1;

    for (int i = 4; i < length; i++) {
        int category = rand() % 4;
        if (category == 0) {
            password[i] = uppercase[rand() % (sizeof(uppercase) - 1)];
            upperCount++;
        } else if (category == 1) {
            password[i] = lowercase[rand() % (sizeof(lowercase) - 1)];
            lowerCount++;
        } else if (category == 2) {
            password[i] = numbers[rand() % (sizeof(numbers) - 1)];
            numCount++;
        } else {
            password[i] = specialCharacters[rand() % (sizeof(specialCharacters) - 1)];
            specialCount++;
        }
    }

    password[length+1] = '\0'; 
}
void write_e(web w[],const char *s,int l)
{
    FILE *file = fopen(s, "w");
    if (file == NULL) {
        perror("Error opening file");
        
    }

    
    fprintf(file, "website,username,password\n");


    for (int i = 0; i < l; i++) {
        fprintf(file,"%s,%s,%s\n",w[i].web_name,w[i].username,w[i].pass);
    }

    fclose(file);

    

    
}

void write(web w,const char *s)
{
    FILE *f1=fopen(s,"a");
    if(f1 == NULL)
    {
        printf("FILE NOT FOUND\n");
        exit(2);
    }
    fprintf(f1,"%s,%s,%s\n",w.web_name,w.username,w.pass);
    fclose(f1);
}

void write_u(user w)
{
    FILE *f1=fopen("C:\\MinGW\\c#\\mini_project\\users.csv","a");
    fprintf(f1,"%s,%s,%s\n",w.user,w.quest,w.key);
    fclose(f1);
    char add[200];
    strcpy(add,"C:\\MinGW\\c#\\mini_project\\");
    strcat(add,w.user);
    strcat(add,".csv");
    const char *address = add;
    FILE *f=fopen(address,"w");
    fprintf(f,"%s,%s,%s\n","website","username","password");
    fclose(f);
}
void search(char k[],const char *add)
{
    FILE *fp=fopen(add,"r");
    char a[100];       
    fgets(a,sizeof(a),fp);
    char *tok;
    web *s = (web *)malloc(100 * sizeof(web));
    int i=0;
    while(fgets(a,sizeof(a),fp))
    {
        tok=strtok(a,",");
            if(tok !=NULL && tok != "\n")
            {
            strcpy(s[i].web_name,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL && tok != "\t")
            {
            strcpy(s[i].username,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL && tok != "\n")
            {
                if (tok[strlen(tok) - 1] == '\n')
                {
                    tok[strlen(tok) - 1] = '\0'; 
                }
                strcpy(s[i].pass,tok);
            }
            i++;
    }
    int l= i;
    int flag=0;
    for(i=0;i<l;i++)
    {
        if(strcmp(s[i].web_name,k)== 0)
        {   
            printf("PASSWORD IS: %s\n",s[i].pass);
            flag++;
        }
        
    }
    if(flag==0){
        printf("NO WEBSITE FOUND\n");
    }
    free(s);

}
void edit(char k[],const char *add)
{
    FILE *fp=fopen(add,"r");
    char a[100];       
    fgets(a,sizeof(a),fp);
    char *tok;
    web *s = (web *)malloc(100 * sizeof(web));
    int i=0;
    while(fgets(a,sizeof(a),fp))
    {
         tok=strtok(a,",");
            if(tok !=NULL && tok != "\n")
            {
            strcpy(s[i].web_name,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL && tok != "\t")
            {
            strcpy(s[i].username,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL && tok != "\n")
            {
                if (tok[strlen(tok) - 1] == '\n')
                {
                    tok[strlen(tok) - 1] = '\0'; 
                }
                strcpy(s[i].pass,tok);
            }
            i++;
    }
    int q=i;
    int flag=0;
    for(i=0;i<q;i++)
    {
        if(strcmp(s[i].web_name,k)== 0)
        {   do
                {   int count=0;
                    fflush(stdin);
                    count++;
                    if (count>2)
                    {   
                    char ans;
                    do{
                        fflush(stdin);
                        printf("DO YOU WANT TO GENERATE A RANDOM PASSWORD\nY/N:");
                        scanf("%c",&ans);
                    }while(ans != 'Y' && ans!='N');
                    if(ans == 'Y')
                        {
                            do 
                            {
                                generatePassword(s[i].pass);
                            } while (strength_check(s[i].pass));
                            printf("Generated Password: %s\n", s[i].pass);
                            break;

                        }
                    }
                    fflush(stdin);
                    printf("ENTER THE PASSWORD: ");
                    scanf("%[^\n ]s",&s[i].pass);
                }while(strength_check(s[i].pass));
            flag++;
        }
        
    }
    if(flag==0){
        printf("NO WEBSITE FOUND\n");
    }
    write_e(s,add,q);
    printf("DETAILS STORED SUCCESFULLY\n");
    free(s);

}
int verify(char *use)
{
    FILE *fp=fopen("C:\\MinGW\\c#\\mini_project\\users.csv","r");
    if (fp == NULL) 
    {
        printf("FILE NOT FOUND\n");
        return 0;
    }
    else
    {

        char a[100],key[100];       
        fgets(a,sizeof(a),fp);
        char *tok;
        user s[100];
        int i=0;
        
        while(fgets(a,sizeof(a),fp))
        {
            tok=strtok(a,",");
            if(tok !=NULL || tok != "\n")
            {
            strcpy(s[i].user,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL || tok != "\t")
            {
            strcpy(s[i].quest,tok);
            }
            tok=strtok(NULL,",");
            if(tok !=NULL || tok != "\n")
            {
                if (tok[strlen(tok) - 1] == '\n')
                {
                    tok[strlen(tok) - 1] = '\0'; 
                }
                strcpy(s[i].key,tok);
            }
            i++;
        }
        
        int l=sizeof(s)/sizeof(user);
        int FL= -1;
        for(i=0;i<l;i++)
        {
            if(strcmp(s[i].user,use)== 0)
            {   
                FL=i;
            }           
        }
        if(FL == -1)
        {
            printf("USER NOT FOUND\n");
            fclose(fp);
            return 1;
        }
        fflush(stdin);
        printf("%s\n",s[FL].quest);
        scanf("%[^\n]s",key);
        if(strcmp(key,s[FL].key) == 0)
        {
            fclose(fp);
            return 2;
        }
        else
        {
            printf("WRONG KEY\n");
            fclose(fp);
            return 3;
        }
    }
 
}
int main()
{   web w;
    int n,stat;
    char s[100];
    int count=0;
    printf("CHOOSE OPTION\nSIGN IN:1\nSIGN UP:2\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {   
        fflush(stdin);
        printf("ENTER THE USERNAME: ");
        scanf("%[^\n]s",&s);
        do{
            count++;
            stat=verify(s);
            if(stat==1)
            {
                fflush(stdin);
                printf("ENTER THE USERNAME: ");
                scanf("%[^\n]s",&s);
            }
           
        }while( stat != 2 && count<3);
        if(stat == 2)
        {   
            char add[200];
            strcat(add,"C:\\MinGW\\c#\\mini_project\\");
            strcat(add,s);
            strcat(add,".csv");
            const char *address =add;
            char t[10];
            do
            { 
                
                fflush(stdin);
                printf("CHOOSE AN OPTION\nTO SAVE A NEW PASSWORD:1\nSEARCH FOR A PASSWORD:2\nEDIT PASSWORD:3\n");
                scanf("%d",&n);
                switch(n)
                {
                    case 1:
                    {   
                        
                            int count=0;
                        fflush(stdin);
                        printf("ENTER THE WEBSITE NAME: ");
                        scanf("%[^\n]s",&w.web_name);
                        fflush(stdin);
                        printf("ENTER THE USERNAME: ");
                        scanf("%[^\n]s",&w.username);
                        do
                        {
                            fflush(stdin);
                            count++;
                            if (count>2)
                            {   
                            char ans;
                            do{
                                fflush(stdin);
                                printf("DO YOU WANT TO GENERATE A RANDOM PASSWORD\nY/N:");
                                scanf("%c",&ans);
                            }while(ans != 'Y' && ans!='N');
                            if(ans == 'Y')
                                {
                                    do 
                                    {
                                        generatePassword(w.pass);
                                    } while (strength_check(w.pass));
                                    printf("Generated Password: %s\n", w.pass);
                                    break;

                                }
                            }
                            fflush(stdin);
                            printf("ENTER THE PASSWORD: ");
                            scanf("%[^\n ]s",&w.pass);
                        }while(strength_check(w.pass));
                        write(w,address);
                        printf("DETAILS STORED SUCCESFULLY\n");
                        break;
                    }
                    case 2:
                    {   
                        char key[100];
                        fflush(stdin);
                        printf("ENTER THE WEBSITE TO BE SEARCHED\n");
                        scanf("%[^\n]s",&key);
                        char pass[100];
                        search(key,address);
                        break;
                    }
                    case 3:
                    {
                        char key[100];
                        fflush(stdin);
                        printf("ENTER THE WEBSITE TO BE SEARCHED\n");
                        scanf("%[^\n]s",&key);
                        char pass[100];
                        edit(key,address);
                        break;
                    }
                    default: {printf("INVALID CHOICE");break;}

                }
                fflush(stdin);
                printf("TYPE EXIT TO END THE PROGRAM\nTYPE ANYTHING ELSE TO CONTINUE\n");
                scanf("%s",&t);
            }while(strcmp(t,"exit")!=0 && strcmp(t,"EXIT")!=0);
        }
        else 
        {
            printf("TERMINATING EXECUTION DUE TO TOO MANY TRIES\n");
        }
        break;
    }
    case 2:
    {
        user u;
        fflush(stdin);
        printf("ENTER THE USERNAME: ");
        scanf("%[^\n]s",&u.user);
        fflush(stdin);
        printf("ENTER THE VERIFICATION QUESTION: ");
        scanf("%[^\n]s",&u.quest);
        fflush(stdin);
        printf("ENTER THE KEY: ");
        scanf("%[^\n]s",&u.key);
        write_u(u);
        printf("DETAILS STORED SUCCESFULLY\n");
        break;
    }
    default:{printf("INVALID CHOICE");break;}
    }

}