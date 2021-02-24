#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct karyawan
{
    char nama[30];
    int jenis_kelamin;
    char kota[30];
    int status_karyawan;
    int status_kawin;
    int umur;
    struct karyawan *next;
} * head, *tail, *temp;
void push_head(char nama[], int jenis_kelamin, char kota[], int status_karyawan, int status_kawin, int umur)
{
    temp = (struct karyawan *)malloc(sizeof(struct karyawan));
    strcpy(temp->nama, nama);
    temp->jenis_kelamin = jenis_kelamin;
    strcpy(temp->kota, kota);
    temp->status_karyawan = status_karyawan;
    temp->status_kawin = status_kawin;
    temp->umur = umur;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head; //dari depan
        head = temp;
    }
}
void push_tail(char nama[], int jenis_kelamin, char kota[], int status_karyawan, int status_kawin, int umur)
{
    temp = (struct karyawan *)malloc(sizeof(struct karyawan));
    strcpy(temp->nama, nama);
    temp->jenis_kelamin = jenis_kelamin;
    strcpy(temp->kota, kota);
    temp->status_karyawan = status_karyawan;
    temp->status_kawin = status_kawin;
    temp->umur = umur;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp; //dari belakang
        tail = temp;
    }
    tail->next = NULL; //set tail menjadi NULL
}
void delete_head()
{
    temp = head;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        head = head->next;
        free(temp);
    }
}
void delete_tail()
{
    if (head == NULL)
    {
        printf("No Data\n");
    }
    else if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        struct karyawan *storage = head; //buat variabel penampung baru dan assign/beri nilai mulai dari head
        while (storage->next != tail)
        {
            storage = storage->next;
        }
        temp = tail;
        tail = temp;
        free(temp);
        tail->next = NULL;
    }
}
void print_data()
{
    char *jk, *stats, *stats_married;
    temp = head;
    while (temp != NULL)
    {
        if (temp->jenis_kelamin == 0)
        {
            jk = "Female";
        }
        else if (temp->jenis_kelamin == 1)
        {
            jk = "Male";
        }
        else
        {
            jk = "SheMale";
        }
        if (temp->status_karyawan == 1)
        {
            stats = "Permanent Worker";
        }
        else if (temp->status_karyawan == 0)
        {
            stats = "Not Permanent Worker";
        }
        else
        {
            stats = "Not Employee";
        }
        if (temp->status_kawin == 1)
        {
            stats_married = "Married";
        }
        else
        {
            stats_married = "Not Married";
        }
        printf("Name: %s\n", temp->nama);
        printf("Gender: %s\n", jk);
        printf("City: %s\n", temp->kota);
        printf("Employee Status: %s\n", stats);
        printf("Martial Status: %s\n", stats_married);
        printf("Age: %d\n", temp->umur);
        printf("\n");
        printf("\n");
        temp = temp->next; //untuk value selanjutnya
    }
}
int main()
{
    int data, i, jenis_kelamin, status_karyawan, status_kawin, umur;
    char nama[30], kota[30], hapustambah[30], pilihan[30], lagi[30];
input:
    system("cls");
    printf("Enter Data(Integer): ");
    scanf("%d", &data);
    for (int i = 1; i <= data; i++)
    {
        printf("Data - %d\n", i);
        printf("Enter Name: ");
        scanf("%s", nama);
        printf("Gender? (0 for Female And 1 for Male): ");
        scanf("%d", &jenis_kelamin);
        printf("City: ");
        scanf("%s", kota);
        printf("Emloyee Status? (0 for Not Permanent Employee And 1 for Permanent Employee): ");
        scanf("%d", &status_karyawan);
        printf("Married Status? (0 for Not Married and 1 for Married): ");
        scanf("%d", &status_kawin);
        printf("Input Age: ");
        scanf("%d", &umur);
        printf("\n");
        if (i == 1)
        {
            push_head(nama, jenis_kelamin, kota, status_karyawan, status_kawin, umur);
        }
        else
        {
            printf("Enter data from head or tail? (Front or Back): ");
            scanf("%s", pilihan);
            if (strcmp(pilihan, "Front") == 0 || strcmp(pilihan, "front") == 0)
            {
                push_head(nama, jenis_kelamin, kota, status_karyawan, status_kawin, umur);
            }
            else
            {
                push_tail(nama, jenis_kelamin, kota, status_karyawan, status_kawin, umur);
            }
        }
    }
    print_data();
    printf("Want to add data? (Yes or No): ");
    scanf("%s", hapustambah);
    if (strcmp(hapustambah, "Yes") == 0 || strcmp(hapustambah, "yes") == 0)
    {
        printf("Data - %d\n", i);
        printf("Enter Name: ");
        scanf("%s", nama);
        printf("Gender? (0 for Female And 1 for Male): ");
        scanf("%d", &jenis_kelamin);
        printf("City: ");
        scanf("%s", kota);
        printf("Emloyee Status? (0 for Not Permanent Employee And 1 for Permanent Employee): ");
        scanf("%d", &status_karyawan);
        printf("Married Status? (0 for Not Married and 1 for Married): ");
        scanf("%d", &status_kawin);
        printf("Input Age: ");
        scanf("%d", &umur);
        printf("\n");
        printf("Enter data from head or tail? (Front or Back): ");
        scanf("%s", pilihan);
        if (strcmp(pilihan, "Front") == 0 || strcmp(pilihan, "front") == 0)
        {
            push_head(nama, jenis_kelamin, kota, status_karyawan, status_kawin, umur);
        }
        else
        {
            push_tail(nama, jenis_kelamin, kota, status_karyawan, status_kawin, umur);
        }
    }
    else
    {
        printf("Delete From Front or Delete From Back or Enough? (Front or Back or No): ");
        scanf("%s", pilihan);
        if (strcmp(pilihan, "Front") == 0 || strcmp(pilihan, "front") == 0)
        {
            delete_head();
        }
        else if (strcmp(pilihan, "Back") == 0 || strcmp(pilihan, "back") == 0)
        {
            delete_tail();
        }
        else
        {
            goto exit;
        }
    }
    print_data();
    printf("Want to add data? (Yes or No): ");
    scanf("%s", lagi);
    if (strcmp(lagi, "Yes") == 0 || strcmp(lagi, "yes") == 0)
        goto input;
    else
        goto exit;
exit:
    system("cls");
    printf("Thank You\n\n");
    print_data();
    return 0;
}