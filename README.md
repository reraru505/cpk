# cpk
intended simple code manager for C languae

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

## Compilemode usage

1) Set 0 for release without libs
2) Set 1 for release with libs
3) Set 2 for debug without libs
4) Set 3 for debug with libs


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

