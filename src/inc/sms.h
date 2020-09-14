#include <stdio.h>
#include <string.h>
#define MAX (2)
// DECLARATIONS 
typedef struct date
{
   short int day;
   short int month;
   short int year;
} date_t;
typedef enum branch
{
    AE=0,
    CS=1,
    CV=2,
    EC=3, 
    EE=4,
    IS=5,
    ME=6,
    MAX_BRANCH = 7
}branch_t;
struct branch_info
{
    char code[3];
    char name[50];
    branch_t num;
};

const struct branch_info br_lookup[MAX_BRANCH] = 
{
    // col 1 code, col 2- name, col 3-num 
    {"AE", "Aeronotical Engineering", AE},
    {"CS", "Computer Science Engineering", CS},
    {"CV", "Civil Engineering", CV},
    {"EC", "Electronics and Communication Engineering", EC},
    {"EE", "Electrical and Electronics Engineering", EE},
    {"IS", "Information Science Engineering", IS},
    {"ME", "Mechanical Engineering", ME}
    
};   
typedef struct student_details
{
    char name[50];
    char usn[30];
    unsigned int adm_no;
    unsigned long phone_no;
    branch_t branch;
    date_t dob;
}student_t;
