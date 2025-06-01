#10/25/24

#DESCRIPTION
'''
Create a simple game library to add, view, remove and buy games from an online store, including saving and loading libraries (STREAM STORE)
'''

#Global Variables
games = {} #library
cart = {} #user cart
balance = 10000.00 #starting balance, is updated


def menu(): #main menu
	print("\nYour balance is:", balance)
	print("|WELCOME TO THE STREAM STORE!|")
	print('   [1] Add a game to store')
	print('   [2] Add a game to cart')
	print('   [3] View games list')
	print('   [4] View current cart')
	print('   [5] Remove a game from cart')
	print('   [6] Remove a game from library')
	print('   [7] Clear cart')
	print('   [8] Purchase games in cart')
	print('   [9] Check current balance')
	print('   [10] Save library')
	print('   [11] Load library')
	print('   [0] Exit')
	choice = int(input('Enter Your Choice: '))
	print('')
	return choice


def add_game_to_store(): #adds a game to the library
    global games

    game_id = int(input("Enter ID (number): "))
    for id in games.keys():
        if game_id == id:
            print("There is already a game with that ID!")
            return None
    games[game_id] = []

    game_title = str(input("Enter Title: "))
    game_title = game_title.upper()
    games[game_id].append(game_title)

    game_description = str(input("Enter Description: "))
    game_description = game_description.capitalize()
    games[game_id].append(game_description)

    game_copies = int(input("Enter No. of Copies: "))
    games[game_id].append(game_copies)

    game_price = float(input("Enter Price (Each): "))
    games[game_id].append(game_price)

    print(f'\nAdded {game_title} into the library!')


def add_game_to_cart(): #adds a game to the user cart
    global games

    print("Choose the ID of the game you want to add to your cart!")
    game_id = int(input("Enter ID (number): "))

    for id in cart.keys():
        if game_id == id:
            print("There is already a game with that ID!")
            return None

    if game_id in games.keys():
        data = games[game_id]
        cart[game_id] = data
        
        game_title = cart[game_id][0]
        print(f"'{game_title}' is now in your cart!")

    else:
        print("That game is not in the list!")


def view_games(): #displays all items in library
    global games

    if len(games) > 0:
        print("View the games to buy!")
        #print(games)
        print("|  ID  |  NAME  |  DESCRIPTION  |  STOCK  |  PRICE  |")
        for id,data in games.items():
            print("| ",id," | ",data[0]," | ",data[1]," | ",data[2]," | ",data[3]," |")

    else:
        print("Your Library is empty!")


def view_cart(): #displays all items in cart
    global cart

    if len(cart) > 0:
        print("View your cart!")
        #print(cart)
        print("|  ID  |  NAME  |  DESCRIPTION  |  PRICE  |")
        for id,data in cart.items():
            print("| ",id," | ",data[0]," | ",data[1]," | ",data[3]," |")

    else:
        print("Your cart is empty!")


def remove_game_from_cart(): #checks if given id is in cart, removes a chosen game
    global cart

    if len(cart) > 0:
        print("Choose the ID of the game you want to delete from your cart!")
        game_id = int(input("Enter ID (number): "))

        if game_id in cart.keys():
            game_title = cart[game_id][0]
            del cart[game_id]
            print(f"'{game_title}' is now removed from your cart!")

        else:
            print("That game is not in the cart!")
    else:
        print("Your cart is empty!")


def remove_games(): #checks if given id is in library, removes a chosen game
    global games

    if len(games) > 0:
        print("Choose the ID of the game you want to delete from the library!")
        game_id = int(input("Enter ID (number): "))

        if game_id in games.keys():
            game_title = games[game_id][0]
            del games[game_id]
            print(f"'{game_title}' is now removed from the library!")

        else:
            print("That game is not in the library!")
    else:
        print("Your library is empty!")


def clear_cart(): #Asks confirmation, removes all items in cart
    global cart

    if len(cart) > 0:
        print("Are you sure you want to delete all contents of your cart?")
        game_id = int(input("[1]yes [0]no: "))

        if game_id == 1:
            cart.clear()
            print("Your cart has been cleared!")

        elif game_id == 0:
            pass

    else:
        print("Your cart is already empty!")


