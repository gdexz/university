import threading
import socket
import tkinter as tk
import random
from tkinter.simpledialog import *
from tkinter import messagebox
from ladder import*
from pic import*
from rpgame import*
import datetime
import time

class UiChatClient:
    # class 변수 / static 변수 : 모든 객체가 공유
    ip = 'localhost'
    port = 9999

    def __init__(self, mainMenu = None):
        self.id = ''
        self.pw = ''
        self.chatCont = None
        self.conn_soc = None  # 서버와 연결된 소켓
        self.win = None
        self.chatCont = None
        self.myChat = None
        self.sendBtn = None
        self.mainMenu = mainMenu
        self.listMenu = None
        self.fileMenu = None
        self.subMenu = None
        self.allChat =''
        self.list_Id = []
        self.lenOfId = 0
        
    def conn(self):
        self.conn_soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.conn_soc.connect((UiChatClient.ip, UiChatClient.port))

    def recv_func(self):
        self.lenOfId = self.conn_soc.recv(1)
        self.lenOfId = int(self.lenOfId.decode())

        for name in range(self.lenOfId):
            rec_id_len = int(self.conn_soc.recv(1).decode())
            rec_Id = self.conn_soc.recv(rec_id_len).decode()
            print(rec_Id)
            self.list_Id.append(rec_Id)
        
    def login(self):
        log = member(self.conn_soc)
        log.run_login()
        
    def now_time(self): 
        self.now = datetime.datetime.now()
        self.time_str=self.now.strftime('[%H:%M] ')
        return self.time_str
   
    def func_ptopen(self):
        runPic()
    
    def showFriendList(self):
        win2 = tk.Tk()
        win2.title('전체 친구 목록')
        win2.geometry('300x400')
        win2.configure(bg = "thistle1")
        label = tk.Label(win2,text = "● 친구: "+ str(self.lenOfId),width = 10,height = 1,font = ("맑은고딕",12),bg = "thistle1")
        label.pack()
        for i in range(self.lenOfId):
            name = self.list_Id[i]
            chatList = tk.Label(win2, text=name,width = 6,height = 2,font = ("맑은고딕",12),bg = "thistle1")
            chatList.pack()
                    
        win2.mainloop()
        
    def setWindow(self):
        self.win = tk.Tk()
        self.win.title('채팅프로그램')
        self.win.geometry('400x500+100+100')
        self.win.configure(bg = "lightblue")
        self.chatCont = tk.Label(self.win, width=50, height=30,bg = "lightblue")
        self.myChat = tk.Entry(self.win, width=40,border = 1,borderwidth = 3)
        self.sendBtn = tk.Button(self.win, width=10, text='전송',bg = "white",font = ("맑은고딕",10,"bold"))

        self.chatCont.grid(row=0, column=0, columnspan=2)
        self.myChat.grid(row=1, column=0, padx=8)
        self.sendBtn.grid(row=1, column=1)
        
        self.mainMenu = tk.Menu(self.win)
        self.win.config(menu = self.mainMenu)

        self.fileMenu = tk.Menu(self.mainMenu)
        self.listMenu = tk.Menu(self.mainMenu)
        self.mainMenu.add_cascade(label = "메뉴", menu = self.fileMenu)
        self.subMenu = tk.Menu(self.fileMenu)
        self.fileMenu.add_cascade(label = "게임",menu = self.subMenu)
        self.subMenu.add_command(label = "사다리 게임", command = runGame)
        self.subMenu.add_separator()
        self.subMenu.add_command(label = "제비뽑기", command= runRp)
        self.fileMenu.add_separator()
        self.fileMenu.add_command(label = "사진", command = self.func_ptopen)

        
        self.mainMenu.add_cascade(label = "친구 목록", menu = self.listMenu)
        self.listMenu.add_command(label = "친구 목록 보기", command = self.showFriendList)

        self.myChat.bind('<Return>', self.sendMsg)
        
    def sendMsg(self, e):  # 키보드 입력 받아 상대방에게 메시지 전송
        time = self.now_time()
        time = time.encode(encoding='utf-8')
        self.conn_soc.sendall(time)
        msg = self.myChat.get()
        self.myChat.delete(0, tk.END)
        self.myChat.config(text='')
        
        msg = msg.encode(encoding='utf-8')
        self.conn_soc.sendall(msg)

    def recvMsg(self):  # 상대방이 보낸 메시지 읽어서 화면에 출력
        self.recv_func()
        while True:
            msg = self.conn_soc.recv(1024)
            msg = msg.decode()+'\n'
            self.allChat += msg

            self.chatCont.config(text=self.allChat)
            if msg == '/stop':
                self.close()
                break

    def run(self):
        self.conn()
        self.login()
        self.setWindow()

        th2 = threading.Thread(target=self.recvMsg)
        th2.start()
        self.win.mainloop()

    def close(self):
        self.conn_soc.close()
        print('종료되었습니다')

