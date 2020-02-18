/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;
    
    T(int v, const char* n) : value(v), name(n) { }   //1, 2, 3
};

struct StructOne    //4
{
    T* compare(T& a, T& b) const //5
    {
        if(a.value < b.value) return &a;
        if(a.value > b.value) return &b;
        return nullptr;
    }
};

struct U
{
    float floatOne { 0 }, floatTwo { 0 };
    float memberFunction(const float& updatedValue)    //12
    {
        std::cout << "U's floatOne value: " << floatOne << std::endl;
        floatOne = updatedValue;
        std::cout << "U's floatOne updated value: " << floatOne << std::endl;
        while(std::abs(floatTwo - floatOne) > 0.001f)
        {
            floatTwo += 0.001f;
        }   
        std::cout << "U's floatTwo updated value: " << floatTwo << std::endl;
        return floatTwo * floatOne;
    }
};

struct StructTwo
{
    static float staticFunctionA(U& that, const float& updatedValue)    //10
    {
        std::cout << "U's floatOne value: " << that.floatOne << std::endl;
        that.floatOne = updatedValue;
        std::cout << "U's floatOne updated value: " << that.floatOne << std::endl;
        while( std::abs(that.floatTwo - that.floatOne) > 0.001f)
        {
            that.floatTwo += 0.001f;
        }
        std::cout << "U's floatTwo updated value: " << that.floatTwo << std::endl;
        return that.floatTwo * that.floatOne;
    }
};
        
int main()
{
    T t1(102, "T1");    //6
    T t2(6, "T2");    //6
    
    StructOne f;    //7
    auto* smaller = f.compare( t1, t2 );    //8
    if(smaller != nullptr)
    { 
        std::cout << "the smaller one is << " <<  smaller->name << std::endl;    //9
    }

    U u1;
    const float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << StructTwo::staticFunctionA(u1, updatedValue) << std::endl;    //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.memberFunction(updatedValue) << std::endl;
}

        
        
        
        
        
        
        
