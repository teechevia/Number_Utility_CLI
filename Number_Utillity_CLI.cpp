#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

int choose(){
    int choice;
    cout << "========================\n\t NUMBER TOOL\n========================\n\n";
    cout << "1. Check prime\n2. Factorial\n3. Fibonacci\n4. GCD\n5. LCM\n6. Number statistics\n7. Exit\n\n";
    cout << "Choice: ";
    if(!(cin >> choice)){
        return 0;
    }
    return choice;
}

void Check_prime(int value){
    if(value<=1){
        cout << "It is not prime";
        return;
    }
    bool check = true;
    for(int i = 2; i<(value/2 + 1); i++){
        if(value%i == 0){
            check = false;
        }
    }
    if(check){
        cout << "It is prime\n";
    }
    else{
        cout << "It is not prime\n";
    }
}

int Factorial(int value){
    if(value<=0){
        cout << "Use only natural numbers.";
        return -1;
    }
    int ans = 1;
    while(value!=1){
        ans *= value;
        value--;
    }
    return ans;
}

void Fibonacci(int value){
    int a = 0;
    int b = 1;
    for(int i = 0; i<value; i++){
        cout << a << " ";
        int next = a+b;
        a = b;
        b = next;
    }
}

int GCD(int first_val, int second_val){
    int small;
    if(first_val<second_val){
        small = first_val;
    }
    else{
        small = second_val;
    }
    int factor = 1;
    for(int i = 1; i<=small; i++){
        if(first_val%i == 0 && second_val%i == 0){
            factor = i;
        }
    }
    return factor;
}

int LCM(int first_val, int second_val){
    int multiply = first_val*second_val;
    int ans = multiply/GCD(first_val, second_val);
    return ans;
}

void Number_statistics(){
    vector<int> num;
    string input;
    int value;
    cout << "Enter numbers separated by spaces: ";
    getline(cin >> ws, input);
    stringstream ss(input);
    while(ss >> value){
        num.push_back(value);
    }
    if(num.empty()){
        cout << "No numbers entered.\n";
        return;
    }
    int count = num.size();
    int sum = 0;
    int minimum = num[0];
    int maximum = num[0];
    int even = 0;
    int odd = 0;
    for(int number : num){
        sum += number;

        if(number < minimum){
            minimum = number;
        }

        if(number > maximum){
            maximum = number;
        }

        if(number%2 == 0){
            even += 1;
        }
        else{
            odd += 1;
        }
    }
    double average = static_cast<double>(sum)/count;
    int range = maximum - minimum;
    cout << "\n========== RESULTS ==========\n";
    cout << "Count:   " << count << '\n';
    cout << "Sum:     " << sum << '\n';
    cout << "Average: " << average << '\n';
    cout << "Minimum: " << minimum << '\n';
    cout << "Maximum: " << maximum << '\n';
    cout << "Range:   " << range << '\n';
    cout << "Even:    " << even << '\n';
    cout << "Odd:     " << odd << '\n';
}

int main(){
    while(true){
        system("cls");
        int choice = choose();
        if(choice == 0){
            continue;
        }
        switch(choice){
            case 1: {
                system("cls");
                int value1;
                cout << "Enter the value: ";
                cin >> value1;
                Check_prime(value1); 
                system("pause");
                break;
            }    
            case 2: {
                system("cls");
                int value2;
                cout << "Enter the value: ";
                cin >> value2;
                int result2 = Factorial(value2);
                if(result2 == -1){
                    continue;
                } 
                cout << "The factorial of " << value2 << " is " << result2 << '\n';
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                int value3;
                cout << "Enter the value: ";
                cin >> value3;
                Fibonacci(value3); 
                system("pause");
                break;
            }
            case 4: {
                system("cls");
                int first_val4, second_val4;
                cout << "Enter the two values: ";
                cin >> first_val4 >> second_val4;
                int result4 = GCD(first_val4, second_val4); 
                cout << "The GCD of " << first_val4 << " and " << second_val4 << " is " << result4 << '\n';
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                int first_val5, second_val5;
                cout << "Enter the two values: ";
                cin >> first_val5 >> second_val5;
                int result5 = LCM(first_val5, second_val5);
                cout << "The LCM of " << first_val5 << " and " << second_val5 << " is " << result5 << '\n';
                system("pause");
                break;
            }
            case 6: {
                system("cls");
                Number_statistics(); 
                system("pause");
                break;
            }
            case 7: return 0;
            default:
            cout << "Not in choice";
        }
    }
    return 0;
}