#include <iostream>

#include "../include/utils.h"

int showMenu(std::vector<std::string> text, std::vector<std::string> options)
{
    bool firstAttempt = true;

    while (true)
    {
        std::string toShow = "\n========================================\n";

        if (!firstAttempt)
            toShow += "\nThat isn't an option! Try again. Type in 1-" + std::to_string(options.size()) + "\n";

        for (std::size_t i = 0; i < text.size(); i++)
            toShow += "\n" + text[i];

        toShow += '\n';

        for (std::size_t i = 0; i < options.size(); i++)
            toShow += "\n" + std::to_string(i + 1) + ") " + options[i];

        std::string input;

        std::cout << toShow << '\n'
                  << std::endl;
        std::cin >> input;

        int selected = -1;

        try
        {
            selected = std::stoi(input);
        }
        catch (const std::exception &e)
        {
            // empty
        }

        if (selected >= 1 && selected <= static_cast<int>(options.size()))
            return selected;

        firstAttempt = false;
    }
}