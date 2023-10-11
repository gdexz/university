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
            printf("\n※번호를 다시 선택하세요※\n");
        }
    } while (1);
}
void GameStart()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("     ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("     ■                                                                                                        ■\n");
    printf("     ■  ■■■■  ■■■■  ■■■■  ■■■■  ■■■■  ■■■■      ■■■■ ■■■■ ■■■■ ■      ■ ■\n");
    printf("     ■  ■        ■        ■        ■    ■  ■    ■  ■            ■    ■ ■    ■ ■    ■ ■■  ■■ ■\n");
    printf("     ■  ■■■■  ■■■■  ■        ■■■■  ■■■■  ■■■■      ■■■■ ■    ■ ■    ■ ■  ■  ■ ■\n");
    printf("     ■  ■              ■  ■        ■    ■  ■        ■            ■■     ■    ■ ■    ■ ■      ■ ■\n");
    printf("     ■  ■■■■  ■■■■  ■■■■  ■    ■  ■        ■■■■      ■  ■■ ■■■■ ■■■■ ■      ■ ■\n");
    printf("     ■                                                                                                        ■\n");
    printf("     ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\n\n");
    system("pause");
    system("cls");

}

void ShowMainMenu()
{
    system("color E");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■                 1. 로그인                  □\n");
    printf("\t\t\t\t□                 2. 회원가입                ■\n");
    printf("\t\t\t\t■                 3. 나가기                  □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t번호 선택 > ");
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
    printf("\t\t\t\t아이디를 입력하세요 : ");
    scanf_s(" %s", id, sizeof(id));
    printf("\t\t\t\t비밀번호를 입력하세요 : ");
    scanf_s(" %s", pwd, sizeof(pwd));

    for (i = 0; i < numOfUser; i++)
    {
        if (!(strcmp(id, user[i]->id)) && !(strcmp(pwd, user[i]->password)))
        {
            printf("\t\t\t\t로그인 되었습니다!\n");
            system("cls");
            FirstStory();
            BeforeGame(i);
            break;
        }
        else if (!(strcmp(id, user[i]->id)))
        {
            printf("\t\t\t\t비밀번호가 다릅니다!\n");
            system("cls");
            break;
        }
    }
    if (i == numOfUser)
    {
        printf("\t\t\t\t존재하지 않는 아이디입니다!\n");
    }
}

void Join()
{
    user[numOfUser] = (User_Info*)malloc(sizeof(User_Info));
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t아이디를 입력하세요 : ");
    scanf_s(" %s", user[numOfUser]->id, sizeof(user[numOfUser]->id));
    printf("\t\t\t\t비밀번호를 입력하세요 : ");
    scanf_s(" %s", user[numOfUser]->password, sizeof(user[numOfUser]->password));

    user[numOfUser]->score = 0;

    numOfUser++;
}

void FirstStory()
{
    system("color c");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\tESCAPE ROOM에 오신 당신을 환영합니다.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n \n\n\n\n\n");
    printf("\n\t\t당신이 갇힌 이곳은 반드시 특정 점수를 넘기셔야 열쇠를 얻어 탈출할 수 있습니다.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t방 안에서 게임기를 발견하여 게임을 하십시오.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t특정 점수를 넘기시면 이 곳을 탈출할 수 있습니다.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t꼭 이 곳을 탈출하시기 바랍니다.\n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t행운을 빕니다. \n\n\n\n");
    printf("\n\n\n\n\n\n\n"); system("pause"); system("cls");
}

void ShowBeforeGameMenu()
{
    system("color A");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■       1. 새로운 게임 시작 (점수 리셋)      □\n");
    printf("\t\t\t\t□       2. 이어서 하기                       ■\n");
    printf("\t\t\t\t■       3. 점수 확인                         □\n");
    printf("\t\t\t\t□       4. 로그아웃                          ■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■□■□■□■□■□■□■□■□■□■□■□■□\n");
    printf("\t\t\t\t번호 선택 > ");
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
            //게임이 끝나면 score+ 되는 코딩 필요
            break;
        case CHECKMYSCORE:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
            printf("\t\t\t\t\t[회원 아이디]\n");
            printf("\t\t\t\t\t%s\n", user[index]->id);
            printf("\n");
            printf("\t\t\t\t\t[총 점수]\n");
            printf("\t\t\t\t\t%d\n", user[index]->score);
            printf("\t\t\t\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
            system("pause");
            system("cls");
            break;
        case LOGOUT:
            if (user[index]->score < 400)
            {
                printf("\n\n\n\n\n");
                printf("\t\t\t\t당신의 점수는 %d점으로 400점을 넘지 못했군요.\n", user[index]->score);
                printf("\t\t\t\t탈출하시려면 게임을 계속하여 점수를 획득하여주세요.\n");
                return;// Bank → LogIn → Main , Do~while , ShowMainMenu
            }
        default:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t※번호를 다시 선택하세요※\n");
        }
    } while (1);
}


void ShowGameMenu()
{
    system("color 9");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■                1. 침대                     □\n");
    printf("\t\t\t\t□                2. 책상                     ■\n");
    printf("\t\t\t\t■                3. 옷장                     □\n");
    printf("\t\t\t\t□                4. 냉장고                   ■\n");
    printf("\t\t\t\t■                5. 탈출하기                 □\n");
    printf("\t\t\t\t□                                            ■\n");
    printf("\t\t\t\t■                                            □\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t번호 선택 > ");
}

