// #include "point.hpp"
#include "tuple.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Initilization of a tuple that is a point", "Tuple")
{
  const Ray::Tuple tuple(4.3, 4.2, -4.2, 1);

  REQUIRE(tuple.GetX() == 4.3);
  REQUIRE(tuple.GetY() == 4.2);
  REQUIRE(tuple.GetZ() == -4.2);

  REQUIRE(tuple.IsPoint());
  REQUIRE_FALSE(tuple.IsVector());
}

TEST_CASE("Initilization of a tuple that is a vector", "Tuple")
{
  const Ray::Tuple tuple(4.3, 4.2, -4.2, 0);

  REQUIRE(tuple.GetX() == 4.3);
  REQUIRE(tuple.GetY() == 4.2);
  REQUIRE(tuple.GetZ() == -4.2);

  REQUIRE_FALSE(tuple.IsPoint());
  REQUIRE(tuple.IsVector());
}

TEST_CASE("Initilization of Point and Vector", "[Point][Vector][Tuple]")
{

  Ray::Tuple tuple(4, -4, 3, 1);
  const Ray::Tuple point = Ray::Point(4, -4, 3);

  REQUIRE(point == tuple);

  tuple = Ray::Tuple(4, -4, 3, 1);
  const Ray::Tuple vector = Ray::Vector(4, -4, 3);

  REQUIRE(vector == tuple);
}

TEST_CASE("Adding tuples", "[Tuple]")
{
  const Ray::Tuple tuple1(3, -2, 5, 1);
  const Ray::Tuple tuple2(-2, 3, 1, 0);

  const Ray::Tuple answer(1, 1, 6, 1);

  REQUIRE(answer == tuple1 + tuple2);
}
