import csv
import os
from tkinter import *
from tkinter import messagebox

import tksheet


def destroyDisplay(root):  # clears the entire window
    for widget in root.winfo_children():  # winfo_children returns a list of all widgets which are children of this widget.
        widget.destroy()  # destory all widgets


# Manager Functions for GUI
class ManagerFunctions:

    def __init__(self,root=None,managerWindow=None):
        destroyDisplay(root)
        self.root=root
        self.managerWindow = managerWindow
        self.display_window()

    def display_window(self):
        frame = Frame(self.root)
        frame.pack()
        self.root.geometry("1280x720+150+50")

        # staff menu label
        self.Staff_Label = Label(text="Manager Functions", font=('Segoe Script', 48), pady=50, bg="#2d2d2d", fg="#ffffff")
        self.Staff_Label.pack()

        # new table close tab frame
        row1Frame = Frame(self.root, bg="#2d2d2d")
        row1Frame.pack()

        # new table button
        self.MenuEdit_Button = Button(row1Frame, text="Menu Edits", font=('Segoe UI Light', 16), width=10)
        self.MenuEdit_Button.bind("<Button>", lambda e: MenuEdit(self.root, self))
        self.MenuEdit_Button.pack(side=LEFT, padx=5, pady=10)

        # new table button
        self.Track_Inventory_Button = Button(row1Frame, text="Track Inventory", font=('Segoe UI Light', 16), width=10)
        self.Track_Inventory_Button.pack(side=LEFT, padx=5, pady=10)

        # close tab button
        self.Items_86_Buttons = Button(row1Frame, text="86 Items", font=('Segoe UI Light', 16), width=10)
        self.Items_86_Buttons.pack(side=LEFT, padx=5, pady=10)

        # get check,check out frame
        row2Frame = Frame(self.root, bg="#2d2d2d")
        row2Frame.pack()

        # get check button
        self.Orders_History_Button = Button(row2Frame, text="Order History", font=('Segoe UI Light', 16), width=10)
        self.Orders_History_Button.pack(side=LEFT, padx=5, pady=10)

        # check out button
        self.CheckOut_Button = Button(row2Frame, text="Manager Message", font=('Segoe UI Light', 16), width=10)
        self.CheckOut_Button.pack(side=LEFT, padx=5, pady=10)

        # clock in button
        self.ClockIn_Button = Button(row2Frame, text="Comps & Discounts", font=('Segoe UI Light', 16), width=10)
        self.ClockIn_Button.pack(side=LEFT, padx=5, pady=10)

        # back and quit frame
        back_quit = Frame(self.root, bg="#2d2d2d")
        back_quit.pack()

        # back button (goes back to main login screen)
        self.Back_Button = Button(back_quit, text="Back", font=('Segoe UI Light', 16), width=10,
                                  command=self.Back_Pushed)
        self.Back_Button.pack(side=LEFT, padx=5, pady=50)

        # quit button
        self.Quit_Button = Button(back_quit, text="Quit", font=('Segoe UI Light', 16), width=10, command=frame.quit)
        self.Quit_Button.pack(side=LEFT, padx=5, pady=50)

    # Put Functions Under This Comment

    def Back_Pushed(self):
        destroyDisplay()
        self.managerWindow.display_window()


class MenuEdit:

    def __init__(self, root=None, manager_functions_window=None):
        self.root = root
        self.manager_functions_window = manager_functions_window
        destroyDisplay(root)
        frame = Frame(root)
        frame.pack()
        root.geometry("1280x720+150+50")

        add_menu_frame = Frame(root, bg="#2d2d2d")
        add_menu_frame.pack()

        hint_frame = Frame(root)
        hint_frame.pack()

        sheet_frame = Frame(root,pady=5)
        sheet_frame.pack()

        # cook menu label
        label = Label(frame, text="Menu Edits", font=('Segoe Script', 48), pady=20, bg="#2d2d2d", fg="#ffffff")
        label.pack()

        add_menu_button = Button(add_menu_frame, text="Add New Item Entry", font=('Segoe UI Light', 16), width=15)
        add_menu_button.pack(side=LEFT, padx=5, pady=10)

        save_entries_button = Button(add_menu_frame, text="Save Menu", font=('Segoe UI Light', 16), width=12)
        save_entries_button.pack(side=RIGHT, padx=5, pady=10)

        label = Label(hint_frame, text="* Right click on row selector for more options, double click for edit"
                                       , font=('Segoe Script', 11),
                      pady=15, bg="#2d2d2d", fg="#aaaaaa")
        label.pack()

        sheet = tksheet.Sheet(sheet_frame, width=645, height=400, show_x_scrollbar=False)
        sheet.grid()
        sheet.headers(["Item Number", "Item Name", "Item Category", "Item price ($)", "Stock"])
        read_menu_from_file(sheet)
        sheet.enable_bindings()
        add_menu_button.bind("<Button>", lambda e: add_menu_action(sheet))
        save_entries_button.bind("<ButtonRelease>", lambda e: save_menu_action(sheet,e))

        back_quit_frame = Frame(root, bg="#2d2d2d", pady=15)
        back_quit_frame.pack()

        back_button = Button(back_quit_frame, text="Back", font=('Segoe UI Light', 16), width=15,
                             command=self.back_to_manager_functions_window)
        back_button.pack(side=LEFT, padx=5)

        quit_button = Button(back_quit_frame, text="Quit", font=('Segoe UI Light', 16), width=15, command=root.quit)
        quit_button.pack(side=LEFT, padx=5)

    def back_to_manager_functions_window(self):
        destroyDisplay(self.root)
        self.manager_functions_window.display_window()


def read_menu_from_file(sheet):
    with open('menu.csv', 'r') as f:
        f.seek(0, os.SEEK_END)  # go to end of file
        if f.tell():  # if current position is truish (i.e != 0)
            f.seek(0)  # rewind the file for later use
            reader = csv.reader(f)
            next(reader)
            for row in reader:
                sheet.insert_row(row)

        else: #File is empty
            sheet.insert_row()


def add_menu_action(sheet):
    sheet.insert_row()
    sheet.redraw()


def save_menu_action(sheet,e):
    with open('menu.csv', 'w') as f:
        writer=csv.writer(f)
        writer.writerow(sheet.headers())
        writer.writerows(sheet.get_sheet_data())
        messagebox.showinfo("Save Menu", "Menu saved successfully")


