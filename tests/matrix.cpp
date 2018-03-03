#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("adding matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string resultadd{
        "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    matrix_t matrix1, matrix2, result;
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    result = matrix1 + matrix2;
    std::ostringstream ostream;
    result.write( ostream );
    REQUIRE( resultadd == ostream.str() );
}

TEST_CASE("sub matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    matrix_t matrix1, matrix2, result;
    std::istringstream istream1{ input2 };
    std::istringstream istream2{ input1 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    result = matrix1 - matrix2;
    std::ostringstream ostream;
    result.write( ostream );
    REQUIRE( input1 == ostream.str() );
}

TEST_CASE("mul matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string resultadd{
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    matrix_t matrix1, matrix2, result;
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    result = matrix1 * matrix2;
    std::ostringstream ostream;
    result.write( ostream );
    REQUIRE( resultadd == ostream.str() );
}

TEST_CASE("addequals matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string resultadd{
        "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    matrix1+=matrix2;
    std::ostringstream ostream;
    matrix1.write( ostream );
    REQUIRE( resultadd == ostream.str() );
}

TEST_CASE("subequals matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input2 };
    std::istringstream istream2{ input1 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    matrix1-=matrix2;
    std::ostringstream ostream;
    matrix1.write( ostream );
    REQUIRE( input1 == ostream.str() );
}

TEST_CASE("mulequals matrix")
{
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string resultadd{
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input1 };
    std::istringstream istream2{ input2 };
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    matrix1*=matrix2;
    std::ostringstream ostream;
    matrix1.write( ostream );
    REQUIRE( resultadd == ostream.str() );
}
