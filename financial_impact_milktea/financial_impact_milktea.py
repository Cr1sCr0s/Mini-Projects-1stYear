interestRate = 0.04

#user input for milk tea in a week
MTBuy = int( input('\nHow many times in a week do you buy milk tea? '))

#user input for milk tea cost
MTCost = int( input('How much does your milk tea order typically cost? '))

#calculate (52 weeks in a year)
MTYear = MTBuy * 52
PMT1 = MTYear * MTCost

#total amount spent in a year
print(
'\nThe total amount you will spend on milk tea per year is Php ' + str(PMT1) + '.\n'
)

#five FVs and spending
PMT1 = MTYear * MTCost
#PMT2 = PMT1 * 2
PMT5 = PMT1 * 5 
PMT10 = PMT1 * 10
PMT20 = PMT1 * 20
PMT40 = PMT1 * 40

FV1 = PMT1 * ((((1 + interestRate)**1) - 1) / interestRate) #1 year
#FV2 = PMT1 * ((((1 + interestRate)**2) - 1) // interestRate) #2 year
FV5 = PMT1 * ((((1 + interestRate)**5) - 1) / interestRate) #5 year
FV10 = PMT1 * ((((1 + interestRate)**10) - 1) / interestRate) #10 year
FV20 = PMT1 * ((((1 + interestRate)**20) - 1) / interestRate) #20 year
FV40 = PMT1 * ((((1 + interestRate)**40) - 1) / interestRate) #40 year

#interest = type(((((1 + interestRate)**2) - 1) // interestRate))

#Output of FV and spending
print(
'If you save this money every year in a high-yield bank account earning 4% APY, you would have earned an extra \n' 
'   Php ' + str(round(FV1)) + ' in 1 year (vs. spending Php ' + str(PMT1) + '),\n'
#'Php ' + str(FV2) + ' in 2 years (vs. spending Php ' + str(PMT2) + '),\n'
'   Php ' + str(round(FV5)) + ' in 5 years (vs. spending Php ' + str(PMT5) + '),\n'
'   Php ' + str(round(FV10)) + ' in 10 years (vs. spending Php ' + str(PMT10) + '),\n'
'   Php ' + str(round(FV20)) + ' in 20 years (vs. spending Php ' + str(PMT20) + '), and\n'
'   Php ' + str(round(FV40)) + ' in 40 years (vs. spending Php ' + str(PMT40) + ').\n'
#+str(interest)
)
