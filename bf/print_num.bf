from esolangs dot org

space needed is 7 plus number of digits

copy cell to workspace and back
[>>+>+<<<-]>>>
[<<<+>>>-]<<+>
[<->[ while value exists
   >++++++++++< make a 10
   [->-[>+>>]>[+[-<+>]>+>>]<<<<<] divide value by 10
   >[-] dont need this cell
   ++++++++[<++++++>-] add 48 to remainder
   >[<<+>>-] store the remainder
   >[<<+>>-] get next value
   <<
]>]
<[- else need to make a zero
   >>++++++++[<++++++>-]
]
print and clear each stored remainder in reverse
<[.[-]<]<