char YesOrNo()
{
    char yesorno;
    printf("\t\t\t\t게임을 확인하시겠습니까? (Y/N) : ");
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
            printf("\t\t\t\t침대 밑에서 게임기를 발견했습니다.\n");
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
            printf("\t\t\t\t책상 서랍에서 게임기를 발견했습니다.\n");
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
            printf("\t\t\t\t옷장 안에서 게임기를 발견했습니다.\n");
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
            printf("\t\t\t\t이곳엔 게임기가 없습니다.\n");
            printf("\t\t\t\t당신의 점수가 -100 되었습니다.\n");
            user[index]->score -= 100;
            system("pause");
            system("cls");
            break;
        case EXIT2:
            if (user[index]->score < 400)
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t당신의 점수는 %d점으로 400점을 넘지 못했군요.\n", user[index]->score);
                printf("\t\t\t\t탈출하시려면 게임을 계속하여 점수를 획득하여주세요.\n");
                system("pause");
                system("cls");
                return;
            }
            else
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t당신의 점수는 %d점으로 400점을 달성하여 열쇠를 획득하였습니다.\n", user[index]->score);
                system("pause"); system("cls");
                printf("\n\n\n\n\n");
                printf("\t\t\t\t열쇠를 획득하여 탈출에 성공하셨습니다.\n");
                WriteData();
                exit(1);
            }
        default:
            printf("\n\n\n\n\n");
            printf("\t\t\t\t※번호를 다시 선택하세요※\n");
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
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□             별 피하기 게임             ■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n\n");

    printf("\t\t\t\t게임을 시작하시겠습니까? (Y/N) : ");
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
        x = rand() % 8 + 1;   // 양 옆 벽 빼고 남은 공간이 8 -> 8개의 공간 중에 랜덤으로 지정

        if (map[0][x] == STAR)
            i--;
        else
            map[0][x] = STAR;
    }
}

void MakeWall(int map[][WIDTH]) // 벽 만들어 주는 함수
{
    int y, x;

    for (y = 0; y < HEIGHT; y++)  // 벽 만들기 코드 : 벽의 값은 1로 초기화
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
                printf("▲");

            else if (map[y][x] == WALL)
                printf("|");

            else if (map[y][x] == STAR)
                printf("☆");

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

                if (y + 1 >= HEIGHT) // 맨 윗줄을 아래로 내려주는 코드
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
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□           동물카드 뒤집기 게임         ■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n\n");

    printf("\t\t\t\t게임을 시작하시겠습니까? (Y/N) : ");
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
            printf("\n뒤집을 카드를 2개 고르세요 : ");
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
                printf("\n\n빙고! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
                checkAnimal[firstSelect_x][firstSelect_y] = 1;
                checkAnimal[secondSelect_x][secondSelect_y] = 1;
            }
            else
            {
                printf("\n\n땡! (틀렸거나, 이미 뒤집힌 카드입니다.)\n");
                printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
                printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
                printf("\n\n");
                totalScore -= 10;

                failcnt++;
            }

            if (foundAllAnimal() == 1)
            {
                printf("\n\n 축하합니다! 모든 동물을 다 찾았네요. \n");
                printf("지금까지 총 %d번 실수했습니다.\n\n", failcnt);
                printf("점수는 : %d점 입니다.\n", totalScore);
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
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";

    strAnimal[5] = "호랑이";
    strAnimal[6] = "토끼";
    strAnimal[7] = "낙타";
    strAnimal[8] = "기린";
    strAnimal[9] = "얼룩말";
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
    printf("\n====== 이건 비밀인데.. 몰래 보여주는겁니다..======\n\n");
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
    printf("\n\n(문제)\n");
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
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□           행운의 숫자 맞추기           ■\n");
    printf("\t\t\t\t■                                        □\n");
    printf("\t\t\t\t□■□■□■□■□■□■□■□■□■□■□■\n\n");

    printf("\t\t\t\t게임을 시작하시겠습니까? (Y/N) : ");
    scanf_s(" %c", &choice, sizeof(choice));

    switch (choice)
    {
    case 'Y': case 'y':
        system("cls");
        srand(time(NULL));
        random = rand() % 10;

        printf("\n\n\n\n\n");
        printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("\t\t\t\t┃\t행운의 숫자를 맞춰보세요\t┃\n");
        printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        //printf("%d\n", random);
        for (i = 0; i < 4; i++)
        {
            printf("\t\t\t\t[%d round]\n", i + 1);
            printf("\t\t\t\t숫자 입력 : ");
            scanf_s("%d", &num);
            printf("\n");

            if (num == random)
            {
                printf("\t\t\t\t맞췄습니다\n");
                printf("\t\t\t\t♬♪당신은 럭키 가이♪♬\n\n");
                break;
            }
            else
            {
                printf("\t\t\t\t틀렸습니다.\n");
                printf("\t\t\t\t다시 맞춰보세요.\n\n");
                score_c -= 25;
            }
        }
        printf("\t\t\t\t당신이 획득한 점수는 %d입니다.\n", score_c);

    case 'N': case 'n':
        return;
    }
}