def buy_games(): #buys games based on total price and stock in cart, resets cart after, cannot buy game already bought
    global cart
    global balance

    if len(cart) > 0:
        total = 0
        for data in cart.values(): #adds up for the total
            total += data[3]

        if total < balance: #checks balance
            for data in list(cart.values()): #checks current game/s stock
                if data[2] == 0:
                    print(f"Oops, {data[0]} is out of stock!")
                    print(f"Type 5 in the menu to remove a game in your cart!")
                    return None

            print("Stock: Available")
            print("Balance: ",balance)
            print("Total: ",total)

            balance = balance - total #updates user balance

            for id_1,data_1 in cart.items(): #deducts stock of games that are bought in cart
                for id_2,data_2 in games.items():
                    if id_1 == id_2:
                        data_2[2] -= 1

            print("Your purchase was successful!")

            cart.clear()

            return None

        else:
            print("You don't have enough balance in your account!")
            return None

    else:
        print("Your cart is empty!")


def check_balance(): #displays the user balance (starts at 10000)
    global balance
    print("Your balance is:", balance)


def save_library(): #saves current game library in a file called library.dat
	global games
	global balance
	game_data = None

	if len(games) > 0:
		fileHandle = open("library.dat","w") #saves data to library.dat, write mode

		fileHandle.write(f"{float(balance)}\n") #save current balance
		fileHandle.write(f"{int(len(games))}\n") #save no. of games
		for id,data in games.items():
			game_data = str(id) + "," + data[0] + "," + data[1] + "," + str(data[2]) + "," + str(data[3])
			fileHandle.write(game_data + "\n") #save each game

		fileHandle.close() #close to avoid data loss

		print("library.dat successfully saved!")

		cart.clear()
		games.clear()

	else:
		print("Your Library is empty!")


def load_library(): #updates balance, loads saved games to game dict from file called library.dat
    global balance
    global games

    if len(games) > 0: #confirmation
        print("Are you sure you want to load? There are games in your Library")
        game_id = int(input("[1]yes [0]no: "))

        if game_id == 1:
            cart.clear()
            games.clear()

        elif game_id == 0:
            return None

    readHandle = open("library.dat","r") #reads library.dat file
    
    line_number = 0 #for conditional, tracks line number in library.dat
    
    for line in readHandle:

        if line_number == 0: #balance update
            balance = float(line[:-1])
            print("Balance updated!")

        elif line_number == 1: #game amount loaded
            games_amount = int(line[:-1])
            print(f"There are {games_amount} games in your save")

        else: #appends line to game dict, iterates
            data = line[:-1].split(",")
            
            #variable assignment
            game_id = int(data[0])
            game_title = data[1]
            game_description = data[2]
            game_copies = int(data[3])
            game_price = float(data[4])
            
            #dictionary appending
            games[game_id] = []
            games[game_id].append(game_title)
            games[game_id].append(game_description)
            games[game_id].append(game_copies)
            games[game_id].append(game_price)

        line_number += 1

    readHandle.close() #clost to avoid data loss
    print("library.dat successfully loaded!")


option = menu() #starts menu

while(option!=0):

    if(option==1):
        add_game_to_store() #EX: {1: ['Genshin', 'noelle', 500, 0.0]}

    elif(option==2):
        add_game_to_cart() #EX: {1: ['Genshin', 'noelle', 500, 0.0]}

    elif(option==3):
        view_games() #EX: | 1 | Genshin | noelle | 500 | 0.0 |

    elif(option==4):
        view_cart() #EX: | 1 | Genshin | noelle | 0.0 |

    elif(option==5):
        remove_game_from_cart() #removes a single chosen game (Cart)

    elif(option==6):
        remove_games() #removes a single chosen game (library)

    elif(option==7):
        clear_cart() #removes all games (Cart)

    elif(option==8):
        buy_games() #buys games in cart

    elif(option==9):
        check_balance() #checks user balance
        
    elif(option==10):
    	save_library() #saves library in a different file
    
    elif(option==11):
    	load_library() #loads previously saved user game library

    else:
        print("Invalid value") #resets menu if any other number

    option = menu() #exit or option 0

print('Thanks for using the Stream store!')