class member:
    def __init__(self,rec_soc):
        self.conn_soc2 = rec_soc
        self.win = None
        self.win2 = None
        self.enterNewId = None
        self.enterNewPw =None
        self.enter_id = None
        self.enter_pw=None
        
    def set_login_win(self):
        self.win = Tk()
        self.win.title("카카오톡")
        self.win.geometry("500x700")
        self.win.configure(bg = "lightyellow")#win의 전체 배경색 변경
        img = PhotoImage(file = "kakao.gif")
        label = Label(self.win,image = img,width = 500,height = 500)
        label.image = img 
        label.pack()
        
        id_label = Label(self.win,text = "아이디", bg = "lightyellow",font = ("맑은고딕",10,"bold"))
        id_label.pack()

        self.enter_id = Entry(self.win)
        self.enter_id.pack()

        pw_label = Label(self.win,text = "비밀번호", bg = "lightyellow",font = ("맑은고딕",10,"bold"))
        pw_label.pack()

        self.enter_pw = Entry(self.win)
        self.enter_pw.config(show = "*")
        self.enter_pw.pack()

        button1 = Button(self.win,text = "회원가입 하기",bg = "white", font = ("맑은고딕",10,"bold"), command = self.join)
        button1.pack()
       
        button2 = Button(self.win,text = "로그인", bg = "white", font = ("맑은고딕",10,"bold"), command = self.check_login)
        button2.pack()
  
        self.win.mainloop()

    def join(self):
        self.win2 = Tk()
        self.win2.title("회원가입")
        self.win2.geometry("200x150")
        self.win2.configure(bg = "lightyellow")
        newId = Label(self.win2,text = "새로 만들 아이디를 입력하세요",font = ("맑은고딕",10,"bold"), bg = "lightyellow")
        newId.pack()
        self.enterNewId = Entry(self.win2)
        self.enterNewId.pack()
        
        newPw = Label(self.win2,text = "새로 만들 비밀번호를 입력하세요",font = ("맑은고딕",10,"bold"), bg = "lightyellow")
        newPw.pack()
        self.enterNewPw = Entry(self.win2, show = "*")
        self.enterNewPw.pack()
        
        btn = Button(self.win2,text = "회원가입하기",command = self.check_join, bg = "white",font = ("맑은고딕",10,"bold"))
        btn.pack()
            
        self.win2.mainloop()

    def check_join(self):
        
        if len(self.enterNewId.get()) == 0 or len(self.enterNewPw.get()) == 0:
            messagebox.showinfo("오류"," 아이디와 비밀번호는 한 글자 이상이어야 합니다")
        
        else:
            _id = self.enterNewId.get()
            _pw = self.enterNewPw.get()
            messagebox.showinfo("로그인","회원가입을 완료하였습니다")
            num = '0'
            join_or_login = num.encode(encoding = 'utf-8')
            self.conn_soc2.sendall(join_or_login)
            
            lenOfId = str(len(_id))
            lenOfId = lenOfId.encode(encoding='utf-8')
            self.conn_soc2.sendall(lenOfId)

             
            lenOfPw = str(len(_pw))
            lenOfPw = lenOfPw.encode(encoding='utf-8')
            self.conn_soc2.sendall(lenOfPw)
            
            sendId = _id.encode(encoding='utf-8')
            self.conn_soc2.sendall(sendId)                                                              #아이디를 서버로 보냄

            sendPw = _pw.encode(encoding='utf-8')
            self.conn_soc2.sendall(sendPw)                                                              #패스워드를 서버로 보냄
            self.win2.destroy()

    def check_login(self):#server에 id,pw를 보내고/ 일치하는지(True,False)를 다시 받아 로그인 성공 및 실패를 띄움
        _id = self.enter_id.get()
        _pw = self.enter_pw.get()
        num = '1'
        join_or_login = num.encode(encoding = 'utf-8')
        self.conn_soc2.sendall(join_or_login)

        lenOfId = str(len(_id))
        lenOfId = lenOfId.encode(encoding='utf-8')
        self.conn_soc2.sendall(lenOfId)

        lenOfPw = str(len(_pw))
        lenOfPw = lenOfPw.encode(encoding='utf-8')
        self.conn_soc2.sendall(lenOfPw)
            
        sendId = _id.encode(encoding='utf-8')
        self.conn_soc2.sendall(sendId)
            
        sendPw = _pw.encode(encoding='utf-8')
        self.conn_soc2.sendall(sendPw)

        receive_v = self.conn_soc2.recv(5).decode()
        
        if receive_v == 'True':
            messagebox.showinfo("로그인","로그인 성공")
            self.win.destroy()

        if receive_v == 'False':
            messagebox.showinfo("오류"," 아이디와 비밀번호가 틀립니다. 다시 로그인하세요")

    def run_login(self):
        self.set_login_win()
        
def main():
        conn = UiChatClient()
        conn.run()

main()
