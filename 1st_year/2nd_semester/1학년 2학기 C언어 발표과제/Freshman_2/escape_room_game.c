#include <stdio.h>
#include<windows.h> 
#include <stdlib.h>
#include "cardgamehead.h"
#include "avoidstarhead.h"
#include "lotteryhead.h"
#define MAX 10

void GameStart();
void ShowMainMenu();
int ReadInput();
void LogIn();
void Join();
void FirstStory();
void BeforeGame(int);
void ShowBeforeGameMenu();
void ShowGameMenu();
char YesOrNo();
void GameMenu(int);
void ReadData();
void WriteData();
enum { LOGIN = 1, JOIN, EXIT1 };
enum { NEWGAME = 1, CONTINUE, CHECKMYSCORE, LOGOUT };
enum { GAME1 = 1, GAME2, GAME3, TEASE, EXIT2 };

typedef struct User_Info
{
    char id[20];
    char password[20];
    int score;
}User_Info;

User_Info* user[MAX];
int numOfUser;

int main()
{
    int input;
    GameStart();
    ReadData();
    do
    {
        ShowMainMenu();
        input = ReadInput();
        system("cls");
        switch (input)
        {
        case LOGIN:
            LogIn();
            system("cls");
            break;
        case JOIN:
            Join();
            system("cls");
            break;
        case EXIT1:
            WriteData();
            return 0;
        default:
            printf("\n�ع�ȣ�� �ٽ� �����ϼ����\n");
        }
    } while (1);
}
void GameStart()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("     �������������������������������������������������������\n");
    printf("     ��                                                                                                        ��\n");
    printf("     ��  �����  �����  �����  �����  �����  �����      ����� ����� ����� ��      �� ��\n");
    printf("     ��  ��        ��        ��        ��    ��  ��    ��  ��            ��    �� ��    �� ��    �� ���  ��� ��\n");
    printf("     ��  �����  �����  ��        �����  �����  �����      ����� ��    �� ��    �� ��  ��  �� ��\n");
    printf("     ��  ��              ��  ��        ��    ��  ��        ��            ���     ��    �� ��    �� ��      �� ��\n");
    printf("     ��  �����  �����  �����  ��    ��  ��        �����      ��  ��� ����� ����� ��      �� ��\n");
    printf("     ��                                                                                                        ��\n");
    printf("     �������������������������������������������������������\n");
    printf("\n\n");
    system("pause");
    system("cls");

}

void ShowMainMenu()
{
    system("color E");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                 1. �α���                  ��\n");
    printf("\t\t\t\t��                 2. ȸ������                ��\n");
    printf("\t\t\t\t��                 3. ������                  ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��ȣ ���� > ");
}

int ReadInput()
{
    int input;
    scanf_s("%d", &input);
    return input;
}

void LogIn()
{
    char id[20], pwd[20];
    int i;

    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t���̵� �Է��ϼ��� : ");
    scanf_s(" %s", id, sizeof(id));
    printf("\t\t\t\t��й�ȣ�� �Է��ϼ��� : ");
    scanf_s(" %s", pwd, sizeof(pwd));

    for (i = 0; i < numOfUser; i++)
    {
        if (!(strcmp(id, user[i]->id)) && !(strcmp(pwd, user[i]->password)))
        {
            printf("\t\t\t\t�α��� �Ǿ����ϴ�!\n");
            system("cls");
            FirstStory();
            BeforeGame(i);
            break;
        }
        else if (!(strcmp(id, user[i]->id)))
        {
            printf("\t\t\t\t��й�ȣ�� �ٸ��ϴ�!\n");
            system("cls");
            break;
        }
    }
    if (i == numOfUser)
    {
        printf("\t\t\t\t�������� �ʴ� ���̵��Դϴ�!\n");
    }
}

void Join()
{
    user[numOfUser] = (User_Info*)malloc(sizeof(User_Info));
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t���̵� �Է��ϼ��� : ");
    scanf_s(" %s", user[numOfUser]->id, sizeof(user[numOfUser]->id));
    printf("\t\t\t\t��й�ȣ�� �Է��ϼ��� : ");
    scanf_s(" %s", user[numOfUser]->password, sizeof(user[numOfUser]->password));

    user[numOfUser]->score = 0;

    numOfUser++;
}

