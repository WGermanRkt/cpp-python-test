# Cpp Python runner
This a cpp test tool that can execute python calls.

## Install python development libraries
```
sudo apt-get install python3.8-dev
```

## Configure python development libraries
```
python3.8-config --cflags
```
```
for each flag, add
    add_compile_options("FLAG")
in CMakeLists.txt
```

```
python3.8-config --ldflags
```
```
for each flag, add
    link_libraries("FLAG") 
in CMakeLists.txt
```