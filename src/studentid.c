#include "sms.h"
#include <stdlib.h>
// VARIABLE DEFINITIONS
student_t a[MAX];
int count=0;
student_t *list = NULL;

branch_t usn_to_branch(char* usn)
{
    int i, ret=0;
    for(i=0; i<MAX_BRANCH; i++)
    {
        ret = strncmp(br_lookup[i].code , &usn[5], 2);
        if(ret == 0)
        {
            
            break;
        }
    }
    if(i== MAX_BRANCH)
    {
        printf("branch not found\n");
        return (-1);
    }
    return (br_lookup[i].num); 
}

const char * br_num_to_name(branch_t branch)
{
    printf("%d\n", branch);
    int j;
    for(j=0;j<MAX_BRANCH; j++)
    {
        if(br_lookup[j].num == branch)
        {   
           
           return (br_lookup[j].name);
        }
    }
}
        
int create_entry(student_t **head)
{
    int result;
    student_t *new = NULL;
    new = malloc(sizeof(student_t));
    if(new == NULL)
    {
        printf("memory is not allocated\n");
        return (-1);
    }
    printf("----------------------------------\n");
    printf("Enter the details of the student:\n");
    printf("----------------------------------\n");
    printf("Enter name: ");
    scanf("%s",new->name);
    printf("Enter DOB (dd-mm-yyyy): ");
    scanf("%hu-%hu-%hu", &new->dob.day, 
            &new->dob.month, &new->dob.year);
    printf("Enter phone number: ");
    scanf("%lu", &new->phone_no);
    do
    {
        printf("Enter usn: ");
        scanf("%s",new->usn);
        result = usn_to_branch(new->usn);
        if(result == (-1))
        {
            printf("wrong usn!!\n");
        }
    } while(result == (-1));
    new->branch = result;
    DEBUG("%d\n", new->branch);
    printf("Enter admission number: ");
    scanf("%u", &new->adm_no);
    new->next = *head;
    DEBUG("head = %p\n",*head);
    *head = new;
    DEBUG("new = %p\n",new);
    
    return 0;
}
  
int search_print(student_t *head, int adm_no)
{
    student_t *ptr = head;
    while(ptr != NULL)
    {   
        DEBUG("ADMISSION NUMBER = %d %d",ptr->adm_no,adm_no);
        if(ptr->adm_no == adm_no)
        {
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        return (-1);
    }
    printf("----------------------------------\n");
    printf("The student details are:\n");
    printf("----------------------------------\n");   
    printf("Name: %s\n",ptr->name);
    printf("DOB (dd-mm-yyyy): %hu-%hu-%hu\n",ptr->dob.day, 
            ptr->dob.month, ptr->dob.year);
    printf("Phone number: %lu\n",ptr->phone_no);
    printf("Branch: %s\n",br_num_to_name(ptr->branch));
    printf("usn: %s\n",ptr->usn);
    printf("Admission number: %u\n",ptr->adm_no);
    return 0;
}

int Delete_entry(student_t **head)
{
    int adm_no;
    student_t *ptr = *head;
    student_t *prev = NULL;
    printf("Enter the admission number to be Deleted\n");
    scanf("%d",&adm_no);
    
    while(ptr != NULL)
    {   /* match is found */
        if(ptr->adm_no == adm_no)
        {   /* match found at first node */
            if(prev == NULL)
            {
                *head = ptr->next;
                free(ptr);
                ptr = NULL;
                break;
            }   /* match found at other node */
            else
            {
                prev->next = ptr->next;
                free(ptr);
                ptr = NULL;
                break;
            }
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

int print_entire_list(student_t **head)
{
    printf("HERE\n");
    student_t *ptr = *head;
    while(ptr != NULL)
    {
        printf("----------------------------------\n");
        printf("The student details are:\n");
        printf("----------------------------------\n");   
        printf("Name: %s\n",ptr->name);
        printf("DOB (dd-mm-yyyy): %hu-%hu-%hu\n",ptr->dob.day, 
        ptr->dob.month, ptr->dob.year);
        printf("Phone number: %lu\n",ptr->phone_no);
        printf("Branch: %s\n",br_num_to_name(ptr->branch));
        printf("usn: %s\n",ptr->usn);
        printf("Admission number: %u\n",ptr->adm_no);
        ptr = ptr->next;
    }
}

int update_entry(student_t **head, int adm_no)
{
    int result;
    student_t *ptr = *head;
    while(ptr != NULL)
    {
        if(ptr->adm_no == adm_no)
        {
            printf("##################################\n");
            printf("Update the details of the student:\n");
            printf("##################################\n");
            printf("Enter name: ");
            scanf("%s",ptr->name);
            printf("Enter DOB (dd-mm-yyyy): ");
            scanf("%hu-%hu-%hu", &ptr->dob.day, 
            &ptr->dob.month, &ptr->dob.year);
            printf("Enter phone number: ");
            scanf("%lu", &ptr->phone_no);
            do
            {
            printf("Enter usn: ");
            scanf("%s",ptr->usn);
            result = usn_to_branch(ptr->usn);
            if(result == (-1))
            {
            printf("wrong usn!!\n");
            }
            } while(result == (-1));
            ptr->branch = result;
        }
        else
        {
            printf("details not found\n");
        }
        ptr = ptr->next;
    }
}


    
        
            
        
    

        

int main()
{
    int result = 0;
    int adm_no = 0;   
    create_entry(&list);
    
    print_entire_list(&list);
    /*do
    {
        printf("Enter adm.no to be searched: ");
        scanf("%d",&adm_no);
        result = search_print(list, adm_no);
        if(result == (-1))
        {
            printf("Details not found\n");
        }
    } while(result == (-1));  
    Delete_entry(&list); */
    printf("Enter adm.no to be searched: ");
        scanf("%d",&adm_no);
    update_entry(&list , adm_no);
    print_entire_list(&list);
    
   
}
