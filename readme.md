# Clox - C lox bytecode VM

Written following https://craftinginterpreters.com/a-bytecode-virtual-machine.html
My recursive descent interpreter: https://github.com/uozuAho/pylox

# Quick start
```sh
make run
```

# Notes
- scanner: chars to tokens
- compiler: tokens to bytecode
- vm: run bytecode

## GC
Not done yet, but keeping some notes:

- the vm stores a linked list of object pointers
- each call to allocate adds to the list

See https://craftinginterpreters.com/strings.html#freeing-objects

# To do
- WIP: https://craftinginterpreters.com/global-variables.html
