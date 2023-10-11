import socket, threading
import sqlite3
import copy

class Room:  # 채팅방 클래스.
    def __init__(self):
        self.clients = []
        self.allChat=None

    def addClient(self, c):  # c: 텔레마케터 . 클라이언트 1명씩 전담하는 쓰레드
        self.clients.append(c)

    def delClient(self, c):
        self.clients.remove(c)

    def sendMsgAll(self, msg):  # 채팅방에 있는 모든 사람한테 메시지 전송
        for i in self.clients:
            print(i)
            i.sendMsg(msg)


class ChatClient:  # 텔레마케터
    
    def __init__(self, r, soc,idid,f_list):
        self.room = r  # 채팅방. Room 객체
        self.id = idid  # 사용자 id
        self.soc = soc  # 사용자와 1:1 통신할 소켓def now_time():
        self.FriendList = f_list
    def readMsg(self):
       
        self.sendFriends() 
        
        msg = self.id + '님이 입장하셨습니다'
        self.room.sendMsgAll(msg)

        while True:
            time = self.soc.recv(1024).decode()
            msg = self.soc.recv(1024).decode()  # 사용자가 전송한 메시지 읽음
            if msg == '/stop':  # 종료 메시지이면 루프 종료
                self.soc.sendall(msg)  # 이 메시지를 보낸 한명에게만 전송
                self.room.delClient(self)
                break
            msg = time + self.id+': '+ msg
            self.room.sendMsgAll(msg)  # 모든 사용자에 메시지 전송
        self.room.sendMsgAll(self.id + '님이 퇴장하셨습니다.')

    def sendMsg(self, msg):
        self.soc.sendall(msg.encode(encoding='utf-8'))

    def sendFriends(self):
        lenOfId = str(len(self.FriendList))
        sendIdLen = lenOfId.encode(encoding='utf-8')
        self.soc.sendall(sendIdLen)
        
        for name in self.FriendList:
            sendIdLen = str(len(name))
            sendIdLen = sendIdLen.encode(encoding='utf-8')
            self.soc.sendall(sendIdLen)
            sendId = name.encode(encoding ='utf-8')
            self.soc.sendall(sendId)

class ChatServer:
    ip = 'localhost'  # or 본인 ip or 127.0.0.1
    port = 9999
    con = None
    cur = None
    def __init__(self):
        self.server_soc = None  # 서버 소켓(대문)
        self.room = Room()
        self.cont_id = ''
        self.listOfFriends = []
    def open(self):
        self.server_soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_soc.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_soc.bind((ChatServer.ip, ChatServer.port))
        self.server_soc.listen()

    def run(self):
        self.open()
        print('서버 시작11')
        
        while True:
            client_soc, addr = self.server_soc.accept()
            print(addr, '접속')
            
            while True:
                rec_option = int(client_soc.recv(1).decode())

                if rec_option == 0:
                    len_id1 = int(client_soc.recv(1).decode())
                    len_pw1 = int(client_soc.recv(1).decode())
                    
                    r1_id = client_soc.recv(len_id1).decode()
                    r1_pw = client_soc.recv(len_pw1).decode()
                    
                    self.addFriend(r1_id,r1_pw)
                else:
                    len_id2 = int(client_soc.recv(1).decode())
                    len_pw2 = int(client_soc.recv(1).decode())
                    
                    r2_id = client_soc.recv(len_id2).decode()
                    r2_pw = client_soc.recv(len_pw2).decode()
                    return_v = self.check_id_pw(r2_id,r2_pw)
                    if return_v == True:
                        success = 'True'.encode(encoding='utf-8')
                        client_soc.sendall(success)
                        self.cont_id = r2_id
                        break  
                    else:
                        success = 'False'.encode(encoding='utf-8')
                        client_soc.sendall(success)
            self.call_db_id()
            c = ChatClient(self.room, client_soc,self.cont_id,copy.deepcopy(self.listOfFriends))
            self.room.addClient(c)
            print('클라:',self.room.clients)
            th = threading.Thread(target=c.readMsg)
            th.start()
            
        self.server_soc.close()

    def addFriend(self,idid,pwpw):
        ChatServer.con = sqlite3.connect("C:/Users/Adria/accountDB.db")
        ChatServer.cur = ChatServer.con.cursor()
        ChatServer.cur.execute("CREATE TABLE IF NOT EXISTS userTable (id TEXT, pw TEXT)")
        ChatServer.cur.execute("INSERT INTO userTable VALUES('"+idid+"','"+pwpw+"')")       
        ChatServer.con.commit()
        ChatServer.con.close

    def call_db_id(self):
        ChatServer.con = sqlite3.connect("C:/Users/Adria/accountDB.db")
        ChatServer.cur = ChatServer.con.cursor()
        ChatServer.cur.execute("CREATE TABLE IF NOT EXISTS userTable (id Text, pw TEXT)")
        ChatServer.cur.execute("SELECT * FROM userTable")

        while(True):
            row = ChatServer.cur.fetchone()
            if row == None:
                break
            db_Id = row[0]
            self.listOfFriends.append(db_Id)
        ChatServer.con.close()
   
    def check_id_pw(self,idid,pwpw):
        ChatServer.con = sqlite3.connect("C:/Users/Adria/accountDB.db")
        ChatServer.cur = ChatServer.con.cursor()
        ChatServer.cur.execute("CREATE TABLE IF NOT EXISTS userTable (id Text, pw TEXT)")
        ChatServer.cur.execute("SELECT * FROM userTable")

        while(True):
            row = ChatServer.cur.fetchone()
            if row == None:
                break
            db_Id = row[0]
            db_Pw = row[1]
            if db_Id == idid and db_Pw == pwpw:
                return True
        ChatServer.con.close()
        
def main():
    cs = ChatServer()
    cs.run()

main()
