coupon_count = 2
cur_total = 0

def menu():
    print("\nWELCOME TO SILVERLOCK'S COFFEE SHOP\n")
    print('MAIN MENU')
    print('[1] Choose coffee')
    print('[2] Enter discount coupon')
    print('[3] Compute total and pay')
    print('[0] Exit')
    choice = int(input('enter choice: '))
    print('')
    return choice

def coffee_choices():
    print('COFFEES')
    print('[1] Espresso: P150.00')
    print('[2] Cappuccino: P200.00')
    print('[3] Latte: P180.00')
    print('[4] Americano: P140.00')
    print('[5] Mocha: P220.00')
    print('[0] Back to main menu')

def coffee(total):

    coffee_choices()

    total = 0
    option = 1
    choice = 0

    while(option != 0):
        choice = int(input('enter choice: '))
        print('')

        if(choice == 1):
            total += 150.00
            coffee_choices()

        elif(choice == 2):
            total += 200.00
            coffee_choices()

        elif(choice == 3):
            total += 180.00
            coffee_choices()

        elif(choice == 4):
            total += 140.00
            coffee_choices()

        elif(choice == 5):
            total += 220.00
            coffee_choices()

        elif(choice == 0):
            option = 0

        else:
            print("Invalid value")

    return total


def coupon(value):
    code = str(input("Enter coupon code: "))

    if code == "COFFEELOVER":
        discount = round(value * 0.15)
        value -= discount
        print("Discount (15%): P", discount)
        print("Total: P", value)

    elif code == "FREESHOT":
        discount = round(value * 0.10)
        value -= discount
        print("Discount (10%): P", discount)
        print("Total: P", value)

    else:
        print("Invalid value \n")
        print("Total: P", value)

    return value


def computepay(value):
    print("Total: P", value)
    value = DelChar(value)
    print("Total: P", value, "\n")

    senior_pwd = int(input("Do you have a PWD ID or a Senior Citizen ID ([1]Yes [0]No)?: "))

    if senior_pwd == 1:
        value = senior_pwd_disc(value)
        print("Total: P", value, "\n")

    elif senior_pwd == 0:
        print("Total: P", value, "\n")

    else:
        print("Invalid value")

    payment = None
    finish_payment = True

    while finish_payment == True:
        payment = int(input("Payment Amount: P "))

        if payment >= value:
            change = payment - value
            print("Change: P", change, "\n")
            print("Please wait for your order to arrive")
            finish_payment = False

        elif payment < value:
            print("That amount is not enough")
            print("Total: P", value, "\n")
            finish_payment = True

        else:
            print("Invalid")
            print("Total: P", value)
            finish_payment = True


def DelChar(value):
    DelChar = round(value * 0.07)
    print("Delivery Charge (7%):", DelChar)
    value += DelChar
    return value


def senior_pwd_disc(value):
    discount = round(value * 0.20)
    print("Senior/PWD Discount (20%):", discount)
    value -= discount
    return value

option = menu()
while(option!=0):
    if(option==1):
        total_1 = None
        total_1 = coffee(total_1)
        cur_total = total_1 + cur_total
        print("Current Total: P", cur_total)

    elif(option==2):
        if cur_total != 0:
            if coupon_count <= 2 and coupon_count > 0:
                cur_total_temp = coupon(cur_total)
                if cur_total_temp == cur_total:
                    coupon_count = coupon_count
                else:
                    cur_total = cur_total_temp
                    coupon_count -= 1
            elif coupon_count == 0:
                print("A max of TWO COUPONS ONLY  can be redeemed")
                print("Current Total: P", cur_total)
        else:
            print("You have not picked a coffee yet")

    elif(option==3):
        if cur_total != 0:
            computepay(cur_total)
            cur_total = 0
            coupon_count = 2
        else:
            print("You have not picked a coffee yet")
        
    else:
        print("Invalid value")

    option = menu()

print('Thanks for coming!')