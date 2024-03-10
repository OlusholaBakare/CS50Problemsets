import cs50
def main():
	cardNumber = input("Number: ")
	print("Please input a valid number")
	validateNumber(cardNumber)

def validateNumber(i):
    if len(i) == 15 and i[:2] == "34" or i[:2] == "37":
        type = "AMEX"
    elif len(i) == 16 and i[:2] == "51" or i[:2] == "52" or i[:2] == "53" or i[:2] == "54" or i[:2] == "55" or i[:2] == "22":
        type = "MASTERCARD"
    elif len(i) == 13 or len(i) == 16 and i[:1] == "4":
        type = "VISA"
    else:
        type = "INVALID"
          
    if type == "INVALID":
        print(type)
        return
    else:
        lenght = len(i)
        addednums = 0
        doublednums = 0
        
        if (lenght % 2 == 0):
            for j in range(lenght):
                if j == 0 or j % 2 == 0:
                    number = i[j] - '0';
                    addingtodoublednums(number,doublednums);
                }else {
                    number = i[j] - '0';
                    addingtoaddednums(number,addednums);
                }
                
            }   
        }else {
            for (int j = 0; j < lenght; j++){
                if (j == 0 || j % 2 == 0){
                    number = i[j] - '0';
                    addingtoaddednums(number,addednums);
                }else {
                    number = i[j] - '0';
                    addingtodoublednums(number,doublednums);
                }
                
            }  
        } 
        
        int TotalSum = addednums + doublednums;
        int validity = TotalSum % 10;
        if (validity == 0){
            printf("%s\n",type);
        }
    }
}


# void addingtoaddednums(int num, int addednums){
#     /**
#      * Adds a number to the existing sum of numbers.
#      *
#      * @param num The number to be added.
#      * @param addednums The current sum of numbers.
#      *
#      * @returns None
#      */
#     addednums = addednums + num;
# }


# void addingtodoublednums(int num, int doublednums){
#     /**
#      * Adds the doubled value of a number to another number.
#      *
#      * @param num The number to be doubled and added.
#      * @param doublednums The number to which the doubled value is added.
#      *
#      * @returns None
#      */
#     int firstdigit;
#     int secondDigit;
#     num = num * 2;
#     if (num <= 9){
#         doublednums = doublednums + num;
#     }else {
#         firstdigit = num / 10;
#         secondDigit = num % 10;
#         num = firstdigit + secondDigit;
#         doublednums = doublednums + num;
#     }
# }