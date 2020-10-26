
/**
 * Thread safe implementation of Singleton class
 * 
 * @file: Singleton.cpp
 * @author: Mohammad Aasim
 *
 */


#include <iostream>
#include <thread>
#include <mutex>

class DepartmentHead{
    std::string name;

    //will hold singleton department head object
    static DepartmentHead *obj;

    static std::mutex mtx;

    DepartmentHead(): name("Mr./Mrs. XYZ") { }

public:

    //delete copy ctor and copy assignment operator
    DepartmentHead(const DepartmentHead& obj) = delete; 
    DepartmentHead& operator=(const DepartmentHead& obj) = delete;

    static DepartmentHead* getObject(){
		/**
		 * To ensure that, only single object is created when multiple threads are
		 * accessing object at the same time.
		 */
        std::lock_guard<std::mutex> lock(mtx);
        if(!obj){
            obj = new DepartmentHead();
        }
        return obj;
    }

    std::string getDepartmentHeadName(){
        return name;
    }

	//Overriding delete operator, so that singleton object is not deleted 
    void operator delete (void *head) { /*Don't delete it*/ }

    void doSomeWork(){
        /**
         * Do work here
         */
        std::cout<<"Work done\n";
    }
};

//initialize static properties
DepartmentHead *DepartmentHead::obj = nullptr;
std::mutex DepartmentHead::mtx;

// Driver Program
int main(){
    DepartmentHead *head = DepartmentHead::getObject();
    std::cout<<"Head is: "<<head->getDepartmentHeadName()<<std::endl;
    head->doSomeWork();

    delete head;
    std::cout<<"After deleting head\n";
    head->doSomeWork();
	head->doSomeWork();

    return 0;
}