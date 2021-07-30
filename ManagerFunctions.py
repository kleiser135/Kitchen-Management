import csv
from tkinter import *
from tkinter import messagebox

import tksheet

def destroyDisplay(root):  # clears the entire window
    for widget in root.winfo_children():  # winfo_children returns a list of all widgets which are children of this widget.
        widget.destroy()  # destory all widgets


class MenuEdit():

    def __init__(self, root=None, manager_window=None):
        self.root = root
        self.managerWindow = manager_window
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
                             command=self.back_to_manager_window)
        back_button.pack(side=LEFT, padx=5)

        quit_button = Button(back_quit_frame, text="Quit", font=('Segoe UI Light', 16), width=15, command=root.quit)
        quit_button.pack(side=LEFT, padx=5)

    def back_to_manager_window(self):
        destroyDisplay(self.root)
        self.managerWindow.display_window()


def read_menu_from_file(sheet):
    with open('menu.csv', 'r') as f:
        reader=csv.reader(f)
        next(reader)
        for row in reader:
            sheet.insert_row(row)


def add_menu_action(sheet):
    sheet.insert_row()
    sheet.redraw()


def save_menu_action(sheet,e):
    with open('menu.csv', 'w') as f:
        writer=csv.writer(f)
        writer.writerow(sheet.headers())
        writer.writerows(sheet.get_sheet_data())
        messagebox.showinfo("Save Menu", "Menu saved successfully")


