import random
from tkinter import *
from tkinter.simpledialog import *
import copy

class PlayerXY:#player의 이름,현 위치,초기화 된 ladder을 가진 클래스
    x,y = 0,0
    subLadder = []
    name = ''
    
    def __init__(self,x,y,name,lad):
        self.subLadder = copy.deepcopy(lad)
        self.x = x
        self.y = y
        self.name = name
        
    def setXY(self,x,y):
        self.x = x
        self.y = y
        
    def markSubL(self,x,y):
        self.subLadder[x][y] = 4
        
def initLadder():
    global Row,Col,playerInform,ladder
    num = 0
    opInput = ''
    option, subLadder,name = [],[],[]
    
    num = askinteger("인원 수 입력","GAME을 PLAY할 인원을 입력하세요")
    Row = num+(num-1)+5 #두행 추가(Row-2는 옵션들 출력,Row-1은 해당 자리에 도착한 player의 이름 출력
    Col = num+(num-1)
    
    opInput = askstring("PLAYER","MY NAME")
    name.append(opInput)
   
    for i in range(1,num):
        opInput = askstring("PLAYER","PLAYER "+str(i+1))
        name.append(opInput)
    
    for i in range(num):
        opInput = askstring("내기 옵션","옵션 "+str(i+1))
        option.append(opInput)
        
    cnt = 0
    
    #사다리 초기화 작업
    for i in range(Row):#0-8
        subLadder = []
        cnt = 0
        for j in range(Col):#0-6
            if i == 0 and j % 2 == 0:
                subLadder.append(name[cnt])
                cnt+=1
            elif i == Row-2 and j % 2== 0:
                subLadder.append(option[cnt])
                cnt+=1
            elif i == Row-1 and j % 2 == 0:
                subLadder.append('')
                
            elif j % 2 == 0:
                subLadder.append(1)

            else:
                subLadder.append(0)

        ladder.append(subLadder)

    return name.copy()

def makeLadder(): #사다리 길을 뚫는 작업
    global ladder
    randomRow = 0
    
    for j in range(1,Col,2):#홀수 인덱스(초기화 된 사다리의 길 부분의 열들)
        for i in range(Col//2+1):#길을 뚫을 갯수, Col//2-1만큼 길을 만들어주기 위함
            
            while True:
                randomRow = random.randrange(2, Row-1-1-1)#첫행과 마지막 두 행을 제외(1번째 행~마지막 두행을 제외한 인덱스까지)
               
                if j == 1: #1열이라면 그냥 길을 뚫음
                    ladder[randomRow][j] = 1
                    break
                
                elif j!=1 and ladder[randomRow][j-2] == 0:  #1열이 아니면서 그 전 열에 길이 안뚫려 있다면 길을 뚫음
                    ladder[randomRow][j] = 1
                    break
                
                else:   #j!=1 and ladder[randomRow][j-2] == 1
                    continue
                    

def makeEachObj(name):
    global ladder
    cnt = 0
    
    for j in range(Col): #처음 초기화 상태의 위치(i,j),player의 이름,초기화 된 ladder을 객체 리스트로 만들어줌
        if j % 2 == 0:
            playerInform.append(PlayerXY(0,j,name[cnt],ladder))
            cnt+=1
              
def moveLadder(): #playeInform에 담긴 객체들의 위치를 이동 시키는 함수
    global ladder,playerInform
    
    for ob in playerInform: #사용자의 현위치,이름을 가지고 있는 클래스

        x = ob.x
        y = ob.y

        if x == Row-1: #마지막 행에 도달 했다면
            ladder[x][y] = ob.name
            continue
        
        elif x == 0:#아직 한번도 안움직인 상태
            ob.setXY(x+1,y)

        else:       #그 외
            if y == 0:
                if ob.subLadder[x][y+1]== 1: #길이 있다면
                    ob.markSubL(x, y)  #원래 있던 위치를 4로 마킹(왔던 길을 다시 가지 않기 위함)
                    ob.setXY(x,y+1)          #현 위치를 변경
                    
                elif ob.subLadder[x+1][y] == 1:
                    ob.markSubL(x, y)
                    ob.setXY(x+1,y)
                
                else:
                    ob.markSubL(x, y)
                    ob.setXY(x+2,y)
            
            elif y == Col-1:
                if ob.subLadder[x][y-1]== 1:
                    ob.markSubL(x, y)
                    ob.setXY(x,y-1)
                    
                elif ob.subLadder[x+1][y] == 1:
                    ob.markSubL(x, y)
                    ob.setXY(x+1,y)
                
                else:
                    ob.markSubL(x, y)
                    ob.setXY(x+2,y)
            
            else:
                if ob.subLadder[x][y+1]== 1:
                    ob.markSubL(x, y)
                    ob.setXY(x,y+1)

                elif ob.subLadder[x][y-1]== 1:
                    ob.markSubL(x, y)
                    ob.setXY(x,y-1)

                elif ob.subLadder[x+1][y] == 1:
                    ob.markSubL(x, y)
                    ob.setXY(x+1,y)

                else:
                    ob.markSubL(x, y)
                    ob.setXY(x+2,y)
    
def printLadder():#사다리 출력
    global win
    
    for i in range(Row):
        for j in range(Col):
            if ladder[i][j] == 1:
                label1 = Label(win,text='■',width = 40,height=25,fg = "black", bg = "black",font = ("맑은고딕", 11,"bold"))

            elif ladder[i][j] == 4:
                label1 = Label(win,text='■',width = 40,height=25,fg = "red", bg = "red",font = ("맑은고딕", 11,"bold"))
                
            elif ladder[i][j] == 0:
                label1 = Label(win,text=' ',width = 1,height=1, fg = "white",bg = "white")
                        
            else:   #name이나 option이라면
                label1 = Label(win,text=ladder[i][j],width = 20,height=20,fg = "blue",bg = "white",font = ("맑은고딕", 15,"bold"))
            
            label1.place(x = 55*(j+1),y = 55*(i+1),width = 40,height = 25)
            
    #y가 행이고 x가 열
    x = playerInform[0].x-1
    y = playerInform[0].y
    label1 = Label(win,text=str(ladder[x][y])+' 당첨!',width = 90,height=70,fg = "red", bg = "white",font = ("맑은고딕", 20,"bold"))
    label1.place(x=160,y=700,width = 90,height = 70)


def checkGame(): #게임종료 체크
    global ladder
    x,y,cnt = 0,0,0
    
    for ob in playerInform:     #각 객체를 받아옴
        for j in range(0,Col,2):    #ladder의 맨 마지막 행에 그 객체의 name이 있는지 확인 시켜주기 위함
            if ladder[Row-1][j] == ob.name:
                cnt+=1
                
    if cnt==len(playerInform):  #playerInform 안에 들어 있는 객체들의 name의 갯수와 같아면 게임 종료
        return True

    return False

def getMyRoute():
    for i in range(Row):
        for j in range(Col):
            if playerInform[0].subLadder[i][j] == 4:
                ladder[i][j] = 4
                
ladder=[]
playerInform = []   #player의 정보들을 담을 리스트
Row,Col= 0,0

win = None

def runGame():
    global win
    win = Tk()
    win.title("사다리 게임")
    win.geometry("650x900")
    win.configure(bg='white')

    n = initLadder()
    makeLadder()
    makeEachObj(n)

    while checkGame() != True: 
        moveLadder()

    getMyRoute()
    printLadder()

    win.mainloop()
    
