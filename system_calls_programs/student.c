#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DB_FILE "student.txt"

typedef struct {
    int roll;
    char name[20];
    float marks;
}stud_t;

void accept_student(stud_t *s1)
{
    printf("Enter roll : ");
    scanf("%d",&s1->roll);
    printf("Enter Name : ");
    scanf("%s",s1->name);
    printf("Enter marks : ");
    scanf("%f",&s1->marks);
}

void display_student(stud_t s1)
{
    printf("roll : ");
    printf("%d",s1.roll);
    printf("Name : ");
    printf("%s",s1.name);
    printf("Marks : ");
    printf("%f",s1.marks);
}

void add_student(stud_t *s1) 
{
    int fd;
    fd = open(DB_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if(fd < 0) {
        perror("open() failed");
        exit(1);
}

    write(fd, s1, sizeof(stud_t));

    close(fd);
    printf("student added.\n");
}

void display_all() {
    int fd;
    stud_t s1;

    fd = open(DB_FILE, O_RDONLY);
    if(fd < 0) 
    {
        perror("open() failed");
        exit(1);
    }

    while(read(fd, &s1, sizeof(stud_t)) > 0)
        printf("%d, %s , %f\n", s1.roll, s1.name ,s1.marks);

    close(fd);
}

void delete_student(int roll) {
    int fd, found = 0;
    long size = sizeof(stud_t), filesize;
    stud_t s1, s2;

    fd = open(DB_FILE, O_RDWR);
    if(fd < 0) {
        perror("open() failed");
        exit(1);
    }

    while(read(fd, &s1, sizeof(stud_t)) > 0) {
        if(s1.roll == roll) {
            found = 1;
            break;
        }
    }

    if(found == 1) {
        // write all next records on their previous loc.
        while(read(fd, &s2, sizeof(stud_t)) > 0) {
            lseek(fd, -2 * size, SEEK_CUR);
            write(fd, &s2, sizeof(stud_t));
            lseek(fd, +1 * size, SEEK_CUR);
        }
        // truncate file to skip last record
        filesize = lseek(fd, 0, SEEK_END);
        ftruncate(fd, filesize-size);
        close(fd);
    } else
        printf("student not found not found.\n");

    close(fd);
}


void edit_student(int roll) {
    int fd,found = 0;
    stud_t s1, s2;

    fd = open(DB_FILE, O_RDWR);
    if(fd < 0) {
        perror("open() failed");
        exit(1);
    }

    while(read(fd, &s1, sizeof(stud_t)) > 0) {
        if(s1.roll == roll) 
        {
            lseek(fd, -1 * sizeof(stud_t), SEEK_CUR);
            accept_student(&s2);
            write(fd, &s2, sizeof(stud_t));
            printf("Record updated..\n");
            close(fd);
            return;
            break;
        }
    }

    if(found == 0) 
    {
        printf("student not found not found.\n");
    }

    close(fd);
}

int main() 
{
    int ch;
    int roll;
    stud_t s1;
    do
    {
    printf("0.Exit/n1.Add-file/n2.display-file/n3.update/4.delete\n");
    printf("Enter ch : ");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1 : accept_student(&s1);
                 add_student(&s1);
            break;
        case 2:display_all();
            break;
        case 3:printf("enter roll to edit :");
                scanf("%d",&roll);
                edit_student(roll);
                
            break;
        case 4:printf("enter roll to delete :");
                scanf("%d",&roll);
                delete_student(roll);
            break;
    
        default:printf("invalid option \n");
            break;
    }

    } while (ch != 0);
   
    return 0;
}

