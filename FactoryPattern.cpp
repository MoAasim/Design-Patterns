
/**********************************************************************************
 * Simple Factory Design Pattern implementation
 * 
 * @file: FactoryPattern.cpp
 * @auther: Mohammad Aasim
 *  
 * *******************************************************************************/

#include <iostream>

//abstract class as interface
class Cloud{
public:
    Cloud(){}

    virtual void operations() = 0;

    virtual ~Cloud() {}
};

class AWS : public Cloud{
public:
    AWS(){
        std::cout<<"AWS started\n";
    }

    void operations() override {
        std::cout<<"AWS operations\n";
        std::cout<<".......................\n";
        std::cout<<"Done\n";
    }

    ~AWS(){
        std::cout<<"Shutting down AWS\n";
    }
};

class Azure : public Cloud {
public:
    Azure(){
        std::cout<<"Azure started\n";
    }

    void operations() override {
        std::cout<<"Azure operations\n";
        std::cout<<".......................\n";
        std::cout<<"Done\n";
    }

    ~Azure(){
        std::cout<<"Shutting down Azure\n";
    }
};

class GoogleCloud : public Cloud {
public:
    GoogleCloud(){
        std::cout<<"GoogleCloud started\n";
    }

    void operations() override {
        std::cout<<"GoogleCloud operations\n";
        std::cout<<".......................\n";
        std::cout<<"Done\n";
    }

    ~GoogleCloud(){
        std::cout<<"Shutting down GoogleCloud\n";
    }
};

/*
 * So called NULL OBJECT PATTERN
 * It is used to mimic the cretion of null object.
 * If the required type is not set as the param of object creating method
 * then null object is created.
 * It doesn't implement any functionality but just be there to handle the non-supported type
 */ 
class NullCloud : public Cloud {
public:
    NullCloud(){
        std::cout<<"Null ptr\n";
    }
    void operations() override {
        std::cout<<"Null ptr:). \nNothing can be done\n";
    }

    ~NullCloud(){
        std::cout<<"Nothing...\n";
    }
};

enum class Type{
    AWS,
    Azure,
    GoogleCloud
};

class CloudFactory{
public:
    static Cloud* getCloudObject(Type type){
        Cloud *cloud;
        switch(type){
            case Type::AWS:
                cloud = new AWS();
                break;
            case Type::Azure:
                cloud = new Azure();
                break;
            case Type::GoogleCloud:
                cloud = new GoogleCloud();
                break;
            default:
                cloud = new NullCloud();
        }

        return cloud;
    }
};

//Driver program
int main(){
    
    Cloud *cloud = CloudFactory::getCloudObject(Type::AWS);
    cloud->operations();
    delete cloud;

    cloud = CloudFactory::getCloudObject(Type::Azure);
    cloud->operations();
    delete cloud;

    cloud = CloudFactory::getCloudObject(Type::GoogleCloud);
    cloud->operations();
    delete cloud;

    cloud = CloudFactory::getCloudObject(static_cast<Type>(-1));
    cloud->operations();
    delete cloud;

    return 0;
}