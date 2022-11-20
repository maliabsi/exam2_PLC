# exam2_PLC

*	Addition: +
*	Subtraction: -
*	Multiplication: *
*	Division: /
*	Module: %
*	Less than: <
*	Greater than: >
*	Less than Equal To: #
*	Greater than Equal To: ^
*	Equal To: @
*	Not Equal To: !
*	Assignment: =
*	(There must also be a way to break precedence, this is usually done with the use of parenthesis):
( [a-zA-Z0-9_+-*/%]* )

# VARIABLE NAMES: 
* [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z]? [a-z_A-Z]?

# INT LITERALS:
* 1 byte (byte): 	[0-9]+_b
* 2 byte (int): 		[0-9]+_i
* 4 byte SHORT(float): 	[0-9]+_f
* 8 byte LONG (double): 	[0-9]+_d

# PRODUCTION RULES:
* <program> --> begin <stmt_list> end
* <stmt_list> --> { <stmt> ‘;’ }
* <stmt> --> <whale_loop> | <declare> | <iguana_stmt> | <assign_stmt>
* <while_loop> --> ‘whale’ ‘(‘ <bool_expr>’)’ <stmt>
* <declare> --> ‘temp’ ‘id’ 
* <if_stmt> --> ‘iguana’ ‘(‘ <bool_expr>’)’ <stmt> [‘elephant’ <stmt> ]
* <assign_stmt> -->‘id’ ‘=’ <expr> 
* <expr> --> <term> { (‘*’| ‘-‘) <term> }
* <term> --> <factor> { (‘/’| ‘+’ | ‘%’) <factor> }
* <factor> --> ‘id’ | ‘int_lit’ |  ‘(‘ <expr> ‘)’

* <bool_expression> --> <brel> { (‘!’| ‘@’) <brel> }
* <brel> --> <bexpr> { (‘#’| ‘^’| ‘<’| ‘>‘) <bexpr> }
* <bexpr> --> <bterm> { (‘*’| ‘-‘) <bterm> }
* <bterm> --> <bstuff> { (‘/’| ‘+’| ‘%’) <bstuff> }
* <bfactor> --> ‘id’ | ‘int_lit’ | ‘bool_lit’ | ‘(‘ <bexpr> ‘)’

 # SEE DOC FOR REST:
  
https://docs.google.com/document/d/1nkkAqYrTwohuYH_5K3Iwt1ATRMISi3IN/edit?usp=sharing&ouid=109582375527567682751&rtpof=true&sd=true

