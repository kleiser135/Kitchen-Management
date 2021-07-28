#library imports
from tkinter import *
from tkinter import messagebox
import time
import pandas as pd
import sqlite3

def destroyDisplay(): #clears the entire window
    for widget in root.winfo_children(): #winfo_children returns a list of all widgets which are children of this widget.
        widget.destroy() #destory all widgets

class MainWindow():
    #constructor
    def __init__(self,master): #master means we pass in the main window (our variable 'root')
        frame = Frame(master) #makes a frame in the main window(root)
        frame.pack() #displays frame on screen
        root.geometry("200x100")
        #login label
        self.Login_Label=Label(text="Login")
        self.Login_Label.pack(side=LEFT)

        #pin text entry
        self.Pin_Entry = Entry()
        self.Pin_Entry.pack(side=LEFT)

        #login button
        self.Login_Button = Button(frame, text="Login", command=self.Login) #frame puts button widget in the frame
        self.Login_Button.pack(side=LEFT)

        #quit button
        self.Quit_Button = Button (frame, text="Quit", command=frame.quit)
        self.Quit_Button.pack(side=LEFT)

    #functions
    def Login(self):
        print("Login Button Pressed")

        userPIN = self.Pin_Entry.get()
        if len(userPIN) == 0:  # if entry box has nothing in it
            print("Nothing entered")
        else:
            print(userPIN) #check to see if value is correct with what user enters

        if userPIN == "cook":
            print("successfully logged in as a Cook")
            destroyDisplay()
            cookwindow=CookWindow() #calls cookwindow class widgets
        elif userPIN == "staff":
            print("successfully logged in as a Server")
            destroyDisplay()
            staffwindow=StaffWindow() #calls staffwindow class widgets
        else:
            print("Wrong PIN")


class CookWindow():
    def __init__(self):
        frame = Frame()
        frame.pack()
        root.geometry("400x100")
        #cook menu label
        self.Cook_Label = Label(text="Cook Menu")
        self.Cook_Label.pack(side=LEFT)

        #clock in button
        self.ClockIn_Button = Button(frame, text="Clock In")
        self.ClockIn_Button.pack(side=LEFT)

        # clock out button
        self.ClockOut_Button = Button(frame, text="Clock Out", command=self.clockOut)
        self.ClockOut_Button.pack(side=LEFT)

        # get check button
        self.GetCheck_Button = Button(frame, text="Get Check")
        self.GetCheck_Button.pack(side=LEFT)

        # track order time button
        self.TrackOrderTime_Button = Button(frame, text="Track Order Time")
        self.TrackOrderTime_Button.pack(side=LEFT)

        # back button (goes back to main login screen)
        self.Back_Button = Button(frame, text="Back", command=self.Back_Pushed)
        self.Back_Button.pack(side=BOTTOM)

        # quit button
        self.Quit_Button = Button(frame, text="Quit", command=frame.quit)
        self.Quit_Button.pack(side=BOTTOM)

    def Back_Pushed(self):
        destroyDisplay()
        mywindow=MainWindow(root)
    
    def clockOut(self):
        destroyDisplay()
        frame = Frame()
        frame.pack()
        root.geometry("150x100")  
        header = Label(frame,text = "Enter Pin to Clock Out")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")
        
        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open("cook.txt","a+")   
                clockOutFile.write("\nOut " + timestr) 
                clockOutFile.close
                destroyDisplay()
                mywindow=MainWindow(root)
        self.SubmitButton = Button(frame, text="Clock Out", command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")
        

        

        

class StaffWindow():
    def __init__(self):
        frame = Frame()
        frame.pack()
        root.geometry("400x100")    
        #cook menu label
        self.Staff_Label = Label(text="Server Menu")
        self.Staff_Label.pack(side=LEFT)

        #new table button
        self.NewTable_Button = Button(frame, text="New Table")
        self.NewTable_Button.pack(side=LEFT)

        #close tab button
        self.CloseTab_Button = Button(frame, text="Close Tab")
        self.CloseTab_Button.pack(side=LEFT)

        #get check button
        self.GetCheck_Button = Button(frame, text="Get Check")
        self.GetCheck_Button.pack(side=LEFT)

        #check out button
        self.CheckOut_Button = Button(frame, text="Check Out")
        self.CheckOut_Button.pack(side=LEFT)

        # clock in button
        self.ClockIn_Button = Button(frame, text="Clock In")
        self.ClockIn_Button.pack(side=LEFT)

        # clock out button
        self.ClockOut_Button = Button(frame, text="Clock Out")
        self.ClockOut_Button.pack(side=LEFT)

        # back button (goes back to main login screen)
        self.Back_Button = Button(frame, text="Back", command=self.Back_Pushed)
        self.Back_Button.pack(side=BOTTOM)

        # quit button
        self.Quit_Button = Button(frame, text="Quit", command=frame.quit)
        self.Quit_Button.pack(side=BOTTOM)

    def Back_Pushed(self):
        destroyDisplay()
        mywindow=MainWindow(root)

root = Tk()
mywindow = MainWindow(root)
root.mainloop()