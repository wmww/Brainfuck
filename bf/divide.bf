input
n	d	0	0	0	0	0

output
ans	0	0	0	0	0	0

this is an abstraction of division that should be able to be used in other code
when it is called the first 2 cells should hold the numorator and denominator and the next 5 cells should be 0
when it exits the first cell will be the answer and the next 6 will be 0

inputs at start			true
outputs at start		true
zeros all by end		true
total needed space		7

n	d	0	1	0	tmp	out

>>>+<<<
[
	->->>>>+<<<<
	[>]>>[ if d is 0
		>>>+			add one to out
		<[<<<<+>>>>-]<	copy value from tmp back to d leaving off at the 0 before tmp
	]
	<<<< decrement n
]
>>>>>>[<<<<<<+>>>>>>-] move out back to the 1st position
<[-]<<-<<[-]< zero out the other vals
