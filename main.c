#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int mathuoc;
	char tenthuoc[50];
	int soluong;
	float dongia;
}Nhathuoc;


void displaymenu() {
	printf("\n === QUAN LY THUOC ===\n");
	printf("1. them thuoc\n");
	printf("2. hien thi danh sach thuoc\n");
	printf("3. cap nhat thuoc theo ma\n");
	printf("4. xoa thuoc theo ma\n");
	printf("5.tim thuoc theo ten\n");
	printf("6. thong ke kho khang\n");
	printf("0. thoat\n");
	printf("chon chuc nang (0-6): ");
}
int main(int argc, char *argv[]) {
	Nhathuoc nhathuocs[MAX_SIZE];
	int currentlength = 0;
	
	while (1) {
		int userchoose;
		displaymenu();
		scanf("%d",&userchoose);
		
		switch (userchoose) {
			case 1: {
				if (currentlength >= MAX_SIZE) {
					printf ("Danh sach da day\n");
					break;
				}
				
				int mathuoc;
				char tenthuoc[50];
				int soluong;
				float dongia;
				
				printf ("Nhap ma thuoc: ");
				scanf("%d",&mathuoc);
				getchar();
				
				printf ("Nhap ten thuoc: ");
				fgets(tenthuoc, sizeof(tenthuoc), stdin);
				tenthuoc[strcspn(tenthuoc,"\n")] = '\0';
				
				printf ("Nhap vao so luong: ");
				scanf("%d",&soluong);
				getchar();
				
				printf("Nhap vao don gia: ");
				scanf("%f",&dongia);
				getchar();
				
				nhathuocs[currentlength].mathuoc = mathuoc;
				strcpy(nhathuocs[currentlength].tenthuoc,tenthuoc);
				nhathuocs[currentlength].soluong = soluong;
				nhathuocs[currentlength].dongia = dongia;
				
				currentlength++;
				printf("Them thuoc thanh cong");
				break;
			}
			
			case 2: {
				if (currentlength == 0) {
					printf("Danh sach rong");
					break;
				}
				
				for (int i = 0; i < currentlength;i++) {
					printf("Ma thuoc : %d\n",nhathuocs[i].mathuoc);
					printf("Ten thuoc : %s\n",nhathuocs[i].tenthuoc);
					printf("So luong thuoc : %d\n",nhathuocs[i].soluong);
					printf("Don gia thuoc : %f\n",nhathuocs[i].dongia);
					
				}
				break;
			}
			
			case 3: {
				if (currentlength == 0) {
					printf("Danh sach rong");
					break;
				}
				
				int mathuoc;
				printf("Nhap ma thuoc can cap nhat: ");
				scanf("%d",&mathuoc);
				getchar();
				
				int foundindex = -1;
				for (int i = 0;i < currentlength;i++) {
					if (nhathuocs[i].mathuoc == mathuoc) {
						foundindex = i;
						break;
					}
				}
				
				if (foundindex == -1) {
					printf ("Khong tim thay thuoc");
					break;
				}
				
				printf("Nhap ten thuoc: ");
				fgets(nhathuocs[foundindex].tenthuoc,sizeof(nhathuocs[foundindex].tenthuoc),stdin);
				nhathuocs[foundindex].tenthuoc[strcspn(nhathuocs[foundindex].tenthuoc, "\n")] = '\0';
				
				printf ("Nhap so luong: ");
				scanf("%d",&nhathuocs[foundindex].soluong);
				getchar();
				
				printf("Nhap don gia: ");
				scanf("&f",&nhathuocs[foundindex].dongia);
				getchar();
				
				printf("Cap nhat thanh cong");
				break;
			}
			
			case 4: {
				if (currentlength == 0) {
					printf("Danh sach rong");
					break;
				}
				
				int mathuoc;
				printf("Nhap ma thuoc can xoa: ");
				scanf("%d",&mathuoc);
				getchar();
				
				int foundindex = -1;
				for (int i = 0;i < currentlength;i++) {
					if (nhathuocs[i].mathuoc == mathuoc) {
						foundindex = i;
						break;
					}
				}
				
				if (foundindex == -1) {
					printf ("Khong tim thay thuoc");
					break;
				}
				
				for (int i = foundindex; i< currentlength -1; i++) {
					nhathuocs[i] = nhathuocs[i+1];
				}
				currentlength--;
				
				printf("Xoa thuoc thanh cong");
				break;
			}
			
			case 5: {
				if (currentlength == 0) {
					printf("Danh sach rong");
					break;
				}
				getchar();
				
				char tukhoa[50];
				printf("Nhap ten can tim: ");
				fgets(tukhoa,sizeof(tukhoa),stdin);
				tukhoa[strcspn(tukhoa, "\n")] = '\0';
				
				int isfound = 0;
				for (int i =0;i < currentlength;i++) {
					if (strstr(nhathuocs[i].tenthuoc,tukhoa)!= NULL) {
						printf("Ma thuoc : %d\n",nhathuocs[i].mathuoc);
						printf("Ten thuoc : %s\n",nhathuocs[i].tenthuoc);
						printf("So luong thuoc : %d\n",nhathuocs[i].soluong);
						printf("Don gia thuoc : %f\n",nhathuocs[i].dongia);
						isfound = 1;
					}
				}
				
				if (!isfound) {
					printf("Khong tim thay thuoc");
					break;
				}
				break;
			}
			
			case 0: {
				printf("Thoat chuon trinh\n");
				return 0;
			}
			default: {
				printf("Lua chon khong hop le");
			}
			}
		}
		return 0;
	}
	