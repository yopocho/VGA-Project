# Driver for user IO to VGA output for STM32F407

This repository contains an example project which utilizes a custom driver which interfaces between a UART peripheral and a VGA-screen driver, allowing for increased simplicity in reusing recycled VGA-screens.

On behalf of IP (Innovative Power) Culemborg, created at the Univeristy of Applied Sciences Utrecht.

## Overview
![image1](images/Functioneel_Schema.png)


### Front Layer

The Front Layer is the point of contact between the program and the user. This is where the most errors can occure. The first point of entry is an interupt that takes care of the UART. The recieved messaged is put into an input struct with the command length. When a message is recieved the message is put into the parser to check what command it is. If a command is found the rest of the arguments wil be looked for and added to a new command struct. This command struct is filled with the command number, command arguments, text, font & font style. this struct can be passed on to all the different layers.

### Logic Layer

Suspendisse commodo consectetur nulla, sit amet eleifend odio mattis sed. Phasellus pretium euismod nibh at feugiat. In vehicula venenatis dolor. Pellentesque et rutrum sem. Vivamus dictum finibus est, nec dictum ligula fringilla vitae. Duis nec risus et dolor egestas sodales et quis orci. Aliquam vel ullamcorper ipsum.


### IO Layer

Nullam ac nulla sit amet metus condimentum lobortis non sit amet neque. Nam euismod metus dolor, in lacinia diam congue ut. Morbi blandit imperdiet eros, eu vehicula purus vestibulum in. In a dolor dolor. Cras quis hendrerit elit. Vivamus nec gravida purus. Duis dapibus mollis risus non feugiat. Donec porta arcu non est interdum egestas. Ut ullamcorper libero convallis, ullamcorper lorem a, volutpat ex. Proin tincidunt nec ante eget sodales. Nunc sed accumsan lacus.


## Use

Mauris maximus, diam eget commodo pretium, metus est sollicitudin urna, eget condimentum arcu velit a diam. Aliquam dui quam, vulputate vitae gravida imperdiet, faucibus non lacus. Suspendisse potenti. Ut blandit quam a lacinia tincidunt. Nunc convallis lectus ut vulputate ornare. Donec risus turpis, scelerisque sed blandit id, tristique et neque. Vestibulum et consequat lorem. Pellentesque vel elit eu lacus fermentum iaculis. Curabitur pretium auctor augue, egestas commodo magna lacinia non. Vivamus pharetra est ut placerat consectetur. Pellentesque vel interdum tellus. In vestibulum sit amet turpis nec elementum.


## Built With

* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) - IDE 
* [STM32F4DISCOVERY](https://www.st.com/en/evaluation-tools/stm32f4discovery.html) - Development Board
* [Google C++ Styleguide](https://google.github.io/styleguide/cppguide.html#Constant_Names) - Styleguide

## Authors

* **Niels van der Zijden** - [Yopocho](https://github.com/yopocho)
* **Ruben Middelman** - [rubenmiddelman](https://github.com/rubenmiddelman) 
* **Sjoerd den Breejen** - [Sjoerddbb](https://github.com/Sjoerddbb) 

## License

This project is licensed under the MIT License

## List of commands
- clearscherm,
- lijn,
- rechthoek,
- wacht,
- tekst,
- bitmap,
- cirkel,
- figuur,
- herhaal,

## known bugs and errors
- [x] command , 
        - (example: clearscherm ,) if there is a space on any other spot there is no problem but when it is a comma richt after the space it will give an unkown command error. This is because it doesnt recoginze the command with a space at the end.
- [ ] herhaal, 
- [ ] errors are broad and not added everywhere
- [ ] too many arguments doesn't return an error
- [x] wacht doesn't wait


## posible new features
- [ ] parser filter on \n: so we can send multiple commands at the same 
- [ ] random numbers, to auto generate input




