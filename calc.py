import math


def add(x, y):
    return x + y


def subtract(x, y):
    return x - y


def multiply(x, y):
    return x * y


def divide(x, y):
    return x / y


def power(x, y):
    return x ** y


def square_root(x):
    return math.sqrt(x)


def logarithm(x, base):
    return math.log(x, base)


def sin(x):
    return math.sin(math.radians(x))


def cos(x):
    return math.cos(math.radians(x))


def tan(x):
    return math.tan(math.radians(x))


def bodymassindex(height, weight):
    return round((weight / height**2),1)


def exponential(x):
    return round((2.71828 ** x), 3)


def temperature(temp):
    degree = int(temp[:-1])
    d = temp[-1]

    if d.upper() == "C":
        result = int(round((9 * degree) / 5 + 32))
        o = "Fahrenheit"
    elif d.upper() == "F":
        result = int(round((degree - 32) * 5 / 9))
        o = "Celsius"
    else:
        print("Input proper convention.")
        quit()
    print("The temperature in", o, "is ",end = '')
    return result


def calculate():
    print("Scientific Calculator")
    print("Operations:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Power")
    print("6. Square Root")
    print("7. Logarithm")
    print("8. Sine")
    print("9. Cosine")
    print("10. Tangent")
    print("11. BMI")
    print("12. Exponent")
    print("13. Temperature converter[C->F or F->C]")

    choice = int(input("Enter operation number (1-13): "))

    if choice in [1, 2, 3, 4, 5]:
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

    if choice == 1:
        result = add(num1, num2)
        print("Result:", result)
    elif choice == 2:
        result = subtract(num1, num2)
        print("Result:", result)
    elif choice == 3:
        result = multiply(num1, num2)
        print("Result:", result)
    elif choice == 4:
        result = divide(num1, num2)
        print("Result:", result)
    elif choice == 5:
        result = power(num1, num2)
        print("Result:", result)
    elif choice == 6:
        num = float(input("Enter a number: "))
        result = square_root(num)
        print("Result:", result)
    elif choice == 7:
        num = float(input("Enter a number: "))
        base = float(input("Enter the logarithm base: "))
        result = logarithm(num, base)
        print("Result:", result)
    elif choice == 8:
        angle = float(input("Enter an angle in degrees: "))
        result = sin(angle)
        print("Result:", result)
    elif choice == 9:
        angle = float(input("Enter an angle in degrees: "))
        result = cos(angle)
        print("Result:", result)
    elif choice == 10:
        angle = float(input("Enter an angle in degrees: "))
        result = tan(angle)
        print("Result:", result)
    elif choice == 11:
        h = float(input("Enter your height in meters: "))
        w = float(input("Enter your weight in kg: "))
        bmi = bodymassindex(h, w)
        print("Your BMI is: ", bmi)
        if bmi <= 18.5:
            print("You are underweight.")
        elif 18.5 < bmi <= 24.9:
            print("Your weight is normal.")
        elif 25 < bmi <= 29.29:
            print("You are overweight.")
        else:
            print("You are obese.")
    elif choice == 12:
        num = float(input("Enter a number: "))
        result = exponential(num )
        print("Result:", result)
    elif choice == 13:
        temp = (input("Enter the  temperature to convert:(e.g.32C,43F)  "))
        result = temperature(temp)
        print(result)

    else:
        print("Invalid choice!")

    # Ask for input again
    again = input("Perform another calculation? (yes/no): ")
    if again.lower() == "yes":
        calculate()
    elif again.lower() == "no":
        print("Goodbye!")
    else:
        print("Invalid choice!")
        again = input("Perform another calculation? (yes/no): ")

calculate()