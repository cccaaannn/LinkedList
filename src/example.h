#include <iostream>
#include "List.h"
#include <time.h>

void example1();
void example2();
void example3();

void runExample(int num){
    if(num == 1){
        example1();
    }
    if(num == 2){
        example2();
    }
    if(num == 3){
        example3();
    }
}



void example1(){

    List<int> list;

    try{
        // using append push remove
        std::cout << "append push remove example" << std::endl;
        std::cout << "appending elements" << std::endl;
        list.append(0);
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        std::cout << list << " length:" << list.getLen() << std::endl;

        std::cout << "removing elements on indexes 1,2,0" << std::endl;
        list.remove(1);
        list.remove(2);
        list.remove(0);

        std::cout << list << " length:" << list.getLen() << std::endl;

        std::cout << "pushing elements 2,1,0 to the begining" << std::endl;
        list.push(2);
        list.push(1);
        list.push(0);

        std::cout << list << " length:" << list.getLen() << std::endl;


        // using get and set
        std::cout << "\nget and set example" << std::endl;
        std::cout << "geting elements 0,1,2" << std::endl;
        int element0 = list.get(0);
        int element1 = list.get(1);
        int element2 = list.get(2);

        std::cout << "elements: " << element0 << " " << element1 << " " << element2 << std::endl;
        
        std::cout << "seting elements 0,1,2 to 10,11,12" << std::endl;
        list.set(0, 10);
        list.set(1, 11);
        list.set(2, 12);

        std::cout << "elements: " << list[0] << " " << list[1] << " " << list[2] << std::endl;
        

        // using pop and top
        std::cout << "\npop and top example" << std::endl;
        std::cout << "top: " << list.top() << std::endl;
        std::cout << "pop" << std::endl;
        list.pop();
        std::cout << "top: " << list.top() << std::endl;
        std::cout << "pop" << std::endl;
        list.pop();
        std::cout << "top: " << list.top() << std::endl;


        // copy constructor
        std::cout << "\ncopy constructor example" << std::endl;
        std::cout << "creating list2 with copy constructor" << std::endl;
        List<int> list2 = list;
        std::cout << "clearing list to test deep copying" << std::endl;
        list.clear();
        std::cout<< "list isEmpty: " << list.isEmpty() << list  << std::endl;
        std::cout << "list2 isEmpty: " << list2.isEmpty() << list2 << std::endl;
        

        // print options
        std::cout << "\nprinting example" << std::endl;
        std::cout << list2 << std::endl;
        list2.printList();
        list2.printListReverse(-1);
        list2.printListCustom(")->(", "\n", "(", ")"); 
        
        list2.~List();

        std::cout << std::endl;

    }
    catch(std::string e){
        std::cout << e << std::endl;
    }
    catch(...)  { 
        std::cout << "Default Exception" << std::endl; 
    } 
}


void example2(){

    std::cout << "string example" << std::endl << std::endl;

    List<std::string> list;

    list.append("Hello");
    list.append(" ");
    list.append("World");
    list.append("!");
    
    std::cout << list << std::endl;

    for (int i = 0; i < list.getLen(); i++){
        std::cout << i << " - " << list[i] << std::endl;
    }
    


}


void example3(){
    
    std::cout << "sorting example" << std::endl;
    std::cout << "int sorting" << std::endl << std::endl;

    List<int> intList;

    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        int randNum = rand() % 100 + 1;
        intList.append(randNum);
    }

    intList.printList();
    intList.sortList();
    intList.printList();

    std::cout << "\nstr sorting" << std::endl << std::endl;

    List<std::string> strList;

    strList.append("!");
    strList.append("a");
    strList.append("can");
    strList.append("hi");
    strList.append("hello");
    strList.append("1");
    strList.append("100");
    strList.append("asd");
    strList.append("c");
    strList.append("*");
    
    strList.printList();
    strList.sortList();
    strList.printList();


}



