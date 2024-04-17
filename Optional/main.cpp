
#include <iostream>
#include <optional>
#include <filesystem>

class FootballTeam
{
public:
  int getSizeOfTeam() { return 53; }

private:
};

std::optional<FootballTeam> getTeam(std::string teamName) {
  // search for team in the database
  FootballTeam aggies;
  if (teamName == "aggies")
  {
    return aggies;
  }
  return std::nullopt;
}

int main() {
  auto team = getTeam("doughnuts");

  if (team)
  {
    std::cout << team->getSizeOfTeam() << std::endl;
    std::cout << "Found the doughnuts football team" << std::endl;
  }
  else
  {
    std::cout << "Did not find the doughnuts football team" << std::endl;
  }

  std::optional<int> myInt;
  std::cout << myInt.value_or(3) << std::endl;

  std::filesystem::path myPath("../output.txt");
  std::cout << myPath.string() << std::endl;

  if (std::filesystem::exists(myPath))
  {
    std::cout << "It exists!" << std::endl;
    if (std::filesystem::is_directory(myPath))
      std::cout << "its a directory!" << std::endl;
    std::filesystem::copy(myPath, "output.txt");
  }

  std::cout << std::filesystem::current_path().string() << std::endl;

  for (auto itr = std::filesystem::recursive_directory_iterator(".");
       itr != std::filesystem::recursive_directory_iterator();
       itr++)
  {
    std::cout << itr->path().string() << std::endl;
  }

  return 0;
}