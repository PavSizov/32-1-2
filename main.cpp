#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

int main()
{

    std::ifstream file("text.json");

    nlohmann::json film;
    file >> film;
    file.close();

    std::string name;
    std::cout << "Enter actors name: ";
    std::getline(std::cin, name);

    std::vector<std::string> f;

    for(auto it = film.begin(); it != film.end(); ++it)
    {
        auto act = it->find("actors");

        if(act != it->end())
        {
            auto na = act->find(name);
            if(na != act->end())
            {
                std::string out = "Film: " +  it.key()
                                  + ", role in the film : " + nlohmann::to_string(na.value());
                f.push_back(out);
            }

        }
    }

    if(f.size() > 0)
    {
        for(auto &x : f)
            std::cout<< x <<std::endl;
    }
    else
    {
        std::cout << "Sorry, no such actor has been found";
    }

}
