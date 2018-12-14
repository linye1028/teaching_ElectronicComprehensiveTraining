from tkinter import *
import serial
def send():
	s.write((speed.get()+'m').encode())

s=serial.Serial("COM2",9600)	
root=Tk()
speed=StringVar()
speed.set("please input speed")
en1=Entry(root,textvariable=speed)
en1.pack(side=LEFT)
bt1=Button(root,text="发送",command=send)
bt1.pack(side=LEFT)
root.mainloop()

