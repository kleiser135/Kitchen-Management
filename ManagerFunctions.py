from tkinter import *
import tksheet

def destroyDisplay(root): #clears the entire window
    for widget in root.winfo_children(): #winfo_children returns a list of all widgets which are children of this widget.
        widget.destroy() #destory all widgets

class MenuEdit():

    def __init__(self, root=None):
        destroyDisplay(root)
        frame = Frame(root)
        frame.pack()
        root.geometry("1280x720+150+50")

        add_menu_frame=Frame(root,bg = "#2d2d2d")
        add_menu_frame.pack()

        frame2 = Frame(root)
        frame2.pack()

        # cook menu label
        label = Label(frame, text="Menu Edits", font=('Segoe Script', 48), pady=30, bg = "#2d2d2d", fg="#ffffff")
        label.pack()

        #clock in button
        AddMenuButton = Button(add_menu_frame, text="Add Menu Item", font=('Segoe UI Light', 16),  width = 20)
        AddMenuButton.pack(side=LEFT, padx=5, pady=20)


        sheet = tksheet.Sheet(frame2)
        sheet.grid()
        sheet.headers(["Item Name","Item Category","Item price"])
        sheet.set_sheet_data([[f"{ri + cj}" for cj in range(3)] for ri in range(2)])

        sheet.enable_bindings((
                        "single_select",

                       "row_select",

                       "column_width_resize",

                       "arrowkeys",

                       "right_click_popup_menu",

                       "rc_select",

                       "rc_insert_row",

                       "rc_delete_row",

                       "copy",

                       "cut",

                       "paste",

                       "delete",

                       "undo",

                       "edit_cell"))
