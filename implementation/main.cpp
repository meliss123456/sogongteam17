// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <string>

#include "user.h"
#include "signup.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
FILE* in_fp, * out_fp;

// 최상위에서 각 클래스를 vector로 선언해서 가지고 있는다 (repository)
// CRUD가 일어나는 동작은 control class에 해당 repository 레퍼런스를 전달해서
// 원하는 object 찾을 수 있도록 한다


int main()
{
	// 파일 입출력을 위한 초기화
	FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
	FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");



	doTask();



	return 0;
}






void doTask() {
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		// 입력파일에서 메뉴 숫자 2개를 읽기
		scanf("%d %d", &menu_level_1, &menu_level_2);


		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 1:
		
			switch (menu_level_2) {
			case 1:   // "1.1. 회원가입“ 메뉴 부분
			
				// join() 함수에서 해당 기능 수행 
				join();

				break;
			
			case 2:
			{

				break;
			}
			}

		case 7:

			switch (menu_level_2) {
			case 1:   // "6.1. 종료“ 메뉴 부분


				program_exit();
				is_program_exit = 1;
				break;;

			}




		

		return;
		}
	}