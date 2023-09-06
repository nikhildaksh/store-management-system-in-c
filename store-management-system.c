// c store management project
#include<stdio.h>
#include<stdlib.h>

typedef struct store_record{    
    int product_id;
    char product_name[50];
    int product_quantity;    
}store_record;

void createrecord(){
    FILE *fptr;        
    store_record *s1;
    s1 = (store_record *)calloc(1,sizeof(store_record));   
    fptr = fopen("store-database.txt","a+");
    printf("\n Create New Record");
    printf("\n Enter Product ID: ");
    scanf("%d",&s1[0].product_id);    
    printf("\n Enter Product Name: ");
    scanf("%s",s1[0].product_name);    
    printf("\n Enter Product Quantity: ");
    scanf("%d",&s1[0].product_quantity);   
    fwrite(&s1[0], sizeof(store_record), 1, fptr);
    fclose(fptr);   
}
void deleterecord(){    
    int id;
    store_record s1;
    int isfound=0;
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("store-database.txt","r");    
    if(fptr){
        fptr2 = fopen("store-database2.txt","a+");
        printf("\nDelete Record");
        printf("\nEnter ID to Search: ");
        scanf("%d",&id);
        while(fread(&s1, sizeof(store_record), 1, fptr)){
            if(s1.product_id==id){
                printf("\n%-40s %-40s %-40s","Product ID", "Product Name", "Product Quantity");
                printf("\n%-40d %-40s %-40d",s1.product_id, s1.product_name, s1.product_quantity);
                printf("\n This Data Deleted Sucessfully.");
                isfound = 1;
            }else{
                fwrite(&s1, sizeof(store_record), 1, fptr2);
            }
        }
        if(isfound==0){
            printf("\nSorry Record was not found.");
        }
        remove("store-database.txt");
        rename("store-database2.txt","store-database.txt");
        fclose(fptr2);
        fclose(fptr);
    }else{
        printf("File Not Exist.");
    }
}
void updaterecord(){
    int id;
    store_record s1;
    store_record s2;
    int isfound=0;
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("store-database.txt","r");
    if(fptr){
        fptr2 = fopen("store-database2.txt","a+");
        printf("\nUpdate Record");
        printf("\nEnter ID to Search: ");
        scanf("%d",&id);
        while(fread(&s1, sizeof(store_record), 1, fptr)){
            if(s1.product_id==id){
                printf("\n%-40s %-40s %-40s","Product ID", "Product Name", "Product Quantity");
                printf("\n%-40d %-40s %-40d",s1.product_id, s1.product_name, s1.product_quantity);
                printf("\n This is old data and please enter new values.");
                printf("\n This Data Deleted Sucessfully.");
                printf("\n Create New Record");
                printf("\n Enter Product ID: ");
                scanf("%d",&s2.product_id);    
                printf("\n Enter Product Name: ");
                scanf("%s",s2.product_name);    
                printf("\n Enter Product Quantity: ");
                scanf("%d",&s2.product_quantity);                        
                isfound = 1;
                fwrite(&s2, sizeof(store_record), 1, fptr2);
            }else{
                fwrite(&s1, sizeof(store_record), 1, fptr2);
            }
        }
        if(isfound==0){
            printf("\n Sorry Record was not found.");
        }
        remove("store-database.txt");
        rename("store-database2.txt","store-database.txt");
        fclose(fptr2);
        fclose(fptr);
    }else{
        printf("File Does't Not Exist.");
    }
}
void displayrecord(){
    store_record s1;
    FILE *fptr;
    fptr = fopen("store-database.txt","r");
    if(fptr){
        printf("\nThe All Records are Display.");
        printf("\n---------------------------------------------");
        printf("\n%-40s %-40s %-40s","Product ID", "Product Name", "Product Quantity");
        while(fread(&s1, sizeof(store_record), 1, fptr)){
            printf("\n%-40d %-40s %-40d",s1.product_id, s1.product_name, s1.product_quantity);
        }
        printf("\n---------------------------------------------");
        fclose(fptr);
    }else{
        printf("File Does't Not Exist.");
    }
}
void searchrecord(){
    int id;
    store_record s1;
    int isfound=0;
    FILE *fptr;
    fptr = fopen("store-database.txt","r");
    if(fptr){
        printf("\n Search Record\n");
        printf("\n---------------------------------------------");
        printf("\nEnter ID to Search: ");
        scanf("%d",&id);
        while(fread(&s1, sizeof(store_record), 1, fptr)){
            if(s1.product_id==id){
                printf("\n%-40s %-40s %-40s","Product ID", "Product Name", "Product Quantity");
                printf("\n%-40d %-40s %-40d",s1.product_id, s1.product_name, s1.product_quantity);  
                printf("\n---------------------------------------------");
                isfound = 1;          
            }
        }
        if(isfound==0){
            printf("\n Sorry Record was not found.");
        }
        fclose(fptr);
    }else{
        printf("File Does't Not Exist.");
    }
}
void menu(){
    int slt;    
    while(1){
        printf("\n------- Menu of the Store Management -------");
        printf("\n0. Exit the program.");
        printf("\n1. Create Record. ");
        printf("\n2. Delete Record. ");
        printf("\n3. Update Record. ");
        printf("\n4. Display Record. ");
        printf("\n5. Search Record.");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice! ");
        scanf("%d", &slt);
        switch(slt){
            case 0: exit(1);
            case 1: createrecord(); break;
            case 2: deleterecord(); break;
            case 3: updaterecord(); break;
            case 4: displayrecord(); break;
            case 5: searchrecord(); break;
            default:
                printf("\nTry Again, Select Correct Option.");
        }
    }
}
int main(){
    menu();
    return 0;
}