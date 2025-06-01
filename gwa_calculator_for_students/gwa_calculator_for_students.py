#input pandemic or post pandemic (integer flag or boolean)
TypeSem = int(input("What type of semester were the grades obtained? [1] Pandemic or [2] Pre/Post-Pandemic: "))

#input five (5) grades and corresponding units
SDCounter = 0

Grade1 = float(input("(1) Enter grade: "))
Units1 = int(input("(1) Enter number of units: "))
if Grade1 >= 4:
    SDCounter += 1

Grade2 = float(input("(2) Enter grade: "))
Units2 = int(input("(2) Enter number of units: "))
if Grade2 >= 4:
    SDCounter += 1

Grade3 = float(input("(3) Enter grade: "))
Units3 = int(input("(3) Enter number of units: "))
if Grade3 >= 4:
    SDCounter += 1

Grade4 = float(input("(4) Enter grade: "))
Units4 = int(input("(4) Enter number of units: "))
if Grade4 >= 4:
    SDCounter += 1

Grade5 = float(input("(5) Enter grade: "))
Units5 = int(input("(5) Enter number of units: "))
if Grade5 >= 4:
    SDCounter += 1

#compute for total units
TotalUnits = Units1 + Units2 + Units3 + Units4 + Units5

#compute for total grades*units
GWA = round((((Grade1 * Units1) + (Grade2 * Units2) + (Grade3 * Units3) + (Grade4 * Units4) + (Grade5 * Units5)) / TotalUnits), 2)
print("Your GWA is " + str(GWA) + ".")
print("Your Total Units is " + str(TotalUnits) + ".")


#latin honors and underload/overload

if TypeSem == 1: #Pandemic
    if TotalUnits >= 12 and TotalUnits < 20: #Normal
        if SDCounter == 2:
            print("Scholastic Delinquency: Warning")
        elif SDCounter == 3:
            print("Scholastic Delinquency: Probation")
        elif SDCounter == 4:
            print("Scholastic Delinquency: Dismissal")
        elif SDCounter == 5:
            print("Scholastic Delinquency: Permanent Disqualification")
        if GWA == 1 and GWA <= 1.20:
            print("If you can maintain your GWA, you can graduate summa cum laude.")
        elif GWA > 1.20 and GWA <= 1.45:
            print("If you can maintain your GWA, you can graduate magna cum laude.")
        elif GWA > 1.45 and GWA <= 1.75:
            print("If you can maintain your GWA, you can graduate cum laude.")
        elif GWA > 1.75 and GWA <= 5:
            print("Improve your GWA to get latin honors.")
            
    elif TotalUnits >= 20: #Overload Permit
        OvPermit = int(input("Did you file for an overload permit? [1]Yes [2]No: "))
        
        if OvPermit == 1: #Yes
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                
        elif OvPermit == 2: #No
            print("Some of your courses will be dropped.")
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                
    elif TotalUnits < 12: #Underload Permit
        UnPermit = int(input("Did you file for an underload permit? [1]Yes [2]No: "))
        if UnPermit == 1: #Yes
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                    
        elif UnPermit == 2: #No
            print("You are underloaded since your total number of units is " + str(TotalUnits) + ". This disqualifies your from receiving latin honors since you did not apply for an underload permit.")


elif TypeSem == 2: #Pre/Post Pandemic

    if TotalUnits >= 15 and TotalUnits < 20: #Normal
        if SDCounter == 2:
            print("Scholastic Delinquency: Warning")
        elif SDCounter == 3:
            print("Scholastic Delinquency: Probation")
        elif SDCounter == 4:
            print("Scholastic Delinquency: Dismissal")
        elif SDCounter == 5:
            print("Scholastic Delinquency: Permanent Disqualification")
        if GWA == 1 and GWA <= 1.20:
            print("If you can maintain your GWA, you can graduate summa cum laude.")
        elif GWA > 1.20 and GWA <= 1.45:
            print("If you can maintain your GWA, you can graduate magna cum laude.")
        elif GWA > 1.45 and GWA <= 1.75:
            print("If you can maintain your GWA, you can graduate cum laude.")
        elif GWA > 1.75 and GWA <= 5:
            print("Improve your GWA to get latin honors.")
            
    elif TotalUnits >= 20: #Overload Permit
        OvPermit = int(input("Did you file for an overload permit? [1]Yes [2]No: ")) 
        if OvPermit == 1: #Yes
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                    
        elif OvPermit == 2: #No
            print("Some of your courses will be dropped.")
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                    
    elif TotalUnits < 15: #Underload Permit
        UnPermit = int(input("Did you file for an underload permit? [1]Yes [2]No: "))
        if UnPermit == 1: #Yes
            if SDCounter == 2:
                print("Scholastic Delinquency: Warning")
            elif SDCounter == 3:
                print("Scholastic Delinquency: Probation")
            elif SDCounter == 4:
                print("Scholastic Delinquency: Dismissal")
            elif SDCounter == 5:
                print("Scholastic Delinquency: Permanent Disqualification")
            if GWA == 1 and GWA <= 1.20:
                print("If you can maintain your GWA, you can graduate summa cum laude.")
            elif GWA > 1.20 and GWA <= 1.45:
                print("If you can maintain your GWA, you can graduate magna cum laude.")
            elif GWA > 1.45 and GWA <= 1.75:
                print("If you can maintain your GWA, you can graduate cum laude.")
            elif GWA > 1.75 and GWA <= 5:
                print("Improve your GWA to get latin honors.")
                    
        elif UnPermit == 2: #No
            print("You are underloaded since your total number of units is " + str(TotalUnits) + ". This disqualifies your from receiving latin honors since you did not apply for an underload permit.")
