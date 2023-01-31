void test_launch() {
  Points points{Coordinate(1, 1), Coordinate(2, 2)};
  Parameters parameters{.LENGTH1 = 1};
  std::vector<bool (*)(Points, Parameters)> lics;
  lics.push_back(lic0);
}

int main() { test_launch(); }