/*
 * main.c
 *
 *  Created on: May 29, 2023
 *      Author: DELL
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define  DPRINTF(...)    {fflush(stdout); \
	                     fflush(stdin); \
	                     printf(__VA_ARGS__); \
	                     fflush(stdout);  \
	                     fflush(stdin);}
void Get_Nth_Student();
void Find_Num_of_Student(); /* using iterative method */
void GET_the_Nth_STUDENT_DATA_FROM_THE_END();
void Middle_of_List();
int Detect_List_Loop();
void Reverse_List();
/* effective data */
struct Sdata
{
	int ID ;
	char name[40] ;
	float height ;
};
/* linked list node */
struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextStudent ;
};

struct SStudent* gpFirstStudent= NULL ;

void AddStudent ()
{
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text[40] ;
	/* check list is empty == yes */
	if (gpFirstStudent == NULL)
	{
		/* creat new record */
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		/* assign it to gpfirst */
		gpFirstStudent = pNewStudent ;
	}else /* list contain records */
	{
		/* navigate until reach to the last record */
		pLastStudent = gpFirstStudent;
		while (pLastStudent->PNextStudent)
			pLastStudent =pLastStudent->PNextStudent;
		/* create new record   */
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent ;
	}
	/* fill new record */
	DPRINTF("\n Enter the ID: ");
	gets (temp_text);
	pNewStudent->student.ID = atoi (temp_text);

	DPRINTF("\n Enter student full name: ");
	gets (pNewStudent->student.name);

	DPRINTF("\n Enter the height: ");
	gets (temp_text);
	pNewStudent->student.height = atof (temp_text);

	/* set the next pointer (new_student) null */
	pNewStudent->PNextStudent = NULL ;
}


 int delete_student()
{
	char temp_text[40];
	unsigned int selected_id ;
	/* get the selected id */
	DPRINTF("\n enter the student id to be deleted: ");
	gets (temp_text);
	selected_id = atoi (temp_text);

	/* list is not empty */
	if (gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;

		/* LOOP ON ALL RECORDS */
		while(pSelectedStudent)
		{
			/* compare each node with the selected ID */
			if (pSelectedStudent->student.ID == selected_id )
			{
				if(pPreviousStudent) /* the first is not the selected one */
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}else /* 1st student == ID */
			    {
				  gpFirstStudent = pSelectedStudent->PNextStudent;
			    }
			    free (pSelectedStudent);
			    return 1;
			}
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
	}
	DPRINTF("\n cannot find student ID.");
	return 0;
}


 void view_students()
 {
	 struct SStudent* pcurrentStudent = gpFirstStudent ;
	 int count=0;
	 if (gpFirstStudent == NULL)
	 {
		 DPRINTF("\n Empty list");
	 }
	 else
	 {
		 while (pcurrentStudent)
		 {
			 DPRINTF("\n record number %d", count+1);
			 DPRINTF("\n \t ID: %d ", pcurrentStudent->student.ID);
			 DPRINTF("\n \t Name: %s", pcurrentStudent->student.name );
			 DPRINTF("\n \t height: %f", pcurrentStudent->student.height);
			 pcurrentStudent = pcurrentStudent->PNextStudent;
			 count++;
		 }
	 }

 }

 void DeleteAll ()
 {
	 struct SStudent* pcurrentStudent = gpFirstStudent ;

	 	 if (gpFirstStudent == NULL)
	 	 {
	 		 DPRINTF("\n Empty list");
	 	 }
	 	 else
	 	 {
	 		 while (pcurrentStudent)
	 		 {
	 			struct SStudent* pTempStudent = pcurrentStudent ;
	 			pcurrentStudent = pcurrentStudent->PNextStudent;
	 			free (pTempStudent);
	 		 }
	 		gpFirstStudent = NULL ;
	 	 }

 }
 void Get_Nth_Student()
 {
	 int Index;
 	int count = 1;
 	struct SStudent* pcurrentStudent = gpFirstStudent ;

 	if(!gpFirstStudent)
 	{
 		/* List is empty */
 		DPRINTF("\n=========Empty List=========\n\n");
 	}
 	else /* List contains records */
 	{
 		DPRINTF("Enter the Index: ");
 		scanf("%d",&Index);
 		while(pcurrentStudent &&  count != Index)
 		{
 			pcurrentStudent = pcurrentStudent->PNextStudent;
 			count++;
 		}

 		if(!pcurrentStudent)
 		{
 			DPRINTF("\nIndex is not exit\n\n");
 		}
 		else
 		{
 			DPRINTF("=========Student Number (%d)========= \n",count);
 			DPRINTF("ID: %d\n",pcurrentStudent->student.ID);
 			DPRINTF("Name: %s\n",pcurrentStudent->student.name);
 			DPRINTF("Height: %.2f\n\n",pcurrentStudent->student.height);
 		}
 	}
 }
 void Find_Num_of_Student() /* using iterative method */
 {
 	int count = 0;
 	struct SStudent* pcurrentStudent = gpFirstStudent ;
 	if(gpFirstStudent) /* if list contains records */
 	{
 		/* List contains records */
 		while(pcurrentStudent)
 		{
 			pcurrentStudent = pcurrentStudent->PNextStudent;
 			count++;
 		}
 		DPRINTF("\nNumber of the Student is: (%d) Student\n\n",count);
 	}else{
 		DPRINTF("\n=========Empty List=========\n\n");
 	  }
 }

 void GET_the_Nth_STUDENT_DATA_FROM_THE_END()
 {
	 int Index;
 	int count = 0;
 	struct SStudent* pcurrentStudent = gpFirstStudent ;
 	struct SStudent* PReferenceStudent = gpFirstStudent;

 	if(!gpFirstStudent)
 	{
 		/* List is empty */
 		DPRINTF("\n=========Empty List=========\n\n");
 	}
 	else /* List contains records */
 	{
 		DPRINTF("Enter the Index: ");
 		scanf("%d",&Index);

 		while(PReferenceStudent && count != Index)
 		{
 			PReferenceStudent = PReferenceStudent->PNextStudent;
 			count++;
 		}
 		if(count != Index)
 		{
 			/* Index is not found in List */
 			DPRINTF("\n=====Index is not exit in List=====\n\n");
 		}
 		else /* Index is found in List */
 		{
 			while(PReferenceStudent)
 			{
 				pcurrentStudent = pcurrentStudent->PNextStudent;
 				PReferenceStudent = PReferenceStudent->PNextStudent;
 			}
 			DPRINTF("=========Student Number (%d)========= \n",count);
 			DPRINTF("ID: %d\n",pcurrentStudent->student.ID);
 			DPRINTF("Name: %s\n",pcurrentStudent->student.name);
 			DPRINTF("Height: %.2f\n\n",pcurrentStudent->student.height);
 		}
 	}
 }
 void Middle_of_List()
 {
	 int Index;
 	int count = 0;
 	struct SStudent* pcurrentStudent = gpFirstStudent ;
 	while(pcurrentStudent)
 	{
 		pcurrentStudent = pcurrentStudent->PNextStudent;
 		count++;
 	}
 	/* Check odd or even */

 	if(count%2 == 1)
 	{
 		/* Number of nodes is odd */
 		count = 0;
 		struct SStudent* PFastStudent = gpFirstStudent , * PSlowStudent = gpFirstStudent;
 		while(PFastStudent->PNextStudent)
 		{
 			PFastStudent = PFastStudent->PNextStudent->PNextStudent;
 			PSlowStudent = PSlowStudent->PNextStudent;
 			count++;
 		}
 		DPRINTF("=========Middle is Number (%d)========= \n",count);
 		DPRINTF("ID: %d\n",PSlowStudent->student.ID);
 		DPRINTF("Name: %s\n",PSlowStudent->student.name);
 		DPRINTF("Height: %.2f\n\n",PSlowStudent->student.height);
 	}
 	else
 	{

 		Index = 1;
 		/* Number of nodes is even */
 		pcurrentStudent =gpFirstStudent;
 		while(Index != ((count/2) + 1) ) /* PCurrentStudent->PNext_Student && */
 		{
 			pcurrentStudent = pcurrentStudent->PNextStudent;
 			Index++;
 		}
 		DPRINTF("=========Middle Student is Number (%d)========= \n",Index);
 		DPRINTF("ID: %d\n",pcurrentStudent->student.ID);
 		DPRINTF("Name: %s\n",pcurrentStudent->student.name);
 		DPRINTF("Height: %.2f\n\n",pcurrentStudent->student.height);
 	}
 }
 int Detect_List_Loop()
 {
 	struct SStudent* PFastStudent = gpFirstStudent , * PSlowStudent = gpFirstStudent;

 	while(PSlowStudent && PFastStudent && PFastStudent->PNextStudent)
 	{
 		PSlowStudent = PSlowStudent->PNextStudent;
 		PFastStudent = PFastStudent->PNextStudent->PNextStudent;
 		if(PSlowStudent == PFastStudent)
 		{
 			DPRINTF("\n***Found Loop***\n");
 			return 1;
 		}
 	}
 	DPRINTF("\nNo loop found\n");
 	return 0;
 }
 void Reverse_List()
 {
	 struct SStudent* pcurrentStudent;
	 pcurrentStudent = NULL;
 	struct SStudent* PrevStudent = NULL;
 	while(gpFirstStudent)
 	{
 		pcurrentStudent = gpFirstStudent->PNextStudent;
 		gpFirstStudent->PNextStudent = PrevStudent;
 		PrevStudent = gpFirstStudent;
 		gpFirstStudent = pcurrentStudent;
 	}
 	gpFirstStudent = PrevStudent;
 	DPRINTF("====Reversing the list done===\n");
 }

