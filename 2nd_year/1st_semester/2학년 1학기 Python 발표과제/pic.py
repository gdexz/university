from tkinter import*
from tkinter.filedialog import *
from tkinter import messagebox

def clickN():
    global num,pLabel,photo
    num+=1
    
    if num > len(fnameList)-1:
        num = 0

    photo = PhotoImage(file= fnameList[num],master=win)
    pLabel.configure(image = photo)
    pLabel.image=photo

def clickP():
    global num,pLabel,photo
    num-=1
    
    if num < 0:
        num = len(fnameList)-1

    photo = PhotoImage(file= fnameList[num],master=win)
    pLabel.configure(image = photo)
    pLabel.image=photo

def AddPic():
    global win
    
    filename = str(askopenfilename(parent = win, filetypes = (("GIF 파일","*.gif"),("모든 파일","*.*"))))
    fnameList.append(filename)

fnameList = []
num = 0
win,pLabel,photo= None,None,None

def runPic():
    global win,pLabel,photo
    win=Tk()
    win.geometry("620x500")
    win.title("사진 앨범 보기")
    win.configure(bg = "white")
    btnP = Button(win,text = "<<이전",fg = "white",bg = "skyblue",font = ("맑은고딕",10,"bold"),command = clickP)
    btnN = Button(win,text = "다음>>",fg = "white",bg = "skyblue",font = ("맑은고딕",10,"bold"),command = clickN)
    btnA = Button(win,text = "사진 추가",fg = "white",bg = "lightpink",font = ("맑은고딕",10,"bold"),command = AddPic)

    btnP.place(x = 210,y=10)
    btnN.place(x = 370,y=10)
    btnA.place(x = 540,y=10)

    if len(fnameList) == 0:
        messagebox.showinfo("※안내","앨범이 비었습니다. 사진을 추가하세요")
        AddPic()

    photo = PhotoImage(file = fnameList[0],master = win)
    pLabel = Label(win,image = photo)

    pLabel.place(x = 130,y=70)    

    win.mainloop()
