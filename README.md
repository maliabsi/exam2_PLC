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
( )

# VARIABLE NAMES: 
* [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z] [a-z_A-Z]? [a-z_A-Z]?

# INT LITERALS:
* 1 byte (byte): 	[0-9]+_b
* 2 byte (int): 		[0-9]+_i
* 4 byte SHORT(float): 	[0-9]+_f
* 8 byte LONG (double): 	[0-9]+_d

# KEYWORDS:
* While: Whale
*	If: Iguana
*	Else: Elephant
*	Variable: temp
*	Begin
*	End

# PRODUCTION RULES:
* <program> -> begin <stmt_list> end
* <stmt_list> -> <stmt>
* <stmt> -> <whale_loop> | <declare> | <iguana_stmt> | <assign_stmt> | <block>
* <block -> { <stmt_list> }
* <while_loop> -> ‘whale’ ‘(‘ <bool_expr> ’)’ <block>
* <declare> -> ‘temp’ ‘id’ ‘;’
* <if_stmt> -> ‘iguana’ ‘(‘ <bool_expr> ’)’ <block> [ ‘elephant’ <block> ]
* <assign_stmt> -> ‘id’ ‘=’ <expr> ‘;’
* <expr> -> <term> { (‘*’| ‘-‘) <term> }
* <term> -> <factor> { (‘/’| ‘+’ | ‘%’) <factor> }
* <factor> -> ‘id’ | ‘int_lit’ |  ‘(‘ <expr> ‘)’
* <bool_expr> -> <brel> { (‘!’| ‘@’) <brel> }
* <brel> -> <bexpr> { (‘#’| ‘^’| ‘<’| ‘>‘) <bexpr> }
* <bexpr> -> <bterm> { (‘*’| ‘-‘) <bterm> }
* <bterm> -> <bfactor> { (‘/’| ‘+’| ‘%’) <bfactor> }
* <bfactor> -> ‘id’ | ‘int_lit’ | ‘(‘ <bexpr> ‘)’
  
# PARSE TABLE RULES:
* S' -> PROGRAM
* PROGRAM -> begin STMT_LIST end
* STMT_LIST -> STMT
* STMT -> WHALE_LOOP
* STMT -> DECLARE
* STMT -> IGUANA_STMT
* STMT -> ASSIGN_STMT
* STMT -> BLOCK
* WHALE_LOOP -> whale ( BOOL_EXPR ) BLOCK
* DECLARE -> temp id ;
* IGUANA_STMT -> iguana ( BOOL_EXPR ) BLOCK
* IGUANA_STMT -> iguana ( BOOL_EXPR ) BLOCK elephant BLOCK
* ASSIGN_STMT -> id = EXPR ;
* BLOCK -> { STMT_LIST }
* EXPR -> TERM * TERM
* EXPR -> TERM - TERM
* TERM -> FACTOR / FACTOR
* TERM -> FACTOR % FACTOR
* TERM -> FACTOR + FACTOR
* FACTOR -> id
* FACTOR -> int_lit
* FACTOR -> ( EXPR )
* BOOL_EXPR -> BREL ! BREL
* BOOL_EXPR -> BREL @ BREL
* BOOL_EXPR -> BREL
* BREL -> BEXPR # BEXPR
* BREL -> BEXPR ^ BEXPR
* BREL -> BEXPR < BEXPR
* BREL -> BEXPR > BEXPR
* BEXPR -> BTERM * BTERM
* BEXPR -> BTERM - BTERM
* BEXPR -> BTERM
* BTERM -> BFACTOR / BFACTOR
* BTERM -> BFACTOR + BFACTOR
* BTERM -> BFACTOR % BFACTOR
* BTERM -> BFACTOR
* BFACTOR -> id
* BFACTOR -> int_lit
* BFACTOR -> ( BEXPR )

# SEE DOC FOR REST:
  
https://docs.google.com/document/d/1nkkAqYrTwohuYH_5K3Iwt1ATRMISi3IN/edit?usp=sharing&ouid=109582375527567682751&rtpof=true&sd=true

