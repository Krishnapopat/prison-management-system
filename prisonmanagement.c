#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

void addRecord();

void viewRecord();

void editRecord();

void searchRecord();

void deleteRecord();

int login();

struct record
{
	char id[10];
    char name[30];
    char age[6];
    char gender[10];
    char weight[20];
    char height[20];
    char crime[40];
    char convictedf[20];
	char lawyer[20];
    char punishment[50];
    char punishments[20];
    char punishmente[20];
} pr;

int main()
{
    system("COLOR 0B");

    	int flag = login();
	if(flag == 1)
    {
        int ch;
        printf("\n\n\t************************************\n");
        printf("\t     *PRISON MANAGEMENT SYSTEM*\n");
        printf("\t************************************");

        while(1)
        {
            printf("\n\n\t\t      MAIN MENU:");
            printf("\n\n\tAdd Record\t[1]");
            printf("\n\tSearch Record\t[2]");
            printf("\n\tEdit Record\t[3]");
            printf("\n\tView Record\t[4]");
            printf("\n\tDelete Record\t[5]");
            printf("\n\tExit\t\t[6]");
            printf("\n\n\tEnter Your Choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1:
                    addRecord();
                    break;

                case 2:
                    searchRecord();
                    break;

                case 3:
                    editRecord();
                    break;

                case 4:
                    viewRecord();
                    break;

                case 5:
                    deleteRecord();
                    break;

                case 6:
                    system("cls");
                    printf("\n\n\t\tThank You\n\t\t ");
                    return 0;

                default:
                    printf("\n\tChoice Invalid!!");
                    printf("\n\tPress any key to try again");
                    getch();
                    break;
            }
            system("cls");
        }
	}
    return 0;
}

void addRecord()
{
    system("cls");
    FILE *fp ;
    char newRecord, id[10];
    int recordEntry;

    printf("\n\n\t************************************\n");
    printf("\t\t   *THE ADD MENU*");
    printf("\n\t************************************\n\n");

    fp = fopen("PrisonRecord", "ab+");
    if(fp == NULL)
    {
        printf("\nSystem Error...");
        printf("\nPress any key to exit");
        getch();
        return;
    }

    do
    {
        recordEntry=0;

		printf ( "\n\tEnter Prisoner ID: ");
        scanf("%s",&id);

		rewind(fp);

        while(fread(&pr, sizeof(pr), 1, fp)==1)
        {
            if(strcmp(pr.id,id)==0)
            {
                printf("\n\tThe record already exists.\n");
                recordEntry=1;
            }
        }

        if(recordEntry==0)
        {
            strcpy(pr.id,id);

            printf("\tEnter Prisoner Name: ");
            scanf("%s",&pr.name);

			printf("\tEnter Gender: ");
			scanf("%s",&pr.gender);

            printf("\tEnter Age: ");
            scanf("%s",&pr.age);

            printf("\tEnter Weight: ");
            scanf("%s",&pr.weight);

            printf("\tEnter Height: ");
            scanf("%s",&pr.height);

            printf("\tEnter Crime: ");
            scanf("%s",&pr.crime);

            printf("\tEnter Lawyer: ");
            scanf("%s",&pr.lawyer);

            printf("\tEnter Conviction: ");
            scanf("%s",&pr.punishment);

            printf("\tEnter The Date Punishment Started at: ");
            scanf("%s",&pr.punishments);

            printf("\tEnter The Date Punishment Ends at: ");
            scanf("%s",&pr.punishmente);

            fwrite(&pr, sizeof(pr), 1, fp);
            printf("\nThe record is added...\n");
        }
        printf( "\n\tWould you like to continue to add another record...(Y/N) " ) ;
        fflush(stdin);
        scanf("%c",&newRecord);
    }while(newRecord == 'Y'|| newRecord=='y');

    fclose(fp) ;
    printf("\n\tPress any key to exit...");
    getch();
}

int login()
{
	int attempts=0;
    char systemUsername[10];
    char systemPassword[10];
    char inputUsername[10]="admin";
    char inputPassword[10]="1234";

    do
    {
        printf("\n  **************************  LOGIN FORM  **************************  \n");
        printf(" \n                       ENTER USERNAME: ");
        scanf("%s", &systemUsername);
        printf(" \n                       ENTER PASSWORD: ");
        scanf("%s", &systemPassword);

        if(strcmp(systemUsername,inputUsername)==0 && strcmp(systemPassword,inputPassword)==0)
        {
            printf("  \n       Welcome to prison management system !! Your login was successful");
            printf("\n\n\t\t      Press any key to continue..");
            getch();
            system("cls");
            return 1;
        }
        else
        {
            printf("\n        Invalid Credentials !! Please Check Username and password\n");
            attempts++;
        }
    } while(attempts<=2);

    if (attempts>2)
    {
        printf("\nYou have reached maximum number of attempts !! Please try later.\n");
    }
    return 0;
}

void deleteRecord()
{
    system("cls");
    FILE *fp,*ft ;
    char deleteRecord ,id[16];
    char inputPassword[10],systemPassword[10]="admin23";
    int recordEntry=0;

    printf("\n\n\t************************************\n");
    printf("\t\t *THE DELETE MENU*");
    printf("\n\t************************************\n\n");

    printf("\n\tENTER PASSWORD: ");
    scanf("%s",&inputPassword);
    if (strcmpi(inputPassword,systemPassword)==0)
    {
        printf("\n\t*ACCESS GRANTED*\n\n");
        do
        {
            fp = fopen ("PrisonRecord", "rb" ) ;
            if ( fp == NULL )
            {
                printf("\n\tThe file does not exist");
                printf("\n\tPress any key to go back");
                getch();
                return;
            }
            ft=fopen("temp","wb");
            if(ft==NULL)
            {
                printf("\n\tSystem Error");
                printf("\n\tPress any key to go back");
                getch();
                return;
            }
            printf("\n\tEnter the ID of the record to be deleted: ");
            scanf("%s",id);
            while(fread(&pr,sizeof(pr),1,fp)==1)
            {
                if(strcmp(pr.id,id)!=0)
                    fwrite(&pr,sizeof(pr),1,ft);
                else
                    recordEntry=1;

            }
            fclose(ft);
            fclose(fp);
            remove("PrisonRecord");
            rename("temp","PrisonRecord");

            if(recordEntry==1)
                printf("\n\tDeleted Successfully...");

            else
                printf("\n\tThe record does not exist in the system so can't be deleted\n");

            printf("\n\tWould you like to delete another record...(Y/N):");
            fflush(stdin);
            scanf("%c",&deleteRecord);
        } while(deleteRecord == 'Y'|| deleteRecord=='y');

        printf("\n\n\tPress any key to exit...");
        getch();
    }
    else
    {
        printf("\n\tSorry!Invalid password\n");
        printf("\n\n\tPress any key to exit...");
        getch();
        return;
    }
}

