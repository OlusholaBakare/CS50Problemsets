import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna.py [ dnaDatabase.csv ] [ individualFile.csv ]")
        return 1
    elif sys.argv[1][-3:] != "csv":
        print("PLease input a valid dna database csv file")
        return 1
    elif sys.argv[2][-3:] != "txt":
        print("PLease input a valid individual dna text file")
        return 1
    else:
        database = sys.argv[1]
        individual = sys.argv[2]

    # TODO: Read database file into a variable
    try:
        with open(database,"r") as databaseFile:
            databasereader = csv.reader(databaseFile)
            header = next(databasereader)
            databaseRecords = []
            for row in databasereader:
                databaseRecords.append(row)
    except:
        print("Couldn't open database file, please check your input")
    
    # TODO: Read DNA sequence file into a variable
    try:
        with open(individual,"r") as individualFile:
            individualVariable = individualFile.read()
    except:
        print("Couldn't open individual file, please check your input")

    # TODO: Find longest match of each STR in DNA sequence
    Firstno = longest_match(individualVariable,header[1])
    Secondno = longest_match(individualVariable,header[2])
    Thirdno = longest_match(individualVariable,header[3])

    # TODO: Check database for matching profiles
    for data in databaseRecords:
        if int(data[1]) == Firstno and int(data[2]) == Secondno and int(data[3]) == Thirdno:
            print(data[0])
            return
    print("No Match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()