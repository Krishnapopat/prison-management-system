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
void searchRecord()
{
	system("cls");
    FILE *fp ;
	char id[16], searchRecord;
    int recordEntry=0;

    do
	{
	    printf("\n\n\t************************************\n");
        printf("\t\t*THE SEARCHING MENU*");
        printf("\n\t************************************\n\n");

        fp = fopen ( "PrisonRecord", "rb" ) ;
        recordEntry=0;

        printf("\n\tEnter Prisoner ID: ");
        scanf("%s",&id);

        while (fread(&pr,sizeof(pr),1,fp) == 1)
        {
            if(strcmpi(pr.id,id)==0)
            {
                recordEntry=1;
                printf("\n\tThe Record is: ");
                printf("\n");
                printf("\n\tPrisoner's Name: %s",pr.name);
                printf("\n\tPrisoner's Gender: %s",pr.gender);
                printf("\n\tPrisoner's Age: %s",pr.age);
                printf("\n\tPrisoner's Weight: %s",pr.weight);
                printf("\n\tPrisoner's Height: %s",pr.height);
                printf("\n\tPrisoner's Crime: %s",pr.crime);
                printf("\n\tPrisoner's Lawyer: %s",pr.lawyer);
                printf("\n\tPrisoner's Conviction: %s",pr.punishment);
                printf("\n\tThe Date Punishment Started at: %s",pr.punishments);
                printf("\n\tThe Date Punishment Ends at: %s",pr.punishmente);
                printf("\n");
            }
        }

        if(recordEntry==0)
            printf("\n\tThis record does not exist in the system. Please check and retry again!");

        printf("\n\n\tWould you like to continue searching...(Y/N):");
        fflush(stdin);
        scanf("%c",&searchRecord);
        system("cls");
    } while(searchRecord=='Y'||searchRecord=='y');

    fclose (fp) ;
    printf("\n\n\tPress any key to exit...");
    getch();
    return ;
}

