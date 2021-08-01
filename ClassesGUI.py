#library imports
from tkinter import *
from tkinter import messagebox
import time
import sqlite3



def destroyDisplay(): #clears the entire window
    for widget in root.winfo_children(): #winfo_children returns a list of all widgets which are children of this widget.
        widget.destroy() #destory all widgets

class MainWindow():
    #constructor
    def __init__(self,master): #master means we pass in the main window (our variable 'root')
        frame = Frame(master, bg = "#2d2d2d") #makes a frame in the main window(root)
        frame.pack() #displays frame on screen
        root.geometry("1280x720+150+50")


        #Title label
        self.Title_Label=Label(frame, text="Guadalupes" , bg = "#2d2d2d", fg="#ffffff", pady=50, font=('Segoe Script', 48))
        self.Title_Label.pack()

        # pin label
        self.Pin_Label = Label(frame, text="PIN", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        self.Pin_Label.pack(side=LEFT, ipadx=10)

        #pin text entry
        self.Pin_Entry = Entry(frame, width=60)
        self.Pin_Entry.pack(side=LEFT, ipady=8)

        #login and quit button frame
        login_quit_frame=Frame(bg = "#2d2d2d")
        login_quit_frame.pack()

        #login button
        self.Login_Button = Button(login_quit_frame, text="Login",font=('Segoe UI Light', 16),  width = 10,command=self.Login) #frame puts button widget in the frame
        self.Login_Button.pack(side=LEFT, padx=5, pady=20)

        #quit button
        self.Quit_Button = Button (login_quit_frame, text="Quit", font=('Segoe UI Light', 16), width = 10,command=frame.quit)
        self.Quit_Button.pack(side=LEFT , padx=5, pady=20)

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
        elif userPIN == "manager":
            print("successfully logged in as a manager")
            destroyDisplay()
            managerwindow=ManagerWindow()
        else:
            print("Wrong PIN")


class CookWindow():
    def __init__(self):
        frame = Frame()
        frame.pack()
        root.geometry("1280x720+150+50")

        #cook menu label
        self.Cook_Label = Label(frame, text="Cook Menu", font=('Segoe Script', 48), pady=50, bg = "#2d2d2d", fg="#ffffff")
        self.Cook_Label.pack()

        #clock in/out frame
        clock_frame=Frame(bg = "#2d2d2d")
        clock_frame.pack()

        #clock in button
        self.ClockIn_Button = Button(clock_frame, text="Clock In", font=('Segoe UI Light', 16),  width = 10, command=self.clockIn)
        self.ClockIn_Button.pack(side=LEFT, padx=5, pady=10)

        # clock out button
        self.ClockOut_Button = Button(clock_frame, text="Clock Out", font=('Segoe UI Light', 16),  width = 10, command=self.clockOut)
        self.ClockOut_Button.pack(side=LEFT, padx=5, pady=10)

        #check and ordertime frame
        check_order_frame=Frame(bg = "#2d2d2d")
        check_order_frame.pack()

        # get check button
        self.GetCheck_Button = Button(check_order_frame, text="Get Check", font=('Segoe UI Light', 16),  width = 10)
        self.GetCheck_Button.pack(side=LEFT, padx=5, pady=10)

        # track order time button
        self.TrackOrderTime_Button = Button(check_order_frame, text="Order Time", font=('Segoe UI Light', 16),  width = 10)
        self.TrackOrderTime_Button.pack(side=LEFT, padx=5, pady=10)

        #back and quit frame
        back_quit = Frame(bg = "#2d2d2d")
        back_quit.pack()

        # back button (goes back to main login screen)
        self.Back_Button = Button(back_quit, text="Back", font=('Segoe UI Light', 16),  width = 10, command=self.Back_Pushed)
        self.Back_Button.pack(side=LEFT, padx=5, pady=50)

        # quit button
        self.Quit_Button = Button(back_quit, text="Quit", font=('Segoe UI Light', 16),  width = 10, command=frame.quit)
        self.Quit_Button.pack(side=LEFT, padx=5, pady=50)

    def Back_Pushed(self):
        destroyDisplay()
        mywindow=MainWindow(root)

    def clockOut(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock Out", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nOut " + timestr)
                clockOutFile.close
                destroyDisplay()
                mywindow=MainWindow(root)
        self.SubmitButton = Button(frame, text="Clock Out",font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")
    
    def clockIn(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock In", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nIn " + timestr)
                clockOutFile.close
                destroyDisplay()
                cookwindow=CookWindow()
        self.SubmitButton = Button(frame, text="Clock In", font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")







class StaffWindow():
    def __init__(self):
        frame = Frame()
        frame.pack()
        root.geometry("1280x720+150+50")

        #staff menu label
        self.Staff_Label = Label(text="Server Menu", font=('Segoe Script', 48), pady=50, bg="#2d2d2d", fg="#ffffff")
        self.Staff_Label.pack()

        #new table close tab frame
        new_close_frame=Frame(bg = "#2d2d2d")
        new_close_frame.pack()

        #new table button
        self.NewTable_Button = Button(new_close_frame, text="New Table", font=('Segoe UI Light', 16),  width = 10)
        self.NewTable_Button.pack(side=LEFT, padx=5, pady=10)

        #close tab button
        self.CloseTab_Button = Button(new_close_frame, text="Close Tab", font=('Segoe UI Light', 16),  width = 10)
        self.CloseTab_Button.pack(side=LEFT, padx=5, pady=10)

        #get check,check out frame
        get_out_check=Frame(bg = "#2d2d2d")
        get_out_check.pack()

        #get check button
        self.GetCheck_Button = Button(get_out_check, text="Get Check",font=('Segoe UI Light', 16),  width = 10)
        self.GetCheck_Button.pack(side=LEFT, padx=5, pady=10)

        #check out button
        self.CheckOut_Button = Button(get_out_check, text="Check Out",font=('Segoe UI Light', 16),  width = 10)
        self.CheckOut_Button.pack(side=LEFT, padx=5, pady=10)

        #clock in out frame
        clock_in_out = Frame(bg="#2d2d2d")
        clock_in_out.pack()

        # clock in button
        self.ClockIn_Button = Button(clock_in_out, text="Clock In", font=('Segoe UI Light', 16),  width = 10, command = self.clockIn)
        self.ClockIn_Button.pack(side=LEFT, padx=5, pady=10)

        # clock out button
        self.ClockOut_Button = Button(clock_in_out, text="Clock Out", font=('Segoe UI Light', 16),  width = 10, command = self.clockOut)
        self.ClockOut_Button.pack(side=LEFT, padx=5, pady=10)

        # back and quit frame
        back_quit = Frame(bg="#2d2d2d")
        back_quit.pack()

        # back button (goes back to main login screen)
        self.Back_Button = Button(back_quit, text="Back", font=('Segoe UI Light', 16),  width = 10, command=self.Back_Pushed)
        self.Back_Button.pack(side=LEFT, padx=5, pady=50)

        # quit button
        self.Quit_Button = Button(back_quit, text="Quit", font=('Segoe UI Light', 16),  width = 10 ,command=frame.quit)
        self.Quit_Button.pack(side=LEFT, padx=5, pady=50)

    def Back_Pushed(self):
        destroyDisplay()
        mywindow=MainWindow(root)

    def clockOut(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock Out", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nOut " + timestr)
                clockOutFile.close
                destroyDisplay()
                mywindow=MainWindow(root)
        self.SubmitButton = Button(frame, text="Clock Out", font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")

    def clockIn(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock In", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nIn " + timestr)
                clockOutFile.close
                destroyDisplay()
                staffwindow=StaffWindow()
        self.SubmitButton = Button(frame, text="Clock In", font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")

#Manager window for GUI
class ManagerWindow():
    def __init__(self):
        frame = Frame()
        frame.pack()
        root.geometry("1280x720+150+50")

        #staff menu label
        self.Staff_Label = Label(text="Manager Menu", font=('Segoe Script', 48), pady=50, bg="#2d2d2d", fg="#ffffff")
        self.Staff_Label.pack()

        #new table close tab frame
        new_close_frame=Frame(bg = "#2d2d2d")
        new_close_frame.pack()

        #new table button
        self.NewTable_Button = Button(new_close_frame, text="New Table", font=('Segoe UI Light', 16),  width = 10)
        self.NewTable_Button.pack(side=LEFT, padx=5, pady=10)

        #close tab button
        self.CloseTab_Button = Button(new_close_frame, text="Close Tab", font=('Segoe UI Light', 16),  width = 10)
        self.CloseTab_Button.pack(side=LEFT, padx=5, pady=10)

        #get check,check out frame
        get_out_check=Frame(bg = "#2d2d2d")
        get_out_check.pack()

        #get check button
        self.GetCheck_Button = Button(get_out_check, text="Get Check",font=('Segoe UI Light', 16),  width = 10)
        self.GetCheck_Button.pack(side=LEFT, padx=5, pady=10)

        #check out button
        self.CheckOut_Button = Button(get_out_check, text="Check Out",font=('Segoe UI Light', 16),  width = 10)
        self.CheckOut_Button.pack(side=LEFT, padx=5, pady=10)

        #clock in out frame
        clock_in_out = Frame(bg="#2d2d2d")
        clock_in_out.pack()

        # clock in button
        self.ClockIn_Button = Button(clock_in_out, text="Clock In", font=('Segoe UI Light', 16),  width = 10,  command = self.clockIn)
        self.ClockIn_Button.pack(side=LEFT, padx=5, pady=10)

        # clock out button
        self.ClockOut_Button = Button(clock_in_out, text="Clock Out", font=('Segoe UI Light', 16),  width = 10, command = self.clockOut)
        self.ClockOut_Button.pack(side=LEFT, padx=5, pady=10)

        # manager functions button
        self.ClockOut_Button = Button(clock_in_out, text="Clock Out", font=('Segoe UI Light', 16),  width = 10, command = self.clockOut)
        self.ClockOut_Button.pack(side=LEFT, padx=5, pady=10)

        # back and quit frame
        back_quit = Frame(bg="#2d2d2d")
        back_quit.pack()

        # back button (goes back to main login screen)
        self.Back_Button = Button(back_quit, text="Back", font=('Segoe UI Light', 16),  width = 10, command=self.Back_Pushed)
        self.Back_Button.pack(side=LEFT, padx=5, pady=50)

        # quit button
        self.Quit_Button = Button(back_quit, text="Quit", font=('Segoe UI Light', 16),  width = 10 ,command=frame.quit)
        self.Quit_Button.pack(side=LEFT, padx=5, pady=50)








    #Put Functions Under This Comment

    def showMenu():
        print("Manager Menu")
    print("1) clock in")
    print("2) new table")
    print("3) get check")
    print("4) close tab")
    print("5) clock out")
    print("q) exit\n")

    def managerMenu(choice):
        while True:

            if choice == '1':
                # clock in function
                print("")
            elif choice == '2':
                # new table
                print("")
            elif choice == '3':
                # get check
                print("")
            elif choice == '4':
                # close tab
                print("")
            elif choice == '5':
                # clock out
                print("")
            elif choice == 'q':
                # quit manager menu
                return
            else:
                print("")
    def Back_Pushed(self):
        destroyDisplay()
        mywindow=MainWindow(root)

    def clockOut(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock Out", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nOut " + timestr)
                clockOutFile.close
                destroyDisplay()
                mywindow=MainWindow(root)
        self.SubmitButton = Button(frame, text="Clock Out", font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")

    def clockIn(self):
        destroyDisplay()
        frame = Frame(bg = "#2d2d2d")
        frame.pack()
        root.geometry("250x100+700+300")
        header = Label(frame,text = "Enter Pin to Clock In", font=('Segoe UI Light', 16), bg = "#2d2d2d", fg="#ffffff")
        header.grid(row = 1, column = 1, ipadx = "10")
        pin_field = Entry(frame)
        pin_field.grid(row = 2, column = 1, ipadx = "10")
        timestr = time.strftime("%Y %m %d- %H %M %S")

        def submit():
            pin = pin_field.get()
            if(pin != ""):
                clockOutFile = open(pin + ".txt","a+")
                clockOutFile.write("\nIn " + timestr)
                clockOutFile.close
                destroyDisplay()
                managerwindow=ManagerWindow()
        self.SubmitButton = Button(frame, text="Clock In", font=('Segoe UI Light', 12), command = submit)
        self.SubmitButton.grid(row = 3, column = 1, ipadx = "10")





root = Tk()
root.configure(bg = "#2d2d2d") #changes background color of window
mywindow = MainWindow(root)
root.mainloop()