struct SStudent* gpFirstStudent;

int choice;
int main()
{

	do{
		DPRINTF("\t Choose on of the following options\n\n");
		DPRINTF("1: Add Student\n");
		DPRINTF("2: Delete Student\n");
		DPRINTF("3: View Student\n");
		DPRINTF("4: Delete All\n");
		DPRINTF("5: Find Student Data by its Index in the list\n");
		DPRINTF("6: Find the Number of Students\n");
		DPRINTF("7: Find the Student Data From the End\n");
		DPRINTF("8: Find the middle of the List\n");
		DPRINTF("9: Find If There is a Loop\n");
		DPRINTF("10: Reverse the List\n");
		DPRINTF("\nEnter Option Number (1,2,3,4,....,10): ");
		scanf("%d",&choice);
		DPRINTF("Your choice is number: %d  \n\n",choice);
		switch(choice)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			Get_Nth_Student();
			break;
		case 6:
			Find_Num_of_Student();  /*using iterative method */
			break;
		case 7:
			GET_the_Nth_STUDENT_DATA_FROM_THE_END();
			break;
		case 8:
			 Middle_of_List();
			break;
		case 9:
			Detect_List_Loop();
			break;
		case 10:
			Reverse_List();
			break;
		default :
			DPRINTF("\n========Your choice isn't in the list========\n");
			break;
		}
		DPRINTF("\n-------------------------------\n");
		DPRINTF("Choose any thing again or exit?\n");
		DPRINTF("1: Yes.\n");
		DPRINTF("2: No.\n");
		DPRINTF("-------------------------------\n");
		scanf("%d",&choice);
		DPRINTF("Have Nice Day");
	}while(choice == 1);

	return 0;
}
