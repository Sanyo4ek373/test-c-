#include <iostream>
#include <random>
#include <string>

int main() {
    while (true) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<int> distribution(1,6);

        int dice_roll = distribution(generator);
        std::string player_input;

        while (true) {
            std::cout << "Write your number from 1 to 6 or exit: ";
            std::cin >> player_input;

            if(player_input == "exit") {
                return 0;
            }

            try {
                std::stoi(player_input);
            } 
            catch (std::exception &err) {
                std::cerr << "Error! Your must write number or 'exit' " << std::endl;
                continue;
            }   

            int player_number = std::stoi(player_input);

            std::cout << "Your number: " << player_number << std::endl; 

            if (player_number == dice_roll) {
                std::cout << "You win!" << std::endl;
                break;
            }
            else if (player_number > dice_roll) {
                std::cout << "You number bigger!" << std::endl; 
            }
            else if (player_number < dice_roll) {
                std::cout << "You number smaller!" << std::endl;
            }
        }
    }
    return 0;
}