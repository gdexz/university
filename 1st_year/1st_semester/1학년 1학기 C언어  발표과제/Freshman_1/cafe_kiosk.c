#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void PaymentWindow();
void ShowPaymentMenu();
int ChoiceNumber();
int sum = 0;

void main()
{
	char choice = 'H';
	char choiceMenu[1000] = "";

	while (1)
	{
		system("cls");

		switch (choice)
		{
		case 'H':
			system("color e");
			printf("========= MENU =========\n");
			printf("                      \n");
			printf("   1. ShavedIce\n");
			printf("   2. Coffee\n");
			printf("   3. NonCoffee\n");
			printf("   M. 선택한 메뉴\n");
			printf("   Q. 종 료\n");

			printf("▶메뉴를 선택하세요 : ");
			scanf("%c", &choice);

			if (choice == 'M' || choice == 'm')
			{
				printf("★선택한 메뉴 및 가격★\n");
				printf("%s", choiceMenu);
				printf(" 합계 : %d원\n", sum);
				system("pause");
				PaymentWindow();
			}
			break;

		case '1':
			while (1)
			{
				char choice1;

				system("cls");

				system("color d");
				printf("========== Shaved Ice ==========\n");
				printf("                                \n");
				printf("   1. 팥빙수 - 8000원\n");
				printf("   2. 인절미 빙수 - 9000원\n");
				printf("   3. 초코 빙수 - 10000원\n");
				printf("   4. 녹차 빙수 - 10500원\n");
				printf("   5. 딸기 빙수 - 11000원\n");
				printf("   6. 망고 빙수 - 11500원\n");
				printf("   H. 첫 페이지로\n");

				printf("▶빙수를 선택하세요 : ");
				scanf("%c", &choice1);

				if (choice1 == 'H' || choice1 == 'h')
				{
					choice = 'H';
					break;
				}

				switch (choice1)
				{
				case '1':
					sum += 8000;
					strcat(choiceMenu, "- 팥빙수 (8000원)\n");
					break;
				case '2':
					sum += 9000;
					strcat(choiceMenu, "- 인절미 빙수 (9000원)\n");
					break;
				case '3':
					sum += 10000;
					strcat(choiceMenu, "- 초코 빙수 (10000원)\n");
					break;
				case '4':
					sum += 10500;
					strcat(choiceMenu, "- 녹차 빙수 (10500원)\n");
					break;
				case '5':
					sum += 11000;
					strcat(choiceMenu, "- 딸기 빙수 (11000원)\n");
					break;
				case '6':
					sum += 11500;
					strcat(choiceMenu, "- 망고 빙수 (11500원)\n");
					break;
				default:
					break;
				}
			}
			break;

		case '2':
			while (1)
			{
				char choice2;

				system("cls");

				system("color c");
				printf("=============== Coffee ===============\n");
				printf("                                      \n");
				printf("   1. 아메리카노 - 4000원\n");
				printf("   2. 에스프레소 - 3500원\n");
				printf("   3. 카페 라떼 - 4500원\n");
				printf("   4. 카페 모카 - 5000원\n");
				printf("   5. 카라멜 마키아또 - 5500원\n");
				printf("   6. 아포가토 - 6000원\n");
				printf("   H. 첫 페이지로\n");

				printf("▶커피를 선택하세요 : ");
				scanf("%c", &choice2);

				if (choice2 == 'H' || choice2 == 'h')
				{
					choice = 'H';
					break;
				}

				switch (choice2)
				{
				case '1':
					sum += 4000;
					strcat(choiceMenu, "- 아메리카노 (4000원)\n");
					break;
				case '2':
					sum += 3500;
					strcat(choiceMenu, "- 에스프레소 (3500원)\n");
					break;
				case '3':
					sum += 4500;
					strcat(choiceMenu, "- 카페 라떼 (4500원)\n");
					break;
				case '4':
					sum += 5000;
					strcat(choiceMenu, "- 카페 모카 (5000원)\n");
					break;
				case '5':
					sum += 5500;
					strcat(choiceMenu, "- 카라멜 마키아또 (5500원)\n");
					break;
				case '6':
					sum += 6000;
					strcat(choiceMenu, "- 아포가토 (6000원)\n");
					break;
				default:
					break;
				}
			}
			break;

		case '3':
			while (1)
			{
				char choice3;

				system("cls");

				system("color b");
				printf("============= Non Coffee =============\n");
				printf("                                      \n");
				printf("   1. 초코 라떼 - 5000원\n");
				printf("   2. 유기농 녹차 - 4700원\n");
				printf("   3. 허니 블랙 자몽티 - 5300원\n");
				printf("   4. 허니 레몬티 - 5500원\n");
				printf("   5. 블랙 밀크티 - 4900원\n");
				printf("   6. 딸기 스무디 - 5600원\n");
				printf("   H. 첫 페이지로\n");

				printf("▶음료를 선택하세요 : ");
				scanf("%c", &choice3);

				if (choice3 == 'H' || choice3 == 'h')
				{
					choice = 'H';
					break;
				}

				switch (choice3)
				{
				case '1':
					sum += 5000;
					strcat(choiceMenu, "- 초코 라떼 (5000원)\n");
					break;
				case '2':
					sum += 4700;
					strcat(choiceMenu, "- 유기농 녹차 (4700원)\n");
					break;
				case '3':
					sum += 5300;
					strcat(choiceMenu, "- 허니 블랙 자몽티 (5300원)\n");
					break;
				case '4':
					sum += 5500;
					strcat(choiceMenu, "- 허니 레몬티 (5500원)\n");
					break;
				case '5':
					sum += 4900;
					strcat(choiceMenu, "- 블랙 밀크티 (4900원)\n");
					break;
				case '6':
					sum += 5600;
					strcat(choiceMenu, "- 딸기 스무디 (5600원)\n");
					break;
				default:
					break;
				}
			}
			break;

		default:
			choice = 'H';
			break;
		}
		if (choice == 'Q' || choice == 'q')
		{
			printf("결제가 완료되었습니다.\n");
			break;
		}
	}
}

void PaymentWindow()
{
	int choice, inputMoney;
	static int money = 0;
	do
	{
		ShowPaymentMenu();
		choice = ChoiceNumber();
		switch (choice)
		{
		case 1:
			printf("카드를 넣어 주십시오.\n");
			Sleep(5000);
			system("cls");
			sum = 0;
			printf("결제 되었습니다.\n");
			break;
		case 2:
			printf("현금을 넣어주십시오.");
			printf("입금액 : ");
			scanf_s("%d", &inputMoney);
			money += inputMoney;
			break;
		case 3:
			if (money < sum)
			{
				printf("입금된 금액이 결제금액보다 적습니다.\n");
			}
			else
			{
				money -= sum;
				printf("%d원 결제되어 출금액은 %d원 입니다.\n", sum, money);
				break;
			}
		case 4:
			printf("Menu로 돌아가겠습니다.\n");
			return;
		default:
			printf("번호를 다시 골라주세요!\n");
		}
	} while (1);
}

void ShowPaymentMenu()
{
	printf("======================= Payment Menu =======================");
	printf("\n 1. 카드 결제");
	printf("\n 2. 현금 입금 (현금 결제시 현금 충전을 먼저 해 주세요.)");
	printf("\n 3. 현금 결제");
	printf("\n 4. 처음 페이지로 돌아가기");
}

int ChoiceNumber()
{
	int num;
	printf("\nChoice>");
	scanf_s("%d", &num);
	return num;
}