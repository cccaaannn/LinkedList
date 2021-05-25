## LinkedList
----

![GitHub top language](https://img.shields.io/github/languages/top/cccaaannn/LinkedList?style=flat-square) ![](https://img.shields.io/github/repo-size/cccaaannn/LinkedList?style=flat-square) [![GitHub license](https://img.shields.io/github/license/cccaaannn/LinkedList?style=flat-square)](https://github.com/cccaaannn/LinkedList/blob/master/LICENSE)

### C++ LinkedList

<br/>
 
```c++
List<int> list;

list.append(10);
list.append(1);
list.append(0);
list.append(42);
list.append(500);

list.push(-10);
list.push(-50);
list.push(21);

list.pop();
list.remove(1);

list.printList();
list.sortList();
list.printListCustom(")->(","\n\n","(",")");
```

output
```
[21,-10,10,1,0,42]
(-10)->(0)->(1)->(10)->(21)->(42)
```

<br/>


```c++
List<std::string> list;

list.append("Hello");
list.append(" ");
list.append("World");
list.append("!");

std::cout << list << std::endl;

for (int i = 0; i < list.getLen(); i++){
    std::cout << i << " - " << list[i] << std::endl;
}

std::cout << "length: " << list.getLen() << std::endl;
```

output
```
[Hello, ,World,!]
0 - Hello
1 -
2 - World
3 - !
length: 4
```




