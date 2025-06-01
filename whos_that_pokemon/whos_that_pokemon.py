#09/27/24

import random

pokeList = [] #or pokeDex


def menu():
    print("\n|WELCOME TO WHO'S THAT POKEMON|")
    print('What Do You Want To Do?')
    print('~[1] Enter a Pokemon')
    print('~[2] View all Pokemon')
    print("~[3] Let's play ")
    print('~[0] Exit')
    choice = int(input('enter choice: '))
    print('')
    return choice


def ADD(): 
	pokemon = input("Enter a Pokemon: ")
	if len(pokemon) >= 5: #At least 5 letters
		pokemon = pokemon.upper() #user input always CAPS
		pokeList.append(pokemon) #add to pokeList
		print(f"['{pokemon}'] Has Been Added To The Database!!!")
	
	elif pokemon.isdigit() == True: #checks if input is number
		print("There cannot be a number!!!")
	
	else:
		print("Invalid, Please enter a name with 5 or more letters!!!")


def PLAY():
    if len(pokeList) >= 1: #checks if there's one or more pokemon

        random.shuffle(pokeList) #shuffles pokeList

        i = 0
        score = 0
        while i < len(pokeList): #asks pokeList amount of times
            hiddenPoke = SHUFFLE(pokeList[i]) #calls shuffle function
            print("Who's that Pokemon?", hiddenPoke)
            guess = input("Enter your guess: ")
            
            if guess.upper() == str(pokeList[i]): #guess is always CAPS
                score += 1
                print("Correct Answer\n")
            else:
                print("Incorrect Answer\n")
            
            i += 1

        print(f"!!!Your score is: {score}/{str(len(pokeList))}!!!\n") #final score
        pokeList.clear()

    else:
        print("You need at least one pokemon in the database to play!!!")


def SHUFFLE(pokeListElement):
    letters = list(pokeListElement) 
    # pokeListElement = ['P','I','K','A','C','H','U']
    indices = list(range(0, len(pokeListElement)))
    # pokeListElement = ['0','1','2','3','4','5','6']

    for i in range(0, 3): 
        randomIndex = random.randrange(0, len(indices)) #replace letters with asterisk using indices
        letters[indices.pop(randomIndex)] = '*' #removes picked indices so no duplicates then assign letters index to *

        #example ['P','I','*','*','C','*','U']

    pokeListElement = '' #reset pokeListElement so string
    for letter in letters: 
        pokeListElement += letter #spell out letters and store in variable
    
    return pokeListElement #pokeListElement = "PI**C*U"


option = menu() #starts menu
while(option!=0):
    if(option==1):
        addPoke = ADD()

    elif(option==2):
        if len(pokeList) >= 1: #checks if there's one or more pokemon
            print(pokeList) #prints list of pokemons
        else:
            print("You need at least one pokemon in the database to view!!!")

    elif(option==3):
        playPoke = PLAY()

    else:
        print("Invalid value")

    option = menu() #option 0 or exit

print('Thanks for playing!')