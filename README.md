# Events Library

C++ library that implements C#-like events

## Features
    * Header-only
    * C#-like feel, i.e. +=, -=, invoke

## Usage
Simply clone this repository and include in your project.
Example:
```c++
struct SomeStruct {
    int a;
};

class Server {
    event::Event<SomeStruct> OnSomeStruct;

    void Handle(std::shared_ptr<SomeStruct> data)
    {   
        this->OnSomeStruct.Invoke(data);
        // or
        this->OnSomeStruct(data);
    }
}

// someStruct is a shared_ptr to SomeStruct
server.OnSomeStruct += [](auto someStruct) {
    std::cout << someClass->a << std::endl;
};
```