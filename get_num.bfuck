this program gets a base 10 number from the user of arbitrary length
the number is stored at the entry position
the program needs 4 spaces to start out as zero as they will be when it exits

_mem map_

val	1	tmp	in

>+
[
	>>, get input
	---------- subtract ten
	[ if the input is not 10 ie newline
		
		----------
		----------
		----------
		--------	subtract 38 which brings the total down to input minus 48
		
		<<<[	multiply val by 10
			>>
			++++++++++
			<<-
		]
		
		>>[<<+>>-] move tmp to val
		
		>[<<<+>>>-] add in to val
		
		< comes out with the pointer on tmp
	] this loop will always end on the zero
	
	<	if the input was 10 the pointer will be on tmp and the loop will quit
		otherwise the pointer will be on 1 and it will keep going
]
<-<