void FirstStory()
{
    system("color c");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\tESCAPE ROOM�� ���� ����� ȯ���մϴ�.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n \n\n\n\n\n");
    printf("\n\t\t����� ���� �̰��� �ݵ�� Ư�� ������ �ѱ�ž� ���踦 ��� Ż���� �� �ֽ��ϴ�.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t�� �ȿ��� ���ӱ⸦ �߰��Ͽ� ������ �Ͻʽÿ�.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\tƯ�� ������ �ѱ�ø� �� ���� Ż���� �� �ֽ��ϴ�.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t�� �� ���� Ż���Ͻñ� �ٶ��ϴ�.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t����� ���ϴ�. \n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
}

void ShowBeforeGameMenu()
{
    system("color A");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��       1. ���ο� ���� ���� (���� ����)      ��\n");
    printf("\t\t\t\t��       2. �̾ �ϱ�                       ��\n");
    printf("\t\t\t\t��       3. ���� Ȯ��                         ��\n");
    printf("\t\t\t\t��       4. �α׾ƿ�                          ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��ȣ ���� > ");
}

void BeforeGame(int index)
{
    int input;
    do
    {
        ShowBeforeGameMenu();
        input = ReadInput();
        system("cls");
        switch (input)
        {
        case NEWGAME:
            user[index]->score = 0;
            GameMenu(index);
            break;
        case CONTINUE:
            GameMenu(index);
            //������ ������ score+ �Ǵ� �ڵ� �ʿ�
            break;
        case CHECKMYSCORE:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t�����������������\n");
            printf("\t\t\t\t\t[ȸ�� ���̵�]\n");
            printf("\t\t\t\t\t%s\n", user[index]->id);
            printf("\n");
            printf("\t\t\t\t\t[�� ����]\n");
            printf("\t\t\t\t\t%d\n", user[index]->score);
            printf("\t\t\t\t�����������������\n");
            system("pause");
            system("cls");
            break;
        case LOGOUT:
            if (user[index]->score < 400)
            {
                printf("\n\n\n\n\n");
                printf("\t\t\t\t����� ������ %d������ 400���� ���� ���߱���.\n", user[index]->score);
                printf("\t\t\t\tŻ���Ͻ÷��� ������ ����Ͽ� ������ ȹ���Ͽ��ּ���.\n");
                return;// Bank �� LogIn �� Main , Do~while , ShowMainMenu
            }
        default:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t�ع�ȣ�� �ٽ� �����ϼ����\n");
        }
    } while (1);
}


void ShowGameMenu()
{
    system("color 9");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                1. ħ��                     ��\n");
    printf("\t\t\t\t��                2. å��                     ��\n");
    printf("\t\t\t\t��                3. ����                     ��\n");
    printf("\t\t\t\t��                4. �����                   ��\n");
    printf("\t\t\t\t��                5. Ż���ϱ�                 ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t��                                            ��\n");
    printf("\t\t\t\t�������������������������\n");
    printf("\t\t\t\t��ȣ ���� > ");
}

char YesOrNo()
{
    char yesorno;
    printf("\t\t\t\t������ Ȯ���Ͻðڽ��ϱ�? (Y/N) : ");
    scanf_s(" %c", &yesorno, sizeof(yesorno));

    return yesorno;
}

void GameMenu(int index)
{
    int input;
    char yesorno;
    do
    {
        ShowGameMenu();
        input = ReadInput();
        system("cls");
        switch (input)
        {
        case GAME1:
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\tħ�� �ؿ��� ���ӱ⸦ �߰��߽��ϴ�.\n");
            yesorno = YesOrNo();
            system("cls");
            if (yesorno == 'Y' || yesorno == 'y')
            {
                AnimalMainRole();
                user[index]->score += totalScore;
                totalScore = 0;
            }
            system("pause");
            system("cls");
            break;
        case GAME2:
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\tå�� �������� ���ӱ⸦ �߰��߽��ϴ�.\n");
            yesorno = YesOrNo();
            system("cls");
            if (yesorno == 'Y' || yesorno == 'y')
            {
                StarGame();
                user[index]->score += score_s;
                score_s = 0;
            }
            system("pause");
            system("cls");
            break;
        case GAME3:
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t���� �ȿ��� ���ӱ⸦ �߰��߽��ϴ�.\n");
            yesorno = YesOrNo();
            system("cls");
            if (yesorno == 'Y' || yesorno == 'y')
            {
                Lottery();
                user[index]->score += score_c;
                score_c = 100;
            }
            system("pause");
            system("cls");
            break;
        case TEASE:
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t�̰��� ���ӱⰡ �����ϴ�.\n");
            printf("\t\t\t\t����� ������ -100 �Ǿ����ϴ�.\n");
            user[index]->score -= 100;
            system("pause");
            system("cls");
            break;
        case EXIT2:
            if (user[index]->score < 400)
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t����� ������ %d������ 400���� ���� ���߱���.\n", user[index]->score);
                printf("\t\t\t\tŻ���Ͻ÷��� ������ ����Ͽ� ������ ȹ���Ͽ��ּ���.\n");
                system("pause");
                system("cls");
                return;
            }
            else
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t����� ������ %d������ 400���� �޼��Ͽ� ���踦 ȹ���Ͽ����ϴ�.\n", user[index]->score);
                system("pause"); system("cls");
                printf("\n\n\n\n\n");
                printf("\t\t\t\t���踦 ȹ���Ͽ� Ż�⿡ �����ϼ̽��ϴ�.\n");
                WriteData();
                exit(1);
            }
        default:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t�ع�ȣ�� �ٽ� �����ϼ����\n");
        }
    } while (1);
}

