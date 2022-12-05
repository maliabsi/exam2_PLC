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

# FIRST TABLE:
<img width="252" alt="image" src="https://user-images.githubusercontent.com/90993724/205756541-f0530e03-5e04-4933-8c1a-db03234c0984.png">

# CODE SAMPLES:
* CORRECT: 
<img width="468" alt="image" src="https://user-images.githubusercontent.com/90993724/205756164-95ace011-1cae-4d7d-8e23-c2d21e870e1c.png">
<img width="468" alt="image" src="https://user-images.githubusercontent.com/90993724/205756223-078980fa-39de-46c6-957a-edaddc2e1465.png">

* INCORRECT: 
<img width="468" alt="image" src="https://user-images.githubusercontent.com/90993724/205756343-17973832-324e-4540-896f-5c91cb13e813.png">
<img width="468" alt="image" src="https://user-images.githubusercontent.com/90993724/205756369-4fa57a2f-9271-47f4-85f0-4d34f7cba715.png">



# SEE DOC FOR REST:
  
https://docs.google.com/document/d/1c1CKPVK2RPAiskiI82ruzTDwOySZDg5z/edit?usp=sharing&ouid=117926942441823319803&rtpof=true&sd=true
