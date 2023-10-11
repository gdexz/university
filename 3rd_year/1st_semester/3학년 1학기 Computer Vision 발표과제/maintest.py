import cv2
import mediapipe as mp
import tkinter as tk
from face_base import*
from face1_cat import*
from face2_ryan import*
from face3_sunglass import*
from face4_hat import*
from face5_sprout import*

def run_code(title):
    if title == "base":
        base_function()  # face_base.py 모듈의 함수 호출
    elif title == "cat":
        cat_function()  # face1_cat.py 모듈의 함수 호출
    elif title == "ryan":
        ryan_function()  # face2_ryan.py 모듈의 함수 호출
    elif title == "sunglasses":
        sunglasses_function()  # face3_sunglass.py 모듈의 함수 호출
    elif title == "hat":
        hat_function()  # face4_hat.py 모듈의 함수 호출
    elif title == "sprout":
        sprout_function()  # face5_hat.py 모듈의 함수 호출

def handle_click(event):
    widget = event.widget
    item = widget.get(widget.curselection())
    run_code(item)

root = tk.Tk()
root.title("Sticker List")

listbox = tk.Listbox(root)
listbox.pack()

# 목차 항목 추가
listbox.insert(tk.END, "base")
listbox.insert(tk.END, "cat")
listbox.insert(tk.END, "ryan")
listbox.insert(tk.END, "sunglasses")
listbox.insert(tk.END, "hat")
listbox.insert(tk.END, "sprout")

# 목차 클릭 이벤트 핸들러 등록
listbox.bind("<<ListboxSelect>>", handle_click)

root.mainloop()