void ReadData()
{
    int i;
    FILE* fp;
    fopen_s(&fp, "game.txt", "rt");

    if (fp == NULL)
    {
        /*printf("Error_Read");*/
        return;
    }
    fscanf_s(fp, "%d", &numOfUser);

    for (i = 0; i < numOfUser; i++)
    {
        user[i] = (User_Info*)malloc(sizeof(User_Info));
        fscanf_s(fp, "%s %s %d", user[i]->id, sizeof(user[i]->id), user[i]->password, sizeof(user[i]->password), &user[i]->score);
    }
    fclose(fp);
}

void WriteData()
{
    FILE* fp;
    int i;
    fopen_s(&fp, "game.txt", "wt");
    if (fp == NULL)
    {
        printf("Error_Write");
        return;
    }

    fprintf(fp, "%d\n", numOfUser);

    for (i = 0; i < numOfUser; i++)
        fprintf(fp, "%s %s %d\n", user[i]->id, user[i]->password, user[i]->score);
    for (i = 0; i < numOfUser; i++)
        free(user[i]);

    fclose(fp);
}


char gamemenu_s()
{
    char choice;

    system("color 6");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�����������������������\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t��             �� ���ϱ� ����             ��\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t�����������������������\n\n");

    printf("\t\t\t\t������ �����Ͻðڽ��ϱ�? (Y/N) : ");
    scanf_s(" %c", &choice, sizeof(choice));

    return choice;
}

void Init(int map[][WIDTH])
{
    player[X] = WIDTH - 5;
    player[Y] = HEIGHT - 1;
}

void StarCreate(int map[HEIGHT][WIDTH])
{
    int i, x;

    for (i = 0; i < 4; i++)
    {
        x = rand() % 8 + 1;   // �� �� �� ���� ���� ������ 8 -> 8���� ���� �߿� �������� ����

        if (map[0][x] == STAR)
            i--;
        else
            map[0][x] = STAR;
    }
}

void MakeWall(int map[][WIDTH]) // �� ����� �ִ� �Լ�
{
    int y, x;

    for (y = 0; y < HEIGHT; y++)  // �� ����� �ڵ� : ���� ���� 1�� �ʱ�ȭ
    {
        map[y][0] = WALL;
        map[y][WIDTH - 1] = WALL;
    }

    StarCreate(map);
}

void MapDraw(int map[][WIDTH])
{
    system("cls");

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (player[Y] == y && player[X] == x)
                printf("��");

            else if (map[y][x] == WALL)
                printf("|");

            else if (map[y][x] == STAR)
                printf("��");

            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n Score : %d\n", score_s);
}

void Star_Update(int map[HEIGHT][WIDTH])
{
    for (int y = HEIGHT - 1; y >= 0; y--)
    {
        for (int x = 1; x < WIDTH - 1; x++)
        {
            if (map[y][x] == STAR)
            {
                map[y][x] = 0;

                if (y + 1 >= HEIGHT) // �� ������ �Ʒ��� �����ִ� �ڵ�
                {
                    map[HEIGHT - 1][1] = 0;

                    map[HEIGHT - 1][2] = 0;

                    map[HEIGHT - 1][3] = 0;

                    map[HEIGHT - 1][4] = 0;

                    map[HEIGHT - 1][5] = 0;

                    map[HEIGHT - 1][6] = 0;

                    map[HEIGHT - 1][7] = 0;

                    map[HEIGHT - 1][8] = 0;

                    StarCreate(map);

                    return;
                }
                else
                    map[y + 1][x] = STAR;

            }
        }
    }
}

int cheak_hit(int map[][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == STAR)
                if (player[Y] == y && player[X] == x)
                    return 1;
        }
    }
    return 0;
}



void PlayerMove(int map[][WIDTH])
{
    char ch;

    if (_kbhit())
    {
        ch = _getch();

        if (ch == 'a' || ch == 'A')
            if (map[player[Y]][player[X] - 1] != WALL)
                player[X]--;

        if (ch == 'd' || ch == 'D')
            if (map[player[Y]][player[X] + 1] != WALL)
                player[X]++;
    }

    if (cheak_hit(map) == 1)
        run = 0;

    else
        score_s++;
}

