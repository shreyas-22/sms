#include "sms.h"
// VARIABLE DEFINITIONS
student_t a[MAX];
int count=0;

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

int create_entry(void)
{
    int result;
    if(count==MAX)
    {
        printf("memory is full!!\n");
        return (-1);
    }
    printf("----------------------------------\n");
    printf("enter the details of the student:\n");
    printf("----------------------------------\n");
    printf("Enter name: ");
    scanf("%s",a[count].name);
    printf("Enter DOB (dd-mm-yyyy): ");
    scanf("%hu-%hu-%hu",&a[count].dob.day, 
            &a[count].dob.month, &a[count].dob.year);
    printf("Enter phone number: ");
    scanf("%lu",&a[count].phone_no);
    do
    {
        printf("Enter usn: ");
        scanf("%s",a[count].usn);
        result = usn_to_branch(a[count].usn);
        if(result == (-1))
        {
            printf("wrong usn!!\n");
        }
    }while(result == (-1));
    a[count].branch = result;
    printf("%d\n", a[count].branch);
    printf("Enter admission number: ");
    scanf("%u",&a[count].adm_no);
    count++;
    return 0;
}

const char * br_num_to_name(int i)
{
    printf("%d\n", a[i].branch);
    int j;
    for(j=0;j<MAX_BRANCH; j++)
    {
        if(br_lookup[j].num == a[i].branch)
        {   
           
           return (br_lookup[j].name);
        }
    }
}
        
            
int print_entry(int i)
{
    char branch[50];
    if(i>=MAX)
    {
        printf("invalid index: %d\n",i);
        return (-1);
    }
    printf("----------------------------------\n");
    printf("The student details are:\n");
    printf("----------------------------------\n");   
    printf("Name: %s\n",a[i].name);
    printf("DOB (dd-mm-yyyy): %hu-%hu-%hu\n",a[i].dob.day, 
            a[i].dob.month, a[i].dob.year);
    printf("Phone number: %lu\n",a[i].phone_no);
    printf("Branch: %s\n",br_num_to_name(i));
    printf("usn: %s\n",a[i].usn);
    printf("Admission number: %u\n",a[i].adm_no);
    return 0;
}
    
        
    
    
    



int print_report()
{}

int main()
{
    create_entry();
    create_entry();
    
    print_entry(0);
    print_entry(1);
    
    
    
}
