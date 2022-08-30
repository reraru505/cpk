# cpk
intended simple package manager for C languae

# installation steps

```sh
./cpk compile
```

```sh
sudo cp bin/cpk /usr/bin
```
## Usage ->

To make a simple cpk project use
```sh
$ cpk mksol <projectname>
```
To compile the said project use
  ```sh
$ cpk compile
```

## Adding libraries

1) Go to your cpkinfo.cpk 
2) Create folder named libs in solution directory and put your static libs there
3) Add the library headers to the headers directory
4) Add the libs at the end with "-l" prefix 
  exaple : -lsdl2 -lm
5) Run the command
 ```sh
$ cpk addlib
```
6) now you can compile your projects with 
  ```sh
$ cpk compile
```

## Note it only wroks on linux

