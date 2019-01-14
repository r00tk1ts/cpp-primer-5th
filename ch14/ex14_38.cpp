#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

struct IsInRange
{
    IsInRange(std::size_t _lower, std::size_t _upper) : lower(_lower), upper(_upper) { }

    bool operator()(std::string const& str) const
    {
        return str.size() >= lower && str.size() <= upper;
    }

    std::size_t lower_limit() const
    {
        return lower;
    }

    std::size_t upper_limit() const
    {
        return upper;
    }
private:
    std::size_t lower;
    std::size_t upper;
};

int main()
{
    //create predicates with various upper limits.
    std::size_t lower = 1;
    auto uppers = { 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u };
    std::vector<IsInRange> predicates;
    for (auto upper : uppers)
        predicates.push_back(IsInRange{ lower, upper });

    //create count_table to store counts 
    std::map<std::size_t, std::size_t> count_table;
    for (auto upper : uppers)
        count_table[upper] = 0;

    //read file and count
    std::ifstream fin("storyDataFile.txt");
    for (std::string word; fin >> word; /* */)
        for (auto is_size_in_range : predicates)
            if (is_size_in_range(word))
                ++count_table[is_size_in_range.upper_limit()];

    //print
    for (auto pair : count_table)
        std::cout << "count in range [1, " << pair.first << "] : " << pair.second << std::endl;

    return 0;
}