void viewRecord()
{
system("cls");
    FILE *fp;

    printf("\n\n\t************************************\n");
    printf("\t\t*LIST OF PRISONERS*");
    printf("\n\t************************************\n\n");

    fp=fopen("PrisonRecord","rb");
    rewind(fp);

    printf("Details of Prisoners\n");
    printf("\nID\tName\t\tGender\t\tAge\t\tWeight\t\tHeight\t\tCrime\t\tLawyer\t\tConviction\t\tPunishment Start\t\tPunishment End\n");

    while((fread(&pr,sizeof(pr),1,fp))==1)
    {
        printf("%s",pr.id);
        printf("\t%s",pr.name);
        printf("\t\t%s",pr.gender);
        printf("\t\t%s",pr.age);
        printf("\t\t%s",pr.weight);
        printf("\t\t%s",pr.height);
        printf("\t\t%s",pr.crime);
        printf("\t\t%s",pr.lawyer);
        printf("\t\t%s",pr.punishment);
        printf("\t\t        %s",pr.punishments);
        printf("\t\t\t%s",pr.punishmente);
        printf("\n");
    }
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
}
void editRecord()
{
    system("cls");
    FILE *fp,*ft ;
    char id[10],editRecord;
    int num,recordEntry=0;

    do
    {
        system("cls");
        printf("\n\n\t************************************\n");
        printf("\t\t *THE EDITING MENU*");
        printf("\n\t************************************\n\n");

        recordEntry=0;
        printf("\n\tEnter ID: ");
        scanf("%s",&id);

        fp = fopen ( "PrisonRecord", "rb+" ) ;
        if ( fp == NULL )
        {
            printf( "\nRecord does not exist!!" ) ;
            printf("\nPress any key to go back");
            getch();
            return;
        }

        ft=fopen("temp","wb+");
        if(ft==NULL)
        {
            printf("\n\tSystem Error");
            printf("\n\tPress any key to go back");
            getch();
            return;
        }

        while (fread(&pr,sizeof(pr),1,fp) == 1)
        {
            if(strcmp(pr.id,id)==0)
            {
                recordEntry=1;
                printf("\n\t--------------------");
                printf("\n\tTHE OLD RECORD WAS:\n");
                printf("\t--------------------\n");
                printf("\n\tPrisoner's Name: %s",pr.name);
                printf("\n\tPrisoner's Gender: %s",pr.gender);
                printf("\n\tPrisoner's Age: %s",pr.age);
                printf("\n\tPrisoner's Weight: %s",pr.weight);
                printf("\n\tPrisoner's Height: %s",pr.height);
                printf("\n\tPrisoner's Crime: %s",pr.crime);
                printf("\n\tPrisoner's Lawyer: %s",pr.lawyer);
                printf("\n\tPrisoner's Conviction: %s",pr.punishment);
                printf("\n\tThe Date Punishment Started at: %s",pr.punishments);
                printf("\n\tThe Date Punishment Ends at: %s",pr.punishmente);
                printf("\n\n\t\tWhat Would You Like To Edit...\n");

                printf("\n\t1.Name");
                printf("\n\t2.Gender");
                printf("\n\t3.Age");
                printf("\n\t4.Weight");
                printf("\n\t5.Height");
                printf("\n\t6.Crime");
                printf("\n\t7.Lawyer");
                printf("\n\t8.Conviction");
                printf("\n\t9.Starting Date Of Punishment");
                printf("\n\t10.Ending Date Of Punishment");
                printf("\n\t11.Whole Record");
                printf("\n\t12.Go Back To Main Menu");

                do
                {
                    printf("\n\n\tENTER YOUR CHOICE: ");
                    scanf("%d",&num);

                    switch(num)
                    {

                    case 1:
                        printf("\n\tEnter The New Data");
                        printf("\n\tName: ");
                        scanf("%s",&pr.name);
                        break;

                    case 2:
                        printf("\n\tEnter The New Data");
                        printf("\n\tGender: ");
                        scanf("%s",&pr.gender);
                        break;

                    case 3:
                        printf("\n\tEnter The New Data");
                        printf("\n\tAge: ");
                        scanf("%s",&pr.age);
                        break;

                    case 4:
                        printf("\n\tEnter The New Data");
                        printf("\n\tWeight: ");
                        scanf("%s",&pr.weight);
                        break;

                    case 5:
                        printf("\n\tEnter The New Data");
                        printf("\n\tHeight: ");
                        scanf("%s",&pr.height);
                        break;

                    case 6:
                        printf("\n\tEnter The New Data");
                        printf("\n\tCrime:");
                        scanf("%s",&pr.crime);
                        break;

                    case 7:
                        printf("Enter The New Data");
                        printf("\nLawyer: ");
                        scanf("%s",&pr.lawyer);
                        break;

                    case 8:
                        printf("\n\tEnter The New Data");
                        printf("\n\tConviction: ");
                        scanf("%s",&pr.punishment);
                        break;

                    case 9:
                        printf("\n\tEnter The New Data");
                        printf("\n\tStarting Date Of Punishment: ");
                        scanf("%s",&pr.punishments);
                        break;

                    case 10:
                        printf("\n\tEnter The New Data");
                        printf("\n\tEnding Date Of Punishment: ");
                        scanf("%s",&pr.punishmente);
                        break;

                    case 11:
                        printf("\n\tEnter The New Data");
                        printf("\n\tName: ");
                        scanf("%s",&pr.name);
                        printf("\n\tGender: ");
                        scanf("%s",&pr.gender);
                        printf("\n\tAge: ");
                        scanf("%s",&pr.age);
                        printf("\n\tWeight: ");
                        scanf("%s",&pr.weight);
                        printf("\n\tHeight: ");
                        scanf("%s",&pr.height);
                        printf("\n\tCrime: ");
                        scanf("%s",&pr.crime);
                        printf("\n\tLawyer: ");
                        scanf("%s",&pr.lawyer);
                        printf("\n\tConviction: ");
                        scanf("%s",&pr.punishment);
                        printf("\n\tThe Date Punishment Started at: ");
                        scanf("%s",&pr.punishments);
                        printf("\n\tThe Date Punishment Ends at: ");
                        scanf("%s",&pr.punishmente);
                        break;

                    case 12:
                        printf("\n\tPress any key to go back...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\n\tYou have typed something else...Try again\n");
                        break;
                    }

                } while(num<1 || num>12);

                system("cls");
                printf("\n\tEDITING COMPLETED...\n\n");
                printf("\t--------------------\n");
                printf("\tTHE NEW RECORD IS\n");
                printf("\t--------------------\n");
                printf("\n\tPrisoner's Name: %s",pr.name);
                printf("\n\tPrisoner's Gender: %s",pr.gender);
                printf("\n\tPrisoner's Age: %s",pr.age);
                printf("\n\tPrisoner's Weight: %s",pr.weight);
                printf("\n\tPrisoner's Height: %s",pr.height);
                printf("\n\tPrisoner's Crime: %s",pr.crime);
                printf("\n\tPrisoner's Lawyer: %s",pr.lawyer);
                printf("\n\tPrisoner's Conviction: %s",pr.punishment);
                printf("\n\tThe Date Punishment Started at: %s",pr.punishments);
                printf("\n\tThe Date Punishment Ends at: %s",pr.punishmente);
            }
            fwrite(&pr,sizeof(pr),1,ft);
        }
        fclose(ft);
        fclose(fp);
        remove("PrisonRecord");
        rename("temp","PrisonRecord");

        if(recordEntry==0)
        {
            printf("\n\tThe record does not exist!!\n");
        }
        printf("\n\n\tWould you like to edit another record...(Y/N)");
        fflush(stdin);
        scanf("%c",&editRecord);
    } while(editRecord=='Y'||editRecord=='y');

    printf("\n\tPress enter to exit editing menu");
    getch();
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

