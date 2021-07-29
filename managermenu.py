def showMenu():
    print("Manager Menu")
    print("1) clock in")
    print("2) new table")
    print("3) get check")
    print("4) close tab")
    print("5) clock out")
    print("q) exit\n")

def managerMenu():
    while True:
        showMenu()
        choice = input('enter your choice: ').lower()

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

def main():
    managerMenu
