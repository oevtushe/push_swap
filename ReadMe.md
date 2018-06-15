#Push swap project in 42 School.


There are 2 programs named push_swap and checker, push_swap takes
integer numbers as arguments and prints commands to sort this numbers
using 2 stacks. Checker takes this commands and checks if they will sort
this numbers.

Push_swap operates 2 stacks:
1) stack named 'a' which is initialized by the values passed
    as arguments
2) stack named 'b' which is an additional placeholder for numbers.

##Commands to operate stacks
  -> 'pa' - push from 'a' to 'b'
  -> 'pb' - push from 'b' to 'a'
  -> sa - swap top 2 elements in 'a'
  -> sb - swap top 2 elements in 'b'
  -> ss - swap top 2 elements in both stacks
  -> ra - rotates stack 'a' (the first element becomes the last one)
  -> rb - rotates stack 'b'
  -> rr - rotates stack both stacks
  -> rra - reverse rotates stack 'a' (the last element becomes the first one)
  -> rrb - reverse rotates stack 'b'
  -> rrr - reverse rotates both stacks
 
 ###Checker options
    -c - colored printing both stacks, you can see
          what is going on with stacks after every
          command executed.
    -d - execute commands in the real time, you
          type the command, checker execute it and
          prints the stacks.
    -fd <filename> - force checker to read commands from
                       file except stdin.
    --pretty='<pretty string>' - changes the view of stacks
                                   printing, run ./checker --pretty='' to see format.
    -s - prints statistics of operations executed (sum of all operations executed,
           and number of executions for each operation)
           
 ###Push_swap options
    -fd <filename> - writes commands into specified file.
    
 Some ways to run:
    1) ARG='<random numbers>; ./push_swap $ARG | ./checker $ARG
    2) ARG='<random numbers>; ./push_swap $ARG | ./checker -c $ARG
    3) ARG='<random numbers>; ./push_swap $ARG | ./checker -s $ARG
    4) ARG='<random numbers>; ./push_swap $ARG | ./checker --pretty='^_^:: ^ ' $ARG
