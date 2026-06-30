#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int min, max, attempts, guess;

    cout << "=====================================================" << endl;
    cout << "        WELCOME TO GUESS THE NUMBER GAME!       " << endl;
    cout << "=====================================================" << endl;

    // User chooses the range
    cout << "\n Enter the minimum number: ";
    cin >> min;

    cout << " Enter the maximum number: ";
    cin >> max;

    // Check if range is valid
    if (min >= max)
    {
        cout << "\n Oops! That's not a valid range. " << endl;
        cout << " The maximum number must be greater than the minimum number." << endl;
        cout << " Please restart the game and try again!" << endl;
        return 0;
    }

    // User chooses number of attempts
    cout << "\n How many attempts would you like? ";
    cin >> attempts;

    // Check if attempts are valid
    if (attempts <= 0)
    {
        cout << "\n Wait a second... " << attempts << " attempts? Really? " << endl;
        cout << " Even superheroes need at least ONE chance!" << endl;
        cout << " Restart the game and choose a positive number of attempts. " << endl;
        return 0;
    }

    // Generate random number
    srand(time(0));
    int randomNumber = rand() % (max - min + 1) + min;

    cout << "\n I've secretly chosen a number between "
         << min << " and " << max << "." << endl;
    cout << " You have " << attempts << " attempts to guess it!" << endl;
    cout << " Best of luck! Let the game begin!" << endl;

    // Guessing loop
    for (int i = 1; i <= attempts; i++)
    {
        cout << "\n==============================" << endl;
        cout << " Attempt " << i << " of " << attempts << endl;
        cout << " Enter your guess: ";
        cin >> guess;

        if (guess == randomNumber)
        {
            cout << "\n YAYYYY!! YOU ARE A GENIUS!! " << endl;
            cout << " Congratulations! Your guess was absolutely RIGHT! " << endl;
            cout << " Thanks for playing! " << endl;
            return 0;
        }
        else if (guess > randomNumber)
        {
            cout << " Oops! Your guess was TOO HIGH! " << endl;
            cout << " Try a smaller number! " << endl;
        }
        else
        {
            cout << " Oops! Your guess was TOO LOW! " << endl;
            cout << " Try a bigger number! " << endl;
        }
    }

    // If user loses
    cout << "\n Oh no! You've used all your attempts." << endl;
    cout << " The secret number was: " << randomNumber << endl;
    cout << " Don't worry! Every great player learns with practice." << endl;
    cout << " Play again and beat the game next time! " << endl;

    return 0;
}
