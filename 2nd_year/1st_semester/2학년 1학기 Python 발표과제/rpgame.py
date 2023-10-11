from tkinter import *
import random
from tkinter.simpledialog import *

# 버튼 클릭시 실행될 함수 정의 -> 라벨 문자열 무작위로 변경
def click_btn():
    global label

    label["text"] = random.choice(name)
    label.update()

name = []
root,label= None,None

def runRp():
    global root,name,label
    nameInput = ''
    num = 0
    root = Tk() 
    root.title("제비뽑기 프로그램")
    root.resizable(False, False) 
    canvas = Canvas(root, width = 600, height = 800)
    canvas.pack()
    gazou = PhotoImage(file = "rulet.gif",master = root)
    canvas.create_image(300, 300, image = gazou)
    num = askinteger("닉네임 입력 : ", "참여할 사람의 수를 입력하세요")
    nameInput = askstring("사용자 1", "닉네임을 입력하세요")
    name.append(nameInput)
    for i in range(1, num) :
        nameInput = askstring("사용자 " + str(i), "닉네임을 입력하세요")
        name.append(nameInput)

    label = Label(root, text="??", font = ("Times New Roman", 120), bg = "white")
    label.place(x = 100, y = 250)

    # 버튼 생성, command 인자로 클릭 시 호출할 함수 지정
    button = Button(root, text = "제비뽑기", font = ("Times New Roman", 36), fg = "skyblue", bg = "white", command = click_btn)
    button.place(x = 150, y = 650)

    root.mainloop()
