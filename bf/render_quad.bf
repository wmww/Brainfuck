
(unfinished)

renders a quad with flat top and bottom edges

input format

low_y		hgh_y		low_lft_x	hgh_lft_x	low_rgt_x	hgh_rgt_x
|

[>>>>>>+>+<<<<<<<-]>>>>>>>[<<<<<<<+>>>>>>>-]<<<<<<< move low_y to the end make a copy and move the copy back to the original location

low_y		hgh_y		low_lft_x	hgh_lft_x	low_rgt_x	hgh_rgt_x	i (low_y)
																		|

>[>>>>>->+<<<<<<-]< subtract hgh_y from i and populated a temp var after i
[	starts at i
	
	>>>>>>>[<+<<<<<+>>>>>>-] repopulate hgh_y and fix i
	
	+
]

