#include<stdio.h>
#include<string.h>

struct Books {
	char title[50];
	char author[50];
	char subject[100];
	char book_id;



};

int main(){
struct Books Book1;
struct Books Book2;

strcpy(Book1.title , "C Programming");
		
strcpy(Book1.author, "Nuha Ali");
strcpy(Book1.subject, "C Programming Tutorial");
Book1.book_id = 6495407;


strcpy(Book2.subject, "Telcom Billing");
strcpy(Book2.subject, "Zara Ali");
strcpy(Book2.subject, "Telecom Billing Tutorial");
Book2.book_id = 6495700;




printf("Book 1 title : ",Book1.title);
printf("Book 1 title : ",Book1.author);
printf("Book 1 title : ",Book1.subject);
printf("Book 1 title : ",Book1.book_id);
//Book2 title

printf("Book 2 title :" ,Book2.title);
printf("Book 2 title : ",Book2.author);
printf("Book 2 title : ",Book1.subject);
printf("Book 2 title : ",Book1.book_id);



return 0;
}
