#define MAX_VIDEO 100
#define MAX_CUST 200 // max customer
#define MAX_CHAR 100 // 문자열의 max 문자
#include <stdio.h>
#include <string.h>


typedef struct { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR] ;
	int qty ; // 수량
} VideoInfo;

typedef struct { // 대출 대장: 대출해간 (고객 id와 video id)들을 저장
	int custId ; // 고객 id : 1, 2, 3
	char title[MAX_CHAR] ; // Video 제목
} RentInfo;

//보유 Video들을 출력
void printAllVideo(VideoInfo videoList[], int videoCount) {
	//구현
	int i;
	printf("Video제목 \t 수량 \n");
	printf("---------------------\n");
	for(i = 0; i < videoCount; i++)
		printf("%s \t %d \n", videoList[i].title, videoList[i].qty);
}

//Video구입
void purchaseVideo(VideoInfo videoList[], int *videoCountPtr, char *title, int qty) {
	//구현 purchaseVideo(videoList, &videoCount, title, qty)
	strcpy(videoList[*videoCountPtr].title, title);
	videoList[*videoCountPtr].qty = qty;
	(*videoCountPtr)++;
}

//title로 Video 찾기
VideoInfo * searchVideoByTitle(VideoInfo videoList[], int videoCount, char *title)
{
	int i;

	for(i = 0; i < videoCount; i++)
	{
		if(strcmp(videoList -> title, title) == 0)
			return videoList;
		videoList++;
	}
	return NULL;
}

//Video 대여
void rentVideo(VideoInfo *videoList,  int videoCount, RentInfo rentList[], int *rentCountPtr, char *title, int custId) {
	//구현rentVideo(videoList, videoCount, rentList, &rentCount, title, custId); 
	int i;
	for(i = 0; i < videoCount; i++)
		if(strcmp(videoList[i].title, title) == 0){
			videoList[i].qty--;
			strcpy(rentList[*rentCountPtr].title, title);
			rentList[*rentCountPtr].custId = custId; //pointer 씌워줘야 돌아감. 왜?
			(*rentCountPtr)++; //pointer 씌워줘야 돌아감. 왜?
		}
}

//대여 정보들을 출력 
void printAllRent(RentInfo rentList[], int rentCount) {
	//구현
	int i;

	printf("고객id \t Video제목 \n");
	printf("-----------------------\n");
	for(i = 0; i < rentCount; i++)
		printf("%d \t %s \n", rentList[i].custId, rentList[i].title);
}

int main(void)
{
	int videoCount = 5; 
	VideoInfo videoList[MAX_VIDEO] = {
		{"BeforeSunrise", 1},
		{"BeforeSunset", 3},
		{"BeforeMidnight", 5}, 
		{"Casablanca", 7}, 
		{"EdgeOfTomorrow", 9}
	};
	int rentCount = 0; // 현재 대출 건수는 0임 , 대출이 일어날때 마다 1++;
	RentInfo rentList[MAX_CUST];

	int choice;
	VideoInfo *videoSearched;
	char title[MAX_CHAR];
	int custId, qty;

	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch(choice) {
			case 1: 
				printAllVideo(videoList, videoCount); 
				break;
			case 2:
				printf("Enter video 제목: ");
				scanf("%s", title);
				printf("Enter video 수량: ");
				scanf("%d", &qty);
				purchaseVideo(videoList, &videoCount, title, qty); 
				break;
			case 3:
				printf("Enter video 제목: ");
				scanf("%s", title);
				if ((videoSearched = searchVideoByTitle(videoList, videoCount, title)) == NULL)
					printf("그런 비디오는 없습니다.\n");
				else if ((videoSearched -> qty) == 0)
					printf("다 대여중입니다.\n");
				else
					printf("대여 가능합니다.\n"); 
				break;
			case 4:
				printf("Enter video 제목: ");
				scanf("%s", title);
				printf("Enter 고객 id: ");
				scanf("%d", &custId);
				rentVideo(videoList, videoCount, rentList, &rentCount, title, custId); 
				break;
			case 5:
				printAllRent(rentList, rentCount); 
				break;
		}
		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료): ");
		scanf("%d", &choice);
	}
} 