void StarGame()
{
    int map[HEIGHT][WIDTH] = { 0 };
    int x;
    char choice;

    while (run)
    {
        choice = gamemenu_s();
        switch (choice)
        {
        case 'Y': case 'y':
            MakeWall(map);

            Init(map);

            srand((unsigned)time(NULL));

            while (run)
            {
                Star_Update(map);

                MapDraw(map);

                PlayerMove(map);

                Sleep(33);
            }
            break;

        case 'N': case 'n':
            return;
        }
    }
    run = 1;
}



int AnimalMainRole()
{
    char choice;

    system("color b");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�����������������������\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t��           ����ī�� ������ ����         ��\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t�����������������������\n\n");

    printf("\t\t\t\t������ �����Ͻðڽ��ϱ�? (Y/N) : ");
    scanf_s(" %c", &choice, sizeof(choice));

    switch (choice)
    {
    case 'Y': case 'y':
        system("cls");

        srand((unsigned)time(NULL));

        initAnimalArray();
        initAnimalName();

        shuffleAnimal();

        int failcnt = 0;

        while (1)
        {
            int select1 = 0;
            int select2 = 0;

            //printAnimal();
            printQuestion();
            printf("\n������ ī�带 2�� ������ : ");
            scanf_s("%d %d", &select1, &select2);

            if (select1 == select2)
            {
                continue;
            }
            int firstSelect_x = conv_pos_x(select1);
            int firstSelect_y = conv_pos_y(select1);

            int secondSelect_x = conv_pos_x(select2);
            int secondSelect_y = conv_pos_y(select2);

            if (checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0
                && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]))
            {
                printf("\n\n����! : %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
                checkAnimal[firstSelect_x][firstSelect_y] = 1;
                checkAnimal[secondSelect_x][secondSelect_y] = 1;
            }
            else
            {
                printf("\n\n��! (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�.)\n");
                printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
                printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
                printf("\n\n");
                totalScore -= 10;

                failcnt++;
            }

            if (foundAllAnimal() == 1)
            {
                printf("\n\n �����մϴ�! ��� ������ �� ã�ҳ׿�. \n");
                printf("���ݱ��� �� %d�� �Ǽ��߽��ϴ�.\n\n", failcnt);
                printf("������ : %d�� �Դϴ�.\n", totalScore);
                break;
            }
        }
    case 'N': case 'n':
        return;
    }
    return 0;
}


void initAnimalArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "������";
    strAnimal[1] = "�ϸ�";
    strAnimal[2] = "������";
    strAnimal[3] = "�����";
    strAnimal[4] = "����";

    strAnimal[5] = "ȣ����";
    strAnimal[6] = "�䳢";
    strAnimal[7] = "��Ÿ";
    strAnimal[8] = "�⸰";
    strAnimal[9] = "��踻";
}

void shuffleAnimal()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    while (1)
    {
        int randPos = rand() % 20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x)
{
    return x / 5;
}

int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimal()
{
    printf("\n====== �̰� ����ε�.. ���� �����ִ°̴ϴ�..======\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n==================================================\n\n");
}

void printQuestion()
{
    printf("\n\n(����)\n");
    int seq = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] != 0)
            {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d", seq);
            }
            seq++;
        }
        printf("\n");
    }
}

int foundAllAnimal()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}


void Lottery()
{
    int i, num, random;
    char choice;

    system("color d");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t�����������������������\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t��           ����� ���� ���߱�           ��\n");
    printf("\t\t\t\t��                                        ��\n");
    printf("\t\t\t\t�����������������������\n\n");

    printf("\t\t\t\t������ �����Ͻðڽ��ϱ�? (Y/N) : ");
    scanf_s(" %c", &choice, sizeof(choice));

    switch (choice)
    {
    case 'Y': case 'y':
        system("cls");
        srand(time(NULL));
        random = rand() % 10;

        printf("\n\n\n\n\n");
        printf("\t\t\t\t����������������������������������������������������������������������������������\n");
        printf("\t\t\t\t��\t����� ���ڸ� ���纸����\t��\n");
        printf("\t\t\t\t����������������������������������������������������������������������������������\n");
        //printf("%d\n", random);
        for (i = 0; i < 4; i++)
        {
            printf("\t\t\t\t[%d round]\n", i + 1);
            printf("\t\t\t\t���� �Է� : ");
            scanf_s("%d", &num);
            printf("\n");

            if (num == random)
            {
                printf("\t\t\t\t������ϴ�\n");
                printf("\t\t\t\t�ݢܴ���� ��Ű ���̢ܢ�\n\n");
                break;
            }
            else
            {
                printf("\t\t\t\tƲ�Ƚ��ϴ�.\n");
                printf("\t\t\t\t�ٽ� ���纸����.\n\n");
                score_c -= 25;
            }
        }
        printf("\t\t\t\t����� ȹ���� ������ %d�Դϴ�.\n", score_c);

    case 'N': case 'n':
        return;
    }
}