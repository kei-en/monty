# C - Stacks, Queues - LIFO, FIFO

## Monty Interpreter

This interpreter was built in the C language and is compliant with `ISO90`, `ISO99`, & `ISO11`. It reads Monty bytecode files of any extension (preferably `.m` although it doesn't matter), and interprets the opcodes contained.
The interpreter can be run as either a stack (LIFO) or queue (FIFO). Mode can be switched mid-script. It can handle a variety of Monty opcodes, including printing, mathematical operations, and more - all handled opcodes are listed below.

## Monty Opcodes

- push

  - Usage: push `<int>`
  - Pushes an element to the stack.
  - The parameter `<int>` must be an integer.

- pall

  - Prints all values in the stack/queue, starting from the top.

- pint

  - Prints the top value of the stack/queue.

- pop

  - Removes the top element of the stack/queue.

- swap

  - Swaps the top two elements of the stack/queue.

- nop

  - Does not do anything.

- add

  - Adds the top two elements of the stack/queue.
  - The result is stored in the second element from the top and the top element is popped.

- sub

  - Subtracts the top element of the stack/queue from the second element from the top.
  - The result is stored in the second element from the top and the top element is removed.

- mul

  - Multiplies the top two elements of the stack/queue.
  - The result is stored in the second element from the top and the top element is removed.

- div

  - Divides the second element from the top of the stack/queue by the top element.
  - The result is stored in the second element from the top and the top element is removed.

- mod

  - Computes the modulus of the second element from the top of the stack/queue divided by the top element.
  - The result is stored in the second element from the top and the top element is removed.

- pchar

  - Prints the character value of the top element of the stack/queue.
  - The integer at the top is treated as an ASCII value.

- pstr

  - Prints the string contained in the stack/queue.
  - Prints characters element by element until the stack/queue is empty, a value is 0, or an error occurs.

- rotl

  - Rotates the top element of the stack/queue to the bottom.

- rotr

  - Rotates the bottom element of the stack/queue to the top.

- stack

  - Switches a queue to stack mode.

- queue
  - Switches a stack to queue mode.
