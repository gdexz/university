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
			printf("   M. ������ �޴�\n");
			printf("   Q. �� ��\n");

			printf("���޴��� �����ϼ��� : ");
			scanf("%c", &choice);

			if (choice == 'M' || choice == 'm')
			{
				printf("�ڼ����� �޴� �� ���ݡ�\n");
				printf("%s", choiceMenu);
				printf(" �հ� : %d��\n", sum);
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
				printf("   1. �Ϻ��� - 8000��\n");
				printf("   2. ������ ���� - 9000��\n");
				printf("   3. ���� ���� - 10000��\n");
				printf("   4. ���� ���� - 10500��\n");
				printf("   5. ���� ���� - 11000��\n");
				printf("   6. ���� ���� - 11500��\n");
				printf("   H. ù ��������\n");

				printf("�������� �����ϼ��� : ");
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
					strcat(choiceMenu, "- �Ϻ��� (8000��)\n");
					break;
				case '2':
					sum += 9000;
					strcat(choiceMenu, "- ������ ���� (9000��)\n");
					break;
				case '3':
					sum += 10000;
					strcat(choiceMenu, "- ���� ���� (10000��)\n");
					break;
				case '4':
					sum += 10500;
					strcat(choiceMenu, "- ���� ���� (10500��)\n");
					break;
				case '5':
					sum += 11000;
					strcat(choiceMenu, "- ���� ���� (11000��)\n");
					break;
				case '6':
					sum += 11500;
					strcat(choiceMenu, "- ���� ���� (11500��)\n");
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
				printf("   1. �Ƹ޸�ī�� - 4000��\n");
				printf("   2. ���������� - 3500��\n");
				printf("   3. ī�� �� - 4500��\n");
				printf("   4. ī�� ��ī - 5000��\n");
				printf("   5. ī��� ��Ű�ƶ� - 5500��\n");
				printf("   6. �������� - 6000��\n");
				printf("   H. ù ��������\n");

				printf("��Ŀ�Ǹ� �����ϼ��� : ");
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
					strcat(choiceMenu, "- �Ƹ޸�ī�� (4000��)\n");
					break;
				case '2':
					sum += 3500;
					strcat(choiceMenu, "- ���������� (3500��)\n");
					break;
				case '3':
					sum += 4500;
					strcat(choiceMenu, "- ī�� �� (4500��)\n");
					break;
				case '4':
					sum += 5000;
					strcat(choiceMenu, "- ī�� ��ī (5000��)\n");
					break;
				case '5':
					sum += 5500;
					strcat(choiceMenu, "- ī��� ��Ű�ƶ� (5500��)\n");
					break;
				case '6':
					sum += 6000;
					strcat(choiceMenu, "- �������� (6000��)\n");
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
				printf("   1. ���� �� - 5000��\n");
				printf("   2. ����� ���� - 4700��\n");
				printf("   3. ��� �� �ڸ�Ƽ - 5300��\n");
				printf("   4. ��� ����Ƽ - 5500��\n");
				printf("   5. �� ��ũƼ - 4900��\n");
				printf("   6. ���� ������ - 5600��\n");
				printf("   H. ù ��������\n");

				printf("�����Ḧ �����ϼ��� : ");
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
					strcat(choiceMenu, "- ���� �� (5000��)\n");
					break;
				case '2':
					sum += 4700;
					strcat(choiceMenu, "- ����� ���� (4700��)\n");
					break;
				case '3':
					sum += 5300;
					strcat(choiceMenu, "- ��� �� �ڸ�Ƽ (5300��)\n");
					break;
				case '4':
					sum += 5500;
					strcat(choiceMenu, "- ��� ����Ƽ (5500��)\n");
					break;
				case '5':
					sum += 4900;
					strcat(choiceMenu, "- �� ��ũƼ (4900��)\n");
					break;
				case '6':
					sum += 5600;
					strcat(choiceMenu, "- ���� ������ (5600��)\n");
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
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
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
			printf("ī�带 �־� �ֽʽÿ�.\n");
			Sleep(5000);
			system("cls");
			sum = 0;
			printf("���� �Ǿ����ϴ�.\n");
			break;
		case 2:
			printf("������ �־��ֽʽÿ�.");
			printf("�Աݾ� : ");
			scanf_s("%d", &inputMoney);
			money += inputMoney;
			break;
		case 3:
			if (money < sum)
			{
				printf("�Աݵ� �ݾ��� �����ݾ׺��� �����ϴ�.\n");
			}
			else
			{
				money -= sum;
				printf("%d�� �����Ǿ� ��ݾ��� %d�� �Դϴ�.\n", sum, money);
				break;
			}
		case 4:
			printf("Menu�� ���ư��ڽ��ϴ�.\n");
			return;
		default:
			printf("��ȣ�� �ٽ� ����ּ���!\n");
		}
	} while (1);
}

void ShowPaymentMenu()
{
	printf("======================= Payment Menu =======================");
	printf("\n 1. ī�� ����");
	printf("\n 2. ���� �Ա� (���� ������ ���� ������ ���� �� �ּ���.)");
	printf("\n 3. ���� ����");
	printf("\n 4. ó�� �������� ���ư���");
}

int ChoiceNumber()
{
	int num;
	printf("\nChoice>");
	scanf_s("%d", &num);
	return num;
}